from neurapy.robot import Robot
r = Robot()
linear_property = {
 "speed": 0.25,
 "acceleration": 0.1,
 "blend_radius": 0.005,
 "target_pose": [
 [
 0.3287228886,
 -0.1903355329,
 0.4220780352,
 0.08535207028439847,
 -2.797181496822229,
 2.4713321627410485
 ],
 [
 0.2093363791501374,
 -0.31711250784165884,
 0.422149168855134,
 -3.0565555095672607,
 -0.3447442352771759,
 -1.1323236227035522
 ],
 ],
 "current_joint_angles":r.robot_status("jointAngles")
 }
r.move_linear_from_current_position(**linear_property)
r.stop()