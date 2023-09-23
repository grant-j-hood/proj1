cmake_minimum_required(VERSION 3.5)
project(project1 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The following will not be graded at the autograder. 
#  It is primarily for your convenience 
#  to experiment with your own main() function in project1_main.cpp.
add_executable(project1_main BagInterface.h ArrayBag.h project1_main.cpp)

# Create unit tests 
#   In the following, notice that ArrayBag.cpp is NOT listed.  
#   Instead, ArrayBag.cpp is #included by NewArrayBag.h to support templates.
add_executable(student_tests student_tests.cpp catch.hpp
    BagInterface.h ArrayBag.h)

# Unit tests 
enable_testing()

add_test(NAME student_tests COMMAND student_tests)

