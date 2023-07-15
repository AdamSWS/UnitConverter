/* 
 * MenuFunctions.cpp
 * 
 * Handles the display of menus and retrieval of selected unit names for the  conversion application.
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#include "MenuFunctions.h"

void MenuFunctions::WelcomeMessage()
{
    cout << "==================================================\n\t\tEZ UNIT CONVERTER\n==================================================\n\n";
    cout << "Welcome to EZ Unit Converter!\n\n";
    cout << "This program allows you to easily convert between various units of measurement such as length, weight, temperature, and more. \n\n";
    cout << "Please follow the on-screen instructions and let's get converting!\n\n";
    cout << "Type '6' for instructions or '7' to quit the program.\n\n";
}

void MenuFunctions::DisplayMainMenu()
{
    cout << "Choose a category of measurement for conversion:\n";
    cout << "1. Length Conversion Menu\n";
    cout << "2. Temperature Conversion Menu\n";
    cout << "3. Area Conversion Menu\n";
    cout << "4. Volume Conversion Menu\n";
    cout << "5. Weight Conversion Menu\n";
    cout << "6. Help Menu\n";
    cout << "7. Exit\n";
}

void MenuFunctions::DisplayLengthFromMenu(int page)
{
    const int totalPages = 2;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/2) Select a starting unit to convert from.\n";
        cout << "1. Meter(m)\n";
        cout << "2. Kilometer(km)\n";
        cout << "3. Centimeter(cm)\n";
        cout << "4. Megameter(Mm)\n";
        cout << "5. Decimeter(dm)\n";
        cout << "6. Millimeter(mm)\n";
        cout << "7. Micrometer(um)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    case 2:
        cout << "(Page 2/2) Select a starting unit to convert from.\n";
        cout << "1. Nanometer(nm)\n";
        cout << "2. Mile(mi)\n";
        cout << "3. Yard(yd)\n";
        cout << "4. Foot(ft)\n";
        cout << "5. Inch(in)\n";
        cout << "6. Nautical Mile(nmi)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayLengthToMenu(int page)
{
    const int totalPages = 2;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/2) Select a target unit to convert to.\n";
        cout << "1. Meter(m)\n";
        cout << "2. Kilometer(km)\n";
        cout << "3. Centimeter(cm)\n";
        cout << "4. Megameter(Mm)\n";
        cout << "5. Decimeter(dm)\n";
        cout << "6. Millimeter(mm)\n";
        cout << "7. Micrometer(um)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    case 2:
        cout << "(Page 2/2) Select a target unit to convert to.\n";
        cout << "1. Nanometer(nm)\n";
        cout << "2. Mile(mi)\n";
        cout << "3. Yard(yd)\n";
        cout << "4. Foot(ft)\n";
        cout << "5. Inch(in)\n";
        cout << "6. Nautical Mile(nmi)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayTemperatureFromMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a starting temperature unit to convert from.\n";
        cout << "1. Celsius\n";
        cout << "2. Fahrenheit\n";
        cout << "3. Kelvin\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayTemperatureToMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a target temperature unit to convert to.\n";
        cout << "1. Celsius\n";
        cout << "2. Fahrenheit\n";
        cout << "3. Kelvin\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayAreaFromMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a starting area unit to convert from.\n";
        cout << "1. Square Meter\n";
        cout << "2. Square Kilometer\n";
        cout << "3. Square Centimeter\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayAreaToMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a target area unit to convert to.\n";
        cout << "1. Square Meter\n";
        cout << "2. Square Kilometer\n";
        cout << "3. Square Centimeter\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayVolumeFromMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a starting volume unit to convert from.\n";
        cout << "1. Cubic Meter\n";
        cout << "2. Liter\n";
        cout << "3. Milliliter\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayVolumeToMenu(int page)
{
    const int totalPages = 1;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/1) Select a target volume unit to convert to.\n";
        cout << "1. Cubic Meter\n";
        cout << "2. Liter\n";
        cout << "3. Milliliter\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayWeightFromMenu(int page)
{
    const int totalPages = 2;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/2) Select a starting weight unit to convert from.\n";
        cout << "1. Gram(g)\n";
        cout << "2. Kilogram(kg)\n";
        cout << "3. Metric Ton(t)\n";
        cout << "4. Milligram(mg)\n";
        cout << "5. Microgram(ug)\n";
        cout << "6. Imperial Ton\n";
        cout << "7. US Ton\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    case 2:
        cout << "(Page 2/2) Select a starting weight unit to convert from.\n";
        cout << "1. Stone(st)\n";
        cout << "2. Pound(lb)\n";
        cout << "3. Ounce(oz)\n";
        cout << "4. Dram(dr)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayWeightToMenu(int page)
{
    const int totalPages = 2;
    page = (page - 1) % totalPages + 1;

    switch (page)
    {
    case 1:
        cout << "(Page 1/2) Select a target weight unit to convert to.\n";
        cout << "1. Gram(g)\n";
        cout << "2. Kilogram(kg)\n";
        cout << "3. Metric Ton(t)\n";
        cout << "4. Milligram(mg)\n";
        cout << "5. Microgram(ug)\n";
        cout << "6. Imperial Ton\n";
        cout << "7. US Ton\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    case 2:
        cout << "(Page 2/2) Select a target weight unit to convert to.\n";
        cout << "1. Stone(st)\n";
        cout << "2. Pound(lb)\n";
        cout << "3. Ounce(oz)\n";
        cout << "4. Dram(dr)\n";
        if (totalPages > 1)
            cout << "8) Next\n";
        break;

    default:
        cout << "Invalid page number." << endl;
    }
}

void MenuFunctions::DisplayHelpMenu()
{
    ClearScreen();
    std::cout << "*****************************************************\n"
              << "*                    HELP MENU                      *\n"
              << "*****************************************************\n"
              << "* Using this program, you can convert a number from *\n"
              << "* one unit of measurement to another. Here's how:   *\n"
              << "*                                                   *\n"
              << "* 1. Select the type of conversion (e.g., length,   *\n"
              << "*    mass, volume, etc.) from the main menu.        *\n"
              << "*                                                   *\n"
              << "* 2. Select the unit you're converting from.        *\n"
              << "*                                                   *\n"
              << "* 3. Select the unit you're converting to.          *\n"
              << "*                                                   *\n"
              << "* 4. Enter the value you want to convert.           *\n"
              << "*                                                   *\n"
              << "* The program will then display the converted value.*\n"
              << "*                                                   *\n"
              << "* Want to learn more about unit conversions?        *\n"
              << "* Here are a few resources:                         *\n"
              << "*                                                   *\n"
              << "* - Khan Academy:                                   *\n"
              << "*   https://www.khanacademy.org/science/physics     *\n"
              << "*                                                   *\n"
              << "* - NIST Reference on Constants, Units, and         *\n"
              << "*   Uncertainty:                                    *\n"
              << "*   https://physics.nist.gov/cuu/Units/index.html   *\n"
              << "*****************************************************\n";
}

std::string MenuFunctions::GetUnitName(int selected_type, int selected_page, int selected_unit)
{
    switch (selected_type)
    {
    case 1: // Length
    {
        switch (selected_page)
        {
        case 1:
        {
            switch (selected_unit)
            {
            case 1:
                return "meter";
            case 2:
                return "kilometer";
            case 3:
                return "centimeter";
            case 4:
                return "megameter";
            case 5:
                return "decimeter";
            case 6:
                return "millimeter";
            case 7:
                return "micrometer";
            }
        }
        case 2:
        {
            switch (selected_unit)
            {
            case 1:
                return "nanometer";
            case 2:
                return "mile";
            case 3:
                return "yard";
            case 4:
                return "foot";
            case 5:
                return "inch";
            case 6:
                return "nautical_mile";
            }
        }
        }
        break;
    }
    case 2: // Temperature
    {
        switch (selected_unit)
        {
        case 1:
            return "celsius";
        case 2:
            return "fahrenheit";
        case 3:
            return "kelvin";
        }
        break;
    }
    case 3: // Area
    {
        switch (selected_unit)
        {
        case 1:
            return "square_meter";
        case 2:
            return "square_kilometer";
        case 3:
            return "square_centimeter";
        }
        break;
    }
    case 4: // Volume
    {
        switch (selected_unit)
        {
        case 1:
            return "cubic_meter";
        case 2:
            return "liter";
        case 3:
            return "milliliter";
        }
        break;
    }
    case 5: // Weight
    {
        switch (selected_page)
        {
        case 1:
        {
            switch (selected_unit)
            {
            case 1:
                return "gram";
            case 2:
                return "kilogram";
            case 3:
                return "metric_ton";
            case 4:
                return "milligram";
            case 5:
                return "microgram";
            case 6:
                return "imperial_ton";
            case 7:
                return "us_ton";
            }
        }
        case 2:
        {
            switch (selected_unit)
            {
            case 1:
                return "stone";
            case 2:
                return "pound";
            case 3:
                return "ounce";
            case 4:
                return "dram";
            }
        }
        }
        break;
    }
    }
    return "invalid";
}

void MenuFunctions::BadEntry(const User& user)
{
    ClearScreen();
    user.DisplayUserStats();
    cout << "Invalid Entry." << endl;
}

void MenuFunctions::ClearScreen()
{
    cout << string(100, '\n');
}
