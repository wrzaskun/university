cmake_minimum_required(VERSION 3.13)
project(unitTest)

set(CMAKE_CXX_STANDARD 17)

set(test
  university_test.cpp
  pesel_test.cpp
  student_test.cpp
  cmain.cpp
  ../catch2/catch.hpp
)

add_executable(${PROJECT_NAME} ${test})
target_link_libraries(${PROJECT_NAME} PUBLIC university_static)
