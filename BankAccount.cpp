#include "BankAccount.h"
bool BankAccount ::CheckTransfer_account(string accountNumber){
    string name;
	for(temp = HeadInfo_BankAccount;temp != NULL ; temp = temp->link){
        if(accountNumber == temp->AccountNumber){
			name = temp->Name;
			return true;
		}
	}
	return false;
}
string BankAccount :: getMoneyAccount(string username){
    string money;
   for(temp = HeadInfo_BankAccount;temp != NULL ; temp = temp->link){
	   if(username==temp->Username){
            money = temp->Money;
       }
    } 
	return money;
}
string BankAccount :: setDateandTime(){
    string Date,Time;
	time_t 	   now = time(0);
	struct tm  tstruct;
	char       date[80],time[80];
	tstruct = *localtime(&now);
	strftime(date, sizeof(date), "%Y-%m-%d", &tstruct);
	strftime(time, sizeof(time), "%X", &tstruct);

    Date = date;
    Time = time;
    return Date+","+Time;
}
void BankAccount :: payBill(string group, string username,double moneyAccount, double amount){
    double balance=0,fee=0;
    string TypeBill, Balance, date, time;

    if(group=="1"){
        TypeBill = "Water bill";
        moneyAccount = moneyAccount - amount;
        fee = amount*0.3;
        balance = moneyAccount - fee;
    }
    else if(group=="2"){
        TypeBill = "Electricity bill";
        moneyAccount = moneyAccount - amount;
        fee = amount*0.4;
        balance = moneyAccount - fee;
    }
    else if(group=="3"){
        TypeBill = "Phone bill";
        moneyAccount = moneyAccount - amount;
        fee = amount*0.5;
        balance = moneyAccount - fee;
    }
	cout << "*********Bill********" << endl;
    //setTime
	date=setDateandTime();
    time=date.substr((date.find(",")+1),date.find(" "));
    date=date.substr(0,date.find(","));

    cout << "TypeBill: " << TypeBill << endl;
    cout << "Fee: " << fee << " baht"<< endl;
    cout << "Balance: " <<  balance << " baht" << endl;
    cout << "Date: " << date << " : " << time << endl;
    
    //ChangData at File Account
    stringstream ss; 
    ss << balance;
	ss >> Balance;
	ss.clear();
	for(temp = HeadInfo_BankAccount;temp !=NULL ; temp = temp->link){
       if(username==temp->Username){
            temp->Money = Balance;
            cout << "Yes" << endl;
            
       }
    }

	cout << "*******Chengce******" << endl;
	ShowBankAccount();//test
    chengceDataFile();
}
void BankAccount :: chengceDataFile(){
    string fileName;
    fstream myfile;
    fileName = "BankAccount.dat";
    myfile.open(fileName.c_str(),std::ios::out);

    for(temp = HeadInfo_BankAccount;temp !=NULL ; temp = temp->link){
        myfile << temp->Name << "," << temp->AccountNumber << "," << temp->Money << "," << temp->Username << "," << temp->Password << endl;
	}
	myfile.close();
}