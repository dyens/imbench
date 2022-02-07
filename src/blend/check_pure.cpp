#include "blend/pure.h"

int main()
{
  const char* IM1 = "assets/cpp.png";
  const char* IM2 = "assets/rust.png";
  const char* DST = "checks/blend_pure.png";
  blend::pure::check(IM1, IM2, DST);
}
