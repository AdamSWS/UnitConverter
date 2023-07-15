/* 
 * UnitConverter_test.cpp
 * 
 * Tests for UnitConverter.cpp
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */ 

#include "gtest/gtest.h"
#include "../ConversionUtils.h"

// Length Conversion Tests
TEST(LengthConversionTest, MeterToKilometer) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "kilometer", 1000.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, KilometerToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("kilometer", "meter", 1.0);
    EXPECT_NEAR(result, 1000.0, 0.001);
}

TEST(LengthConversionTest, CentimeterToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("centimeter", "meter", 100.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, MeterToCentimeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "centimeter", 1.0);
    EXPECT_NEAR(result, 100.0, 0.001);
}

TEST(LengthConversionTest, MileToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("mile", "meter", 1.0);
    EXPECT_NEAR(result, 1609.34, 0.01);
}

TEST(LengthConversionTest, MeterToMile) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "mile", 1609.34);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, YardToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("yard", "meter", 1.0);
    EXPECT_NEAR(result, 0.9144, 0.001);
}

TEST(LengthConversionTest, MeterToYard) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "yard", 0.9144);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, FootToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("foot", "meter", 1.0);
    EXPECT_NEAR(result, 0.3048, 0.001);
}

TEST(LengthConversionTest, MeterToFoot) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "foot", 0.3048);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, InchToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("inch", "meter", 1.0);
    EXPECT_NEAR(result, 0.0254, 0.001);
}

TEST(LengthConversionTest, MeterToInch) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "inch", 0.0254);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, NauticalMileToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("nautical_mile", "meter", 1.0);
    EXPECT_NEAR(result, 1852.0, 0.01);
}

TEST(LengthConversionTest, MeterToNauticalMile) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "nautical_mile", 1852.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, DecimeterToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("decimeter", "meter", 10.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, MeterToDecimeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "decimeter", 1.0);
    EXPECT_NEAR(result, 10.0, 0.001);
}

TEST(LengthConversionTest, MicrometerToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("micrometer", "meter", 1000000.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, MeterToMicrometer) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "micrometer", 1.0);
    EXPECT_NEAR(result, 1000000.0, 0.001);
}

TEST(LengthConversionTest, NanometerToMeter) {
    UnitConverter converter;
    double result = converter.ConvertLength("nanometer", "meter", 1000000000.0);
    EXPECT_NEAR(result, 1.0, 0.001);
}

TEST(LengthConversionTest, MeterToNanometer) {
    UnitConverter converter;
    double result = converter.ConvertLength("meter", "nanometer", 1.0);
    EXPECT_NEAR(result, 1000000000.0, 0.001);
}

// Tempature Conversion Tests
TEST(TempatureConversionTest, CelsiusToFahrenheit) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("celsius", "fahrenheit", 0.0);
    EXPECT_NEAR(result, 32.0, 0.001);
}

TEST(TempatureConversionTest, FahrenheitToCelsius) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("fahrenheit", "celsius", 32.0);
    EXPECT_NEAR(result, 0.0, 0.001);
}

TEST(TempatureConversionTest, CelsiusToKelvin) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("celsius", "kelvin", 0.0);
    EXPECT_NEAR(result, 273.15, 0.001);
}

TEST(TempatureConversionTest, KelvinToCelsius) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("kelvin", "celsius", 273.15);
    EXPECT_NEAR(result, 0.0, 0.001);
}

TEST(TempatureConversionTest, FahrenheitToKelvin) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("fahrenheit", "kelvin", 32.0);
    EXPECT_NEAR(result, 273.15, 0.001);
}

TEST(TempatureConversionTest, KelvinToFahrenheit) {
    UnitConverter converter;
    double result = converter.ConvertTemperature("kelvin", "fahrenheit", 273.15);
    EXPECT_NEAR(result, 32.0, 0.001);
}

// Area Conversion test
// Test converting square meters to square kilometers
TEST(AreaConversionTest, MetersToKilometers) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_meter", "square_kilometer", 1000000.0), 1.0, 1e-6);
}

// Test converting square meters to square centimeters
TEST(AreaConversionTest, MetersToCentimeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_meter", "square_centimeter", 1.0), 10000.0, 1e-6);
}

// Test converting square kilometers to square meters
TEST(AreaConversionTest, KilometersToMeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_kilometer", "square_meter", 1.0), 1000000.0, 1e-6);
}

// Test converting square kilometers to square centimeters
TEST(AreaConversionTest, KilometersToCentimeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_kilometer", "square_centimeter", 1.0), 10000000000.0, 0.000001);
}

// Test converting square centimeters to square meters
TEST(AreaConversionTest, CentimetersToMeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_centimeter", "square_meter", 10000.0), 1.0, 1e-6);
}

// Test converting square centimeters to square kilometers
TEST(AreaConversionTest, CentimetersToKilometers) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertArea("square_centimeter", "square_kilometer", 10000000000.0), 1.0, 0.000001);
}

// Tests for Volume
TEST(VolumeConversionTest, MetersToLiters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("cubic_meter", "liter", 1.0), 1000.0, 1e-6);
}

// Test converting cubic meters to milliliters
TEST(VolumeConversionTest, MetersToMilliliters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("cubic_meter", "milliliter", 1.0), 1000000.0, 1e-6);
}

// Test converting liters to cubic meters
TEST(VolumeConversionTest, LitersToMeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("liter", "cubic_meter", 1000.0), 1.0, 1e-6);
}

// Test converting liters to milliliters
TEST(VolumeConversionTest, LitersToMilliliters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("liter", "milliliter", 1.0), 1000.0, 1e-6);
}

// Test converting milliliters to cubic meters
TEST(VolumeConversionTest, MillilitersToMeters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("milliliter", "cubic_meter", 1000000.0), 1.0, 1e-6);
}

// Test converting milliliters to liters
TEST(VolumeConversionTest, MillilitersToLiters) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertVolume("milliliter", "liter", 1000.0), 1.0, 1e-6);
}

// Tests for weights

// Test converting grams to kilograms
TEST(WeightConversionTest, GramsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("gram", "kilogram", 1000.0), 1.0, 1e-6);
}

// Test converting metric tons to kilograms
TEST(WeightConversionTest, MetricTonsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("metric_ton", "kilogram", 0.001), 1.0, 1e-6);
}

// Test converting milligrams to kilograms
TEST(WeightConversionTest, MilligramsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("milligram", "kilogram", 1000000.0), 1.0, 1e-6);
}

// Test converting micrograms to kilograms
TEST(WeightConversionTest, MicrogramsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("microgram", "kilogram", 1000000000.0), 1.0, 1e-6);
}

// Test converting imperial tons to kilograms
TEST(WeightConversionTest, ImperialTonsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("imperial_ton", "kilogram", 0.000984207), 1.0, 1e-6);
}

// Test converting US tons to kilograms
TEST(WeightConversionTest, USTonsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("us_ton", "kilogram", 0.00110231), 1.0, 1e-6);
}

// Test converting stones to kilograms
TEST(WeightConversionTest, StonesToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("stone", "kilogram", 0.157473), 1.0, 1e-6);
}

// Test converting pounds to kilograms
TEST(WeightConversionTest, PoundsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("pound", "kilogram", 2.20462), 1.0, 1e-6);
}

// Test converting ounces to kilograms
TEST(WeightConversionTest, OuncesToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("ounce", "kilogram", 35.274), 1.0, 1e-6);
}

// Test converting drams to kilograms
TEST(WeightConversionTest, DramsToKilograms) {
    UnitConverter converter;
    EXPECT_NEAR(converter.ConvertWeight("dram", "kilogram", 564.383), 1.0, 1e-6);
}