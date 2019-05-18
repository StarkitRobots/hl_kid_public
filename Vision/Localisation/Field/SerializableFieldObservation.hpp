#pragma once

#include "FieldPosition.hpp"
#include "starkit_utils/serialization/json_serializable.h"

#include "starkit_unsorted/particle_filter/bounded_score_observation.h"

// Ensure that the particle is inside of the field

namespace Vision {
namespace Localisation {

class SerializableFieldObservation
  : public starkit_unsorted::BoundedScoreObservation<FieldPosition>,
      public starkit_utils::JsonSerializable {};
}
}
