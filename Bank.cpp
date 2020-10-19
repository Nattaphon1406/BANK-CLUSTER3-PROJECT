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
  public:
    string Name,CitizenID,BirthDate,PhoneNumber;
    Person();
    ~Person();
    void Info(string Name,string CitizenID,string BirthDate,string PhoneNumber);
    //Save Information
};
class Information{
  protected:
    class Customer : public Person{
      public:
        Customer *link;
        string TypeAccount,money;
        Customer(string Name,string CitizenID,string BirthDate,string PhoneNumber,string TypeAccount,string money);
    };
    class BankClerk{
      public:
        BankClerk *link;
        string ClerkID,Password;
        BankClerk(string Name,string CitizenID,string BirthDate,string PhoneNumber,string ClerkID,string Password);
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
class BankAccount : public Information{
  private:
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
    BankAccount(){
      Customer *D;
      D = HeadCustomer;
    }
    ~BankAccount();
    void GenerateAccountNumber(){
    }
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
void MainMenu(){
  cout << "******************************" << endl;
  cout << "1.Register" << endl;
  cout << "2.Login" << endl;
  cout << "3.Exit" << endl;
  cout << "******************************" << endl;
}
void RegisterMenu(){
  cout << "******************************" << endl;
  cout << "1.Register Customer" << endl;
  cout << "2.Register BankClerk" << endl;
  cout << "3.Back" << endl;
  cout << "******************************" << endl;
}
void LoginMenu(){
  cout << "******************************" << endl;
  cout << "1.Login Customer" << endl;
  cout << "2.Login BankClerk" << endl;
  cout << "3.Back" << endl;
  cout << "******************************" << endl;
}
void ClerkMenu(){
  cout << "******************************" << endl;
  cout << "1.AddCustomerAccount" << endl;
  cout << "2.RemoveCustomerAccount" << endl;
  cout << "3.Deposit" << endl;
  cout << "4.Withdraw" << endl;
  cout << "5.Transfer" << endl;
  cout << "6.PayBill" << endl;
  cout << "7.MoneyExchange" << endl;
  cout << "8.Statement" << endl;
  cout << "9.Back" << endl;
  cout << "******************************" << endl;
}
void CustomerMenu(){
  cout << "******************************" << endl;
  cout << "1.Transfer" << endl;
  cout << "2.PayBill" << endl;
  cout << "3.Statement" << endl;
  cout << "4.Back" << endl;
  cout << "******************************" << endl;
}



