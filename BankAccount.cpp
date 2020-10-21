#include "BankAccount.h"
BankAccount :: BankAccount(){
    Name = "";
    AccountNumber = "";
    Money = "";
    Username = "";
    Password = "";
}
void BankAccount :: SetInfoBankAccount(string name,string accountNumber,string money,string username,string password){
    Name = name;
    AccountNumber = accountNumber;
    Money = money;
    Username = username;
    Password = password;
}
string BankAccount :: getName(){
    return Name;
}
string BankAccount :: getAccountNumber(){
    return AccountNumber;
}
string BankAccount :: getMoney(){
    return Money;
}
string BankAccount :: getUsername(){
    return Username;
}
string BankAccount :: getPassword(){
    return Password;
}
        //Save Info Of BankAccount