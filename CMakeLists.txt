cmake_minimum_required(VERSION 2.8.3)
project(giskard_ros_utils)

find_package(catkin REQUIRED COMPONENTS roscpp)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
)

include_directories(include ${catkin_INCLUDE_DIRS})

####################
## FIXME: Testing ##
####################
