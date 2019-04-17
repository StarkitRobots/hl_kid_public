#pragma once

#include "STM.h"

#include <services/TeamPlayService.h>
#include <starkit_geometry/point.h>

class Walk;
class Approach;
class Placer;

class GoalKeeper : public STM
{
public:
  GoalKeeper(Walk *walk,  Placer *placer);
  std::string getName();

  void onStart();
  void onStop();
  void step(float elapsed);
  void enterState(std::string state);
  void exitState(std::string state);
  starkit_team_play::TeamPlayState teamState();

protected:
  Walk *walk;
  Placer *placer;


  bool ballInZone(float xd, float yd);
  bool ballInAttackZone();
  bool ballInAttackZoneHysteresis();
  bool ignoreBall();
  bool ignoreBallHys();
  bool isNearHome();
  bool isNearHomeHys();
  starkit_geometry::Point getAlignPoint(const starkit_geometry::Point &,float &);
  starkit_geometry::Point home();
  bool isAligned();
  starkit_geometry::Point shootLineCenter();  
  void bufferedSetState(const std::string &);
  
  void setTeamPlayState(starkit_team_play::TeamPlayState state);
  
  bool stopPosture;
  float t;
  float targetX, targetY ;
  float xAttack, yAttack;
  float xAttackHys, yAttackHys;
  float xIgnoreBall, xIgnoreBallHys;
  float homeX,maxHomeDistance,maxHomeDistanceHys;
  float alignTolerance;
  float maxShootDist;
  int nextStateSize;
  std::vector<std::string> nextState;
  int nextStateIndice;	
  //bool isPlacing;
  bool neverWalked;
  bool placedByHand;
  float initElbowOffsetValue;
  float initArmsRollValue;
  float initTrunkZOffsetValue;
  float stopMoveTime;
  bool opponentWithGrass;
  float againstGrassRatio,grassRatio;
};
