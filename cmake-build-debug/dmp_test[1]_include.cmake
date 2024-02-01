if(EXISTS "/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test")
  if(NOT EXISTS "/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_tests.cmake" OR
     NOT "/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_tests.cmake" IS_NEWER_THAN "/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test" OR
     NOT "/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_tests.cmake" IS_NEWER_THAN "${CMAKE_CURRENT_LIST_FILE}")
    include("/home/ne1mnn/.cache/JetBrains/RemoteDev/dist/69f6ce9329a28_CLion-233.11799.171/bin/cmake/linux/x64/share/cmake-3.27/Modules/GoogleTestAddTests.cmake")
    gtest_discover_tests_impl(
      TEST_EXECUTABLE [==[/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test]==]
      TEST_EXECUTOR [==[]==]
      TEST_WORKING_DIR [==[/home/ne1mnn/code/dmp-task/cmake-build-debug]==]
      TEST_EXTRA_ARGS [==[]==]
      TEST_PROPERTIES [==[RUN_SERIAL;TRUE;FIXTURES_REQUIRED;prepare_tests]==]
      TEST_PREFIX [==[]==]
      TEST_SUFFIX [==[]==]
      TEST_FILTER [==[]==]
      NO_PRETTY_TYPES [==[FALSE]==]
      NO_PRETTY_VALUES [==[FALSE]==]
      TEST_LIST [==[dmp_test_TESTS]==]
      CTEST_FILE [==[/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_tests.cmake]==]
      TEST_DISCOVERY_TIMEOUT [==[5]==]
      TEST_XML_OUTPUT_DIR [==[]==]
    )
  endif()
  include("/home/ne1mnn/code/dmp-task/cmake-build-debug/dmp_test[1]_tests.cmake")
else()
  add_test(dmp_test_NOT_BUILT dmp_test_NOT_BUILT)
endif()
