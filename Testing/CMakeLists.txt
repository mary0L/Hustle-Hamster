set(TEST_SOURCES
    ${PROJECT_DIR}/Testing/Testing.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Date.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp)
    
set(TEST_INC_DIRS
    ${PROJECT_DIR}/Hustle-Hamster
    ${PROJECT_DIR}/Testing)

add_executable(Testing Testing.cpp)
target_include_directories(Testing PRIVATE ${TEST_INC_DIRS})
target_link_libraries(Testing src)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Testing PROPERTY CXX_STANDARD 20)
endif()

add_test(NAME Testing COMMAND Testing)