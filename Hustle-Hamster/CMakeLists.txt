# CMakeList.txt : CMake project for Hustle-Hamster, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Hustle-Hamster "Date.cpp" "Journal.cpp" "main.cpp" "utils.cpp" "menuHelp.cpp" "dailyLog.cpp" "feedback.cpp" "hammyDialogue.cpp" "includes/all_includes.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hustle-Hamster PROPERTY CXX_STANDARD 20)
endif()

add_library(src STATIC "Date.cpp" "Journal.cpp" "utils.cpp" "menuHelp.cpp" "dailyLog.cpp" "feedback.cpp" "hammyDialogue.cpp" "includes/all_includes.h")
target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR}/includes)
target_include_directories(Hustle-Hamster PUBLIC ${CMAKE_CURRENT_LIST_DIR}/includes)