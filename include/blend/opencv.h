#pragma once

#include "opencv2/core/cuda.hpp"
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
  void blend(Args & args);
  void check(const char* im1, const char* im2, const char* dest);

}  // namespace default

namespace gpu
{
struct Args
{
  cv::cuda::GpuMat src1;
  cv::cuda::GpuMat src2;
  cv::cuda::GpuMat dst;
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);
}  // namespace gpu

}  // namespace blend::opencv
