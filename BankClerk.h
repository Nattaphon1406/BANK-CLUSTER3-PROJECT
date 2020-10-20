#ifndef BANKCLERK_H
#define BANKCLERK_H
#include <iostream>
#include <string>
using namespace std;
class BankClerk{
    private:
        string Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password;
    public:
        BankClerk();
        void SetInfoBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password);
        string getName();
        string getCitizenID();
        string getBirthDate();
        string getPhoneNumber();
        string getClerkID();
        string getPassword();
        //Save Info Of BankClerk
};
#endif