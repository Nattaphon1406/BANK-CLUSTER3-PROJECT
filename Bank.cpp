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
    //void Info(string Name,string CitizenID,string BirthDate,string PhoneNumber);
    //Save Information
};
class Information{
  protected:
    class Customer : public Person{
      public:
        Customer *link;
        string TypeAccount,Money;
        Customer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money){
          Name = name;
          CitizenID = citizenID;
          BirthDate = birthDate;
          PhoneNumber = phoneNumber;
          TypeAccount = typeAccount;
          Money = money;
        }
    };
    class BankClerk : public Person{
      public:
        BankClerk *link;
        string ClerkID,Password;
        BankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
          Name = name;
          CitizenID = citizenID;
          BirthDate = birthDate;
          PhoneNumber = phoneNumber;
          ClerkID = clerkID;
          Password = password;
        }
    };
    Customer *HeadCustomer,*TailCustomer;
    BankClerk *HeadBankClerk,*TailBankClerk;
    int CustomerAmount,BankClerkAmonut;
  public:
    Information(){
      HeadCustomer = NULL;
      HeadBankClerk = NULL;
      TailCustomer = NULL;
      TailBankClerk = NULL;
      CustomerAmount = 0;
      BankClerkAmonut = 0;
    }
    ~Information(){
      for(int i = 0; i < CustomerAmount; i++){
        Customer * tmp = HeadCustomer;
        HeadCustomer = HeadCustomer->link;
        delete tmp;
        tmp = NULL;
      }
      for(int i = 0; i < BankClerkAmonut; i++){
        BankClerk * ptmp = HeadBankClerk;
        HeadBankClerk = HeadBankClerk->link;
        delete ptmp;
        ptmp = NULL;
      }
      HeadCustomer = NULL;
      HeadBankClerk = NULL;
      TailCustomer = NULL;
      TailBankClerk = NULL;
      CustomerAmount = 0;
      BankClerkAmonut = 0;
    }
    void LoadFileRegisterCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ifstream Read;
      CustomerAmount = 0;
      HeadCustomer = NULL;
      TailCustomer = NULL;
      Read.open("RegisterAccountCustomer.dat");
      if(Read.fail()){
        cout << "Can not Read File 'RegisterAccountCustomer.dat' " << endl;
      }
      else{
          while(getline(Read,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              TypeAccount = Line.substr(0,Line.find(','));
              BirthDate = Line.erase(0,Line.find(',')+1);
              AddCustomer(Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money);
          }
          Read.close();
      }
    }
    //LoadInfo Of Customer From File "RegisterAccountCustomer.dat"
    void LoadFileCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ifstream Read;
      CustomerAmount = 0;
      HeadCustomer = NULL;
      TailCustomer = NULL;
      Read.open("AccountCustomer.dat");
      if(Read.fail()){
        cout << "Can not Read File 'AccountCustomer.dat' " << endl;
      }
      else{
          while(getline(Read,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              TypeAccount = Line.substr(0,Line.find(','));
              BirthDate = Line.erase(0,Line.find(',')+1);
              AddCustomer(Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money);
          }
          Read.close();
      }
    }
    //LoadInfo Of Customer From File "AccountCustomer.dat"
    void LoadFileBankClerk();
    //LoadInfo Of BankClerk From File "BankClerk.dat"
    void AddCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money){
      Customer *newCustomer = new Customer(name,citizenID,birthDate,phoneNumber,typeAccount,money);
            if(HeadCustomer == NULL){
                HeadCustomer = newCustomer;
                TailCustomer = newCustomer;
            }
            else{
                TailCustomer->link = newCustomer;
                TailCustomer = newCustomer;
            }
            CustomerAmount++;
    }
    //Add InfoCustomer to Customer(node)
    void AddBankClerk(string ClerkID,string Password);
    //Add InfoBankClerk to BankClerk(node)
    void RemoveRegisterAccountCustomer(string FullName);
    //Remove Customer's Account at File "RegisterAccountCustomer.dat"
    void SaveRegisterCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ofstream Read("RegisterAccountCustomer.dat");
        if(Read){
            for(Customer *i = HeadCustomer; i != NULL; i = i->link){
                Read << i->Name << "," << i->CitizenID << "," << i->BirthDate << "," << i->BirthDate << "," << i->PhoneNumber << endl;
            }
        }
      Read.close();
    }
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
int main(){

}


