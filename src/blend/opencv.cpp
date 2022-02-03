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

namespace gpu
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
}  // namespace gpu

}  // namespace blend::opencv
