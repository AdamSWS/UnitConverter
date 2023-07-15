/* 
 * ConversionUtils.cpp
 * 
 * Utility functions for conversions
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#include "ConversionUtils.h"

// Function to pause the program and wait for the user to press enter
void ConversionUtils::WaitForUser()
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Function to safely input a value, throwing an exception if the input is invalid
template <typename T>
void ConversionUtils::SafeRead(std::istream &in, T &value)
{
    while (true)
    {
        in >> value;
        if (!in || (in.peek() != '\n' && in.peek() != EOF))
        {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\nTry again: ";
            continue;
        }
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
    user.SetValueToConvert(value);

    double result = user.ConvertValue();

    cout << "The result is: " << result << " " << user.GetConvertToUnit() << endl;
    user.ClearStats();
    WaitForUser();
}