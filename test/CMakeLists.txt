add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR, lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES activityTests.cpp registerFixture.cpp)
add_executable(runActivitiesRegisterTests ${SOURCE_TEST_FILES})
target_link_libraries(runActivitiesRegisterTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)