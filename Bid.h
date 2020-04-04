/**
* @brief Bid Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Bid.h
*/

#ifndef _BID_H
#define _BID_H

#include <iostream> 	
#include <iomanip>		
#include <sstream>		
#include <stdexcept>	
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include <fstream>
#include "Items.h"
#include "Users.h"

using namespace std;

/** @brief Bid Class
 * @description: Used to allow a user to bid on an available item     
 * 
 * 
 */
class Bid : public Items{

    private:
        

    public: 
        /**
         * Default Constructor For Bid class
         */ 
        Bid();

        /**
         * Constant to hold the minimum allowable percentage higher than the previous
         * bid    
         */
        const float MINIMUM_BID_PERCENT = 1.05;

        /**
         * Calculates the minimum amount the user has to be
         * (Current price * minimum_bid_percent)
         */ 
        float CalculateLowestBid(float currentPrice);
        /**
         * User is Prompted to input an item name then selects from a list of items then input
         * an amount to bid on an item
         */ 
        void BidOnItem(string** item, int itemCount, Users user, string);

        bool exitCmd(std::string buffer);

};



#endif