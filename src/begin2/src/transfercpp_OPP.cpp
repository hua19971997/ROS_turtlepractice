#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int64.h"
#include <ros/package.h>
#include <sstream>

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    sub = n.subscribe("/key_pressed", 1000, &SubscribeAndPublish::callback,this);
  }

  void callback(const std_msgs::Int64::ConstPtr& keyvalue){
  //ROS_INFO("number, %d",keyvalue->data);
  int pose = keyvalue->data;
  ros::Rate loop_rate(10);
 int count = 0;
  while (ros::ok())
  {
   geometry_msgs::Twist msg;
//10 enter: move slowly
    if(pose == 10){
      msg.linear.x = 0.5;
      msg.linear.y = 0;
      msg.linear.z = 0;

      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
   }
 //82 up: move quickly
    if(pose == 82){
      msg.linear.x = 1;
      msg.linear.y = 0;
      msg.linear.z = 0;

      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
   }

 //81 left: stop and change angular
    if(pose == 81){
      msg.linear.x = 0;
      msg.linear.y = 0;
      msg.linear.z = 0;

      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 1;
   }

   //32 space: stop
   if(pose == 32){
       msg.linear.x = 0;
      msg.linear.y = 0;
      msg.linear.z = 0;

      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
   }

    vel_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}

private:
  ros::NodeHandle n;
  ros::Publisher vel_pub;
  ros::Subscriber sub;
};


int main(int argc, char **argv){
      ros::init(argc, argv, "transfer");
      SubscribeAndPublish aa;
      ros::spin();
      return 0;
}

