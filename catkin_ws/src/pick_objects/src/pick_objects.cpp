#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  // Tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // Set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // ========== GOAL 1: Pickup Zone ==========
  goal.target_pose.pose.position.x = 2.0;
  goal.target_pose.pose.position.y = -4.0;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending pickup zone goal");
  ac.sendGoal(goal);

  // Wait for the result
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached pickup zone!");
  }
  else{
    ROS_INFO("Failed to reach pickup zone");
    return 1;
  }

  // Wait 5 seconds to simulate pickup
  ROS_INFO("Picking up object... waiting 5 seconds");
  ros::Duration(5.0).sleep();

  // ========== GOAL 2: Drop-off Zone ==========
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = -2.0;
  goal.target_pose.pose.position.y = -7.0;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending drop-off zone goal");
  ac.sendGoal(goal);

  // Wait for the result
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached drop-off zone!");
  }
  else{
    ROS_INFO("Failed to reach drop-off zone");
    return 1;
  }

  ROS_INFO("Object delivered successfully!");

  return 0;
}
