#include "blend/qt.h"

#include <QPainter>

namespace blend::qt
{

Args prepare(const char* im1, const char* im2) { return Args{QImage(im1), QImage(im2)}; }

void blend(Args& args)
{
  QPainter painter(&args.dst);
  painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
  painter.drawImage(0, 0, args.src);
  painter.end();
}

void check(const char* im1, const char* im2, const char* dest)
{
  auto args = prepare(im1, im2);
  blend(args);
  args.dst.save(dest);
}

}  // namespace blend::qt
