#pragma once
#include <QImage>

namespace blend::pure
{
// TODO: remove qimage usage?
struct Args
{
  uchar* dst;
  const uchar* src;
  size_t len;
  QImage _dsti;
  QImage _srci;
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);

}  // namespace blend::pure
