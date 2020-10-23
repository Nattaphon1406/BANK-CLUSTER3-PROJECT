#include "BankClerk.h"
bool BankClerk :: login(string username,string password){
    LoadFileBankClerk();
    for(HeadInfo_BankClerk = HeadInfo_BankClerk; HeadInfo_BankClerk != NULL; HeadInfo_BankClerk = HeadInfo_BankClerk->link){
        if((HeadInfo_BankClerk->ClerkID == username ) && (HeadInfo_BankClerk->Password == password)){
            return true;
        }
    }
    return false;
}
