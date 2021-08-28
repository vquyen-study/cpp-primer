cmake_minimum_required (VERSION 3.20.0)
project (chapter17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure_file(tq-data.sample tq-data.txt COPYONLY)

add_executable (ch17-01-to-03   ch17-01-to-03.cpp) 
add_executable (ch17-04-to-08   ch17-04-to-08.cpp) 
add_executable (ch17-09-to-13   ch17-09-to-13.cpp) 
add_executable (ch17-14-to-16   ch17-14-to-16.cpp) 
add_executable (ch17-17-18      ch17-17-18.cpp) 
add_executable (ch17-19         ch17-19.cpp) 