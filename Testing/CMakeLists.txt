set(TEST_SOURCES
    ${PROJECT_DIR}/Testing/Testing.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Date.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp)
    
set(TEST_INC_DIRS
    ${PROJECT_DIR}/Hustle-Hamster
    ${PROJECT_DIR}/Testing)

add_executable(Testing ${TEST_SOURCES})
target_include_directories(Testing PRIVATE ${TEST_INC_DIRS})

add_test(NAME Testing COMMAND Testing)