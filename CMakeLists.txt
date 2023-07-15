cmake_minimum_required(VERSION 3.10)

project(UnitConverter)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Google Test requires at least C++11
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Create variables with the sources files
set(UNIT_CONVETER_SOURCES
    main.cpp
    menufunctions.cpp
    unitconverter.cpp
    conversionutils.cpp
    user.cpp
)

# If you have headers, you can create a library from them
add_library(unit_converter_library ${UNIT_CONVETER_SOURCES})

# Link the libraries to your project
add_executable(runYourProject ${UNIT_CONVETER_SOURCES})
target_link_libraries(runYourProject unit_converter_library)

# Add your tests
add_executable(runUnitConverterTests tests/UnitConverter_test.cpp)
target_link_libraries(runUnitConverterTests gtest gtest_main unit_converter_library)

add_executable(runUserTests tests/User_test.cpp)
target_link_libraries(runUserTests gtest gtest_main unit_converter_library)

add_executable(runMenuFunctionsTests tests/MenuFunctions_test.cpp)
target_link_libraries(runMenuFunctionsTests gtest gtest_main unit_converter_library)