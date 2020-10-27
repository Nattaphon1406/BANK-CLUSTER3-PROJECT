#include "BankClerk.h"
void BankClerk :: AddName(){
    cin.ignore();
    getline(cin,Name);
}
void BankClerk :: AddCitizenID(){
    cin >> CitizenID;
}
void BankClerk :: AddBirthDate(){
    cin >> BirthDate;
}
void BankClerk :: AddPhoneNumber(){
    cin >> PhoneNumber;
}
void BankClerk :: AddClerkID(){
    cin >> ClerkID;
}
void BankClerk :: AddPassword(){
    cin >> Password;
}
void BankClerk :: Registercustomer(){
    LoadFileBankClerk();
    AddInfoBankClerk(Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password);
    SaveInfoBankClerkToFile();
}
bool BankClerk :: login(string username,string password){
    LoadFileBankClerk();
    for(HeadInfo_BankClerk = HeadInfo_BankClerk; HeadInfo_BankClerk != NULL; HeadInfo_BankClerk = HeadInfo_BankClerk->link){
        if((HeadInfo_BankClerk->ClerkID == username ) && (HeadInfo_BankClerk->Password == password)){
            return true;
        }
    }
    return false;
}
void BankClerk :: MenuMenageRegister(int Number){
    LoadFileRegisterCustomer();
    cin >> Choice;
    if(Choice == 1){
        SaveInfoRegisterToFileBankAccount(Number);
        RemoveInfoRegisterCustomer(Number);
        SaveInfoRegisterCustomerToFile();
    }
    else if(Choice == 2){
        RemoveInfoRegisterCustomer(Number); 
        SaveInfoRegisterCustomerToFile();
    }

}
