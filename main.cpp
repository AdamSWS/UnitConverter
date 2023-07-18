/* 
 * main.cpp
 * 
 * Main driver program for the conversion application
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#include "ConversionUtils.h"

using std::cin;

// Main function where the program starts
int main()
{
    ConversionUtils utility;
    MenuFunctions menu;
    User user;

    menu.ClearScreen();
    user.DisplayUserStats();
    menu.WelcomeMessage();
    utility.WaitForUser();

    while (1)
    {
        int user_input;
        menu.ClearScreen();
        user.DisplayUserStats();
        menu.DisplayMainMenu();
        utility.SafeRead(cin, user_input);
        // Switch block for different menu options
        switch (user_input)
        {
        case 1: // Length conversion
            utility.PerformConversion(user, menu, 1, &MenuFunctions::DisplayLengthFromMenu, &MenuFunctions::DisplayLengthToMenu);
            break;
        case 2: // Temperature conversion
            utility.PerformConversion(user, menu, 2, &MenuFunctions::DisplayTemperatureFromMenu, &MenuFunctions::DisplayTemperatureToMenu);
            break;
        case 3: // Area conversion
            utility.PerformConversion(user, menu, 3, &MenuFunctions::DisplayAreaFromMenu, &MenuFunctions::DisplayAreaToMenu);
            break;
        case 4: // Volume conversion
            utility.PerformConversion(user, menu, 4, &MenuFunctions::DisplayVolumeFromMenu, &MenuFunctions::DisplayVolumeToMenu);
            break;
        case 5: // Weight conversion
            utility.PerformConversion(user, menu, 5, &MenuFunctions::DisplayWeightFromMenu, &MenuFunctions::DisplayWeightToMenu);
            break;
        case 6: // Display help menu
            menu.DisplayHelpMenu();
            utility.WaitForUser();
            break;
        case 7: // Exit
            menu.ClearScreen();
            cout << "Thank you for converting with us!\n\n";
            return 0;
        default: // Invalid entry
            menu.BadEntry(user);
            break;
        }
    }

    return 0;
}
