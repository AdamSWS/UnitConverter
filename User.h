/* 
 * User.h
 * 
 * Manages the user's data and operations
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#ifndef USER_H
#define USER_H

#include "UnitConverter.h"
#include <iomanip>

using std::stringstream;
using std::fixed;
using std::max;
using std::setprecision;

class User {
 public:
  User();

  // Getter methods
  string GetConvertFromUnit() const;
  string GetConvertToUnit() const;
  double GetValueToConvert() const;
  int GetConversionType() const;
  string GetPreviousOperation() const;

  // Setter methods
  void SetConvertFromUnit(const string& unit);
  void SetConvertToUnit(const string& unit);
  void SetValueToConvert(double value);
  void SetConversionType(int type);
  void SetPreviousOperation(const string& operation);

  // Perform conversion and return the result
  double ConvertValue();

  // Display current state and details of the previous operation
  void DisplayUserStats() const;

  // Clear statistics
  void ClearStats();

 private:
  // Data members related to the conversion operation
  string convert_from_unit_;
  string convert_to_unit_;
  double value_to_convert_;
  int conversion_type_;  // 1 for length, 2 for temperature, etc.

  // Instance of the UnitConverter class for performing conversions
  UnitConverter converter_;

  // Details of the previous operation
  string previous_operation_;

  // Variables storing details of the previous operation
  double previous_value_;
  double previous_result_;
  string previous_convert_from_unit_;
  string previous_convert_to_unit_;
};

#endif  // USER_H