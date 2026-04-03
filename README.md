# Project 4 - Map My World (RTAB-Map)

## Overview
This project implements RTAB-Map (Real-Time Appearance-Based Mapping) on a simulated robot to create 2D and 3D maps of a Gazebo environment. The robot uses an RGB-D camera and a Hokuyo lidar sensor to perform SLAM (Simultaneous Localization and Mapping).

## Results
- **20 global loop closures** and **253 local loop closures** detected
- 411 poses captured during mapping
- Occupancy grid and 3D point cloud maps generated successfully

## Project Structure
```
Project4/
├── my_robot/
│   ├── config/                  # Navigation config files
│   ├── launch/
│   │   ├── mapping.launch       # RTAB-Map mapping mode
│   │   ├── localization.launch  # RTAB-Map localization mode
│   │   ├── teleop.launch        # Teleoperation
│   │   ├── world.launch         # Gazebo world + robot
│   │   └── robot_description.launch
│   ├── meshes/
│   │   └── hokuyo.dae           # Lidar mesh
│   ├── urdf/
│   │   ├── my_robot.xacro       # Robot model
│   │   └── my_robot.gazebo      # Gazebo plugins (RGB-D camera, lidar, diff drive)
│   ├── world/
│   │   └── myworld.world        # Gazebo world file
│   ├── CMakeLists.txt
│   └── package.xml
├── screenshots/                 # Screenshots of mapping results
├── rtabmap.db                   # RTAB-Map database file
├── my_robot.rviz                # RViz configuration file
└── README.md
```

## RViz Configuration
The RViz configuration file (`my_robot.rviz`) is located in the root of the Project4 folder. Load it in RViz via File → Open Config.

## How to Run

### 1. Launch the world
```bash
cd ~/catkin_ws/
source devel/setup.bash
roslaunch my_robot world.launch
```

### 2. Launch RTAB-Map (Mapping mode)
```bash
roslaunch my_robot mapping.launch
```

### 3. Launch Teleop
```bash
roslaunch my_robot teleop.launch
```

Drive the robot around the environment to generate the map. The rtabmap.db file will be saved in ~/.ros/.

### 4. View the database
```bash
rtabmap-databaseViewer ~/.ros/rtabmap.db
```

## Download the RTAB-Map Database
The `rtabmap.db` file is too large for GitHub. Download it from Google Drive:

**[Download rtabmap.db](https://drive.google.com/drive/folders/1et_BawkTyAJv1oLXu0QkgK3NUZs_LXBM?usp=sharing)**

After downloading, place it in the project root (`Project4/`) or in `~/.ros/` to use with the database viewer:
```bash
rtabmap-databaseViewer ~/Downloads/rtabmap.db
```

## Author
Ruan Santos - Udacity Robotics Software Engineer Nanodegree
