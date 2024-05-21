#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <unordered_map>

extern std::unordered_map<std::string, std::string> adminAccounts;

void clearScreen();
void setColor(int color);
void resetColor();
void welcomePage();
bool registerAdmin();
bool adminLogin();
void adminOptions();

#endif // LOGIN_H
