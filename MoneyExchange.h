#define MONEYEXCHANGE_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<time.h>
#include "BankAccount.h"
using namespace std;
class MoneyExchange{
	private:
		//BankAccount B;
		string CurrencyType;
		float MoneyAmount;
		string PaymentType;
		float PaymentMoney;
		string Account;
	public:
		MoneyExchange();
		void SetMoneyExchange(int c,float m,int p);
		void ExchangeCalculate(int c);
		string TimeBill();
		void ShowBillCash(float cash);
		void ShowPaymentMoney();
		void SetAccount(string account);
		void ShowBillAccount();
		void WriteFileCash();
};