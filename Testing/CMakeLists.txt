cmake_minimum_required(VERSION 3.14)
project(tests)


set(CMAK
E_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "CC set to: $ENV{CC}")
message(STATUS "CXX set to:$ENV{CXX}")

enable_testing()


add_executable(
	test_main
	test_main.cpp
)


target_link_libraries(
	test_main PUBLIC
	testables
	GTest::gtest_main
	GTest::gtest
)


include(GoogleTest)
gtest_discover_tests(test_main)


