/**
* Bid Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Bid.cpp
*/

#include "Bid.h"
#include <string>
#include "AuctionLib.h"
#include "Writer.h"
#include <cmath>
#include <algorithm>
Bid::Bid(){

}

float Bid::CalculateLowestBid(float currentPrice){
    float rounding = 0.00;
    rounding = std::ceil(((currentPrice * MINIMUM_BID_PERCENT) * 100.0))/100.0;
    return (rounding);
}

void Bid::BidOnItem(string** items, int itemCount, Users user, string transactionFile){
    string itemName = "";
    string buffer = "";
    bool itemCheck = false;
    bool itemMatch = false;
    bool itemSelectCheck = false;
    bool initialBidConfirmation = false;
    bool bidCheck = false;
    bool alphanumericCheck = false;
    bool bidAlphanumericCheck = false;
    bool done = false;
    int itemSelect = 0;
    int itemLength = 0;
    float minimumPrice = 0.0;
    float theBid = 0.0;
    int j = 0; // iterates the bidlist for each match
    string itemNameListCut;
    string** bidList;
    int bidListCount = 0;
    string title = "BID";
    //Don't show any items that belong to user in the list?
    //Loop until user finishes bid 
    //While loop until user to inputs valid item name
    TransactionTitle(title);
    std::cout << "Type \"exit\" to return to main menu";
    LightHighlight();
    /**
     * get rid of all while loops and when an error is thrown you go back to main, meaning no use for goto 
     * and a lot of the if statements managing breaks
     */ 
while(done == false){    
    while (itemMatch == false){
        itemName = "";
        while (itemCheck == false){
            std::cout << "\nEnter an Item name: ";
            getline(cin, itemName);
            if (exitCmd(itemName)){
                done = true;
                break;
            }else{
                //Item name has to be 19 characters or fewer
                if (itemName.length() > MAX_ITEM_NAME_LENGTH){
                    LightHighlight();
                    std::cout << "Item Name must be 19 characters or fewer";
                    Highlight();
                }
                else{
                    itemCheck = true;
                }
            }
        }
        if(done == true){
            break;
        }else{
       
        //Get the first number of characters based on the length of input of itemName and see if they match
        //So if someone types Ham 
        //Ham, Hammer, Hamster gets sent into bidList and is counted, while han,hanmster,chammer doesn't
        //TODO: This needs to ignore case sensitivity

        //Compare input to the item file in a loop and add it into an array if matches
        itemLength = itemName.length();
        //Gets the total number of matching items, which will be used for the array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            if(ToLower(itemName).compare(ToLower(itemNameListCut)) == 0){
                string sellerName = items[i][2];
                sellerName.erase(remove(sellerName.begin(), sellerName.end(), ' '), sellerName.end());
                if(user.getUserName().compare(sellerName) != 0 ){
                    bidListCount++;
                }
            }
        }

        //If itemCount is 0 then that means there are no matches and will prompt user to start over
        if (bidListCount == 0){
            LightHighlight();
            std::cout << "There are no matching results. Please enter a new item name.";
            Highlight();
            itemCheck = false; //reset itemNameCheck
        }else{
            itemMatch = true;
        }
        }
        
    }

        if(done == false){
           

        // 2D array for the bidlist to contain item name and current bid on it
        bidList = new string*[bidListCount];
        for (int i = 0; i < bidListCount; i++){
            bidList[i] = new string[4];
        }
        //Now we can put the item name, seller's name, remaining days and current bid inside with this defined array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);

            //Get Item name, seller's name, remaining days and current bid when it matches
            //TODO: Check if seller's name is same as current user and don't add it in bidList
            if(ToLower(itemName).compare(ToLower(itemNameListCut)) == 0){ //We need i on the items array but we want to increment 
                
                    bidList[j][0] = items[i][1]; //Item Name
                    bidList[j][1] = items[i][2]; //Seller's name
                    bidList[j][2] = items[i][4]; //Remaining days
                    bidList[j][3] = items[i][5]; //Current Bid
                    j++;
                
            }
        }
        //Do another for loop and print out each item with a cooresponding number for user to input, the name and the current bid per line
        // Calculates the number of elements inside an array
        for (int i = 0; i < bidListCount; i++){
            float bid = stof(bidList[i][3]);
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << fixed << bid;
            string daBid = stream.str();
            std::cout << "\n" << i << ". " << bidList[i][0] << " " << bidList[i][1] << " " << bidList[i][2] << " " << daBid;
        }
        // Prompt user to select a number from a list and to exit type -1
        // Check if the item belongs to a user as they cannot bid on their own items and boot them back to item list
        while(itemSelectCheck == false){
            buffer = "";
            while(alphanumericCheck == false){
                std::cout << "\nEnter a number from the list: ";
                getline(cin, buffer);
                
                if (exitCmd(buffer) == true){
                    done = true;
                    break;
                }
                if(IsInteger(buffer)){
                    itemSelect = std::stoi(buffer);
                    alphanumericCheck = true;
                }else {
                    std::cout << "\nError: Input needs to be numeric: ";
                }
            }
            if(done == true){
                break;
            }else{
                // Need to validate against alphabetic characters first then convert to integer
                if(itemSelect < bidListCount && itemSelect >= 0){
                    std::cout << "\nYou have selected from List number: " << buffer;
                    itemSelectCheck = true;
                } 
                else {
                    LightHighlight();
                    std::cout << "Input needs to be between 0 and " << bidListCount << " and numeric only, please try again";
                    Highlight();
                    alphanumericCheck = false;
                }
            }
        }

        if(done == false){
            
            minimumPrice = (std::stof(bidList[itemSelect][3]));
            minimumPrice =  CalculateLowestBid(minimumPrice);
            LightHighlight();
            //Display current bid price
            std::cout << "Current Price: " << bidList[itemSelect][3];
            std::cout << "\nMinimum Bid Price: " << minimumPrice;
            std::cout << "\nWould you like to bid on this? (Yes/No): ";

            //Ask user if they would like to bid on it
            while (initialBidConfirmation == false){
                buffer = "";
                getline(cin, buffer);
                if (exitCmd(buffer) == true){
                    done = true;
                    break;
                }
                if (ToLower(buffer).compare(YES) == 0){
                    //Do the bid
                    initialBidConfirmation = true;
                } else if(ToLower(buffer).compare(NO) == 0){
                    LightHighlight();
                    cout << "Kicking you back to main";
                    Highlight();
                    break;
                }
                else{
                    LightHighlight();
                    cout << "Invalid bid input, Please input \"Yes\" or \"No\": ";
                    Highlight();
                }
            }
            if (done == false){
                
                std::cout << "\nHow much would you like to bid (Min Bid: " << minimumPrice << "): ";
                while (bidCheck == false){
                    buffer = "";
                    getline(cin, buffer);
                    if (exitCmd(buffer) == true){
                        
                        done = true;
                        break;
                    }
                    
                    while(bidAlphanumericCheck == false){
                        
                        if(IsDecimalNumber(buffer)){
                            theBid = stof(buffer);
                            bidAlphanumericCheck = true;
                        } else{
                            LightHighlight();
                            std::cout << "Input must be numeric";
                            Highlight();
                        }
                    }   
                    if (theBid < minimumPrice){
                        LightHighlight();
                        std::cout << "New bid must be 5% higher than current price";
                        Highlight();
                        bidAlphanumericCheck = false;
                    } else if(theBid > MAX_BID){
                        LightHighlight();
                        std::cout << "The maximum bid you can bid is $" << MAX_BID;
                        Highlight();
                        bidAlphanumericCheck = false;
                    } else {
                        Writer writer;
                        //Item Name, Seller's name, buyer's name, new bid all in string
                        LightHighlight();
                        std::cout << Spaces(12) << "A bid of $" << theBid << " has been placed!";
                        Highlight();
                        writer.BidWriteToDailyTransactionFile(bidList[itemSelect][0], bidList[itemSelect][1], user.getUserName(), theBid, transactionFile);
                        bidCheck = true;
                        goto loop_end;
                    }
                    
                }
            }
        }
    }
}
   
    cout << "Exit command executed. Moving you back to main menu" << endl;
    loop_end:;
}

bool Bid::exitCmd(string buffer){
    if (ToLower(buffer).compare(EXIT) == 0){
        return true;
    }else {
        return false;
    }
}

