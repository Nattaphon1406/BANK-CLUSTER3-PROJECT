#include "MoneyExchange.h"
MoneyExchange :: MoneyExchange()
{
	CurrencyType = " ";
	MoneyAmount = 0;
	PaymentType = " ";
	PaymentMoney = 0;
	Account = " ";
	balance = " ";
}
void MoneyExchange :: SetMoneyExchange(int c,unsigned long int m,int p)
{
	if(c == 1){
		CurrencyType = "YPY(Yen)";
	}
	else if(c == 2){
		CurrencyType = "USD(Dollar)";
	}
	else if(c == 3){
		CurrencyType = "CNY(Yuan)";
	}
	else if(c == 4){
		CurrencyType = "KRW(Won)";
	}
	else if(c == 5){
		CurrencyType = "GBP(Pound)";
	}
	else if(c == 6){
		CurrencyType = "EUR(Euro)";
	}
	
	MoneyAmount = m;
	
	if(p == 1){
		PaymentType = "Cash";
	}
	else if(p == 2){
		PaymentType = "Account";
	}	
}
void MoneyExchange :: ExchangeCalculate(int c)
{
	if(c == 1){
		PaymentMoney = MoneyAmount * 0.3;
	}
	else if(c == 2){
		PaymentMoney = MoneyAmount * 31.23;
	}
	else if(c == 3){
		PaymentMoney = MoneyAmount * 4.69;
	}
	else if(c == 4){
		PaymentMoney = MoneyAmount * 0.03;
	}
	else if(c == 5){
		PaymentMoney = MoneyAmount * 40.78;
	}
	else if(c == 6){
		PaymentMoney = MoneyAmount * 37.03;
	}
}
string MoneyExchange :: TimeBill()
{
	stringstream ss;
 	string Date,Time;
 	//function setTimeNow 
	time_t now = time(0);
    struct tm  tstruct;
    char bufA[80],bufB[80];
    tstruct = *localtime(&now);
    strftime(bufA, sizeof(bufA), "%Y-%m-%d", &tstruct);
 	strftime(bufB, sizeof(bufB), "%X", &tstruct);
	//int to string  
 	ss << bufA;
 	ss >> Date;
 	ss.clear();
 	ss << bufB;
 	ss >> Time;
 	ss.clear(); 
 	return Date+"/"+Time;	
}
void MoneyExchange :: ShowBillCash(unsigned long int cash)
{
	cout<<"============ Bill Cash ============"<<endl;
	cout<<"Payment Type: "<<PaymentType <<endl;
	cout<<"Currency Type: "<<CurrencyType <<endl;
	cout<<"Money Amount: "<<MoneyAmount << " " << CurrencyType.substr(0,CurrencyType.find("(")) <<endl;
	cout<<"Money Received: "<<cash << " Baht" <<endl;
	cout<<"Change: "<<cash - PaymentMoney << " Baht"<<endl;
	cout<<"Date: "<<TimeBill() <<endl; 
	cout<<"==================================="<<endl;
	 WriteFileCash();
}
void MoneyExchange :: ShowPaymentMoney()
{
	cout<<"Money Amount Pay: " << PaymentMoney << " Baht" <<endl;
}
void MoneyExchange :: SetAccount(string account)
{
	Account = account;
}
string MoneyExchange :: ShowBillAccount(string getBalance)
{
	stringstream ss;
	string Balance;
	unsigned long int balance;
	Balance = getBalance;
	ss << Balance;
	ss >> balance;
	ss.clear();
	if(balance > PaymentMoney){
		balance = balance - PaymentMoney;
		cout<<"============ Bill Account ============"<<endl;
		cout<<"Payment Type: "<<PaymentType <<endl;
		cout<<"Account Number: "<<Account <<endl;
		cout<<"Currency Type: "<<CurrencyType <<endl;
		cout<<"Money Amount: "<<MoneyAmount << " " << CurrencyType.substr(0,CurrencyType.find("(")) <<endl;
		cout<<"Money Deducted: "<<PaymentMoney << " Baht" <<endl; //money for pay
		cout<<"Balance: " << balance << " Baht"<<endl;
		cout<<"Date: "<<TimeBill() <<endl;
		cout<<"==================================="<<endl;
		ss << balance;
		ss >> Balance;
		ss.clear();
		WriteFileAccount(Balance);
		return Balance;
	} 
	else{
		cout << "!!!!Not enough account balance!!!!" << endl;
	}
	return Balance;
}
void MoneyExchange :: WriteFileCash()
{
	string Date,Time;
    fstream CashFile;
    CashFile.open("MoneyExchangeCash.dat", ios::app);
    if(CashFile.is_open())
	{
        Date = TimeBill();
        Date = Date.erase(0,Date.find(" ")+1);
        Date = Date.substr(0,Date.find("/"));
        Time = TimeBill();
        Time = Time.erase(0,Time.find(" ")+1);
        Time = Time.erase(0,Time.find("/")+1);
            	
        CashFile << CurrencyType << "," << MoneyAmount << "," << PaymentMoney << "," << Date << "," << Time << endl; 
	}//open to write file
     CashFile.close(); 
}
void MoneyExchange :: WriteFileAccount(string Balance)
{
	string Date,Time;
    fstream AccountFile;
    AccountFile.open("MoneyExchangeAccount.dat", ios::app);
    if(AccountFile.is_open())
	{
        Date = TimeBill();
        Date = Date.erase(0,Date.find(" ")+1);
        Date = Date.substr(0,Date.find("/"));
        Time = TimeBill();
        Time = Time.erase(0,Time.find(" ")+1);
        Time = Time.erase(0,Time.find("/")+1);
            	
        AccountFile << Account << "," << CurrencyType << "," << MoneyAmount << "," << PaymentMoney << "," << Balance << "," << Date << "," << Time << endl; 
	}//open to write file
    AccountFile.close(); 
}