#pragma once

#include "FieldPosition.hpp"

#include "starkit_unsorted/particle_filter/bounded_score_observation.h"

// Ensure that the particle is inside of the field

namespace Vision {
namespace Localisation {

class FieldObservation : public starkit_unsorted::BoundedScoreObservation<FieldPosition> {
  bool isGoalKeeper;
public:
  FieldObservation(bool isGoalKeeper);

  virtual double potential(const FieldPosition &p) const;

  double getMinScore() const override;

  /// Required because 0 score are particularly dangerous
  static double pError;
};
}
}
