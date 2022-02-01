#pragma once

#include <thrust/host_vector.h>
namespace blend::thrust
{

struct Args
{
};

Args prepare(const char* im1, const char* im2);
void blend(Args& args);
void check(const char* im1, const char* im2, const char* dest);

}  // namespace blend::thrust
