cmake_minimum_required (VERSION 2.8.4)
project(FE-CLI)
include(CTest)

# ycm support
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# build executables in bin/
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# set flags
set(CMAKE_CXX_FLAGS "-std=c++11")

# include curses
find_package(Curses REQUIRED)

# include directories
include_directories(
	${CURSES_INCLUDE_DIR}
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/lib
)

set(FE-CLI_SOURCES
	src/feBuff.cpp
	src/feCharacter.cpp
	src/feClass.cpp
	src/feConsumable.cpp
	src/feItem.cpp
	src/feJsonUtils.cpp
	src/feMap.cpp
	src/feMechanics.cpp
	src/feRoster.cpp
	src/feSkill.cpp
	src/feSkillCombat.cpp
	src/feSkillMap.cpp
	src/feSkillStat.cpp
	src/feSecondaryStats.cpp
	src/feStats.cpp
	src/feSupport.cpp
	src/feTile.cpp
	src/feUtils.cpp
	src/feVendor.cpp
	src/feWeapon.cpp
	src/feWeaponRank.cpp
)

set(FE-TEST_SOURCES
	tests/buff.cpp
	tests/character.cpp
	tests/class.cpp
	tests/item.cpp
	tests/jsonUtils.cpp
	tests/map.cpp
	tests/mechanics.cpp
	tests/roster.cpp
	tests/skill.cpp
	tests/support.cpp
	tests/stats.cpp
	tests/tests.cpp
	tests/tile.cpp
	tests/utils.cpp
	tests/vendor.cpp
	tests/weapon.cpp
)

# create executables!
add_executable(fe-cli ${PROJECT_SOURCE_DIR}/src/main.cpp ${FE-CLI_SOURCES})
add_executable(fe-test ${FE-TEST_SOURCES} ${FE-CLI_SOURCES})
target_link_libraries(fe-cli ${CURSES_LIBRARIES} menu)
target_link_libraries(fe-test ${CURSES_LIBRARIES})

# tests!
enable_testing()
add_test(NAME UnitTests COMMAND fe-test)
set_tests_properties(
	UnitTests
	PROPERTIES
	PASS_REGULAR_EXPRESSION "1*"
)
