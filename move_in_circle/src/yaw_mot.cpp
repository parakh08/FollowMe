#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <stdio.h>
#include <cmath>
//#include <stdlib.h>
//using namespace std;


int r=0.5;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "yaw_mot");
  ros::NodeHandle n;
  ros::Publisher pub;
  pub = n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 100);
  ros::Rate loop_rate(10);
  geometry_msgs::Twist vel;
  vel.angular.z=0.0;
  while (ros::ok())
  {    	
  	vel.linear.x=-0.02;
  	vel.linear.y=0;
  	vel.linear.z=0;
  	vel.angular.z=0.064;
  	pub.publish(vel);
    ros::spinOnce();
    loop_rate.sleep();
  }  
  return 0;
}