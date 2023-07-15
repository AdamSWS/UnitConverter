/* 
 * MenuFunctions.h
 * 
 * Handles the display of menus and retrieval of selected unit names for the  conversion application.
 *
 * Author: Adam Shaar
 * Date: 7/19/2023
 */

#ifndef MENU_FUNCTIONS_H_
#define MENU_FUNCTIONS_H_

#include "User.h"

class MenuFunctions {
 public:
  // Function declarations for user interaction.
  void WelcomeMessage();
  void DisplayMainMenu();
  void DisplayLengthFromMenu(int page);
  void DisplayLengthToMenu(int page);
  void DisplayTemperatureFromMenu(int page);
  void DisplayTemperatureToMenu(int page);
  void DisplayAreaFromMenu(int page);
  void DisplayAreaToMenu(int page);
  void DisplayVolumeFromMenu(int page);
  void DisplayVolumeToMenu(int page);
  void DisplayWeightFromMenu(int page);
  void DisplayWeightToMenu(int page);
  void DisplayHelpMenu();
  std::string GetUnitName(int selected_type, int selected_page, int selected_unit);
  void ClearScreen();
  void BadEntry(const User& user);  // it's better to pass by reference when possible, and const if you're not modifying the object.
};

#endif  // MENU_FUNCTIONS_H_