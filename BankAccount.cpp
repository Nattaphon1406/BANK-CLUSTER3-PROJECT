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