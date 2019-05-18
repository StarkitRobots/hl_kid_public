#include "Filters/Basics/Integral.hpp"

#include <opencv2/imgproc/imgproc.hpp>
#include "starkit_utils/timing/benchmark.h"

using starkit_utils::Benchmark;

namespace Vision {
namespace Filters {

void Integral::setParameters() {

}

void Integral::process() {
  cv::Mat src = *(getDependency().getImg());
  integral(src, img(), CV_32S);
}
}
}
