#ifndef STATEMENT_H
#define STATEMENT_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

class Statement{
 private :
	class Deposit{
    public :
		string Name;
		string AccountNumber;
		string AmountMoney;
		string Balance;
		string Date;
    	string Time;
    	Deposit *link;
    	Deposit(string name,string account,string money,string balance,string date,string time);
	};//Node for deposition
	class withdraw{
	public:
		string Name;
		string AccountNumber;
		string AmountMoney;
		string Balance;
		string date;
		string time;
		withdraw *link;
		withdraw(string name,string account,string money,string balance,string date,string time);	
	};//node for withdraw
	class MoneyExchange{
		public:
		//string Name;
		string AccountNumber;
		string Currency;
		string AmountMoney;
		string AmountDebited;
		string Balance;
		string Date;
		string Time;
		MoneyExchange *link;
		MoneyExchange(string number,string currency,string money,string debited,string balance,string date,string time);
	};
	class PlayBill{
		public:
		string Name;
		string AccountNumber;
		string Type;
		string Amountmoney;
		string Date;
		string Time;
		PlayBill *link;
		PlayBill(string name,string account,string type,string money,string date,string time);
	};
	class PlayBillBankclerk{
		public:
		string Type;
		string Amountmoney;
		string Date;
		string Time;
		PlayBillBankclerk *link;
		PlayBillBankclerk(string type,string money,string date,string time);
	};
	class Transfer{
		public:
		string AccountNumberT;
		string AccountNumberR;
		string Amountmoney;
		string Balance;
		string Date;
		string Time;
		Transfer *link;
		Transfer(string numberT,string numberR ,string money,string balance,string date,string time);
	};
	Deposit *head_deposit;
	Deposit *tail_deposit;
	int count_deposit;
	withdraw *head_withdraw;
	withdraw *tail_withdraw;
	int count_withdraw;
	MoneyExchange *head_moneyExchange;
	MoneyExchange *tail_moneyExchange;
	int count_moneyExchange;
	PlayBill *head_playBill;
	PlayBill *tail_playBill;
	int count_playBill;
	Transfer *head_Transfer;
	Transfer *tail_Transfer;
	int count_Transfer;
	PlayBillBankclerk *head_PlayBillBankclerk;
	PlayBillBankclerk *tail_PlayBillBankclerk;
	int count_PlayBillBankclerk;
 public:
	Statement();
	~Statement();
	void AddData_deposit(string name,string account,string money,string balance,string date,string time);
	bool ReadFile_deposit();
	void printName(string number);//customer deposit
	void printData_deposit(string number);//customer
	void printstatement_deposit();//Actor
	void AddData_withdraw(string name,string account,string money,string balance,string date,string time);
	bool Readfile_withdraw();
	void printName_withdraw(string number);//customer
	void printData_withdraw(string number);//customer
	void printstatement_withdraw();//Actor
	void AddData_moneyExchange(string number,string currency,string money,string debited,string balance,string date,string time);
	bool Readfile_moneyExchange();
	void printName_moneyExchange(string number);//customer
	void printData_moneyExchange(string number);//customer
	void printstatement_momeyExchange();//Actor
	void AddData_PlayBill(string name,string account,string type,string money,string date,string time);
	bool Readfile_PlayBill();
	void printName_PlayBill(string number);//customer
	void printData_PlayBill(string number);//customer
	void AddData_Transfer(string numberT,string numberR ,string money,string balance,string date,string time);
	bool Readfile_Transfer();
	void printName_Transfer(string number);//customer
	void printData_Transfer(string number);//customer
	void printstatement_Transfer();
	void AddData_PlayBillBankclerk(string type,string money,string date,string time);
	bool Readfile_PlayBillBankclerk();
	void printstatement_PlayBillBankclerk();
};
#endif