#pragma once

#include <opencv2/core/core.hpp>

#include "starkit_utils/angle.h"

namespace Vision {
namespace Utils {

class HT {
public:
  static cv::Mat rotX(const starkit_utils::Angle &theta);
  static cv::Mat rotY(const starkit_utils::Angle &theta);
  static cv::Mat rotZ(const starkit_utils::Angle &theta);
};
}
}
