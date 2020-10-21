#ifndef INFORMATION_H
#define INFORMATION_H
#include <fstream>
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
class Information{
  private:
    class Info{
      public:
        Info *link;
        Customer customer;
        BankAccount bankaccount;
        BankClerk bankclerk;
        Info(Customer Data);
        Info(BankAccount Data);
        Info(BankClerk Data);
        //Call Funtion Info From class Person
    };
    Info *HeadInfo,*TailInfo;
    int CountAmount;
  public:
    Information();
    ~Information();
    void LoadFileRegisterCustomer();
    //LoadInfo Of Customer From File "RegisterCustomer.dat"
    void LoadFileBankAccount();
    //LoadInfo Of BankAccount From File "BankAccount.dat"
    void LoadFileBankClerk();
    //LoadInfo Of BankClerk From File "BankClerk.dat"
    void AddInfoRegisterCustomer(Customer Data);
    //Add InfoInfo to Info(Customer Data)
    void AddInfoBankAccount(BankAccount Data);
    //Add InfoInfo to Info(BankAccount Data)
    void AddInfoBankClerk(BankClerk Data);
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
    void Show();
};
#endif