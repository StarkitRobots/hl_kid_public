#pragma once

#include <opencv2/core/core.hpp>

#include "starkit_utils/angle.h"
#include "starkit_geometry/point.h"
#include "starkit_unsorted/particle_filter/particle.h"

namespace Vision {
namespace Localisation {

/// values[0] -> position X [m]
/// values[1] -> position Y [m]
/// values[2] -> orientation (in degrees, corresponding to the description in
///                           class Angle)
///              top   ->  0
///              right -> 90
class FieldPosition : public starkit_unsorted::Particle<3> {
public:
  FieldPosition() : Particle() {}
  FieldPosition(double xInit, double yInit, double angleInit);
  FieldPosition(const FieldPosition &other) : Particle(other) {}

  virtual ~FieldPosition();

  double x() const { return values[0]; }
  double y() const { return values[1]; }

  starkit_utils::Angle getOrientation() const;
  starkit_geometry::Point getRobotPosition() const;
  cv::Point2f getRobotPositionCV() const;

  /// Return the position of 'pos_in_field' in robot referential
  starkit_geometry::Point getFieldPosInSelf(const starkit_geometry::Point & pos_in_field) const;

  void move(starkit_geometry::Point &dist); // dist is given in the robot referential
  void rotate(const starkit_utils::Angle &rotation);

  starkit_unsorted::Particle<3> *clone() const { return new FieldPosition(*this); }

  void tag(cv::Mat &img, starkit_utils::Angle pan = starkit_utils::Angle(0),
           const cv::Scalar &color = cv::Scalar(255, 0, 255),
           int thickness = 1) const;
};
}
}
