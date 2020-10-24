#include "BankAccount.h"
BankAccount::BankAccount()
{
    Name = "";
    Account_number = "";
    Cash = 0;
    Balance = 0;
	Money = "";
    Day = "";
    Month = "";
    Year = "";
    Hours = "";
    Minute = "";
    Second = "";
}
void BankAccount::setData_deposit(string account,unsigned long int cash)
{
    Account_number = account;
    Cash = cash;
}
void BankAccount::setName()
{
    Info_BankAccount *temp;
    for(temp = HeadInfo_BankAccount;temp!=NULL;temp = temp->link)
    {
        if(temp->AccountNumber == Account_number)
        {
            Name = temp->Name;
        }
    }
}
void BankAccount::setBalance()
{
    Info_BankAccount *temp;
    for(temp=HeadInfo_BankAccount;temp!=NULL;temp=temp->link)
    {
        if(temp->AccountNumber == Account_number)
        {
			string NewBalance= "";
			stringstream ss;
			NewBalance = temp->Money;
			ss << NewBalance;
			ss >> Balance;
        }
    }
}
bool BankAccount :: CheckAccount(string Account){
	temp=HeadInfo_BankAccount;
	for(temp=HeadInfo_BankAccount;temp!=NULL ;temp=temp->link){
		if(temp->AccountNumber==Account){
			return true;
		}
	}	
}
bool BankAccount :: CheckTransfer_account(string accountNumber){
    string name;
	for(HeadInfo_BankAccount = HeadInfo_BankAccount;HeadInfo_BankAccount != NULL; HeadInfo_BankAccount = HeadInfo_BankAccount->link){
        if(accountNumber == HeadInfo_BankAccount->AccountNumber){
			name = HeadInfo_BankAccount->Name;
			return true;
		}
		HeadInfo_BankAccount = HeadInfo_BankAccount->link;
	}
	return false;
}
void BankAccount :: Withdraw(unsigned long int withdraw){
    double m;
    stringstream tmp;
    tmp<<temp->Money;
    tmp>>m;
    tmp.clear();
    m=m-withdraw;
    tmp<<m;
    tmp>>temp->Money;
    tmp.clear();
}
double BankAccount :: getMoney(){
	unsigned long int m;
	stringstream money;
	money<<temp->Money;
	money>>m;
	money.clear();
	return m;
}
void BankAccount::AddMoney()
{
    setBalance();
	int day,month,year,hour,minute,second;
	unsigned long int sum = 0;
	stringstream ss;
	string NewBalance;
	//calculate add money
    sum = Balance + Cash;
    //tranfrom money for deposit then after calculate from unsigned long integer become to string
    ss << sum;
    ss >> Money;
    ss.clear();
    //save date ane time fo deposit
    	// current date/time based on current system
			time_t rawtime;
			struct tm *local;
			// Get current time
			time(&rawtime);
			// Convert to time structure
			local = localtime(&rawtime);
			year = local->tm_year;//years
 			month = 1 + local->tm_mon;//month
  			day = local->tm_mday;//day
   			hour = local->tm_hour;//hours
   			minute = local->tm_min;//minute
   			second = local->tm_sec;//second
        // tranfrom date and time type integer become to string 
            ss << year;
            ss >> Year;
            ss.clear();
            ss << month;
            ss >> Month;
            ss.clear();
            ss << day;
            ss >> Day;
            ss.clear();
            ss << day;
            ss >> Day;
            ss.clear();
            ss << hour;
            ss >> Hours;
            ss.clear();
            ss << minute;
            ss >> Minute;
            ss.clear();
            ss << second;
            ss >> Second;
            ss.clear();
    //update money to account
    for(Info_BankAccount *temp = HeadInfo_BankAccount;temp!=NULL;temp=temp->link)
    {
        if(temp->AccountNumber == Account_number)
        {
            ss << sum;
            ss >> NewBalance;
            ss.clear();
            temp->Money = NewBalance;
			updateMoney_to_BankAccount();
			printBill_of_deposit(NewBalance);
        }
    }   
}
void BankAccount::updateMoney_to_BankAccount()
{
    SaveInfoCustomerToFile();
}
void BankAccount::printBill_of_deposit(string amount)
{
    cout << "===================== Bill ===================" << endl;
    cout << "Name customer: " << Name << endl;
    cout << "Account number: " << Account_number << endl;
    cout << "Date: " << Day << "-" << Month << "-" << Year << endl;
    cout << "Time: " << Hours << ":" << Minute << ":" << Second << endl;
    cout << "----------------------------------------------" << endl;
    cout << "List of deposit" << endl;
    cout << "Add : " << Cash << endl;
    cout << "Balance : " << amount << endl;
    cout << "==============================================" << endl;
}