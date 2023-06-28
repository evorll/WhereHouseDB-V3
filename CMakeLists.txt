cmake_minimum_required(VERSION 3.5)
project(HTTPServer)
add_executable(main
	src/main.cpp
	src/json.cpp
	src/manage.cpp
	src/file.cpp
	src/config.h
)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the test executable
add_executable(tests src/tests.cpp)

enable_testing()
# Specify the C++ standard
set_target_properties(tests PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)