#include "blend/opencv.h"

#include <opencv2/cudaarithm.hpp>

namespace blend::opencv
{

namespace standart
{

Args prepare(const char* im1, const char* im2)
{
  cv::Mat src1 = cv::imread(cv::samples::findFile(im1));
  cv::Mat src2 = cv::imread(cv::samples::findFile(im2));
  return Args{src1, src2, cv::Mat{}};
}

void blend(Args& args) { cv::addWeighted(args.src1, 0.5, args.src2, 0.5, 0.0, args.dst); }

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  cv::imwrite(dest, args.dst);
}
}  // namespace standart

namespace gpu_add_weighted_with_array_move
{

Args prepare(const char* im1, const char* im2)
{
  cv::Mat src1 = cv::imread(cv::samples::findFile(im1));
  cv::Mat src2 = cv::imread(cv::samples::findFile(im2));
  return Args{src1, src2, cv::Mat{}};
}

void blend(Args& args) { cv::cuda::addWeighted(args.src1, 0.5, args.src2, 0.5, 0.0, args.dst); }

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  cv::imwrite(dest, args.dst);
}
}  // namespace gpu_add_weighted_with_array_move

namespace gpu_add_weighted
{

Args prepare(const char* im1, const char* im2)
{
  cv::cuda::GpuMat src1;
  src1.upload(cv::imread(cv::samples::findFile(im1)));
  cv::cuda::GpuMat src2;
  src2.upload(cv::imread(cv::samples::findFile(im2)));
  return Args{src1, src2, cv::cuda::GpuMat{}};
}

void blend(Args& args)
{
  cv::cuda::addWeighted(args.src1, 0.5, args.src2, 0.5, 0.0, args.dst);
  // cv::cuda::alphaComp(args.src1, args.src2, args.dst, cv::cuda::ALPHA_OVER);
}

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  cv::Mat res;
  args.dst.download(res);
  cv::imwrite(dest, res);
}
}  // namespace gpu_add_weighted

}  // namespace blend::opencv
