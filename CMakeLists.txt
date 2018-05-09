cmake_minimum_required(VERSION 2.8.9)
project(Adventure)
 
#Bring the headers into the project
include_directories(Header)
 
file(GLOB SOURCES "Core/*.cpp")
 
add_executable(Adventure ${SOURCES})