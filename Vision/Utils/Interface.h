#pragma once

#include <opencv2/core/core.hpp>

#include "starkit_geometry/point.h"

// Pure interface between opencv and starkit_geometry
namespace Vision
{

starkit_geometry::Point cv2rg(const cv::Point & p);
starkit_geometry::Point cv2rg(const cv::Point2f & p);

cv::Point rg2cv(const starkit_geometry::Point & p);
cv::Point2f rg2cv2f(const starkit_geometry::Point & p);
starkit_utils::Angle angleBetween(const cv::Point3f & v1, const cv::Point3f & v2);

}
