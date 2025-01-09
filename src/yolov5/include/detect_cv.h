#ifndef DETECT_CV_H
#define DETECT_CV_H

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <yaml-cpp/yaml.h>
#include <opencv2/opencv.hpp>
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

    void imageCallback(const sensor_msgs::ImageConstPtr& msg);
};

#endif // DETECT_CV_H