/**
* Advertise Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.1
* @name Advertise.cpp
*/

#include "Advertise.h"
#include "Writer.h"
#include "AuctionLib.h"
#include <string>

Advertise::Advertise(){}

void Advertise::AdvertiseItem(Users self, string transactionFile){
    Writer writer;
    const short MAX_AUC_DAYS = 100;
    const short MIN_AUC_DAYS = 1;

    string itemName, buffer = "";
    float minBid = 0.0f;
    int numDays = 0;
    bool validAd = false;
    string title = "ADVERTISE";

    TransactionTitle(title);
   // while(validAd == false)
    //{
        std::cout << "\nItem name: ";
        getline(cin, buffer);
        if(buffer.length() > MAX_ITEM_NAME_LENGTH) {
            LightHighlight();
            std::cout << "Item name must be " << MAX_ITEM_NAME_LENGTH << " characters or less.";
            Highlight();
        }else if(IsString(buffer) == true){
            LightHighlight();
            cout << "The Item name cannot only contain numbers.";
            Highlight();
            
        }else {
            itemName = ToLower(buffer);
            buffer = "";
            std::cout << "\nMinimum bid: $";
            getline(cin, buffer);

            if(IsDecimalNumber(buffer)) {
                minBid = std::stof(buffer);
                if(minBid > MAX_BID) {
                    LightHighlight();
                    std::cout << "           "
                              << "Maximum bid must be $" << MAX_BID << " or less.";
                    Highlight();
                } else if(minBid < MIN_BID) {
                    LightHighlight();
                    std::cout << "           "
                              << "Minimum bid must be at least $" << MIN_BID << ".";
                    Highlight();
                } else {
                    buffer = "";
                    std::cout << "\nNumber of days to auction: ";
                    getline(cin, buffer);
                    if(IsInteger(buffer)){
                        numDays = std::stoi(buffer);
                        if(numDays > MAX_AUC_DAYS) {
                            LightHighlight();
                            std::cout << "       "
                                      << "You can only auction an item up to " << MAX_AUC_DAYS << " days.";
                            Highlight();
                        } else if(numDays < MIN_AUC_DAYS) {
                            LightHighlight();
                            std::cout << "           "
                                      << "There must be a minimum of " << MIN_AUC_DAYS << " day "
                                      << endl
                                      << "                 "
                                      << "to auction the item.";
                            Highlight();
                        } else {
                            LightHighlight();
                            std::cout << "            "
                                      << "You have put up " << itemName << "." << endl       
                                      << "        "
                                      << "This item will be auctioned for " << numDays << " days" << endl
                                      << "            "
                                      << "with a minimum bid of $"<< setprecision(2) << fixed << minBid << "!";
                            Highlight();
                            validAd = true;
                            writer.WriteAdvertiseToDailyTransactionFile(self, itemName, numDays, minBid, transactionFile);
                        }
                    } else {
                        LightHighlight();
                        std::cout << "  "
                                  << "You must enter a number between " << MIN_AUC_DAYS << " and " << MAX_AUC_DAYS <<" inclusively.";
                        Highlight();
                    }
                }
            } else {
                LightHighlight();
                std::cout << "            "
                          << "A bid must be numeric and can only"
                          << "\n         "
                          << "be between $" << MIN_BID << " and $" << MAX_BID << " inclusively.";
                Highlight();
            }
        }
    
}


