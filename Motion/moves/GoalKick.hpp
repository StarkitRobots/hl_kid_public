#pragma once

#include "Move.h"
#include "starkit_geometry/point.h"
#include <Eigen/Dense>

class Approach;
class KickController;
class GoalKick : public Move
{
public:
  
  GoalKick();
  std::string getName();
  
  void onStart();
  void onStop();
  void step(float elapsed);

  // void toFile(std::map<std::string, std::map<std::string,  float>> &map, std::string filename);
  Eigen::Vector2d getBallDir(starkit_geometry::Point previousBallPos,
                             starkit_geometry::Point currentBallPos);
  
protected:

  starkit_geometry::Point previousBallPosition;
  float previousBallDistance;
  
  starkit_geometry::Point currentBallPosition; 
  float currentBallDistance;

  bool ballGettingCloser;
};
