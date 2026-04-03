#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <cmath>

// Pickup and drop-off positions
double pickup_x = 2.0, pickup_y = -4.0;
double dropoff_x = -2.0, dropoff_y = -7.0;
double tolerance = 0.3;

// States
enum State { GOING_TO_PICKUP, PICKING_UP, GOING_TO_DROPOFF, DELIVERED };
State current_state = GOING_TO_PICKUP;

ros::Publisher marker_pub;

void publish_marker(double x, double y, int action)
{
  visualization_msgs::Marker marker;
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = visualization_msgs::Marker::CUBE;
  marker.action = action;
  marker.pose.position.x = x;
  marker.pose.position.y = y;
  marker.pose.position.z = 0.15;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 0.3;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();
  marker_pub.publish(marker);
}

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  double robot_x = msg->pose.pose.position.x;
  double robot_y = msg->pose.pose.position.y;

  double dist_to_pickup = sqrt(pow(robot_x - pickup_x, 2) + pow(robot_y - pickup_y, 2));
  double dist_to_dropoff = sqrt(pow(robot_x - dropoff_x, 2) + pow(robot_y - dropoff_y, 2));

  switch(current_state)
  {
    case GOING_TO_PICKUP:
      if(dist_to_pickup < tolerance)
      {
        ROS_INFO("Reached pickup zone! Picking up object...");
        // Hide marker
        publish_marker(pickup_x, pickup_y, visualization_msgs::Marker::DELETE);
        current_state = PICKING_UP;
        ros::Duration(5.0).sleep();
        ROS_INFO("Object picked up! Heading to drop-off zone...");
        current_state = GOING_TO_DROPOFF;
      }
      break;

    case GOING_TO_DROPOFF:
      if(dist_to_dropoff < tolerance)
      {
        ROS_INFO("Reached drop-off zone! Delivering object...");
        // Show marker at drop-off
        publish_marker(dropoff_x, dropoff_y, visualization_msgs::Marker::ADD);
        current_state = DELIVERED;
        ROS_INFO("Object delivered successfully!");
      }
      break;

    default:
      break;
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;

  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("/odom", 10, odom_callback);

  // Wait for subscribers
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
      return 0;
    ROS_WARN_ONCE("Waiting for subscriber to visualization_marker");
    sleep(1);
  }

  // Show marker at pickup zone
  ROS_INFO("Showing marker at pickup zone");
  publish_marker(pickup_x, pickup_y, visualization_msgs::Marker::ADD);

  ros::spin();

  return 0;
}
