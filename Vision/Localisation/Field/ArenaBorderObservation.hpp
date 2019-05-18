#pragma once

#include "Localisation/Field/SerializableFieldObservation.hpp"
#include "CameraState/CameraState.hpp"

#include "starkit_geometry/parametric_line.h"

namespace Vision {
namespace Localisation {

class ArenaBorderObservation : public SerializableFieldObservation {
private:
  // Seen line and closestpoint in robotReferential (2 dimensional)
  starkit_geometry::ParametricLine robotSeenLine;
  // The closest point to the robot which belongs to the line (robot
  // referential)
  starkit_geometry::Point robotClosestPoint;
  double robotHeight;

  static double minDist;// [m]
  static int maxTries;

  static double pError;

  static double lAngleMaxError, lSigmoidOffset, lSigmoidLambda;
  static double cpAngleMaxError, cpSigmoidOffset, cpSigmoidLambda;

  static bool debug;

public:
  ArenaBorderObservation();

  // throw std::runtime_error on failure
  ArenaBorderObservation(const starkit_geometry::ParametricLine &imgSeenLine, int imgWidth,
                         int imgHeight, Utils::CameraState &cs);

  virtual double angleScore(const FieldPosition &p,
                            const starkit_geometry::ParametricLine &l) const;
  virtual double closestPointScore(const FieldPosition &p,
                                   const starkit_geometry::ParametricLine &l) const;

  virtual double potential(const FieldPosition &p) const;

  static void bindWithRhIO();
  static void importFromRhIO();

  std::string getClassName() const override;
  Json::Value toJson() const override;
  void fromJson(const Json::Value & v, const std::string & dir_name) override;

  double getMinScore() const override;
};
}
}
