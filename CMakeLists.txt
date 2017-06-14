cmake_minimum_required(VERSION 2.8.3)
project(giskard_ros_utils)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roscpp roslib)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp roslib
)

include_directories(include ${catkin_INCLUDE_DIRS})

####################
## FIXME: Testing ##
####################
