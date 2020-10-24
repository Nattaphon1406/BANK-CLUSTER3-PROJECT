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
void BankAccount :: payBill(string group, string username,double moneyAccount, double amount){
    double balance=0,fee=0;
    string TypeBill, Balance;

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
	time_t 	   now = time(0);
	struct tm  tstruct;
	char       Date[80],Time[80];
	tstruct = *localtime(&now);
	strftime(Date, sizeof(Date), "%Y-%m-%d", &tstruct);
	strftime(Time, sizeof(Time), "%X", &tstruct);

    cout << "TypeBill: " << TypeBill << endl;
    cout << "Fee: " << fee << " baht"<< endl;
    cout << "Balance: " <<  balance << " baht" << endl;
    cout << "Date: " << Date << " : " << Time << endl;
    
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