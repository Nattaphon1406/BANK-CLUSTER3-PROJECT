#include "BankAccount.h"
bool BankAccount ::CheckTransfer_account(string accountNumber){
    string name;
	for(HeadInfo_BankAccount = HeadInfo_BankAccount;HeadInfo_BankAccount != NULL; HeadInfo_BankAccount = HeadInfo_BankAccount->link){
        if(accountNumber == HeadInfo_BankAccount->AccountNumber){
			name = HeadInfo_BankAccount->Name;
			return true;
		}
		HeadInfo_BankAccount = HeadInfo_BankAccount->link;
	}
	return false;
}
bool BankAccount :: CheckAccount(string Account){
	temp=HeadInfo_BankAccount;
	for(temp=HeadInfo_BankAccount;temp!=NULL ;temp=temp->link){
		if(temp->AccountNumber==Account){
			return true;
		}
	}	
	return false;
}

void BankAccount :: Withdraw(int withdraw){
    double m;
    stringstream tmp;
    tmp<<temp->Money;
    tmp>>m;
    tmp.clear();
    m=m-withdraw;
    tmp<<m;
    tmp>>temp->Money;
    tmp.clear();
}

double BankAccount :: getMoney(){
	double m;
	stringstream money;
	money<<temp->Money;
	money>>m;
	money.clear();
	return m;
}