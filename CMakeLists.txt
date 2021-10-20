cmake_minimum_required(VERSION 3.14)
project(University)
set(CMAKE_CXX_STANDARD 17)

 if(MSVC)
    add_compile_options("/W3 /EHsc")
 elseif()
    add_compile_options("-Wall -Wextra -pedantic -Wconversion")
 endif()

set(university_src
        Student.cpp
        Student.hpp
        University.cpp
        University.hpp
        Pesel.hpp
        Pesel.cpp
        IDataBase.hpp
        DataBaseFile.hpp
        DataBaseFile.cpp
        Helper.hpp
        Helper.cpp
)

add_library(university_static OBJECT ${university_src})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC university_static)
add_subdirectory(unit_tests)


