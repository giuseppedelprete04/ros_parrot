
#include "../include/ros_msg/class.h"

int main( int argc, char** argv ) {
	ros::init(argc,argv,"ros_msg_subscriber");
	ROS_SUB rs;
	ros::spin();
	return 0;
}
