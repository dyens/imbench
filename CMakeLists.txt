cmake_minimum_required (VERSION 3.0.0)
project (IMBENCH)


 
add_compile_options( -mmmx -msse -msse2 -msse3 -msse4 -m3dnow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(directory_test)

include_directories(include)
find_package(benchmark REQUIRED)
# find_package(OpenCV REQUIRED)


find_package(OpenCV  REQUIRED PATHS /home/dyens/dev/external/opencv/build/ NO_DEFAULT_PATH)
find_package(Qt6 COMPONENTS Core Widgets Multimedia Qml REQUIRED)

find_package(PkgConfig)
pkg_search_module(CUDA REQUIRED cuda)
include_directories(${CUDA_INCLUDE_DIRS})


add_executable(blend_check_opencv
 src/blend/opencv.cpp
 src/blend/check_opencv.cpp
)
target_link_libraries(blend_check_opencv ${OpenCV_LIBS})


add_executable(blend_check_qt
 src/blend/qt.cpp
 src/blend/check_qt.cpp
)
target_link_libraries(blend_check_qt
  Qt6::Multimedia
)


add_executable(blend_check_pure
 src/blend/pure.cpp
 src/blend/check_pure.cpp
)
target_link_libraries(blend_check_pure
  Qt6::Multimedia
)

add_executable(blend_check_thrust
 src/blend/thrust.cpp
 src/blend/check_thrust.cpp
)
# link_libraries(blend ${CUDA_LIBRARIES})

add_executable(blend
 src/blend/opencv.cpp
 src/blend/qt.cpp
 src/blend/pure.cpp
 src/blend/main.cpp
)
target_link_libraries(blend benchmark::benchmark)
target_link_libraries(blend ${OpenCV_LIBS})
target_link_libraries(blend
  Qt6::Multimedia
)


