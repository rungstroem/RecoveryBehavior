cmake_minimum_required(VERSION 2.8.3)
project(return_to_home_recovery)

find_package(catkin REQUIRED
        COMPONENTS
            cmake_modules
            roscpp
            tf
            costmap_2d
            nav_core
            pluginlib
            base_local_planner
            message_generation
            message_runtime
            std_msgs
        )


include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)


# add_message_files(
#   FILES
# )

generate_messages(
   DEPENDENCIES
   geometry_msgs   
   std_msgs
 )
 
catkin_package(
    CATKIN_DEPENDS
        roscpp
        pluginlib
        message_generation
        message_runtime
        std_msgs
)

add_library(${PROJECT_NAME} src/return_to_home_recovery.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_generate_messages_cpp ${return_to_home_recovery_EXPORTED_TARGETS})


install(TARGETS ${PROJECT_NAME}
       LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
       )

install(FILES return_to_home_recovery_plugin.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#including c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "-std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "-std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
