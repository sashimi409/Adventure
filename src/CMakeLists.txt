#Bring the headers into the project
include_directories(include)
 

 #Get all source files and then remove Main.cpp
 #Will change this after the library is more complete, and adding files is more infrequent
file(GLOB SOURCES "CPPs/*.cpp")
list(REMOVE_ITEM SOURCES Main.cpp)

#seperating the bulk from the basic drive I have
add_library(AdventureLib ${SOURCES})
add_executable(Adventure CPPs/Main.cpp)

#builds the interface to interact witht he library
target_link_libraries(Adventure AdventureLib)

target_include_directories(AdventureLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)