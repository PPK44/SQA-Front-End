/**
* Items Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Items.cpp
*/

#include "Items.h"
#include <string>
#include "Users.h"
#include "AuctionLib.h"

string** bidList;
int bidListCount = 0;
bool itemMatch = false;
bool itemCheck = false;
int itemLength = 0;
string itemNameListCut = "";
int j = 0;
string usernameplusspaces = "";

Items::Items(){

}

void Items::CheckItems(string** items, int itemCount, Users user){
    //Item stores the username + spaces for a total of 16 characters
    //So we need to add spaces at the end of user's username until it's 16 characters long to compare properly
    usernameplusspaces = user.getUserName();
    

    for (int i = user.getUserName().length(); i < 15; i++){
        usernameplusspaces += " ";
    }
    
    for (int i = 0; i < itemCount; i++){
        //Compares username but right now item stores the username + spaces
        //Either trim the spaces at the end or add spaces at the end of user input until it's 15 characters long
        if(usernameplusspaces.compare(items[i][2]) == 0){
            cout << items[i][2] << endl;
            bidListCount++;
        }
    }

    bidList = new string*[bidListCount];
    for (int i = 0; i < bidListCount; i++){
        bidList[i] = new string[5];
    }

    if (bidListCount <= 0){
        cout << "\nYou have no items in auction.";
    }else if(bidListCount >= 1){
        for (int i = 0; i < itemCount; i++){
            //Get Item name, seller's name, remaining days and current bid when it matches
            //TODO: Check if seller's name is same as current user and don't add it in bidList
            if(usernameplusspaces.compare(items[i][2]) == 0){ //We need i on the items array but we want to increment 
                bidList[j][0] = items[i][1]; //Item ID
                bidList[j][1] = items[i][1]; //Item Name
                bidList[j][2] = items[i][3]; //Current bidder's name
                bidList[j][3] = items[i][4]; //Remaining days
                bidList[j][4] = items[i][5]; //Current Bid
                j++;
            }
        }
    }

    for (int i = 0; i < bidListCount; i++){
        std::cout << "\n" << i << ". " << bidList[i][0] << " " << bidList[i][1] << " " << bidList[i][2] << " " << bidList[i][3] << " " << bidList[i][4];
    }
}

void Items::FindItems(string** items, int itemCount){
    // Resets 
    string** bidList;
    int bidListCount = 0;
    bool itemMatch = false;
    bool itemCheck = false;
    int itemLength = 0;
    string itemNameListCut = "";
    int j = 0;

    while (itemMatch == false){
        itemName = "";
        itemCheck = false;
        while (itemCheck == false){
            std::cout << "\nEnter an Item name: ";
            getline(cin, itemName);
            if (exitCmd(itemName)){
                std::cout << "Hi " << exitCmd(itemName);
                break;
            }
            //Item name has to be 19 characters or fewer
            if (itemName.length() > MAX_ITEM_NAME_LENGTH){
                std::cout << "\nItem Name must be 19 characters or fewer";
            }
            else{
                itemCheck = true;
            }
        }

        //Get the first number of characters based on the length of input of itemName and see if they match
        //So if someone types Ham 
        //Ham, Hammer, Hamster gets sent into bidList and is counted, while han,hanmster,chammer doesn't
        //TODO: This needs to ignore case sensitivity

        //Compare input to the item file in a loop and add it into an array if matches
        itemLength = itemName.length();
        //Gets the total number of matching items, which will be used for the array
        for (int i = 0; i < itemCount; i++){
            itemNameListCut = items[i][1].substr(0,itemLength);
            if(itemName.compare(itemNameListCut) == 0){
                bidListCount++;
            }
        }

        //If itemCount is 0 then that means there are no matches and will prompt user to start over
        if (bidListCount == 0){
            std::cout << "\nThere are no matching results. Please enter a new item name.";
            itemCheck = false; //reset itemNameCheck
        }else{
            itemMatch = true;
        }
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
            if(itemName.compare(itemNameListCut) == 0){ //We need i on the items array but we want to increment 
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
            std::cout << "\n" << i << ". " << bidList[i][0] << " " << bidList[i][1] << " " << bidList[i][2] << " " << bidList[i][3];
        }
    }
}
bool Items::exitCmd(string buffer){
    if (ToLower(buffer).compare(EXIT) == 0){
        return true;
    }else {
        return false;
    }
}
