#pragma once

#include "ArucoTag.hpp"

#include <starkit_utils/serialization/json_serializable.h>

class TagsCollection : public starkit_utils::JsonSerializable {
  /// Return a dictionary containing all the aruco tags of the collection
  virtual std::map<int, ArucoTag> getMarkers() const = 0;
};
