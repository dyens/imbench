#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

namespace blend::opencv
{

namespace standart
{

struct Args
{
  cv::Mat src1;
  cv::Mat src2;
  cv::Mat dst;
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);

}  // namespace standart

namespace gpu
{
struct Args
{
  cv::Mat src1;
  cv::Mat src2;
  cv::Mat dst;
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);
}  // namespace gpu

}  // namespace blend::opencv
