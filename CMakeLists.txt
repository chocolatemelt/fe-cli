cmake_minimum_required (VERSION 2.8.4)
project(FE-CLI)
include(CTest)

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# set flags
set(CMAKE_CXX_FLAGS "-std=c++11 -Isrc/classes -lmenu")

# include curses
find_package(Curses REQUIRED)

# include directories
include_directories(
  ${CURSES_INCLUDE_DIR},
  ${PROJECT_SOURCE_DIR}/src/includes
)
file(GLOB FE-CLI_SOURCES ${PROJECT_SOURCE_DIR}/src/classes/*.cpp)

# create executables!
add_executable(fe-cli ${PROJECT_SOURCE_DIR}/src/main.cpp ${FE-CLI_SOURCES})
add_executable(fe-test ${PROJECT_SOURCE_DIR}/src/tests.cpp ${FE-CLI_SOURCES})
target_link_libraries(fe-cli ${CURSES_LIBRARIES})
target_link_libraries(fe-test ${CURSES_LIBRARIES})

# tests!
enable_testing()
add_test(NAME UnitTests COMMAND fe-test)
set_tests_properties(
	UnitTests
	PROPERTIES
	PASS_REGULAR_EXPRESSION "1*"
)
