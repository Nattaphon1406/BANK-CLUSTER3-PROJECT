#include "Customer.h"
bool Customer :: login(string username,string password){
    LoadFileBankAccount();
    for(HeadInfo_BankAccount = HeadInfo_BankAccount; HeadInfo_BankAccount != NULL; HeadInfo_BankAccount = HeadInfo_BankAccount->link){
        if((HeadInfo_BankAccount->Username == username ) && (HeadInfo_BankAccount->Password == password)){
            return true;
        }
    }
    return false;
}