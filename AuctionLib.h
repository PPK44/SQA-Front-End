/**
* Function declarations for functions to be used in multiple files
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @since February 26, 2020
* @version  1.2
* @name AuctionLib.h
*/

#include <string>
#include "Users.h"

#ifndef _AUCTIONLIB_H
#define _AUCTIONLIB_H

// Constants
const std::string YES = "yes";
const std::string NO = "no";
const std::string DISABLE = "disable";
const std::string ENABLE = "enable";
const std::string DISABLED_CODE = "DS";
const string FULL_STANDARD = "FS";
const string SELL_STANDARD = "SS";
const string BUY_STANDARD = "BS";
const std::string EXIT = "exit";
const short MAX_ITEM_NAME_LENGTH = 19;
const short MAX_USER_NAME_LENGTH = 15;
const short MAX_PASSWORD_LENGTH = 12;
const short MAX_CREDIT_LENGTH = 9;
const float MAX_BID = 999.99f;
const float MIN_BID = 0.01f;

std::string ToLower(std::string str);
std::string Spaces(int numSpaces);

bool IsDecimalNumber(std::string str);
bool IsInteger(std::string str);
bool IsString(std::string str);
bool MatchUser(std::string** users, int numUsers, std::string name);

bool exitCmd(std::string buffer);

void Highlight();
void LightHighlight();
void TransactionTitle(string transaction);

#endif