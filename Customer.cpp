#include "Customer.h"
void Customer :: AddName(){
    cin.ignore();
    getline(cin,Name);
}
void Customer :: AddCitizenID(){
    cin >> CitizenID;
}
void Customer :: AddBirthDate(){
    cin >> BirthDate;
}
void Customer :: AddPhoneNumber(){
    cin >> PhoneNumber;
}
void Customer :: AddTypeAccount(){
    cin >> TypeAccount;
}
bool Customer :: AddMoney(){
    cout << "Money: ";
    if(TypeAccount == 1){
        cin >> Money;
        if(Money < 500){
            AddMoney();
        }
        else{
            return true;
        }
    }
    else if(TypeAccount == 2){
        cin >> Money;
        if(Money < 20000){
            AddMoney();
        }
        else{
            return true;
        }
    }
    return false;
}
void Customer :: Registercustomer(){
    LoadFileRegisterCustomer();
    ss << Money;
    ss >> money;
    if(TypeAccount == 1){
        AddInfoRegisterCustomer(Name,CitizenID,BirthDate,PhoneNumber,"10",money);
    }
    else if(TypeAccount == 2){
        AddInfoRegisterCustomer(Name,CitizenID,BirthDate,PhoneNumber,"20",money);
    }
    SaveInfoRegisterCustomerToFile();
}
bool Customer :: login(string username,string password){
    BankAccount Account;
    if(Account.login(username,password)){
        return true;
    }
    return false;
}