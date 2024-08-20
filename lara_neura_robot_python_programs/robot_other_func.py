from time import sleep
from neurapy.robot import Robot
r = Robot()
r.power('on')
#query robot status
print(r.motion_status())
#print warnings
warnings = r.get_warnings()
print(warnings)
#print errors
errors = r.get_errors()
print(errors)
#getting stored point in robot
point = r.get_point("P1")
print(point)
#power off
sleep(2)
#get set io
io_get = r.io("get", io_name = "DO_1") 
io_set = r.io("set", io_name = "DO_2", target_value = True)
tdo_set = r.io("set",io_name="TOD_Array",target_value=[0.0,1.0,0.0])
tdo_get = r.io("get",io_name="TDO_1")
#gripper control
r.gripper('on')
sleep(2)
r.gripper('off')
#changing tool (notify components)
r.set_tool(tool_name="some tool")
print(io_get,io_set)
#status
c = r.robot_status('jointAngles')
"""
 "cartesianPosition" - returns Robot Pose in xyzwxyz format
(rotation in quaternion)
 "jointAngles" - returns Joint Positions
 "jointTorques" - returns Joint Torque
 "commandedjointAngle" - returns last commanded joint angle
 "taskStateTwist" - returns taskStateTwist linear
 "loadSideEncValue" - returns Primary Encoder Value
 "motorSideEncValue" - reutrns Secondary Encoder Value
"""
#zero g
r.zero_g("on")
sleep(1)
r.zero_g("off")
#forward inverse kinematics
target_position = r.ik_fk("fk", target_angle = 
[0.2,0.2,0.2,0.2,0.2,0.2])
target_angle = r.ik_fk("ik", target_pose = [0.140448, -0.134195, 
1.197456, 3.1396, -0.589, -1.025],current_joint = [-1.55, -0.69, 0.06, 
1.67, -0.02, -1.57, 0.11])
#changing modes of operation
r.set_mode("Teach")
sleep(1)
r.set_mode("SemiAutomatic")
sleep(1)
r.set_mode("Automatic")
#reset error is used to reset error on real robot
r.reset_error()
#list available tools
tools_data = r.get_tools()
#getting tcp pose
tcp_pose = r.get_tcp_pose()
print(tcp_pose)
#query current state sim or re
context = r.get_sim_or_real()
print(context)
r.power('off')