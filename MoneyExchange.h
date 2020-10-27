#ifndef MONEYEXCHANGE_H
#define MONEYEXCHANGE_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<time.h>
#include "BankClerk.h"
using namespace std;
class MoneyExchange : public BankAccount{
	protected:
		BankAccount *Obj_BankAccount;
		Info_BankAccount *temp;
		string CurrencyType;
		unsigned long int MoneyAmount;
		string PaymentType;
		unsigned long int PaymentMoney;
		string Account;
		string balance;
	public:
		MoneyExchange();
		void SetMoneyExchange(int c,unsigned long int m,int p);
		void ExchangeCalculate(int c);
		string TimeBill();
		void ShowBillCash(unsigned long int cash);
		void ShowPaymentMoney();
		void SetAccount(string account);
		string ShowBillAccount(string Balance);
		void WriteFileCash();
		void WriteFileAccount(string Balance);
};
#endif
