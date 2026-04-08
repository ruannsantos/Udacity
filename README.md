# Project 4 - Map My World (RTAB-Map)

## Overview
This project implements RTAB-Map (Real-Time Appearance-Based Mapping) on a simulated robot to create 2D and 3D maps of a Gazebo environment. The robot uses an RGB-D camera and a Hokuyo lidar sensor to perform SLAM (Simultaneous Localization and Mapping).

## Results
- **28 global loop closures** and **197 local loop closures** detected
- 322 poses captured during mapping
- Occupancy grid and 3D point cloud maps generated successfully

## Download the RTAB-Map Database
The `rtabmap.db` file is too large for GitHub. Download it from Google Drive:

**[Download rtabmap.db](https://drive.google.com/drive/folders/1et_BawkTyAJv1oLXu0QkgK3NUZs_LXBM?usp=sharing)**

After downloading, place it in `~/.ros/` or in the project root to use with the database viewer:
```bash
rtabmap-databaseViewer ~/Downloads/rtabmap.db
```

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
└── README.md
```

## Key Parameters (mapping.launch)
| Parameter | Value | Description |
|-----------|-------|-------------|
| Reg/Strategy | 0 | Visual registration |
| Reg/Force3DoF | true | 2D SLAM mode |
| RGBD/OptimizeFromGraphEnd | true | Optimize from last node to reduce drift |
| RGBD/AngularUpdate | 0.05 | Angular threshold for new node creation |
| RGBD/LinearUpdate | 0.05 | Linear threshold for new node creation |
| Kp/DetectorStrategy | 0 | SURF feature detector |
| Kp/MaxFeatures | 400 | Max visual words per image |
| Vis/MinInliers | 15 | Min inliers for loop closure |

## How to Run

### Terminal 1 — Launch the world
```bash
cd ~/catkin_ws/ && source devel/setup.bash && roslaunch my_robot world.launch
```

### Terminal 2 — Launch RTAB-Map (Mapping mode)
```bash
cd ~/catkin_ws/ && source devel/setup.bash && roslaunch my_robot mapping.launch
```

### Terminal 3 — Launch RViz
```bash
cd ~/catkin_ws/ && source devel/setup.bash && rviz
```

### Terminal 4 — Launch Teleop
```bash
cd ~/catkin_ws/ && source devel/setup.bash && roslaunch my_robot teleop.launch
```

Drive the robot slowly around the environment to generate the map. The `rtabmap.db` file will be saved in `~/.ros/`.

### View the database
```bash
rtabmap-databaseViewer ~/.ros/rtabmap.db
```

## Author
Ruan Santos — Udacity Robotics Software Engineer Nanodegree
