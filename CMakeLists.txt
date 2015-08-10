cmake_minimum_required (VERSION 2.8)
project(FE-CLI)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# build libraries in lib/
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE}/lib)

# use C++ 11
set(CMAKE_CXX_FLAGS "-std=c++11")

# include curses!
find_package(Curses REQUIRED)
include_directories(
  ${CURSES_INCLUDE_DIR},
  ${PROJECT_SOURCE_DIR}/src
)

# include sources!
file(GLOB FE-CLI_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(fe-cli ${FE-CLI_SOURCES})
target_link_libraries(fe-cli ${CURSES_LIBRARIES})