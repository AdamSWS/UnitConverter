/* 
 * User_test.cpp
 * 
 * Tests for User.cpp
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */ 

#include "gtest/gtest.h"
#include "../ConversionUtils.h"

// Testing User Constructor
TEST(UserTest, ConstructorTest) {
    User user;

    EXPECT_EQ(user.GetConversionType(), 0);
    EXPECT_DOUBLE_EQ(user.GetValueToConvert(), 0.0);
    EXPECT_EQ(user.GetConvertFromUnit(), "NONE");
    EXPECT_EQ(user.GetConvertToUnit(), "NONE");
}

// Testing Setters and Getters
TEST(UserTest, SetterGetter_ConvertFromUnit) {
    User user;
    user.SetConvertFromUnit("meter");
    EXPECT_EQ(user.GetConvertFromUnit(), "meter");
}

TEST(UserTest, SetterGetter_ConvertToUnit) {
    User user;
    user.SetConvertToUnit("kilometer");
    EXPECT_EQ(user.GetConvertToUnit(), "kilometer");
}

TEST(UserTest, SetterGetter_ValueToConvert) {
    User user;
    user.SetValueToConvert(100.0);
    EXPECT_DOUBLE_EQ(user.GetValueToConvert(), 100.0);
}

TEST(UserTest, SetterGetter_ConversionType) {
    User user;
    user.SetConversionType(1);
    EXPECT_EQ(user.GetConversionType(), 1);
}

// Test for ConvertValue method
TEST(UserTest, ConvertValue_Length) {
    User user;
    user.SetConvertFromUnit("meter");
    user.SetConvertToUnit("kilometer");
    user.SetValueToConvert(1000.0);
    user.SetConversionType(1);

    EXPECT_DOUBLE_EQ(user.ConvertValue(), 1.0);
}

TEST(UserTest, ConvertValue_Temperature) {
    User user;
    user.SetConvertFromUnit("celsius");
    user.SetConvertToUnit("kelvin");
    user.SetValueToConvert(0.0);
    user.SetConversionType(2);

    EXPECT_DOUBLE_EQ(user.ConvertValue(), 273.15);
}

// Testing ClearStats method
TEST(UserTest, ClearStats) {
    User user;
    user.SetConvertFromUnit("meter");
    user.SetConvertToUnit("kilometer");
    user.SetValueToConvert(1000.0);
    user.SetConversionType(1);

    user.ClearStats();

    EXPECT_EQ(user.GetConversionType(), 0);
    EXPECT_DOUBLE_EQ(user.GetValueToConvert(), 0.0);
    EXPECT_EQ(user.GetConvertFromUnit(), "NONE");
    EXPECT_EQ(user.GetConvertToUnit(), "NONE");
}

// Testing SetPreviousOperation and GetPreviousOperation
TEST(UserTest, SetterGetter_PreviousOperation) {
    User user;
    user.SetPreviousOperation("2 meter -> 2 kilometer");
    EXPECT_EQ(user.GetPreviousOperation(), "2 meter -> 2 kilometer");
}