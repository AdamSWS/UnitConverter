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

        // If the input string is empty, throw an exception
        if (inputStr.empty())
        {
            throw std::invalid_argument("Input is empty. Try again.");
        }

        // If the input is too long to possibly fit in a long long, throw an exception
        if (inputStr.length() > 20)
        {
            throw std::invalid_argument("Input value is too large. Try again.");
        }

        std::istringstream iss(inputStr);
        iss >> value;

        // If the read operation failed, throw an exception
        if (iss.fail() || iss.peek() != EOF)
        {
            throw std::invalid_argument("Invalid input. Try again.");
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
        try
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
        catch (const std::invalid_argument &e)
        {
            cout << e.what() << '\n';
        }
    }
}

// Function to perform conversion based on selected units
void ConversionUtils::PerformConversion(User &user, MenuFunctions &menu, int conversionType,
                                        void (MenuFunctions::*displayFromMenu)(int), void (MenuFunctions::*displayToMenu)(int))
{
    try
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
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << '\n';
    }
}