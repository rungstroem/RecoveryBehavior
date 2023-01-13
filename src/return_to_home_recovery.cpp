#include <return_to_home_recovery/return_to_home_recovery.h>
#include <pluginlib/class_list_macros.h>
#include <tf/transform_datatypes.h>

PLUGINLIB_DECLARE_CLASS(return_to_home_recovery, return_to_home_recovery, return_to_home_recovery::return_to_home_recovery, nav_core::RecoveryBehavior)

namespace return_to_home_recovery{

	return_to_home_recovery::return_to_home_recovery() : 
		globalMap(NULL), localMap(NULL), tf(NULL) {
		//Do nothing for now
	}
	return_to_home_recovery::~return_to_home_recovery(){
		//Do nothing for now
	}

	void return_to_home_recovery::initialize(std::string n, tf::TransformListener* tf, 
											costmap_2d::Costmap2DROS* global_costmap,
											costmap_2d::Costmap2DROS* local_costmap){
		name = n;
		tf = tf;
		localMap = local_costmap;
		globalMap = global_costmap;
		ros::NodeHandle private_nh("~/", name);

	}

	void return_to_home_recovery::runBehavior(){
		ROS_INFO("-------- All recovery behaviors failed, returning to home -----------");
	}

}
