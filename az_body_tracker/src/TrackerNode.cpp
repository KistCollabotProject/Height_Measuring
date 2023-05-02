#include "TrackerNode.h"
#include <std_msgs/Float32.h>

TrackerNode::TrackerNode(ros::NodeHandle& _nh)
{
	nh=_nh;
	lengthPub = nh.advertise<std_msgs::Float32>("length",1000);
	
}

void TrackerNode::showInfo(InputSettings& inputSettings){
	if(inputSettings.DepthCameraMode == K4A_DEPTH_MODE_NFOV_UNBINNED) {
		ROS_INFO("K4A depth_mode : NFOV_UNBINNED");
		ROS_INFO("K4A camera_FPS : 30");}
		// RCLCPP_INFO(this->get_logger(), "K4A depth_mode : NFOV_UNBINNED");
		// RCLCPP_INFO(this->get_logger(), "K4A camera_FPS : 30");}
	else if (inputSettings.DepthCameraMode == K4A_DEPTH_MODE_WFOV_2X2BINNED){
		ROS_INFO("K4A depth_mode : WFOV_2X2BINNED");
		ROS_INFO("K4A camera_FPS : 30");}

		// RCLCPP_INFO(this->get_logger(), "K4A depth_mode : WFOV_2X2BINNED");
		// RCLCPP_INFO(this->get_logger(), "K4A camera_FPS : 30");}
	else if(inputSettings.DepthCameraMode == K4A_DEPTH_MODE_WFOV_UNBINNED){
		ROS_INFO("K4A depth_mode : WFOV_UNBINNED");
		ROS_INFO("K4A camera_FPS : 15");}
		// RCLCPP_INFO(this->get_logger(), "K4A depth_mode : WFOV_UNBINNED");
		// RCLCPP_INFO(this->get_logger(), "K4A camera_FPS : 15");}
	else ROS_INFO("failed to read DepthMode.");
}

	// k4a_result_t startTracker();
	// k4a_result_t startImu();

	// void stopTracker();
	// void stopImu();

	// // Get camera calibration information for the depth camera
	// void getDepthCameraInfo(sensor_msgs::msg::CameraInfo& camera_info);

	// void getRgbCameraInfo(sensor_msgs::msg::CameraInfo& camera_info);

	// k4a_result_t getDepthFrame(const k4a::capture& capture, std::shared_ptr<sensor_msgs::msg::Image>& depth_frame, bool rectified);

	// k4a_result_t getPointCloud(const k4a::capture& capture, std::shared_ptr<sensor_msgs::msg::PointCloud2>& point_cloud);

	// k4a_result_t getRgbPointCloudInRgbFrame(const k4a::capture& capture, std::shared_ptr<sensor_msgs::msg::PointCloud2>& point_cloud);
	// k4a_result_t getRgbPointCloudInDepthFrame(const k4a::capture& capture, std::shared_ptr<sensor_msgs::msg::PointCloud2>& point_cloud);

