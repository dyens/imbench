#include "blend/pure.h"

namespace blend::pure
{

Args prepare(const char* im1, const char* im2)
{
  Args args;
  args._dsti = QImage(im1);
  args._srci = QImage(im2);
  args.len = args._dsti.width() * args._dsti.height();
  args.dst = args._dsti.bits();
  args.src = args._srci.bits();
  return args;
}

void blend(Args& args)
{
  for (size_t pixel = 0; pixel < args.len * 3; pixel = pixel + 3)
  {
    args.dst[pixel] = (args.dst[pixel] + args.src[pixel]) / 2;
    args.dst[pixel + 1] = (args.dst[pixel + 1] + args.src[pixel + 1]) / 2;
    args.dst[pixel + 2] = (args.dst[pixel + 2] + args.src[pixel + 2]) / 2;
  }
}

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  args._dsti.save(dest);
}

}  // namespace blend::pure
