#pragma once
#include <QImage>

namespace blend::qt
{
struct Args
{
  QImage dst;
  QImage src;
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);

}  // namespace blend::qt
