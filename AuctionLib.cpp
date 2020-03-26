/**
* Library for functions to be used in multiple files 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since February 26, 2020
* @version  1.2
* @name AuctionLib.cpp
*/

#include "AuctionLib.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>


/**
 * Converts a string all to lowercase
 */
std::string ToLower(std::string str) {
    std::string newString = str;

    std::transform(newString.begin(), newString.end(), newString.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return newString;
}

/**
 * Prints out x spaces
 */
std::string Spaces(int numSpaces) {
    std::string spaces = "";
    for(int i = 0; i < numSpaces; i++) {
        spaces += " ";
    }
    return spaces;
}

/**
 * Checks to see if the string is a valid decimal number
 */
bool IsDecimalNumber(std::string str) {
    bool hasDecimal = false;
    int i = 0;
    if(str[0] == '-') i = 1;    // If the number is negative
    while(str[i]){
        if(!isdigit(str[i])) {
            if(str[i] == '.' && hasDecimal == false) hasDecimal = true; // If the character is a decimal and the loop has not already encountered a decimal: 1.000
            else if(str[i] == '.' && hasDecimal == true) return false;  // If the character is a decimal and the loop has encountered a decimal: 1.0.00
            else return false;  // Character is not a digit or a decimal: 10ab
        }
        i++;
    }
    return true;
}

/**
 * Checks to see if the string is a valid number
 */
bool IsInteger(std::string str) {
    int i = 0;
    if(str[0] == '-') i = 1;    // If the number is negative
    while(str[i]) {
        if(!isdigit(str[i])) return false;  // Character is not a digit: 10ab
        i++;
    }
    return true;
}


/**
 * Checks to see if the string only contains numbers
 */
bool IsString(std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/**
 * Loop through a list of users to see if a name matches
 */
bool MatchUser(std::string** users, int numUsers, std::string name){
    for(int i = 0; i < numUsers; i++) if(users[i][0] == name) return true;
    return false;
}

/**
 * Creates a thick highlight
 */
void Highlight() {
    std::cout << "\n=========================================================\n";
}

/**
 * Creates a thick highlight
 */
void LightHighlight() {
    std::cout << "\n---------------------------------------------------------\n";
}

/**
 * Checks if input is "exit" or not
 */
bool exitCmd(string buffer){
    if (ToLower(buffer).compare(EXIT) == 0){
        return true;
    }else {
        return false;
    }
}

void TransactionTitle(string transaction) {
    Highlight();
    std::cout << Spaces(24) << transaction;
    Highlight();
}