#include "detect_cv.h"

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "yolov5");
    DetectCV node;
    ros::spin();
    return 0;
}