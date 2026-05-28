cmake_minimum_required(VERSION 3.10)

project(command_pattern VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(command_lib STATIC src/Command.cpp)

target_include_directories(command_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(command_app src/main.cpp)

target_link_libraries(command_app command_lib)

enable_testing()

add_executable(command_test tests/command_test.cpp)

target_link_libraries(command_test command_lib)

add_test(NAME command_test COMMAND command_test)

install(TARGETS command_app DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "command-pattern")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT "vlad-192")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Lotnik Vladislav")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Command pattern example in C++")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")

include(CPack)

