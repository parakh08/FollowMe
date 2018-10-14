#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <stdio.h>
#include <cmath>

ros::Publisher pub;
void chatterCallBack(const nav_msgs::Odometry::ConstPtr& msg)
{
	geometry_msgs::Twist vel;	
	while((msg->pose.pose.position.x)>0.001)
	{
		vel.linear.x=0.08*(-(msg->pose.pose.position.x));
	}
	if((msg->pose.pose.position.y)<0.32)
	{	
	    vel.linear.y = 0.01;
	    vel.linear.x=0;
	    vel.linear.z=0;
	    vel.angular.z=0;
		pub.publish(vel);
	}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "line");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<nav_msgs::Odometry>("/bebop/odom",100,chatterCallBack);
  pub = n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 100);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }  
  return 0;
}