/**
* Admin function definition for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Admin.cpp
*/

#include "Admin.h"
#include "Users.h"
#include "Writer.h"
#include "AuctionLib.h"
#include <string>

Admin::Admin(){
    
}
void EnableDuplicate(string, Users, string);
inline void UserNotFound(std::string user) {
    LightHighlight();
    std::cout << Spaces(12)
                << "User " << user << " does not exist.";
    Highlight();
}

void Admin::AddCredits(){

};

void Admin::DeleteUser(std::string** users, int numUsers, string transactionFile){
    string username, buffer = "";
    bool userFound, confirm = false;
    Writer writer;
    Users user;
    string userType;
    string credits;
    const string code = "02";
    string title = "DELETE";

		TransactionTitle(title);

    std::cout << "\nEnter username: ";
    getline(cin, username);

    // Loops through the users to see if the usernames match

    for(int i = 0; i < numUsers; i++) if(users[i][0] == username){
         userFound = true;
         userType = users[i][2];
         credits = users[i][3];
    }
    userFound = MatchUser(users, numUsers, username);

    // If a user was found that matches the username
    if(userFound == false) {
        UserNotFound(username);
    } else {
        while(confirm == false) {
            std::cout << "\nAre you sure you want to delete user " << username << "?"
                    << endl
                    << "(Yes/No): ";
            getline(cin, buffer);
            // User confirms to delete the user
            if(ToLower(buffer).compare(YES) == 0) {
                LightHighlight();
                
                std::cout << Spaces(12)
                        << username << " has been successfully deleted!";
                Highlight();
                user.setUserName(username);
                user.setUserType(userType);
                user.setCredits(stof(credits));
                writer.GenericWriteToDailyTransactionFile(user, code, transactionFile);
                confirm = true;
            } else if(ToLower(buffer).compare(NO) == 0) {
                LightHighlight();
                std::cout << Spaces(16)
                        << "Delete process aborted."
                        << endl << Spaces(12)
                        << username << " was not deleted.";
                Highlight();
                confirm = true;
            } else {
                LightHighlight();
                std::cout << Spaces(18)
                        << "Invalid Confirmation.";
                Highlight();
                confirm = true;
            }
        }
    }
}

void Admin::Update(string** users, int numUsers, string transactionFile){
    string buffer = "";
    string title = "UPDATE";

		TransactionTitle(title);
    std::cout << "Would you like to enable or disable a user?: ";
    getline(cin, buffer);
    if(ToLower(buffer).compare(DISABLE) == 0) DisableUser(users, numUsers, transactionFile);
    else if(ToLower(buffer).compare(ENABLE) == 0) EnableUser(users, numUsers, transactionFile);
    else {
        LightHighlight();
        std::cout << Spaces(18) << "Invalid option";
        Highlight();
    }
}

void Admin::EnableUser(string** users, int numUsers, string transactionFile){
    
    string buffer = "";
    string userType = "";
    Users user;
    
    bool userFound, confirm = false;
    std::cout << endl
              << "Which user would you like to enable?: ";
    getline(cin, buffer);

    for(int i = 0; i < numUsers; i++) {
        if(users[i][0] == buffer) {
            userFound = true;
            user.setUserName(users[i][0]);
            user.setUserType(users[i][2]);
            user.setCredits(stof(users[i][3]));
        }
    } 

    if(!userFound) {
        UserNotFound(buffer);
    } else {
        if(user.getUserType().compare(DISABLED_CODE) != 0) {
            LightHighlight();
            std::cout << endl
                      << user.getUserName()
                      << "'s account is already enabled.";
            Highlight();
        } else {
            cout << "\nWhat user type will this user be: " + FULL_STANDARD + " "  + BUY_STANDARD + " " + SELL_STANDARD + "?"<< endl;
                cout << "User Type: ";
                getline(cin, userType);
                cout << userType << endl;
                if(ToLower(userType).compare(ToLower(FULL_STANDARD)) == 0){
                    user.setUserType(FULL_STANDARD);
                    EnableDuplicate(buffer, user, transactionFile);
                }else if(ToLower(userType).compare(ToLower(BUY_STANDARD)) == 0){
                    user.setUserType(BUY_STANDARD);
                    EnableDuplicate(buffer, user, transactionFile);
                }else if(ToLower(userType).compare(ToLower(SELL_STANDARD)) == 0){
                    user.setUserType(SELL_STANDARD);
                    EnableDuplicate(buffer, user, transactionFile);
                }else{
                    cout << "Invalid Option, Please try enabling this user again!" << endl;
                } 
            
            
        }
        
    }
}

void Admin::DisableUser(string** users, int numUsers, string transactionFile){
    const string code = "08";
    string buffer = "";
    Users user;
    Writer writer;
    bool userFound, confirm = false;
    std::cout << endl
              << "Which user would you like to disable?: ";
    getline(cin, buffer);

    for(int i = 0; i < numUsers; i++) {
        if(users[i][0].compare(buffer) == 0) {
            userFound = true;
            user.setUserName(users[i][0]);
            user.setUserType(users[i][2]);
            user.setCredits(stof(users[i][3]));
        } 
    } 

    if(!userFound) {
        UserNotFound(buffer);
    } else {
        if(user.getUserType().compare(DISABLED_CODE) == 0) {
            LightHighlight();
            std::cout << endl
                      << user.getUserName()
                      << "'s account is already disabled.";
            Highlight();
        } else {
            while(confirm == false) {
                std::cout << endl
                        << "Do you want to disable this user? (Yes/No): ";
                getline(cin, buffer);
                if(ToLower(buffer).compare(YES) == 0) {
                    LightHighlight();
                    std::cout << user.getUserName() << "'s account has been disabled!";
                    Highlight();
                    confirm = true;
                    // Disable the man
                    writer.GenericWriteToDailyTransactionFile(user, code, transactionFile);
                } else if(ToLower(buffer).compare(NO) == 0) {
                    LightHighlight();
                    std::cout << user.getUserName() << "'s account was not disabled!";
                    Highlight();
                    confirm = true;
                } else {
                    LightHighlight();
                    std::cout << "Invalid option.  Please type \"yes\" or \"no\".";
                    Highlight();
                }
            }
        }
    }
}  

void Admin::Refund(string** users, int numUsers, string transactionFile) {
    const string code = "05";
    string sellerUsername, buyerUsername, buffer = "";
    bool userFound, validRefund = false;
    Writer writer;
    Users user;
    float credits;
    string title = "REFUND";
    
    TransactionTitle(title);
    // process of getting rid of loop, for when you come back to it 
    //while(validRefund == false){
        sellerUsername = "";
        std::cout << "\nPlease enter seller's name: ";
        getline(cin, sellerUsername);
        if (exitCmd(sellerUsername) == true){
            std::cout << "\nExit command executed. Moving you to main menu.";
            //break;
        }else{
        for(int i = 0; i < numUsers; i++) if(users[i][0] == sellerUsername){
            userFound = true;
        }
        userFound = MatchUser(users, numUsers, sellerUsername);

        if (userFound == false){
            UserNotFound(sellerUsername);
        } else {
            buyerUsername = "";
            std::cout << "\nPlease enter buyer's name: ";
            getline(cin,buyerUsername);

            if (exitCmd(buyerUsername) == true){
                std::cout << "\nExit command executed. Moving you to main menu.";
                //break;
            }else{

                for(int i = 0; i < numUsers; i++) if(users[i][0] == buyerUsername){
                    userFound = true;
                }
                userFound = MatchUser(users, numUsers, buyerUsername);

                if(userFound == false){
                    UserNotFound(buyerUsername);
                } else if(sellerUsername == buyerUsername) {
                    std::cout << "\nError: Buyer and Seller names cannot be the same.";
                }else{
                    cout << "\nPlease enter credit amount to refund: ";
                    getline(cin,buffer);

                    if (exitCmd(buffer) == true){
                        std::cout << "\nExit command executed. Moving you to main menu.";
                        //break;
                    }else{
                        if(IsDecimalNumber(buffer)){
                            credits = std::stof(buffer);
                            if(credits <= 0.0){
                                std::cout << "You cannot refund less than 0 credits";
                            } else if(credits >= 999.99){ // Max bid
                                std::cout << "You cannot refund more than 999.99";
                            } else {
                                std::cout << "\nMoney has been refunded, moving you back to Main Menu!";
                                writer.RefundWriteToDailyTransactionFile(buyerUsername, sellerUsername, credits, transactionFile);
                                //break;
                            }
                        } else {
                            std::cout << "Error: Refund must be numeric and must be between $0.00 and 999.9";
                        }
                    }
                }
            }
        }    
    }
}

void EnableDuplicate(string buffer, Users user, string transactionFile){
    Writer writer;
    const string code = "07";
    cout << endl
         << "Are you sure you want to enable this user? (Yes/No): ";
    getline(cin, buffer);

    if(ToLower(buffer).compare(YES) == 0) {
        
        LightHighlight();
        std::cout << user.getUserName() << "'s account has been enabled with " + user.getUserType() + " access!";
        Highlight();
        // Enable the man
        writer.GenericWriteToDailyTransactionFile(user, code, transactionFile);
    } else if(ToLower(buffer).compare(NO) == 0) {
        LightHighlight();
        std::cout << user.getUserName() << "'s account was not enabled!";
        Highlight();
    } else {
        LightHighlight();
        std::cout << "Invalid option.  Please type \"yes\" or \"no\".";
        Highlight();
    }
}