#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class Vision : public frc::Subsystem
{
	private:
		//cs::AxisCamera cam1;
		//cs::AxisCamera cam2;
		//cs::VideoSink server;
		//cs::CvSink cvsink1;
		//cs::CvSink cvsink2;
		//int isCam1 = 1;
	public:
		Vision();
		void InitDefaultCommand() override;
		void MultiCamServer();
		void StartThread();
		void ToggleCamera();
};