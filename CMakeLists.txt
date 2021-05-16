cmake_minimum_required(VERSION 3.17)
project(Snake_Game)

#set(CMAKE_CXX_STANDARD 14)

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.

include_directories(GL)

add_executable(Snake_Game main.cpp)

target_link_libraries(Snake_Game ${OpenGlLinkers})