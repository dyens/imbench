#pragma once

#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudaimgproc.hpp>

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

namespace gpu_add_weighted_with_array_move
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
}  // namespace gpu_add_weighted

namespace gpu_add_weighted
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
}  // namespace gpu_alpha_comp

}  // namespace blend::opencv
