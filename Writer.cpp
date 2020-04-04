/**
* Writer Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Writer.cpp
*/

#include "AuctionLib.h"
#include "Writer.h"
#include "Users.h"
#include <string>
#include <limits>
#include <sstream>

Writer::Writer(){

}


void Writer::BidWriteToDailyTransactionFile(string itemName, string sellerName, string buyerName, float bid, string transactionFile){

    string buffer;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << fixed << bid;
    string currentBid = stream.str();
    currentBid.insert(currentBid.begin(), 6 - currentBid.length(), '0');
    string name = buyerName;
    name.append(15 - buyerName.length(), ' ');
    outFile.open(transactionFile, ios::app);
    outFile << "04 " << itemName << " " << sellerName << " " << name << " " << currentBid << endl; 

    outFile.close();

}

void Writer::WriteToChangePassword(Users user, string file){

    fstream File;
	int fileNumber;
    int i = 0;
    string getUser;
    string getPwd;
    string getType;
    float getCred;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << fixed << user.getCredits();
    string credHolder = stream.str();
    string username;
    string password;
    string userType;
	string cred;
     username = user.getUserName();
     username.append(15 - user.getUserName().length(), ' ');
     password = user.getPassword();
     password.append(12 - user.getPassword().length(), ' ');
     userType = user.getUserType();
     cred = credHolder;
     cred.insert(cred.begin(), 9 - credHolder.length(), '0');

	File.open(file); //opening the file
	if (!File) {
        cerr << "Unable to open file";
    }
		
	//cout << username;
	while (File >> getUser >> getPwd >> getType >> getCred) {	
			if(user.getUserName().compare(getUser) == 0){
                fileNumber = i;
            }
			i++;
	}
     File.clear();
	 File.seekg(0, ios::beg);
    
     // Position the put pointer -- switching from reading to writing.
     File.seekp(fileNumber * 43);

     File << username << " " << password << " " << userType << " " << cred << endl;
	 File.close(); //closing the file

}

void Writer::GenericWriteToDailyTransactionFile(Users user, string transactionCode, string transactionFile){
    fstream File;
    std::stringstream stream;
    if(transactionCode == "06"){
        stream << std::fixed << std::setprecision(2) << fixed << user.getCreditCount();
    }else{
        stream << std::fixed << std::setprecision(2) << fixed << user.getCredits();
    }
    string credHolder = stream.str();
    string code = transactionCode;
    string username = user.getUserName();
    string userType = user.getUserType();
	string cred = credHolder;
    username.append(MAX_USER_NAME_LENGTH - user.getUserName().length(), ' ');
    cred.insert(cred.begin(), MAX_CREDIT_LENGTH - credHolder.length(), '0');
    
	File.open(transactionFile, ios::app); //opening the file
	if (!File) {
        cerr << "Unable to open file";
    }

    File << code << " " << username << " " << userType << " " << cred << endl;
    File.close(); //closing the file
}

void Writer::WriteAdvertiseToDailyTransactionFile(Users user, string item, int numDays, float bid, string transactionFile) {
    fstream file;
    const string ADVERTISE_CODE = "03";
    std::stringstream bidStream;
    string username, itemName, aucBid = "";

    file.open(transactionFile, ios::app); //opening the file
	if (!file) {
        cerr << "Unable to open file";
    }

    bidStream << std::fixed << std::setprecision(2) << fixed << bid;
    username = user.getUserName();
    itemName = item;
    aucBid   = bidStream.str();
    username.append(MAX_USER_NAME_LENGTH - user.getUserName().length(), ' ');
    itemName.append(MAX_ITEM_NAME_LENGTH - itemName.length(), ' ');
    aucBid.insert(aucBid.begin(), 6 - aucBid.length(), '0');

    file << ADVERTISE_CODE << " " 
         << itemName << " " 
         << username << " " 
         << setfill('0') << setw(3) << numDays << " "
         << setprecision(2) << fixed << aucBid << endl;
    file.close();
}


void Writer::RefundWriteToDailyTransactionFile(string buyerName, string sellerName, float refundAmount, string transactionFile){
    string refund;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << fixed << refundAmount;
    refund = stream.str();
    refund.insert(refund.begin(), 6 - refund.length(), '0');
    string buyer = buyerName;
    buyer.append(15 - buyerName.length(), ' ');
    string seller = sellerName;
    seller.append(15 - sellerName.length(), ' ');
    outFile.open(transactionFile, ios::app);
    outFile << "05 " + buyer + " " +  seller + " " + refund << endl; 

    outFile.close();
}

void Writer::CreateWriteToDailyTransactionFile(Users user, string transactionCode, string transactionFile){
    fstream File;
    std::stringstream stream;
    if(transactionCode == "06"){
        stream << std::fixed << std::setprecision(2) << fixed << user.getCreditCount();
    }else{
        stream << std::fixed << std::setprecision(2) << fixed << user.getCredits();
    }
    string credHolder = stream.str();
    string code = transactionCode;
    string username = user.getUserName();
    string password = user.getPassword();
    string userType = user.getUserType();
	string cred = credHolder;
    username.append(MAX_USER_NAME_LENGTH - user.getUserName().length(), ' ');
    password.append(MAX_PASSWORD_LENGTH - user.getPassword().length(), ' ');
    cred.insert(cred.begin(), MAX_CREDIT_LENGTH - credHolder.length(), '0');
    

	File.open(transactionFile, ios::app); //opening the file
	if (!File) {
        cerr << "Unable to open file";
    }

    File << code << " " << username << " " << password << " " << userType << " " << cred << endl;
    File.close(); //closing the file
}
