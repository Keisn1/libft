cmake_minimum_required(VERSION 3.14)
project(libft)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

file(GLOB SRC_FILES "src/*.c")
file(GLOB BONUS_SRC_FILES "src_bonus/*.c")
file(GLOB TEST_FILES "tests/*.cpp")

# Handle BUFFER_SIZE values
set(TEST_NAME "run_tests")
add_executable(${TEST_NAME} ${SRC_FILES} ${BONUS_SRC_FILES} ${TEST_FILES})

target_include_directories(${TEST_NAME} PRIVATE includes)
target_include_directories(${TEST_NAME} PRIVATE ${gtest_SOURCE_DIR}/googletest/include)

target_link_libraries(
  ${TEST_NAME}
  GTest::gtest
  GTest::gtest_main
  pthread
  bsd
)


# find_package(PkgConfig REQUIRED)
# pkg_check_modules(LIBBSD REQUIRED libbsd)

# # Link the library to your target
# target_link_libraries(${TEST_NAME} ${LIBBSD_LIBRARIES})

# Register the test with CTest
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
