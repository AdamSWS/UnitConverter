/* 
 * UnitConverter.h
 * 
 * Implements the functionalities for performing unit conversion operations
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#ifndef UNIT_CONVERTER_H_
#define UNIT_CONVERTER_H_

#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;
using std::ostringstream;

// UnitConverter class for various units conversion
class UnitConverter {
 public:
  // Default constructor
  UnitConverter();

  // Convert length from one unit to another
  double ConvertLength(const string& from_unit, const string& to_unit, double value);

  // Convert temperature from one unit to another
  double ConvertTemperature(const string& from_unit, const string& to_unit, double value);

  // Convert area from one unit to another
  double ConvertArea(const string& from_unit, const string& to_unit, double value);

  // Convert volume from one unit to another
  double ConvertVolume(const string& from_unit, const string& to_unit, double value);

  // Convert weight from one unit to another
  double ConvertWeight(const string& from_unit, const string& to_unit, double value);

  // Print calculation details
  string PrintCalculation(double initial_value, const string& from_unit, double final_value, 
                               const string& to_unit, double initial_conversion_factor, 
                               double final_conversion_factor);

 private:
  // Maps unit to their conversion factors
  unordered_map<string, double> length_to_meter_;
  unordered_map<string, double> temperature_to_kelvin_;
  unordered_map<string, double> area_to_square_meter_;
  unordered_map<string, double> volume_to_cubic_meter_;
  unordered_map<string, double> weight_to_kilogram_;
};

#endif  // UNIT_CONVERTER_H_
