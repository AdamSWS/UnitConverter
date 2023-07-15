/* 
 * MenuFunctions_test.cpp
 * 
 * Tests for MenuFunctions.cpp
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */ 

#include "../MenuFunctions.h"
#include "gtest/gtest.h"

using std::make_tuple;
using std::tuple;
using std::get;

class MenuFunctionsTest : public ::testing::TestWithParam<tuple<int, int, int, string>> {};

TEST_P(MenuFunctionsTest, GetUnitNameTest) {
    MenuFunctions menuFunctions;
    auto inputs = GetParam();
    string actual = menuFunctions.GetUnitName(get<0>(inputs), get<1>(inputs), get<2>(inputs));
    string expected = get<3>(inputs);
    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(UnitNames, MenuFunctionsTest, 
    ::testing::Values(
        // Length
        make_tuple(1, 1, 1, "meter"),
        make_tuple(1, 1, 2, "kilometer"),
        make_tuple(1, 1, 3, "centimeter"),
        make_tuple(1, 1, 4, "megameter"),
        make_tuple(1, 1, 5, "decimeter"),
        make_tuple(1, 1, 6, "millimeter"),
        make_tuple(1, 1, 7, "micrometer"),
        make_tuple(1, 2, 1, "nanometer"),
        make_tuple(1, 2, 2, "mile"),
        make_tuple(1, 2, 3, "yard"),
        make_tuple(1, 2, 4, "foot"),
        make_tuple(1, 2, 5, "inch"),
        make_tuple(1, 2, 6, "nautical_mile"),
        
        // Temperature
        make_tuple(2, 0, 1, "celsius"),
        make_tuple(2, 0, 2, "fahrenheit"),
        make_tuple(2, 0, 3, "kelvin"),

        // Area
        make_tuple(3, 0, 1, "square_meter"),
        make_tuple(3, 0, 2, "square_kilometer"),
        make_tuple(3, 0, 3, "square_centimeter"),

        // Volume
        make_tuple(4, 0, 1, "cubic_meter"),
        make_tuple(4, 0, 2, "liter"),
        make_tuple(4, 0, 3, "milliliter"),

        // Weight
        make_tuple(5, 1, 1, "gram"),
        make_tuple(5, 1, 2, "kilogram"),
        make_tuple(5, 1, 3, "metric_ton"),
        make_tuple(5, 1, 4, "milligram"),
        make_tuple(5, 1, 5, "microgram"),
        make_tuple(5, 1, 6, "imperial_ton"),
        make_tuple(5, 1, 7, "us_ton"),
        make_tuple(5, 2, 1, "stone"),
        make_tuple(5, 2, 2, "pound"),
        make_tuple(5, 2, 3, "ounce"),
        make_tuple(5, 2, 4, "dram"),

        // Invalid cases
        make_tuple(0, 0, 0, "invalid"),
        make_tuple(6, 1, 1, "invalid"),
        make_tuple(1, 3, 1, "invalid"),
        make_tuple(1, 1, 8, "invalid")
    )
);