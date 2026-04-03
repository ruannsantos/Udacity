#!/bin/sh

# Launch Gazebo + Robot
xterm -e "cd $(pwd)/../../; source devel/setup.bash; roslaunch my_robot world.launch" &
sleep 7

# Launch AMCL + Navigation
xterm -e "cd $(pwd)/../../; source devel/setup.bash; roslaunch my_robot amcl.launch" &
sleep 5

# Launch RViz
xterm -e "cd $(pwd)/../../; source devel/setup.bash; rosrun rviz rviz -d $(rospack find my_robot)/rviz/navigation.rviz" &
sleep 3

# Launch Teleop
xterm -e "cd $(pwd)/../../; source devel/setup.bash; rosrun teleop_twist_keyboard teleop_twist_keyboard.py"
