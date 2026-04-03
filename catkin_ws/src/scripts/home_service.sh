#!/bin/sh

# Launch Gazebo + Robot
xterm -e "cd $(pwd)/../../; source devel/setup.bash; roslaunch my_robot world.launch" &
sleep 7

# Launch AMCL + Navigation
xterm -e "cd $(pwd)/../../; source devel/setup.bash; roslaunch my_robot amcl.launch" &
sleep 5

# Launch RViz
xterm -e "cd $(pwd)/../../; source devel/setup.bash; rosrun rviz rviz -d $(rospack find my_robot)/rviz/navigation.rviz" &
sleep 5

# Launch add_markers_home_service node
xterm -e "cd $(pwd)/../../; source devel/setup.bash; rosrun add_markers add_markers_home_service" &
sleep 3

# Launch pick_objects node
xterm -e "cd $(pwd)/../../; source devel/setup.bash; rosrun pick_objects pick_objects"
