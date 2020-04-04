/**
* @brief Users Header File for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.h
*/

#ifndef _USERS_H
#define _USERS_H

#include <iostream> 	
#include <iomanip>		
#include <sstream>		
#include <stdexcept>	
#include <cstdio> 	
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

/** @brief Users Class for user specific methods
 * @description: Class to represent regular users for this system including
 *				 full-standard, buy-standard and sell standard
 * Contains functions to allow users to login, logout, change password, add credits to their account
 * and if they are a new user they can create an account
 */
class Users{
	
	private:
		
		string userName;
		/** Private Attribute for Users password */
		string password;
		/** Private Attribute for User type */
		string userType;
		/** Private Attribute for Users credits */
		float credits;
		/** Private Attribute for Users credit count */
		float creditCount;

	public:
		/**
		 * Default Constructor for the Users Class
		 * */
		Users();

		/**
		 * The amount of credit a user can add per login session
		 */ 
		const float SESSION_CREDIT_LIMIT = 999.99; 	

		/**
		 * Setter for User Name private attribute
		 */
		void setUserName(string name){
			userName = name;
		}
		/**
		 * Getter for User Name private attribute
		 */
		string getUserName(){
			return userName;
		}
		/**
		 * Setter for password private attribute
		 */
		void setPassword(string pwd){
			password = pwd;
		}
		/**
		 * Getter for password private attribute
		 */
		string getPassword(){
			return password;
		}
		/**
		 * Setter for User Type private attribute
		 */
		void setUserType(string type){
			userType = type;
		}
		/**
		 * Getter for User Type private attribute
		 */
		string getUserType(){
			return userType;
		}
		/**
		 * Setter for setting User Credits private attribute
		 */
		void setCredits(float cred){
			credits = cred;
		}
		/**
		 * Getter for getting User Credits private attribute
		 */
		float getCredits(){
			return credits;
		}
		/**
		 * Setter for setting User Credits private attribute
		 */
		void setCreditCount(float credit){
			creditCount = credit;
		}
		/**
		 * Getter for getting User Credits private attribute
		 */
		float getCreditCount(){
			return creditCount;
		}
		
		/**
		 * Users Class Method for Login
		 */ 
		bool Login(string**, int);
		/**
		 * Users Class Method to change the user password
		 */ 
		void ChangePassword(Users, string);
		/**
		 * Users Class Method for creating an account
		 */ 
		void Create(string**, int, string);
		/**
		 * Users Class Method to add credits to a user account
		 */ 
		virtual void AddCredits(Users, string);
		/**
		 * Users Class Method to end session
		 */ 
		void EndSession(Users, string);

};



#endif



