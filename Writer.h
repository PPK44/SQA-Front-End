/**
* @brief Writer Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Writer.h
*/

#ifndef _WRITER_H
#define _WRITER_H

#include <iostream> 	
#include <iomanip>		
#include <sstream>		
#include <stdexcept>	
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include <fstream>
#include "Users.h"

using namespace std;

/** @brief Writer Class to write to files
 * @description:      
 * 
 * 
 */
class Writer{

    protected:
        /**
         * Protected attribute to open the outfile and input data into it and close the outfile    
         */ 
        ofstream outFile;

    public:
        /**
         *Default Constructor for Writer Class
         */  
        Writer();
       
        /**
         * Constant to hold the daily transaction file name  
         */
        const string DAILY_TRANSACTION_FILE = "daily_transaction_file.txt";
        /**
         * Constant to hold the current user accounts file name    
         */
        const string CURRENT_USER_ACCOUNTS_FILE = "current_user_accounts_file.txt";
        /**
         * Constant to hold the available items file    
         */
        const string AVAILABLE_ITEMS_FILE = "aviailable_items_file.txt"; 

       
        /**
         * Writer Class method to write to the daily transaction file    
         */
        void BidWriteToDailyTransactionFile(string, string, string, float, string);
        /**
         * Writer class method to write to the user accounts file   
         */
        void WriteToChangePassword(Users, string);
        /**
         * Writer class method to write to the user accounts file   
         */
        void GenericWriteToDailyTransactionFile(Users, string, string);
        /**
         * Writer class method to write to the user accounts file   
         */
        void WriteAdvertiseToDailyTransactionFile(Users, string, int, float, string);
        /**
         * Writer class method to write to Transaction file
         */
        void RefundWriteToDailyTransactionFile(string, string, float, string);


};



#endif