#ifndef DETECT_CV_H
#define DETECT_CV_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <yaml-cpp/yaml.h>
#include <iostream>

class DetectCV
{
public:
    DetectCV();
    ~DetectCV();

private:
    ros::NodeHandle nh_;
    ros::NodeHandle nh_private_;

    image_transport::ImageTransport it_;
    image_transport::Subscriber sub_image_;
    image_transport::Publisher pub_image_;
    ros::Publisher pub_detect_result_;
};

#endif // DETECT_CV_H