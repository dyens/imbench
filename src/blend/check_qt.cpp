#include "blend/qt.h"

int main()
{
  const char* IM1 = "assets/cpp.png";
  const char* IM2 = "assets/rust.png";
  const char* DST = "checks/blend_qt.png";
  blend::qt::check(IM1, IM2, DST);
}
