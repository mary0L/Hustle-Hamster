set(TEST_SOURCES_JOURNAL
    ${PROJECT_DIR}/Testing/Journal-Test.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Date.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp
)

set(TEST_SOURCES_DAILYLOG
    ${PROJECT_DIR}/Testing/DailyLog-Test.cpp
    ${PROJECT_DIR}/Hustle-Hamster/dailyLog.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp
    ${PROJECT_DIR}/Hustle-Hamster/utils.cpp)

set(TEST_SOURCES_UTILS
    ${PROJECT_DIR}/Testing/Utils-Test.cpp
    ${PROJECT_DIR}/Hustle-Hamster/utils.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Date.cpp
    ${PROJECT_DIR}/Hustle-Hamster/Journal.cpp)

set(TEST_SOURCES_MENUHELP
    ${PROJECT_DIR}/Testing/menuHelp-Test.cpp
    ${PROJECT_DIR}/Hustle-Hamster/menuHelp.cpp)

    
set(TEST_INC_DIRS
    ${PROJECT_DIR}/Hustle-Hamster
    ${PROJECT_DIR}/Testing)


add_definitions(-DTEST_RUNNING)

# Add executables for unit testing journal
# Include source code directories and link to src
add_executable(TestJournal ${TEST_SOURCES_JOURNAL}) 
target_include_directories(TestJournal PRIVATE ${TEST_INC_DIRS})
target_link_libraries(TestJournal src)

# Add executables for unit testing daily log
# Include source code directories and link to src
add_executable(TestDailyLog ${TEST_SOURCES_DAILYLOG})
target_include_directories(TestDailyLog PRIVATE ${TEST_INC_DIRS})
target_link_libraries(TestDailyLog src)

# Add executables for unit testing utils
add_executable(TestUtils ${TEST_SOURCES_UTILS})
target_include_directories(TestUtils PRIVATE ${TEST_INC_DIRS})
target_link_libraries(TestUtils src)

# Add executables for unit testing menu help
add_executable(TestMenuHelp ${TEST_SOURCES_MENUHELP})
target_include_directories(TestMenuHelp PRIVATE ${TEST_INC_DIRS})
target_compile_definitions(TestMenuHelp PRIVATE TEST_RUNNING)
target_link_libraries(TestMenuHelp src)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET TestJournal PROPERTY CXX_STANDARD 20)
    set_property(TARGET TestDailyLog PROPERTY CXX_STANDARD 20)
    set_property(TARGET TestUtils PROPERTY CXX_STANDARD 20)
endif()

add_test(NAME TestJournal COMMAND TestJournal)
add_test(NAME TestDailyLog COMMAND TestDailyLog)
add_test(NAME TestUtils COMMAND TestUtils)
add_test(NAME TestMenuHelp COMMAND TestMenuHelp)

