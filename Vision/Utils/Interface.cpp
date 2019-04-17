#include "Utils/Interface.h"

#include <cmath>

namespace Vision
{

starkit_geometry::Point cv2rg(const cv::Point & p)
{
  return starkit_geometry::Point(p.x,p.y);
}

starkit_geometry::Point cv2rg(const cv::Point2f & p)
{
  return starkit_geometry::Point(p.x,p.y);
}

cv::Point rg2cv(const starkit_geometry::Point & p)
{
  return cv::Point((int)p.x,(int)p.y);
}

cv::Point2f rg2cv2f(const starkit_geometry::Point & p)
{
  return cv::Point2f(p.x,p.y);
}

starkit_utils::Angle angleBetween(const cv::Point3f & v1, const cv::Point3f & v2)
{
  double nv1 = norm(v1);
  double nv2 = norm(v2);
  if (nv1 < 1e-9 || nv2 < 1e-9) {
    return 0;
  }
  double x = v1.dot(v2) / (nv1 * nv2);
  if (x > 1.0) { x = 1.0;}
  if (x < -1.0) { x = -1.0;}
  return starkit_utils::Angle::arccos(x);
}

}
