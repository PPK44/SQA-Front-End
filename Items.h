/**
* @brief Items Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Items.h
*/

#ifndef _ITEMS_H
#define _ITEMS_H

#include <iostream> 	
#include <iomanip>		
#include <sstream>		
#include <stdexcept>	
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include "Users.h"

using namespace std;

/** @brief Items Class
 * @description: Class to represent all items in this system to be bid on and advertised
 *      
 */
class Items{

    private:
        /** Private Attribute for Item Name */
        string itemName;
        /** Private Attribute for Item Id */
        string itemId;
        /** Private Attribute for Bid Price */
        float bidPrice;
        /** Private Attribute for Seller Name */
        string sellerName;
        /** Private Attribute for Current Bidder Name */
        string currentBidderName;

    public:
        /**
         * Default Constructor for the Items Class
         */ 
        Items();    

        /**
		 * Setter for Item Name private attribute
		 */
		void setItemName(string item){
			itemName = item;
		}
		/**
		 * Getter for Item Name private attribute
		 */
		string getItemName(){
			return itemName;
		}
        /**
		 * Setter for Item Id private attribute
		 */
		void setItemId(string id){
			itemId = id;
		}
		/**
		 * Getter for Item Id private attribute
		 */
		string getItemId(){
			return itemId;
		}
        /**
		 * Setter for Bid Price private attribute
		 */
		void setBidPrice(float price){
			bidPrice = price;
		}
		/**
		 * Getter for Bid Price private attribute
		 */
		float getBidPrice(){
			return bidPrice;
		}
        /**
		 * Setter for Seller Name private attribute
		 */
		void setSellerName(string name){
			sellerName = name;
		}
		/**
		 * Getter for Seller Name private attribute
		 */
		string getSellerName(){
			return sellerName;
		}
        /**
		 * Setter for Current Bidder Name private attribute
		 */
		void setCurrentBidderName(string name){
			currentBidderName = name;
		}
		/**
		 * Getter for Current Bidder Name private attribute
		 */
		string getCurrentBidderName(){
			return currentBidderName;
		}

		/**
         * Items class method to allow a full standard user or sell standard user to check their auction items   
         */
		void CheckItems(string** items, int itemCount, Users user);     

		/**
		 * Items class method to search for an item based on id and item name 
		 */ 
        void FindItems(string** items, int itemCount); 

		bool exitCmd(string buffer);
};



#endif