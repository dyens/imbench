# Build
```sh
cd build && cmake .. && make
```


# Run Benchmark
```sh
./build/blend
```

# Build requirements
1. cmake, 
1. gcc
1. google-benchmark-devel
1. opencv
1. QT
1. Cuda toolkit (thrust lib)

# TODO
1. Naive implementation using per pixel blending (with pointer magic??)
1. Multi thread implementation (openmp)
1. Thrust implementation https://stackoverflow.com/questions/22891244/blend-two-images-using-gpu
1. Opencv cuda

# Notes

For fedora installation cuda toolkit use

```
cudo dnf config-manager --add-repo=https://negativo17.org/repos/fedora-nvidia.repo
sudo dnf install cuda-devel
```
