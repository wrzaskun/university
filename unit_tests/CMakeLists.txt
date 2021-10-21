cmake_minimum_required(VERSION 3.14)

set(test
  university_test.cpp
  pesel_test.cpp
  student_test.cpp
  cmain.cpp
)

set(catch
    ../catch2/catch_amalgamated.cpp
)

add_library(catch_static STATIC ${catch}) # change for requirements OBJECT is 30% faster
add_executable(${PROJECT_NAME}-ut ${test})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC university_static catch_static)
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)
