#include "BankAccount.h"

BankAccount :: statementBill :: statementBill(string name,string accountNumber,string money,string date,string time){
    Name = name;
    AccountNumber = accountNumber;
    Money = money;
    Date = date;
    Time = time;
    linkBill = NULL;
}
BankAccount :: BankAccount(){
    this->headBill = NULL;
    this->tailBill = NULL;
    this->tempBill = NULL;
    this->Obj_BankAccount = NULL;
    this->temp = NULL;
    NameAccount = " ";
    accountNumber = " ";
    moneyAccount = 0;
}
void BankAccount :: AddStatementBill(string name,string accountNumber,string money,string date,string time){
     statementBill *bill= new statementBill(name,accountNumber,money,date,time);
            if(headBill == NULL){
                headBill = bill;
                tailBill = bill;
            }
            else{
                tailBill->linkBill = bill;
                tailBill = bill;
            }
            Count_Customer++;
}
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
double BankAccount :: getMoneyAccount(string username){
    string money;
    stringstream ss;
    for(temp = HeadInfo_BankAccount;temp != NULL ; temp = temp->link){
	   if(username==temp->Username){
            NameAccount = temp->Name;
            accountNumber = temp->AccountNumber;
            money = temp->Money;
       }
    } 
    ss << money ;
	ss >> moneyAccount;
	ss.clear();
	return moneyAccount;
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
void BankAccount :: payBill(string group, string username, double amount){
    double balance=0,fee=0;
    string TypeBill, Balance,Amount, date, time;

    //setTime
    date=setDateandTime();
    time=date.substr((date.find(",")+1),date.find(" "));
    date=date.substr(0,date.find(","));

    if(username.length()==2){//Customer
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
        cout << "TypeBill: " << TypeBill << endl;
        cout << "Fee: " << fee << " baht"<< endl;
        cout << "Balance: " <<  balance << " baht" << endl;
        cout << "Date: " << date << " : " << time << endl;
        
        //ChangData at File Account
        stringstream ss; 
        ss << balance;
        ss >> Balance;
        ss.clear();
        ss << amount;
        ss >> Amount;
        ss.clear();
        for(temp = HeadInfo_BankAccount;temp !=NULL ; temp = temp->link){
            if(username==temp->Username){
                    temp->Money = Balance;
                    cout << "Yes" << endl;
            }
        }
        //username,accountNumber,amount,date,time;
        cout << "*******Chengce******" << endl;
        ShowBankAccount();//test
        SaveInfoCustomerToFile();//saveFile
        /*string fileName;
        fstream myfile;
        fileName = "BankAccount.dat";
        myfile.open(fileName.c_str(),std::ios::out);

        temp=HeadInfo_BankAccount;
        while(temp!=NULL){
            myfile << temp->Name << "," << temp->AccountNumber << "," << temp->Money << "," << temp->Username << "," << temp->Password << endl;
            temp = temp->link;
        }
        myfile.close();*/

        AddStatementBill(NameAccount,accountNumber,Amount,date,time);
        WriteStatement();
    }
    /*else{//Bank clerk
        if(group=="1"){
            amount*3;
        }
        else if(group=="2"){
            amount*4;
        }
        else if(group=="3"){
            amount*5
        }
        
    }*/
}
void BankAccount :: WriteStatement(){
    string fac,num,fileName,data;
    fstream myfile;
    fileName = "Statement.dat";
    myfile.open(fileName.c_str(),std::ios::app);

    tempBill=headBill;
    while(tempBill!=NULL){
        myfile << tempBill->Name << "," << tempBill->AccountNumber << "," << tempBill->Money << "," << tempBill->Date << "," << tempBill->Time << endl;
		tempBill = tempBill->linkBill;
	}
	myfile.close();
}