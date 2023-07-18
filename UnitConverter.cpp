/*
 * UnitConverter.cpp
 *
 * Implements the functionalities for performing unit conversion operations
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#include "UnitConverter.h"

UnitConverter::UnitConverter()
{
    // Populate the length conversion table
    length_to_meter_["meter"] = 1.0; // base unit
    length_to_meter_["kilometer"] = 0.001;
    length_to_meter_["centimeter"] = 100.0;
    length_to_meter_["megameter"] = 0.000001;
    length_to_meter_["decimeter"] = 10.0;
    length_to_meter_["millimeter"] = 1000.0;
    length_to_meter_["micrometer"] = 1000000.0;
    length_to_meter_["nanometer"] = 1000000000.0;
    length_to_meter_["mile"] = 0.000621371;
    length_to_meter_["yard"] = 1.09361;
    length_to_meter_["foot"] = 3.28084;
    length_to_meter_["inch"] = 39.3701;
    length_to_meter_["nautical_mile"] = 0.000539957;

    // Populate the temperature conversion table
    temperature_to_kelvin_["celsius"] = 1.0;
    temperature_to_kelvin_["fahrenheit"] = 1.0 / 1.8;
    temperature_to_kelvin_["kelvin"] = 1.0;

    // Populate the area conversion table
    area_to_square_meter_["square_meter"] = 1.0; // base unit
    area_to_square_meter_["square_kilometer"] = 0.000001;
    area_to_square_meter_["square_centimeter"] = 10000.0;

    // Populate the volume conversion table
    volume_to_cubic_meter_["cubic_meter"] = 1.0; // base unit
    volume_to_cubic_meter_["liter"] = 1000.0;
    volume_to_cubic_meter_["milliliter"] = 1000000.0;

    // Populate the weight conversion table
    weight_to_kilogram_["kilogram"] = 1.0; // base unit
    weight_to_kilogram_["gram"] = 1000.0;
    weight_to_kilogram_["metric_ton"] = 0.001;
    weight_to_kilogram_["milligram"] = 1000000.0;
    weight_to_kilogram_["microgram"] = 1000000000.0;
    weight_to_kilogram_["imperial_ton"] = 0.000984207;
    weight_to_kilogram_["us_ton"] = 0.00110231;
    weight_to_kilogram_["stone"] = 0.157473;
    weight_to_kilogram_["pound"] = 2.20462;
    weight_to_kilogram_["ounce"] = 35.274;
    weight_to_kilogram_["dram"] = 564.383;
}

// Add conversion methods as in the previous example...

string UnitConverter::PrintCalculation(double initialValue, const string &fromUnit, double finalValue, const string &toUnit, double initialConversionFactor, double finalConversionFactor)
{
    ostringstream calculation;
    calculation << "(" << initialValue << " " << fromUnit << ") * "
                << "(1 base unit / " << initialConversionFactor << " " << fromUnit << ") * "
                << "(" << finalConversionFactor << " " << toUnit << " / 1 base unit) = "
                << finalValue << " " << toUnit;

    return calculation.str();
}

// Convert length
double UnitConverter::ConvertLength(const string &fromUnit, const string &toUnit, double value)
{
    if (fromUnit == toUnit)
    {
        cout << "The units are the same. No conversion needed." << endl;
        return value;
    }
    double valueInMeters = value / length_to_meter_[fromUnit];
    double result = valueInMeters * length_to_meter_[toUnit];
    string calculation = PrintCalculation(value, fromUnit, result, toUnit, length_to_meter_[fromUnit], length_to_meter_[toUnit]);
    cout << calculation << endl;
    return result;
}

// Convert temperature
double UnitConverter::ConvertTemperature(const string &fromUnit, const string &toUnit, double value)
{
    if (fromUnit == toUnit)
    {
        cout << "The units are the same. No conversion needed." << endl;
        return value;
    }
    double valueInKelvin;
    if (fromUnit == "celsius")
    {
        valueInKelvin = value + 273.15;
    }
    else if (fromUnit == "fahrenheit")
    {
        valueInKelvin = (value + 459.67) * 5 / 9;
    }
    else
    {
        valueInKelvin = value;
    }
    double result;
    if (toUnit == "celsius")
    {
        result = valueInKelvin - 273.15;
    }
    else if (toUnit == "fahrenheit")
    {
        result = valueInKelvin * 9 / 5 - 459.67;
    }
    else
    {
        result = valueInKelvin;
    }
    string calculation = PrintCalculation(value, fromUnit, result, toUnit, 1.0, 1.0);
    cout << calculation << endl;
    return result;
}

// Convert area
double UnitConverter::ConvertArea(const string &fromUnit, const string &toUnit, double value)
{
    if (fromUnit == toUnit)
    {
        cout << "The units are the same. No conversion needed." << endl;
        return value;
    }
    double valueInSquareMeters = value / area_to_square_meter_[fromUnit];
    double result = valueInSquareMeters * area_to_square_meter_[toUnit];
    string calculation = PrintCalculation(value, fromUnit, result, toUnit, area_to_square_meter_[fromUnit], area_to_square_meter_[toUnit]);
    cout << calculation << endl;
    return result;
}

// Convert volume
double UnitConverter::ConvertVolume(const string &fromUnit, const string &toUnit, double value)
{
    if (fromUnit == toUnit)
    {
        cout << "The units are the same. No conversion needed." << endl;
        return value;
    }
    double valueInCubicMeters = value / volume_to_cubic_meter_[fromUnit];
    double result = valueInCubicMeters * volume_to_cubic_meter_[toUnit];
    string calculation = PrintCalculation(value, fromUnit, result, toUnit, volume_to_cubic_meter_[fromUnit], volume_to_cubic_meter_[toUnit]);
    cout << calculation << endl;
    return result;
}

// Convert weight
double UnitConverter::ConvertWeight(const string &fromUnit, const string &toUnit, double value)
{
    if (fromUnit == toUnit)
    {
        cout << "The units are the same. No conversion needed." << endl;
        return value;
    }
    double valueInKilograms = value / weight_to_kilogram_[fromUnit];
    double result = valueInKilograms * weight_to_kilogram_[toUnit];
    string calculation = PrintCalculation(value, fromUnit, result, toUnit, weight_to_kilogram_[fromUnit], weight_to_kilogram_[toUnit]);
    cout << calculation << endl;
    return result;
}