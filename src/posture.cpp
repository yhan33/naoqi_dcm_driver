/*
 * Copyright 2016 SoftBank Robotics Europe
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

// ROS Headers
#include <ros/ros.h>

#include "naoqi_dcm_driver/posture.hpp"
#include "naoqi_dcm_driver/tools.hpp"

Posture::Posture(const qi::SessionPtr& session)
{
  try
  {
    posture_proxy_ = session->service("ALRobotPosture");
  }
  catch (const std::exception& e)
  {
    ROS_ERROR("Posture: Failed to connect to Posture Proxy!\n\tTrace: %s", e.what());
  }
}

void Posture::StandInit()
{
  try
  {
    ros::Duration(1.0).sleep();
    ROS_INFO_STREAM("Going to standInit ...");
    posture_proxy_.call<void>("goToPosture","standinit", 0.5);
    ros::Duration(3.0).sleep();
  }
  catch (const std::exception& e)
  {
    ROS_WARN("Posture: Failed to stand init the robot!\n\tTrace: %s", e.what());
  }
}

