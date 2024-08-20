from neurapy.robot import Robot
robot = Robot()
robot.turn_on_jog(
    jog_velocity=[0.2, 0.2, 0.2, 0.2, 0.2, 0.2], 
    jog_type='Joint'
)
robot.jog(set_jogging_external_flag = 1)
i = 0
while(i < 500):
    robot.jog(set_jogging_external_flag = 1)
    i+=1
robot.turn_off_jog()