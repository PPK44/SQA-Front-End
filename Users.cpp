/**
* Users Function Definition file for Our Auction Sales Service Project 
*
* @author Paul Kerrigan, Henry Zheng, Calvin Lapp
* @date January 24, 2020
* @version  1.0
* @name Users.cpp
*/

#include "Users.h"
#include "Writer.h"
#include "AuctionLib.h"
#include <string>


Users::Users(){}


bool Users::Login(string** users, int userCount){
	string username = "";
	string password = "";
	bool validation = false;
	string title = "LOGIN";

		TransactionTitle(title);	
		
     	cout << "\nUsername: ";
     	cin >> username;
    	cout << "\nPassword: ";
     	cin >> password;
		setUserName(ToLower(username));
		setPassword(password);
		for(int i = 0; i < userCount; i++){
			if (getUserName().compare(users[i][0]) == 0 && getPassword().compare(users[i][1]) == 0){
			//exists = true;
			
				setUserType(users[i][2]);
				setCredits(stof(users[i][3]));
				setCreditCount(0.0);
				validation = true;
				break;
			
			
		}

		}
	
		return validation;
     	
}

void Users::ChangePassword(Users user, string file){
	string password;
	string password2;
	Writer writer;
	string title = "CHANGE PASSWORD";

		TransactionTitle(title);
	
	std::cout << "\nEnter new password: ";
    getline(cin, password);
	std::cout << "\nConfirm password: ";
    getline(cin, password2);
	if(password.length() > 12 || password.length() == 0){
		cout << "\nYour password must not be longer than 12 characters and greater than 0";

	}else if(password.compare(password2) != 0){
		cout << "\nYour passwords do not match";

	}else if(password.find(" ") != std::string::npos){
		cout << "\nYour password cannot contain spaces";

	}else{

		cout << "\nSuccess";
		user.setPassword(password);
		writer.WriteToChangePassword(user, file);

	}

}

void Users::Create(string** users, int userCount, string transactionFile){

	Writer writer;
	Users user;
	string username;
	string password;
	string userType;
	bool validation = true;
	const string BUY_STANDARD = "BS";
	const string SELL_STANDARD = "SS";
	const string FULL_STANDARD = "FS";
	const string code = "01";
	string title = "CREATE";

		TransactionTitle(title);
///while(validation == false){
	cout << "\nEnter Username: ";
	getline(cin, username);
	for(int i = 0; i < userCount; i++){
		if (username.compare(users[i][0]) == 0){
			validation = false;
			break;
		}
	}
	if(validation == false){
		cout << "\nUsername already exists";
	}else{
	cout << "\nEnter Password: ";
	getline(cin, password);

	cout << "\nPlease type the user type you want: BS - Buy Standard, SS - Sell Standard, FS - Full Standard: ";
	getline(cin, userType);

	if(username.length() > 15){
		cout << "\nUsername is too long and must be 15 characters or fewer";
		
	}else if (username.length() <= 0){
		cout << "\nUsername is blank";
		
	}else if(username.find(" ") != std::string::npos){

		cout << "\nYour username cannot have spaces";

	}else if(password.length() > 12){
		cout << "\nPassword is too long and must be 12 characters or fewer";
		
	}else if (password.length() <= 0){
		cout << "\nPassword is blank";
		
	}else if(password.find(" ") != std::string::npos){

		cout << "\nYour password cannot have spaces";

	}else if(userType.length() > 2 || userType.length() < 0){
		cout << "\nUser Type must be one of the 2 character options above";
		
	}else if(userType.compare(BUY_STANDARD) != 0 && userType.compare(SELL_STANDARD) != 0 && userType.compare(FULL_STANDARD) != 0){
		cout << "\nUser Type must be one of the 2 character options above";
		
	}else{
		LightHighlight();
		cout << "User Successfully Created";
		Highlight();
		user.setUserName(ToLower(username));
		user.setPassword(password);
		user.setUserType(userType);
		user.setCredits(0.0);
		writer.CreateWriteToDailyTransactionFile(user, code, transactionFile);
		//validation = true;
	}
}

}

void Users::AddCredits(Users user, string transactionFile){

	string credit;
	float sum;
	float holder = user.getCreditCount();
	cout << holder << endl;
	cout << user.getCredits() << endl;
	Writer writer;
	const string code = "06";
	float minCredit = 0.0f;
	float cred = 0.0f;
	string title = "ADD CREDIT";

		TransactionTitle(title);

	cout << "\nHow much Credit do you want to add to your account: ";
	getline(cin, credit);
	
	if(IsDecimalNumber(credit) == false){
            LightHighlight();
            cout << "Error! Must only contain numeric values";
            Highlight();
			 
    }else{
		cred = stof(credit);
		sum = holder + cred;
		if(cred <= minCredit){
		LightHighlight();
		cout << "Error! You must add credit greater than 0.";
		Highlight();
	}else if(sum > SESSION_CREDIT_LIMIT){
		LightHighlight();
		cout << "Error! You have exceeded your session credit limit";
		Highlight();
	}else{
		user.setCreditCount(sum);
		setCreditCount(sum);
		LightHighlight();
		cout << "You have added: " << sum ;
		Highlight();
		writer.GenericWriteToDailyTransactionFile(user, code, transactionFile);
	}
	}
	
	
	
}

void Users::EndSession(Users user, string transactionFile){
	const string code = "00";
	Writer writer;
	writer.GenericWriteToDailyTransactionFile(user, code, transactionFile);

}


