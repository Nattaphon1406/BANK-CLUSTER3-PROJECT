#ifndef INFORMATION_H
#define INFORMATION_H
#include <fstream>
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
class Information{
  private:
    class Info_Customer : public Customer{
      public:
        Info_Customer *link;
        Info_Customer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money);
    };
    class Info_BankClerk: public BankClerk{
      public:
        Info_BankClerk *link;
        Info_BankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password);
    };
    class Info_BankAccount : public BankAccount{
      public:
        Info_BankAccount *link;
        Info_BankAccount(string name,string accountNumber,string money,string username,string password);
        //Call Funtion Info From class Person
    };
    Info_Customer *HeadInfo_Customer,*TailInfo_Customer;
    Info_BankClerk *HeadInfo_BankClerk,*TailInfo_BankClerk;
    Info_BankAccount *HeadInfo_BankAccount,*TailInfo_BankAccount;
    int Count_Customer,Count_BankClerk,Count_BankAccount;
  public:
    Information();
    ~Information();
    void LoadFileRegisterCustomer();
    //LoadInfo Of Customer From File "RegisterCustomer.dat"
    void LoadFileBankAccount();
    //LoadInfo Of BankAccount From File "BankAccount.dat"
    void LoadFileBankClerk();
    //LoadInfo Of BankClerk From File "BankClerk.dat"
    void AddInfoRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money);
    //Add InfoInfo to Info(Customer Data)
    void AddInfoBankAccount(string name,string accountNumber,string money,string username,string password);
    //Add InfoInfo to Info(BankAccount Data)
    void AddInfoBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password);
    //Add InfoInfo to Info(BankClerk Data)
    void RemoveInfoRegisterCustomer(int Number);
    //Remove Info's Account at File "RegisterCustomer.dat"
    void RemoveInfoBankAccount(string AccountNumber);
    //Remove Info's Account at File "RegisterBankAccount.dat"
    void RemoveInfoBankClerk(int Number);
    //Remove Info's Account at File "RegisterBankClerk.dat"
    void SaveInfoRegisterCustomerToFile();
    //Save InfoInfo to File "RegisterBankAccount.dat"
    void SaveInfoCustomerToFile();
    //Save InfoInfo to File "BankAccount.dat"
    void SaveInfoBankClerkToFile();
    //Save InfoData_BankClerk to File "Data_BankClerk.dat"
    void ShowRegistercustomer();
    void ShowBankclerk();
    void ShowBankAccount();
};
#endif