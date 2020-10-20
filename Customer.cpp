#include "Customer.h"
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