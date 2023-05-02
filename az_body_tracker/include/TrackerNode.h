#ifndef TRACKER_NODE_H
#define TRACKER_NODE_H
#include <k4a/k4a.h>
#include <k4abt.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

struct InputSettings
{
    k4a_depth_mode_t DepthCameraMode = K4A_DEPTH_MODE_WFOV_UNBINNED;
    k4abt_tracker_processing_mode_t processingMode = K4ABT_TRACKER_PROCESSING_MODE_GPU_CUDA;
    k4a_fps_t cameraFPS = K4A_FRAMES_PER_SECOND_15;
    k4a_color_resolution_t colorResolution = K4A_COLOR_RESOLUTION_720P;
};

class TrackerNode
{
public:
  ros::NodeHandle nh;
  ros::Publisher lengthPub;
  TrackerNode(ros::NodeHandle& _nh);
  void showInfo(InputSettings& inputSettings);
private:
  uint16_t count_=0; 
};
#endif // TRACKER_NODE_H