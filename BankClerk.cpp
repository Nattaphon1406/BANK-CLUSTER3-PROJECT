#include "BankClerk.h"
BankClerk :: BankClerk(){
    Name = "";
    CitizenID = "";
    BirthDate = "";
    PhoneNumber = "";
    ClerkID = "";
    Password = "";;
}
void BankClerk :: SetInfoBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
    Name = name;
    CitizenID = citizenID;
    BirthDate = birthDate;
    PhoneNumber = phoneNumber;
    ClerkID = clerkID;
    Password = password;
}
string BankClerk :: getName(){
    return Name;
}
string BankClerk :: getCitizenID(){
    return CitizenID;
}
string BankClerk :: getBirthDate(){
    return BirthDate;
}
string BankClerk :: getPhoneNumber(){
    return PhoneNumber;
}
string BankClerk :: getClerkID(){
    return ClerkID;
}
string BankClerk :: getPassword(){
    return Password;
}
        //Save Info Of BankClerk