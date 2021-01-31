cmake_minimum_required(VERSION 3.16)

project(ParaCLGtest)

set(CMAKE_CXX_STANDARD 20)

#[[add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)]]

#add_definitions(-DGTESTS)
#add_compile_definitions(GTESTS)


find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME}  ../main.cpp ../tests.cpp ../Nodes/driver.cpp ../Nodes/Node.cpp  ../Nodes/driver.cpp  ../Build/lex.yy.cc ../Build/numgrammar.tab.cc ../Nodes/MyLexer.cpp)
add_definitions(-DGTESTS)

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main  Threads::Threads)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/gtests $<TARGET_FILE_DIR:${PROJECT_NAME}>/tests)