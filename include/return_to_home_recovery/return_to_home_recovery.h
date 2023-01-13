#ifndef RETURN_TO_HOME_RECOVERY_H
#define RETURN_TO_HOME_RECOVERY_H

#include <nav_core/recovery_behavior.h>
#include <costmap_2d/costmap_2d_ros.h>

#include <string>


namespace return_to_home_recovery{

	class return_to_home_recovery : public nav_core::RecoveryBehavior{
		
		public:
		//We don't do anything in the constructor, the work happens in initialize()...
		return_to_home_recovery();
		~return_to_home_recovery();

		void initialize(std::string n, 
						tf::TransformListener* tf, 
						costmap_2d::Costmap2DROS global_costmap, 
						costmap_2d::Costmap2DROS local_costmap);


		//This is where the logic is.
		void runBehavior();

		private:
		ros::NodeHandle mNodeHandle;
		costmap_2d::Costmap2DROS *globalMap;
		costmap_2d::Costmap2DROS *localMap;
		std::string name;
		tf::TransformListener *tf;
	};

}

#endif
