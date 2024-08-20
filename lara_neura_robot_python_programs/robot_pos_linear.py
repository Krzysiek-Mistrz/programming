from neurapy.robot import Robot
r = Robot()
linear_property = {
 "speed": 0.008,
 "acceleration": 1.0,
 "blend_radius": 0.005,
 "target_pose": [
    [
            2.5995838308821924,
            0.24962416292345468,
            -1.8654403327490414,
            0.04503286318691005,
            -1.1740563715454926,
            0.10337461241185522
    ],
    [
            2.1372059994827075,
            0.24939733788589463,
            -1.8651270179353125,
            0.044771940725327274,
            -1.173860821592129,
            0.10315646291502645
    ]
 ],
 "current_joint_angles":r.robot_status("jointAngles"),
 "weaving":True,
 "pattern": 1,
 "amplitude": 0.006,
 "amplitude_left": 0.0,
 "amplitude_right": 0.0,
 "frequency": 1.5,
 "dwell_time_left": 0.0,
 "dwell_time_right": 0.0,
 "elevation": 0.0,
 "azimuth": 0.0
 }
r.move_linear(**linear_property)
r.stop()