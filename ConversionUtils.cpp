/*
 * ConversionUtils.cpp
 *
 * Utility functions for conversions
 *
 * Author: Adam Shaar
 * Date Created: 7/15/2023
 * Last Updated: 7/17/2023
 */

#include "ConversionUtils.h"

// Function to pause the program and wait for the user to press enter
void ConversionUtils::WaitForUser()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
void ConversionUtils::SafeRead(std::istream &in, T &value)
{
    while (true)
    {
        std::string inputStr;
        getline(in, inputStr);

        // If the input string is empty, consider it as an invalid input
        if (inputStr.empty())
        {
            std::cout << "Input is empty. Try again: ";
            continue;
        }

        // Check if the input is too long to possibly fit in a long long
        // 19 is the max number of digits a long long can have
        // +1 for the possible negative sign
        if (inputStr.length() > 20)
        {
            std::cout << "Input value is too large. Try again: ";
            continue;
        }

        std::istringstream iss(inputStr);
        iss >> value;

        // If the read operation failed, the input is invalid
        if (iss.fail() || iss.peek() != EOF)
        {
            std::cout << "Invalid input. Try again: ";
            continue;
        }
        // After successfully reading a value, clear the input buffer completely
        in.clear();
        break;
    }
}

// Function to select a unit from the menu
void ConversionUtils::SelectUnit(User &user, MenuFunctions &menu, int conversionType,
                                 void (MenuFunctions::*displayMenu)(int), bool isFromUnit)
{
    int page = 1;
    int unit;

    while (true)
    {
        menu.ClearScreen();
        user.DisplayUserStats();
        (menu.*displayMenu)(page);
        cout << "Select the " << (isFromUnit ? "starting" : "ending") << " unit: ";
        SafeRead(cin, unit);

        if (isFromUnit)
            user.SetConvertFromUnit(menu.GetUnitName(conversionType, page, unit));
        else
            user.SetConvertToUnit(menu.GetUnitName(conversionType, page, unit));

        if (unit >= 1 && unit <= 7)
            break;
        else if (unit == 8)
            page++;
        else if (unit == 9 && page > 1)
            page--;
        else
            menu.BadEntry(user);
    }
}

// Function to perform conversion based on selected units
void ConversionUtils::PerformConversion(User &user, MenuFunctions &menu, int conversionType,
                                        void (MenuFunctions::*displayFromMenu)(int), void (MenuFunctions::*displayToMenu)(int))
{
    SelectUnit(user, menu, conversionType, displayFromMenu, true);
    SelectUnit(user, menu, conversionType, displayToMenu, false);

    double value;
    cout << "Enter the value to convert: ";
    SafeRead(cin, value);
    user.SetConversionType(conversionType);
    user.SetValueToConvert(value);

    double result = user.ConvertValue();

    cout << "The result is: " << result << " " << user.GetConvertToUnit() << endl;
    user.ClearStats();
    WaitForUser();
}