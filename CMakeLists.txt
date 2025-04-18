cmake_minimum_required(VERSION 3.16)

project(QT_cpp_test_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QT_cpp_test_app main.cpp

    binarytree.h binarytree.cpp)

include(GNUInstallDirs)
install(TARGETS QT_cpp_test_app
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
