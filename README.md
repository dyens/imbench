# Build
```sh
# For build you need custom opencv:
cd build
cmake -DCVPATH="YOUR_PATH_HERE/opencv/build" ..
make
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

# DONE
1. Opencv cuda

# Notes

## For fedora installation cuda toolkit use

```
cudo dnf config-manager --add-repo=https://negativo17.org/repos/fedora-nvidia.repo
sudo dnf install cuda-devel
```


## Opecv Build
1. Build gcc :smile: :cursing_face: :poop:

```sh

sudo dnf install gpm-devel mpfr-devel libmpc-devel libstdc++-devel glibc-devel

# Pick your mirror:
wget http://mirror.linux-ia64.org/gnu/gcc/releases/gcc-10.3.0/gcc-10.3.0.tar.xz

tar -xf gcc-10.3.0.tar.xz
cd gcc-10.3.0

# Download this patch https://gitweb.gentoo.org/proj/gcc-patches.git/tree/10.3.0/gentoo/35_all_remove-cyclades.patch

patch -p1 < 35_all_remove-cyclades.patch

mkdir build && cd build
../configure --prefix=/opt/gcc10.3.0 \
    --program-suffix=-10.3 \
    --enable-languages=c,c++ \
    --disable-multilib

make -j6
make install
cd /opt/gcc10.3.0/bin
sudo ln -s gcc-10.3 gcc
sudo ln -s g++-10.3 g++


```

1. Clone opencv
1. Clone opencv-contrib

```
cd opencv
mkdir build
cd build


export PATH="/opt/gcc10.3.0/bin:$PATH"
export CC=/opt/gcc10.3.0/bin/gcc
export CXX=/opt/gcc10.3.0/bin/g++

cmake -D CMAKE_BUILD_TYPE=Release -D OPENCV_EXTRA_MODULES_PATH="../../opencv_contrib/modules" -DOPENCV_ENABLE_NONFREE=ON -DWITH_CUDA=ON  ..

# make sure cudaarithm in opencv modules in cmake output

make -j6
```
