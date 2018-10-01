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

#Adding testing support
file(GLOB ALLTESTS *.cpp)
add_executable(TestDemo ${ALLTESTS})

target_link_libraries(	TestDemo 
						AdventureLib 
						gtest 
						gtest_main)


gtest_add_tests(TARGET TestDemo)