/*Program Name : Bank
  Student Group : 3
  Date : 6/10/63
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class Person{
  protected:
    string Name,CitizenID,BirthDate,PhoneNumber;
  public:
    Person();
    ~Person();
    void Info(string Name,string CitizenID,string BirthDate,string PhoneNumber);
    //Save Information
};
class Information{
  protected:
    class Customer : public Person{
      private:
        Customer *link;
        string TypeAccount,money;
        Customer(string TypeAccount,string money);
        //Call Funtion Info From class Person
    };
    class BankClerk : public Person{
      private:
        BankClerk *link;
        string ClerkID,Password;
        BankClerk(string ClerkID,string Password);
        //Call Funtion Info From class Person
    };
    Customer *HeadCustomer,*TailCustomer;
    BankClerk *HeadBankClerk,*TailBankClerk;
    int CustomerAmount,BankClerkAmonut;
  public:
    Information();
    ~Information();
    void LoadFileRegisterCustomer();
    //LoadInfo Of Customer From File "RegisterAccountCustomer.dat"
    void LoadFileCustomer();
    //LoadInfo Of Customer From File "AccountCustomer.dat"
    void LoadFileBankClerk();
    //LoadInfo Of BankClerk From File "BankClerk.dat"
    void AddCustomer(string TypeAccount);
    //Add InfoCustomer to Customer(node)
    void AddBankClerk(string ClerkID,string Password);
    //Add InfoBankClerk to BankClerk(node)
    void RemoveRegisterAccountCustomer(string FullName);
    //Remove Customer's Account at File "RegisterAccountCustomer.dat"
    void SaveRegisterCustomer();
    //Save InfoCustomer to File "RegisterAccountCustomer.dat"
    void SaveCustomerInfoToFile();
    //Save InfoCustomer to File "AccountCustomer.dat"
    void SaveBankClerkInfoToFile();
    //Save InfoBankClerk to File "BankClerk.dat"
};
/*class Bank{
  protected:
    Information *Info;
    string AccountNumber;
    int EntranceFee,MoneyAmount;
  public:
  Bank();
    void GenerateAccountNumber();
    //GenerateAccountNumber | AccountNumber = GenerateAccountNumber
};*/
class BankAccount{
  private:
  Information *Info;
  string AccountNumber,ClerkID,PasswordClerk,PasswordCustomer;
  double MoneyAmount;
    /*class DepositAccount : public BankAccount{
      private:
        DepositAccount *link;
        DepositAccount();
        //Call Funtion GenerateAccountNumber From class BankAccount
        //Add AccountNumber in File "AccountCustomer.dat"
    };
    class SavingAccount : public BankAccount{
      private:
        SavingAccount *link;
        string DepositAmount;
        SavingAccount();
        //Call Funtion GenerateAccountNumber From class BankAccount
        //Add AccountNumber in File "AccountCustomer.dat"

    };*/
    //DepositAccount *Deposit;
    //SavingAccount *Saving;
  public:
    BankAccount();
    ~BankAccount();
    void GenerateAccountNumber();
    //GenerateAccountNumber add to File "AccountCustomer.dat"
    void GeneratePasswordOfCustomer();
    //GeneratePassword And return password to File "AccountCustomer.dat"
    void CalculateDeposit();
    //Calculate Money In Account
    void RemoveCustomer(string AccountNumber);
    //Remove Customer's Account at File "AccountCustomer.dat"
    void RemoveAllCustomer();
    //Remove All Customer Account at File "AccountCustomer.dat"
    void RemoveBankClerk(string ClerkID);
    //Remove BankClerk's Account at File "BankClerk.dat"
    void RemoveAllBankClerk();
    //Remove All BankClerk Account at File "BankClerk.dat"
};
void MainMenu();
void RegisterMenu();
void LoginMenu();
void ClerkMenu();
void CustomerMenu();


