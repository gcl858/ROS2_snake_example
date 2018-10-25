#command Test pub sub
#terminal 1--> pub
. '/home/op/ros2_overlay_ws/src/install/
ros2 topic pub /chatter std_msgs/Strin"data: Hello world"

#terminal 2--> syb
. '/home/op/ros2_overlay_ws/src/install/
ros2 topic echo /chatter



