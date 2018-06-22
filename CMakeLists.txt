cmake_minimum_required(VERSION 3.9 FATAL_ERROR)


project(Adventure)
 
include(CTest)
include(GoogleTest)

#Used to pass information to DownloadProject
if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()


#used to download a project from github 
include(DownloadProject.cmake)



#adding Google Test
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)


#Make sure google test does not change any flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#add it to the project
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})



# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()



#Bring the headers into the project
include_directories(include)
 

 #Get all source files and then remove Main.cpp
 #Will change this after the library is more complete, and adding files is more infrequent
file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES Main.cpp)

#seperating the bulk from the basic drive I have
add_library(AdventureLib ${SOURCES})
add_executable(Adventure src/Main.cpp)

#builds the interface to interact witht he library
target_link_libraries(Adventure AdventureLib)


#Adding testing support
file(GLOB ALLTESTS Tests/*cpp)
add_executable(TestDemo ${ALLTESTS})
target_link_libraries(TestDemo AdventureLib gtest gtest_main)


gtest_add_tests(TARGET TestDemo)