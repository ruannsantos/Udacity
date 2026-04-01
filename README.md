# Build My World - Udacity Robotics Project

This project was developed as part of the **Udacity Robotics Software Engineer Nanodegree**.

The goal of this project is to create a custom simulation world in **Gazebo**, including custom models and a world plugin written in **C++**. The simulation demonstrates environment design, model creation, plugin integration, and basic project organization for robotics simulation.

## Project Overview

In this project, I created a custom Gazebo world containing:

- A custom world file
- Custom models created in the Gazebo editor
- A simple rover model
- A C++ world plugin that prints a message in the terminal when the world is launched

When the world is opened in Gazebo, the plugin displays the following message:

`Hello World, This is Ruan first project`

## Technologies Used

- Ubuntu 22.04
- Gazebo
- C++
- CMake
- Git and GitHub

## Project Structure

```bash
project1/
├── build/
├── model/
├── script/
│   └── helloworld.cpp
├── world/
│   └── my_world.world
├── CMakeLists.txt
└── README.md
