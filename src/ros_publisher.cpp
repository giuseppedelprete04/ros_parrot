#include "../include/ros_msg/class.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "ros_msg_publisher");
	ROS_PUB pub;
	ros::Rate rate(1);
	while(ros::ok()) {
		pub.topic_cb();
		rate.sleep();
		ros::spinOnce();
		printf("\n");
		}
	return 0;
}
