#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Wait for subscribers
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
      return 0;
    ROS_WARN_ONCE("Waiting for subscriber to visualization_marker");
    sleep(1);
  }

  visualization_msgs::Marker marker;
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = visualization_msgs::Marker::CUBE;
  marker.scale.x = 0.3;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();

  // Show marker at pickup zone
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = 2.0;
  marker.pose.position.y = -4.0;
  marker.pose.orientation.w = 1.0;
  marker_pub.publish(marker);
  ROS_INFO("Marker at pickup zone");
  ros::Duration(5.0).sleep();

  // Hide marker (simulate pickup)
  marker.action = visualization_msgs::Marker::DELETE;
  marker_pub.publish(marker);
  ROS_INFO("Marker hidden - simulating pickup");
  ros::Duration(5.0).sleep();

  // Show marker at drop-off zone
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = -2.0;
  marker.pose.position.y = -7.0;
  marker.pose.orientation.w = 1.0;
  marker_pub.publish(marker);
  ROS_INFO("Marker at drop-off zone");
  ros::Duration(5.0).sleep();

  return 0;
}
