#include <benchmark/benchmark.h>
#include "blend/opencv.h"
#include "blend/qt.h"


const char* IM1 = "assets/cpp.png";
const char* IM2 = "assets/rust.png";

void BM_OpencvBlend(benchmark::State& state, const char* im1, const char* im2)
{
  auto args = blend::opencv::standart::prepare(im1, im2);

  for (auto _ : state)
  {
    blend::opencv::standart::blend(args);
  }
}

BENCHMARK_CAPTURE(BM_OpencvBlend, , IM1, IM2);

void BM_OpencvGPUBlend(benchmark::State& state, const char* im1, const char* im2)
{
  auto args = blend::opencv::gpu::prepare(im1, im2);

  for (auto _ : state)
  {
    blend::opencv::gpu::blend(args);
  }
}

BENCHMARK_CAPTURE(BM_OpencvGPUBlend, , IM1, IM2);


void BM_QTBlend(benchmark::State& state, const char* im1, const char* im2)
{
  auto args = blend::qt::prepare(im1, im2);

  for (auto _ : state)
  {
    blend::qt::blend(args);
  }
}

BENCHMARK_CAPTURE(BM_QTBlend, , IM1, IM2);

BENCHMARK_MAIN();
