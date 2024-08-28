set(TEST_SOURCES
    ${PROJECT_DIR}/Testing/Journal-Test.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Date.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp)
    
set(TEST_INC_DIRS
    ${PROJECT_DIR}/Hustle-Hamster
    ${PROJECT_DIR}/Testing)

add_executable(TestJournal ${TEST_SOURCES}) 
target_include_directories(TestJournal PRIVATE ${TEST_INC_DIRS})
target_link_libraries(TestJournal src)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestJournal PROPERTY CXX_STANDARD 20)
endif()

add_test(NAME TestJournal COMMAND TestJournal)