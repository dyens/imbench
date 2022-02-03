#include "blend/opencv.h"

int main()
{
  const char* IM1 = "assets/cpp.png";
  const char* IM2 = "assets/rust.png";
  const char* DST = "checks/blend_opencv.png";
  blend::opencv::standart::check(IM1, IM2, DST);

  DST = "checks/blend_opencv_gpu.png";
  blend::opencv::gpu::check(IM1, IM2, DST);
}
