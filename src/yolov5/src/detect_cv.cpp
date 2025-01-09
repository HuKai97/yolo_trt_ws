#include "detect_cv.h"

DetectCV::DetectCV() : it_(nh_), nh_private_("~")
{
    std::string config_path;
    nh_private_.param<std::string>("config_path", config_path, "");
    YAML::Node root = YAML::LoadFile(config_path);
    YAML::Node yolov5_config = root["yolov5"];
    std::string root_path = yolov5_config["root_path"].as<std::string>();
    std::string engine_path = root_path + '/' + yolov5_config["engine_file"].as<std::string>();
    std::string label_path = root_path + '/' + yolov5_config["label_file"].as<std::string>();

}


DetectCV::~DetectCV()
{

}