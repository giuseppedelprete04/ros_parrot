#include "ros/ros.h"
#include "ros_msg/demo.h"
#include <iostream>
#include <cstdlib>

class ROS_PUB {
	public:
		ROS_PUB();
		void topic_cb();
	private:
		ros::NodeHandle nh;
		ros::Publisher topic_pub;
};

ROS_PUB::ROS_PUB() {
	topic_pub = nh.advertise<ros_msg::demo>("testo",10);
}

void ROS_PUB::topic_cb() {
	        ros_msg::demo msg;
		std::cout <<"Inserisci messaggio: ";
		std::cin>>msg.testo;
		ROS_INFO("%s\n",msg.testo.c_str());
		topic_pub.publish(msg);
}


class ROS_SUB {
	public:
		ROS_SUB();
		void topic_cb (ros_msg::demoConstPtr data);

	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
};

ROS_SUB::ROS_SUB() {
	_topic_sub = _nh.subscribe ("/testo", 0, 			&ROS_SUB::topic_cb, this);
}

void ROS_SUB::topic_cb( ros_msg::demoConstPtr data ) {
	ROS_INFO( "Listener: %s", data->testo.c_str() );
}
