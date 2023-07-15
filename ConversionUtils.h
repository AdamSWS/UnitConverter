/* 
 * ConversionUtils.h
 * 
 * Utility functions for conversions
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#ifndef CONVERSION_UTILS_H
#define CONVERSION_UTILS_H

#include <limits>
#include <istream>
#include "MenuFunctions.h"

using std::cin;

class ConversionUtils {
public:
    // Function to pause the program and wait for the user to press enter
    void WaitForUser();

    // Function to safely input a value, throwing an exception if the input is invalid
    template <typename T>
    void SafeRead(std::istream &in, T &value);

    // Function to select a unit from the menu
    void SelectUnit(User &user, MenuFunctions &menu, int conversion_type,
                    void (MenuFunctions::*display_menu)(int), bool is_from_unit);

    // Function to perform conversion based on selected units
    void PerformConversion(User &user, MenuFunctions &menu, int conversion_type,
                        void (MenuFunctions::*display_from_menu)(int), void (MenuFunctions::*display_to_menu)(int));

};  // namespace ConversionUtils

#endif  // CONVERSION_UTILS_H