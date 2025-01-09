#include "detect_cv.h"

DetectCV::DetectCV() : it_(nh_), nh_private_("~")
{
    std::string config_path;
    nh_private_.param<std::string>("config_path", config_path, "");
    YAML::Node root = YAML::LoadFile(config_path);
    YAML::Node yolov5_config = root["detect"];
    std::string root_path = yolov5_config["root_path"].as<std::string>();
    std::string engine_path = root_path + '/' + yolov5_config["engine_file"].as<std::string>();
    std::string label_path = root_path + '/' + yolov5_config["label_file"].as<std::string>();

    sub_image_ = it_.subscribe("/camera/image", 1, &DetectCV::imageCallback, this);
    pub_image_ = it_.advertise("camera/detect_result_image", 1);
}

void DetectCV::imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    sensor_msgs::ImagePtr image_pub = cv_bridge::CvImage(std_msgs::Header(), "bgr8", cv_ptr->image).toImageMsg();
    pub_image_.publish(image_pub);
}

DetectCV::~DetectCV()
{

}