/*
 * Copyright (C) 2017 Georg Bartels <georg.bartels@cs.uni-bremen.de>
 * 
 * This file is part of giskard.
 * 
 * giskard is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef GISKARD_ROS_UTILS_GISKARD_ROS_UTILS_HPP
#define GISKARD_ROS_UTILS_GISKARD_ROS_UTILS_HPP

#include <ros/ros.h>
#include <ros/package.h>
#include <iostream>
#include <fstream>

namespace giskard_ros_utils
{
  template<class T>
  inline T readParam(const ros::NodeHandle& nh, const std::string& name)
  {
    T param;
    if(!nh.getParam(name, param))
      throw std::runtime_error("Could not find parameter '" + name +
          "' in namespace '" + nh.getNamespace() + "'.");
    return param;
  }

  inline std::string read_file(const std::string& filename)
  {
    std::ifstream in(filename);
    if(in.is_open())
    {
      std::string file_content, line;
      while ( std::getline(in, line) )
        file_content += line + "\n";

      return file_content;
    }
    else
      throw std::runtime_error("Could not open file '" + filename + "'.");
  }

  inline std::string read_ros_file(const std::string& filename, const std::string& package_name)
  {
    std::string package_path = ros::package::getPath(package_name);
    return read_file(package_path + "/" + filename);
  }

  inline std::vector<std::string> read_ros_files(const std::vector<std::string>& filenames,
      const std::string& package_name)
  {
    std::vector<std::string> result;
    std::string package_path = ros::package::getPath(package_name);
    for (size_t i=0; i<filenames.size(); ++i)
      result.push_back(read_file(package_path + "/" + filenames[i]));
    return result;
  }
}

#endif
