# Project 5 - Home Service Robot

## Overview
This project programs a home service robot that autonomously navigates to pick up and deliver virtual objects. The robot uses AMCL for localization, move_base for navigation, and RViz markers to visualize the virtual objects.

## Packages Used
- **my_robot**: Contains the robot model (URDF/Xacro), Gazebo world, sensor plugins (RGB-D camera, Hokuyo lidar, differential drive), navigation config files, and launch files.
- **pick_objects**: C++ node that sends navigation goals (pickup and drop-off zones) to the move_base action server.
- **add_markers**: C++ nodes that publish/hide virtual markers in RViz to simulate object pickup and delivery.
- **gmapping**: Used for SLAM to generate the 2D occupancy grid map.
- **amcl**: Adaptive Monte Carlo Localization for robot pose estimation.
- **move_base**: Navigation stack for path planning and obstacle avoidance.
- **teleop_twist_keyboard**: Manual robot control via keyboard.

## Shell Scripts
- **test_slam.sh**: Launches Gazebo, SLAM (gmapping), RViz, and teleop for manual mapping.
- **test_navigation.sh**: Launches Gazebo, AMCL, move_base, RViz, and teleop for manual navigation testing.
- **pick_objects.sh**: Launches navigation stack and sends the robot to pickup and drop-off zones.
- **add_markers.sh**: Launches navigation stack and displays virtual markers at pickup and drop-off zones.
- **home_service.sh**: Full home service - robot navigates to pickup zone, marker disappears, robot navigates to drop-off zone, marker reappears.

## How to Run

### Build
```bash
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
```

### Run Home Service
```bash
cd ~/catkin_ws/src/scripts/
./home_service.sh
```

## RViz Configuration
The RViz config file is located at `my_robot/rviz/navigation.rviz`.

## Author
Ruan Santos - Udacity Robotics Software Engineer Nanodegree
