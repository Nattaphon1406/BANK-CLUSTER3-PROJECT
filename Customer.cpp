#include "Customer.h"
<<<<<<< Updated upstream
Customer :: Customer(){
    Name = "";
    CitizenID = "";
    BirthDate = "";
    PhoneNumber = "";
    TypeAccount = "";
    Money = "";
}
void Customer :: SetInfoCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money){
    Name = name;
    CitizenID = citizenID;
    BirthDate = birthDate;
    PhoneNumber = phoneNumber;
    TypeAccount = typeAccount;
    Money = money;
}
string Customer :: getName(){
    return Name;
}
string Customer :: getCitizenID(){
    return CitizenID;
}
string Customer :: getBirthDate(){
    return BirthDate;
}
string Customer :: getPhoneNumber(){
    return PhoneNumber;
}
string Customer :: getTypeAccount(){
    return TypeAccount;
}
string Customer :: getMoney(){
    return Money;
}
        //Save Info Of Customer
=======
bool Customer :: login(string username,string password){
    LoadFileBankAccount();
    for(HeadInfo_BankAccount = HeadInfo_BankAccount; HeadInfo_BankAccount != NULL; HeadInfo_BankAccount = HeadInfo_BankAccount->link){
        if((HeadInfo_BankAccount->Username == username ) && (HeadInfo_BankAccount->Password == password)){
            return true;
        }
    }
    return false;
}
>>>>>>> Stashed changes
