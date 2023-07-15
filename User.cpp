/* 
 * User.cpp
 * 
 * Manages the user's data and operations
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#include "User.h"

// Default constructor
User::User() : conversion_type_(0), value_to_convert_(0.0), convert_from_unit_("NONE"), convert_to_unit_("NONE") {}

// Setters
void User::SetConvertFromUnit(const string &unit) { 
    convert_from_unit_ = unit; 
}

void User::SetConvertToUnit(const string &unit) { 
    convert_to_unit_ = unit; 
}

void User::SetValueToConvert(double value) { 
    value_to_convert_ = value; 
}

void User::SetConversionType(int type) { 
    conversion_type_ = type; 
}

// Getters
string User::GetConvertFromUnit() const { 
    return convert_from_unit_; 
}

string User::GetConvertToUnit() const { 
    return convert_to_unit_; 
}

double User::GetValueToConvert() const { 
    return value_to_convert_; 
}

int User::GetConversionType() const { 
    return conversion_type_; 
}

// Display user's current and previous conversion details
void User::DisplayUserStats() const {
    // stringstream used to control precision of float values
    stringstream val_convert, prev_op;
    val_convert << fixed << setprecision(1) << value_to_convert_;
    prev_op << fixed << setprecision(1) << previous_value_ << " " 
            << previous_convert_from_unit_ << " -> " << previous_result_ << " " 
            << previous_convert_to_unit_;

    // Prepare details
    string lines[5] = {
        "Current Stats:",
        "Starting Unit: " + convert_from_unit_,
        "Target Unit: " + convert_to_unit_,
        "Value to Convert: " + val_convert.str(),
        "Previous Operation: " + prev_op.str()
    };

    // Determine maximum line length for neat display
    size_t max_length = 0;
    for (int i = 0; i < 5; i++) {
        max_length = max(max_length, lines[i].size());
    }

    // Display user stats
    string border(max_length + 4, '*');
    cout << border << "\n";
    for (int i = 0; i < 5; i++) {
        cout << "* " << lines[i] << string(max_length - lines[i].size(), ' ') << " *\n";
    }
    cout << border << "\n\n";
}

// Perform conversion based on set parameters
double User::ConvertValue() {
    double result = 0.0;
    switch (conversion_type_) {
    case 1:
        result = converter_.ConvertLength(convert_from_unit_, convert_to_unit_, value_to_convert_);
        break;
    case 2:
        result = converter_.ConvertTemperature(convert_from_unit_, convert_to_unit_, value_to_convert_);
        break;
    case 3:
        result = converter_.ConvertArea(convert_from_unit_, convert_to_unit_, value_to_convert_);
        break;
    case 4:
        result = converter_.ConvertVolume(convert_from_unit_, convert_to_unit_, value_to_convert_);
        break;
    case 5:
        result = converter_.ConvertWeight(convert_from_unit_, convert_to_unit_, value_to_convert_);
        break;
    default:
        cout << "Invalid conversion type!" << endl;
        break;
    }

    // Store conversion result for future reference
    previous_value_ = value_to_convert_;
    previous_convert_from_unit_ = convert_from_unit_;
    previous_result_ = result;  
    previous_convert_to_unit_ = convert_to_unit_;
    return result;
}

// Reset stats
void User::ClearStats() {
    conversion_type_ = 0;
    value_to_convert_ = 0.0;
    convert_from_unit_ = "NONE";
    convert_to_unit_ = "NONE";
}

// Previous operation setters and getters
void User::SetPreviousOperation(const string &operation) {
    previous_operation_ = operation;
}

string User::GetPreviousOperation() const {
    return previous_operation_;
}
