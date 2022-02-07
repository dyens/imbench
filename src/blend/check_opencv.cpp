#include "blend/opencv.h"

int main()
{
  const char* IM1 = "assets/cpp.png";
  const char* IM2 = "assets/rust.png";
  const char* DST = "checks/blend_opencv.png";
  blend::opencv::standart::check(IM1, IM2, DST);

  DST = "checks/blend_opencv_gpu_add_weighted.png";
  blend::opencv::gpu_add_weighted::check(IM1, IM2, DST);

  DST = "checks/blend_opencv_gpu_add_weighted_with_array_move.png";
  blend::opencv::gpu_add_weighted_with_array_move::check(IM1, IM2, DST);
}
