/**
* @brief Advertise Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Advertise.h
*/

#ifndef _ADVERTISE_H
#define _ADVERTISE_H

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

/** @brief Advertise Class 
 * @description: Used to allow user to create an item and put it up for auction    
 */
class Advertise : public Items {

    private:
    /** Private Attribute for Remaining Days of the Item */
        short remainingDays;
        Items item;

    public:

        /**
         * Default Constructor 
         */ 
        Advertise();

        /**
		 * Setter for Remaining Days private attribute
		 */
		void setRemainingDays(short days) {
			remainingDays = days;
		}

		/**
		 * Getter for Remaining Days private attribute
		 */
		short getRemainingDays() {
			return remainingDays;
		}
                
        /**
         * User is prompted to input most information of the item they wish to advertise for
         * (item name, minimum bid price and number of days to put the item up for)
         */         
        void AdvertiseItem(Users self, string);



       









};



#endif