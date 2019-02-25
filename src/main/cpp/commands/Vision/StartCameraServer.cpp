#include "commands/Vision/StartCameraServer.h"
#include "Robot.h"

StartCameraServer::StartCameraServer()
{
	Requires(Robot::vision.get());
}

void StartCameraServer::Initialize()
{
}

void StartCameraServer::Execute()
{
//	std::thread visionThread(std::bind(&Robot::vision->MultiVisionThread(),v));
//	visionThread.detach();
	Robot::vision->MultiCamServer();
}

bool StartCameraServer::IsFinished()
{
	return true;
}

void StartCameraServer::End()
{
}

void StartCameraServer::Interrupted()
{
	End();
}

