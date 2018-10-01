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

add_subdirectory(src)


get_directory_property(hasParent PARENT_DIRECTORY)
if(hasParent)
#does not do an additional thing if it is a child
else()
add_subdirectory(Tests)
endif()
