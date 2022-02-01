#include "blend/opencv.h"

int main()
{
  const char* IM1 = "assets/cam_image.png";
  const char* IM2 = "assets/semseg_image.png";
  const char* DST = "checks/blend_opencv.png";
  blend::opencv::standart::check(IM1, IM2, DST);

  // const char* DST = "checks/blend_opencv_gpu.png";
  // blend::opencv::gpu::check(IM1, IM2, DST);

}
