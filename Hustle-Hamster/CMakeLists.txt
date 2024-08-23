# CMakeList.txt : CMake project for Hustle-Hamster, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Hustle-Hamster "Date.cpp" "Date.h" "Journal.cpp" "Journal.h" "main.cpp" "utils.h" "utils.cpp" "menuHelp.ccp" "menuHelp.h" "dailyLog.cpp" "dailyLog.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hustle-Hamster PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
