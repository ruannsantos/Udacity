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
Plugin Description

The project includes a Gazebo WorldPlugin implemented in C++.
This plugin is compiled as a shared library (.so) and loaded inside the world file.

Its purpose is to print a custom message in the terminal when Gazebo starts.

Build Instructions

From the root of the project, run:

mkdir build
cd build
cmake ..
make

After compilation, the shared library will be generated inside the build folder.

Running the Project

Before launching Gazebo, export the plugin path:

export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$HOME/udacity/home/project1/build

Then run the world:

gazebo $HOME/udacity/home/project1/world/my_world.world

If everything is configured correctly, Gazebo will open the custom world and print the plugin message in the terminal.

Features
Custom Gazebo world
Custom model creation
Simple rover built in the Gazebo Model Editor
C++ world plugin integration
Project organized using CMake
Learning Outcomes

Through this project, I practiced:

Creating and editing worlds in Gazebo
Creating robot models using the Model Editor
Writing and compiling Gazebo plugins in C++
Organizing a robotics simulation project
Using Git and GitHub for version control
Author

Ruan Santos
GitHub: ruannsantos
