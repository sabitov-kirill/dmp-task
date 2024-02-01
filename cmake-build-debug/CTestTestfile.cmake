# CMake generated Testfile for 
# Source directory: /home/ne1mnn/code/dmp-task
# Build directory: /home/ne1mnn/code/dmp-task/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_include.cmake")
add_test(build_module "/home/ne1mnn/.cache/JetBrains/RemoteDev/dist/69f6ce9329a28_CLion-233.11799.171/bin/cmake/linux/x64/bin/cmake" "--build" "/home/ne1mnn/code/dmp-task/cmake-build-debug" "--config" "Debug" "--target" "dmp")
set_tests_properties(build_module PROPERTIES  FIXTURES_SETUP "prepare_tests" _BACKTRACE_TRIPLES "/home/ne1mnn/code/dmp-task/CMakeLists.txt;130;add_test;/home/ne1mnn/code/dmp-task/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
