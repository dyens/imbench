#include "blend/opencv.h"


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
  cv::cuda::GpuMat src1;
  cv::cuda::GpuMat src2;
  src1.upload(cv::imread(cv::samples::findFile(im1)));
  src2.upload(cv::imread(cv::samples::findFile(im2)));
  return Args{src1, src2, cv::cuda::GpuMat{}};
}

void blend(Args& args) {

  //TODO https://gist.github.com/raulqf/f42c718a658cddc16f9df07ecc627be7
  assert((false, "Not implemented"));
 }

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  cv::imwrite(dest, args.dst);
}
}  // namespace gpu

}  // namespace blend::opencv
