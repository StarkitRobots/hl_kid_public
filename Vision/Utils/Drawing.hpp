#pragma once

#include <opencv2/core/core.hpp>

#include "starkit_geometry/parametric_line.h"
#include "starkit_geometry/ellipse.h"

namespace Vision {
namespace Utils {

void draw(cv::Mat &img, const starkit_geometry::Ellipse &e, const cv::Scalar &color,
          int thickness = 1);

void draw(cv::Mat &img, const starkit_geometry::ParametricLine &p, const cv::Scalar &color,
          int thickness = 1);

void draw(cv::Mat &img, const std::vector<starkit_geometry::ParametricLine> &lines,
          const cv::Scalar &color, int thickness = 1);
}
}
