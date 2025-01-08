cmake_minimum_required(VERSION 3.0.2)
project(yolov5)

# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

find_package(catkin REQUIRED COMPONENTS
    cv_bridge
    message_generation
    pcl_conversions
    pcl_ros
    roscpp
    roslaunch
    rospy
    sensor_msgs
    std_msgs
    std_srvs
)

catkin_package()

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(yolov5 
    src/main.cpp
    src/detect_cv.cpp
)

target_link_libraries(yolov5 
    ${catkin_LIBRARIES}
)

