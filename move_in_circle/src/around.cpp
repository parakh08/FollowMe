#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;


float r=0.5;
float theta=0;
float v= 0.01;
int k=60;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "around");
  ros::NodeHandle n;
  ros::Publisher pub;
  pub = n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 100);
  ros::Rate loop_rate(10);
  geometry_msgs::Twist vel;
  vel.linear.z=0;
  vel.angular.z=0;
  while (ros::ok())
  {  	
  	float a=v*cos(theta);
  	float b=v*sin(theta);
  	vel.linear.x=-a;
  	vel.linear.y=-b;
  	theta+=(v*0.1/r);
  	//cout << a,b << endl;
  	//cout << theta<< endl;
  	pub.publish(vel);
    ros::spinOnce();
    loop_rate.sleep();
  }  
  return 0;
}