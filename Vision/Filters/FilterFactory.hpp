#pragma once

#include "starkit_utils/serialization/factory.h"

#include "Filters/Filter.hpp"

namespace Vision {
namespace Filters {
class FilterFactory : public starkit_utils::Factory<Filter> {
public:
  FilterFactory();
};
}
}
