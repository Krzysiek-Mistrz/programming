import json
import socket
import datetime
from types import MethodType


import logging
import sys
import os
from logging.handlers import TimedRotatingFileHandler
from threading import Thread
import time

OS = None
if sys.platform == "linux":
    import signal
    OS = "linux"
else :
    import win32api
    OS = "windows"

VERSION = "v4.11.0-alpha.74"
    
LOGLEVEL = os.getenv('NEURAPY_LOG_LEVEL','WARNING')

MONITOR_CYCLE_TIME = 0.05

COUNTER = 0

class CustomFormatter(logging.Formatter):

    grey = "\x1b[38;20m"
    yellow = "\x1b[33;20m"
    red = "\x1b[31;20m"
    bold_red = "\x1b[31;1m"
    reset = "\x1b[0m"
    format = (
        "[%(asctime)s][%(name)s][%(levelname)s] : %(message)s :(%(filename)s:%(lineno)d)"
    )

    FORMATS = {
        logging.DEBUG: grey + format + reset,
        logging.INFO: grey + format + reset,
        logging.WARNING: yellow + format + reset,
        logging.ERROR: red + format + reset,
        logging.CRITICAL: bold_red + format + reset,
    }

    def format(self, record):
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt,datefmt="%Y-%m-%d %H:%M:%S")
        return formatter.format(record)


def get_console_handler():
    console_handler = logging.StreamHandler(sys.stdout)
    console_handler.setLevel(eval('logging.'+LOGLEVEL))
    console_handler.setFormatter(CustomFormatter())
    return console_handler


def get_logger(logger_name):
    logger = logging.getLogger(logger_name)
    if not logger.hasHandlers():
        logger.addHandler(get_console_handler())
    logger.setLevel(logging.DEBUG)
    logger.propagate = False
    return logger

neurapy_logger = get_logger("neurapy_logger")

def generate_function(function_name, address):
    def wrapped_function(self, *args, **kwargs):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            sock.connect(address)
        except ConnectionError:
            raise ConnectionError("Failed to establish the communication to control box.Please cross check whether the robot is reachable or try reset control from Teach pendant")
        try:
            if OS == 'linux':
                signal.signal(signal.SIGINT,lambda signal, frame: self.stop())
                signal.signal(signal.SIGHUP,lambda signal, frame: self.stop())
            else:
                win32api.SetConsoleCtrlHandler(self.stop, True)
        except Exception as e:
            self.logger.warning("Not attaching signal handlers")
            
        self.logger.info(f"{function_name} called with args {args}, {kwargs}")
        data = {"function": function_name, "args": args, "kwargs": kwargs}
        sock.sendall(json.dumps(data).encode("utf-8"))
        new_data = sock.recv(4096)
        sock.close()
        response = json.loads(new_data.decode("utf-8"))
        if response["error"]:
            self.logger.error(f"{function_name} call with args {args}, {kwargs}, failed with exception {response['error']}")
            raise Exception(response["error"])
        return response["result"]

    wrapped_function.__name__ = function_name + "_method"
    return wrapped_function


class Robot:
    def __init__(self):
        self.__server_address = ("192.168.2.13", 65432)
        self.__functions = [
            "move_joint",
            "move_linear",
            "move_circular",
            "move_composite",
            "record_path",
            "power",
            "zero_g",
            "io",
            "set_tool",
            "gripper",
            "wait",
            "override",
            "pause",
            "unpause",
            "stop",
            "ik_fk",
            "robot_status",
            "program_status",
            "get_point",
            "initialize_attributes",
            "set_mode",
            "motion_status",
            "get_mode",
            "get_zerog_status",
            "rpy_to_quaternion",
            "quaternion_to_rpy",
            "get_tcp_pose",
            "get_reference_frame",
            "get_doc",
            "get_reference_frame_with_offset",
            "set_encoder_offsets",
            "set_opcua_msg",
            "turn_on_jog",
            "turn_off_jog",
            "jog",
            "read_safeio",
            "get_encoder_offsets",
            "get_sim_or_real",
            "move_linear_from_current_position",
            "get_tools",
            "get_encoder_offsets",
            "set_sim_real",
            "reset_error",
            "get_diagnostics",
            "get_errors",
            "get_warnings",
            "wait",
            "wait_for_digital_input",
            "wait_for_digital_input_timer_on_delay",
            "wait_for_digital_input_timer_off_delay",
            "wait_for_analog_input",
            "wait_for_tool_digital_input",
            "wait_for_tool_digital_input_timer_on_delay",
            "wait_for_tool_digital_input_timer_off_delay",
            "wait_for_tool_analog_input",
        ]
        self.logger = neurapy_logger
        
        for function in self.__functions:
            setattr(
                self,
                function,
                MethodType(generate_function(function, self.__server_address), self),
            )

        for key, value in self.initialize_attributes().items():
            setattr(self, key, value)
        self.logger.info(f"Robot initialized with following functions {self.__functions} and robot version {self.version}")
        if self.version != VERSION:
            self.logger.warning("Current client version is not compatiable with the version of the server running on the robot. Some of the functionlities specified in the documentation might not work in the intended way. Please upgrade to the correct version .Client Version : {VERSION},Server Version : {self.version}")
        self.start_diagnostics_monitor()
        
    def help(self, name):
        print(self.get_doc(name))
        
    def notify_diagnostics(self):
        while True:
            diagnostics = self.get_diagnostics()
            if "critical" in diagnostics:
                if diagnostics["critical"]:
                    COUNTER += 1
                    if COUNTER > 1000:
                        self.logger.error(f"{diagnostics}")
                        COUNTER = 0
            time.sleep(MONITOR_CYCLE_TIME)
        
    def start_diagnostics_monitor(self):
        self.monitor = Thread(target=self.notify_diagnostics)
        self.monitor.daemon = True
        self.monitor.start()