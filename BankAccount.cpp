#include "BankAccount.h"
BankAccount :: statementBill :: statementBill(string name,string accountNumber,string type,string money,string date,string time){
    Name = name;
    AccountNumber = accountNumber;
    Type = type;
    Money = money;
    Date = date;
    Time = time;
    linkBill = NULL;
}
BankAccount :: statementBillBankclerk :: statementBillBankclerk(string type,string money,string date,string time){
    Type = type;
    Money = money;
    Date = date;
    Time = time;
    linkBillBankclerk = NULL;
}
BankAccount :: statementDeposit :: statementDeposit(string name,string account,string money,string balance,string date,string time){
    this->Name = name;
    this->AccountNumber = account;
    this->Money = money;
    this->Balance = balance;
    this->Date = date;
    this->Time = time;
    link = NULL;
}
BankAccount :: statementWithdraw :: statementWithdraw(string name,string account,string money,string balance,string date,string time){
    this->Name = name;
    this->AccountNumber = account;
    this->Money = money;
    this->Balance = balance;
    this->Date = date;
    this->Time = time;
    Withdrawlink = NULL;
}
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
    this->headBill = NULL;
    this->tailBill = NULL;
    this->tempBill = NULL;
    this->Withdrawhead=NULL;
    this->Withdrawtail=NULL;
    countStatment = 0;
    this->Obj_BankAccount = NULL;
    this->temp = NULL;
    this->headBillBankclerk = NULL;
    this->tailBillBankclerk = NULL;
    this->tempBillBankclerk = NULL;
	coutBillBankclerk = 0;
    count_deposit = 0;
    head_deposit = NULL;
    tail_deposit = NULL;
}
void BankAccount :: AddStatementBillCustoment(string name,string accountNumber,string type,string money,string date,string time){
     statementBill *bill = new statementBill(name,accountNumber,type,money,date,time);
            if(headBill == NULL){
                headBill = bill;
                tailBill = bill;
            }
            else{
                tailBill->linkBill = bill;
                tailBill = bill;
            }
            Count_Customer++;
}
void BankAccount :: AddStatementWithdraw(string name,string accountNumber,string money,string balance,string date,string time){
    statementWithdraw *newnode = new statementWithdraw(name,accountNumber,money,balance,date,time);
            if(Withdrawhead == NULL){
                Withdrawhead = newnode;
                Withdrawtail = newnode;
            }
            else{
                Withdrawtail->Withdrawlink = newnode;
                Withdrawtail = newnode;
            }
            
}
void BankAccount :: AddStatementBillBankclerk(string type,string money,string date,string time){
     statementBillBankclerk *next = new statementBillBankclerk(type,money,date,time);
            if(headBill == NULL){
                headBillBankclerk = next;
                tailBillBankclerk = next;
            }
            else{
                tempBillBankclerk->linkBillBankclerk = next;
                tempBillBankclerk = next;
            }
            coutBillBankclerk++;
}
void BankAccount :: AddStatementBill_deposit(string name,string account,string money,string balance,string date,string time){
     statementDeposit *NewNode = new statementDeposit(name,account,money,balance,date,time);
            if(headBill == NULL){
                head_deposit = NewNode;
                tail_deposit = NewNode;
            }
            else{
                statementDeposit *temp = NewNode;
                tail_deposit->link = NewNode;  
                temp = NewNode;
            }
            count_deposit++;
}
bool BankAccount :: login(string username,string password){
	LoadFileBankAccount();
	Info_BankAccount *Account;
    for(Account = HeadInfo_BankAccount; Account != NULL; Account = Account->link){
        if((Account->Username == username) && (Account->Password == password)){
            return true;
        }
    }
    return false;
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
string BankAccount::getBalance(string Account)
{
    Info_BankAccount *temp;
    for(temp=HeadInfo_BankAccount;temp!=NULL;temp=temp->link)
    {
        if(temp->AccountNumber == Account)
        {
			string NewBalance= "";
			NewBalance = temp->Money;
			return NewBalance;
        }
    }
}
bool BankAccount :: CheckAccount(string Account){
	temp=HeadInfo_BankAccount;
	for(temp=HeadInfo_BankAccount;temp!=NULL ;temp=temp->link){
		if(temp->AccountNumber==Account){
            Account_number = Account;
            Name = temp->Name;
            Money = temp->Money;
			return true;
		}
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
unsigned long BankAccount :: getMoney(){
	unsigned long int m;
	stringstream money;
	money<<temp->Money;
	money>>m;
    moneyAccount = m;
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
            setName();
            printBill_of_deposit(NewBalance);
			updateMoney_to_BankAccount();
        }
    }   
}
void BankAccount::updateMoney_to_BankAccount()
{
    SaveInfoCustomerToFile();
}
void BankAccount::updateExchangeMoney_to_BankAccount(string Balance,string Account)
{
    SaveInfoBalanceToFile(Balance,Account);
}
void BankAccount :: WriteStatement_deposit(){
    statementDeposit *temp;
    string fileName,data;
    fstream myfile;
    fileName = "StatemenDeposit.dat";
    myfile.open(fileName.c_str(),std::ios::app);
    temp = head_deposit;
    while(temp!=NULL){
        myfile << temp->Name << "," << temp->AccountNumber << "," << temp->Money << "," << temp->Balance << "," << temp->Date << "," << temp->Time << endl;
		temp = temp->link;
	}
	myfile.close();
}
void BankAccount::printBill_of_deposit(string amount)
{
    stringstream ss;
    string money;
    string Date,Time;
    Date = Day + "-" + Month + "-" + Year;
    Time =  Hours + ":" + Minute + ":" + Second;
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
    ss << Cash;
    ss >> money;
    ss.clear();
    AddStatementBill_deposit(Name,Account_number,money,amount,Date,Time);
    WriteStatement_deposit();
}
string BankAccount :: setDateandTime(){
    string Date,Time;
	time_t 	   now = time(0);
	struct tm  tstruct;
	char       date[80],time[80];
	tstruct = *localtime(&now);
	strftime(date, sizeof(date), "%Y-%m-%d", &tstruct);
	strftime(time, sizeof(time), "%X", &tstruct);

    Date = date;
    Time = time;
    return Date+","+Time;
}
bool BankAccount :: CheckUser(string user){
	temp=HeadInfo_BankAccount;
	for(temp=HeadInfo_BankAccount;temp!=NULL ;temp=temp->link){
		if(temp->Username==user){
			return true;
		}
	}
    return false;	
}
void BankAccount :: payBill(string type,string group, long double amount){
    unsigned long int getmoney,balance=0,fee=0;
    string TypeBill = " ", chaengceMoney = " ", Amount = " ", date = " ", time = " ", namefile = " ";
    stringstream ss; 
    //setTime
    date=setDateandTime();
    time=date.substr((date.find(",")+1),date.find(" "));
    date=date.substr(0,date.find(","));

    if(type == "customer"){//Customer
        ss << Money;
        ss >> getmoney;
        ss.clear();
        //cout << "MoneyAc: " << moneyAccount << endl;
        if(getmoney>amount){
            if(group=="1"){
                TypeBill = "Water bill";
                getmoney = getmoney - amount;
                fee = 5;
                balance = getmoney - fee;
                cout << balance << endl;
            }
            else if(group=="2"){
                TypeBill = "Electricity bill";
                getmoney = getmoney - amount;
                fee = 8;
                balance = getmoney - fee;
                cout << balance << endl;
            }
            else if(group=="3"){
                TypeBill = "Phone bill";
                getmoney = getmoney - amount;
                fee = 10;
                balance = getmoney - fee;
                cout << balance << endl;
            }
            cout << "*********Bill********" << endl;
            cout << "TypeBill: " << TypeBill << endl;
            cout << "Fee: " << fee << " baht"<< endl;
            cout << "Balance: " <<  balance << " baht" << endl;
            cout << "Date: " << date << " : " << time << endl;
            //ChangData at File Account
            ss << balance;
            ss >> chaengceMoney;
            ss.clear();
            ss << amount;
            ss >> Amount;
            ss.clear();
            //update money to account
            for(temp = HeadInfo_BankAccount;temp !=NULL ; temp = temp->link){
                if(Account_number==temp->AccountNumber){
                        temp->Money = chaengceMoney;
                }
            }
  
            SaveInfoCustomerToFile();//saveFile
            AddStatementBillCustoment(Name,Account_number,TypeBill,Amount,date,time);//addNode
            namefile = "StatementCustomerBill.dat";
            WriteStatementCustomer(namefile,Name,Account_number,TypeBill,Amount,date,time);
        }
        else{
            cout << "The amount is not enough" << endl;
        }
    }
    else if(type == "Bankclerk"){//Bank clerk
        if(group=="1"){
			TypeBill = "Water bill";
            fee = 5;
        }
        else if(group=="2"){
			TypeBill = "Electricity bill";
            fee = 8;
        }
        else if(group=="3"){
			TypeBill = "Phone bill";
            fee = 10;
        }
		ss << amount;
        ss >> Amount;
        ss.clear();

		cout << "*********Bill********" << endl;
        cout << "TypeBill: " << TypeBill << endl;
        cout << "Fee: " << fee << " baht"<< endl;
        cout << "Amonut: " <<  Amount << " baht" << endl;
        cout << "Date: " << date << " : " << time << endl;

        AddStatementBillBankclerk(TypeBill,Amount,date,time);
        namefile = "StatementBankclerkBill.dat";
        WriteStatementBankclerk(namefile,TypeBill,Amount,date,time);
    }
}
void BankAccount :: WriteStatementCustomer(string filename,string nameAc,string accountNumber,string TypeBill,string Amount,string date,string time){
    string fileName;
    fstream myfile;
    fileName = filename;
    myfile.open(fileName.c_str(),std::ios::app);
    myfile << nameAc << "," << accountNumber << "," << TypeBill << "," << Amount << "," << date << "," << time<< endl;
	myfile.close();
}
void BankAccount :: WriteStatementBankclerk(string filename,string TypeBill,string Amount,string date,string time){
    string fileName;
    fstream myfile;
    fileName = filename;
    myfile.open(fileName.c_str(),std::ios::app);
    myfile << TypeBill << "," << Amount << "," << date << "," << time << endl;
	myfile.close();
}
bool BankAccount :: CheckTransfer_Account(string accountNumber){
	for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){
        if(accountNumber == temp->AccountNumber){	
			return true;
	    } 
    } 
    return false; 
} 
string BankAccount::getName(){
    return temp->Name;
}
void BankAccount :: WithdrawBill(int withdraw){
    string w,date, time;

    //setTime
    date=setDateandTime();
    time=date.substr((date.find(",")+1),date.find(" "));
    date=date.substr(0,date.find(","));
    //cout<<date<<"==============="<<time<<endl;
    stringstream ss;
    ss<<withdraw;
    ss>>w;
    ss.clear();
    SaveInfoCustomerToFile();
    AddStatementWithdraw(temp->Money,time,date,w,temp->AccountNumber,temp->Name);
    WriteStatementWithdraw();
}
void BankAccount :: WriteStatementWithdraw(){
    statementWithdraw *newn;
    ofstream myfile("WithdrawStatement.dat",ios::app);
    if(myfile.is_open()){
        //temp = Withdrawhead;
        //while(temp!=NULL){
            //cout<< newn->Name << "," << newn->AccountNumber << "," << newn->Money << "," << newn->Balance << "," << newn->Date << "," << newn->Time << endl;
            myfile << newn->Name << "," << newn->AccountNumber << "," << newn->Money << "," << newn->Balance << "," << newn->Date << "," << newn->Time << endl;
            newn = newn->Withdrawlink;
        //}
        myfile.close();
    }
    
}
string BankAccount :: getname_TransferorBC(string accountNumber){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            return temp->Name;
        } 
    }       
}
string BankAccount :: getname_TransferorCT(string username){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            return temp->Name;
        } 
    }       
}
string BankAccount :: getname_recipient(string Recipient_account){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(Recipient_account == temp->AccountNumber){
            return temp->Name;
        } 
    }       
}
string BankAccount :: getmoneyBC(string accountNumber){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            return temp->Money;
        } 
    }       
}
string BankAccount :: getmoneyCT(string username){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            return temp->Money;
        } 
    }       
}
string BankAccount :: getAccountNumber(string username){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            return temp->AccountNumber;
        } 
    }       
}
bool BankAccount :: Check_RecipientAccount(string Recipient_account){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){
        if(Recipient_account == temp->AccountNumber){	
			return true;
	    } 
    } 
    return false; 
} 
bool BankAccount :: CheckTransfer_AddMoney(int money,string Recipient_account){
    LoadFileBankAccount();
    int Moneyint;
    string Moneystring;
    ofstream myfile("BankAccount.dat");
    stringstream ss,aa;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(Recipient_account == temp->AccountNumber){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            Moneyint = Moneyint + money; 
            aa << Moneyint;
            aa >> Moneystring;
            aa.clear();   
            temp->Money = Moneystring; 
            SaveInfoCustomerToFile();
            return true;    
        }
    }
    return false;    
}
bool BankAccount :: CheckTransfer_DeductMoneyBankclerk(int money,string accountNumber){
    LoadFileBankAccount();
    int Moneyint;
    string Moneystring;
    ofstream myfile("BankAccount.dat");
    stringstream ss,aa;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                Moneyint = Moneyint - money; 
                aa << Moneyint;
                aa >> Moneystring;
                aa.clear();   
                temp->Money = Moneystring; 
                SaveInfoCustomerToFile();
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_DeductMoneyBankOtherBC(int money,string accountNumber){
    LoadFileBankAccount();
    int Moneyint;
    string Moneystring;
    ofstream myfile("BankAccount.dat");
    stringstream ss,aa;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                Moneyint = Moneyint - money - 10; 
                aa << Moneyint;
                aa >> Moneystring;
                aa.clear();   
                temp->Money = Moneystring; 
                SaveInfoCustomerToFile();
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_DeductMoneyBankOtherCT(int money,string username){
    LoadFileBankAccount();
    int Moneyint;
    string Moneystring;
    ofstream myfile("BankAccount.dat");
    stringstream ss,aa;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                Moneyint = Moneyint - money - 10; 
                aa << Moneyint;
                aa >> Moneystring;
                aa.clear();   
                temp->Money = Moneystring; 
                SaveInfoCustomerToFile();
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}

bool BankAccount :: CheckTransfer_DeductMoneyCustomer(int money,string username){
    LoadFileBankAccount();
    int Moneyint;
    string Moneystring;
    ofstream myfile("BankAccount.dat");
    stringstream ss,aa;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                Moneyint = Moneyint - money; 
                aa << Moneyint;
                aa >> Moneystring;
                aa.clear();   
                temp->Money = Moneystring; 
                SaveInfoCustomerToFile();
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
string BankAccount :: getDateandTimeTransfer(){
    string Date,Time;
	time_t 	   now = time(0);
	struct tm  tstruct;
	char       date[80],time[80];
	tstruct = *localtime(&now);
	strftime(date, sizeof(date), "%Y-%m-%d", &tstruct);
	strftime(time, sizeof(time), "%X", &tstruct);

    Date = date;
    Time = time;
    return Date+","+Time;
}
void BankAccount :: statementTransfer_customer(string transferor,string recipient,string money_file,string Service_charge,string date){
    std::fstream myfile;
    myfile.open("StatementTransfer.dat", std::ios::out | std::ios::app);
    myfile << transferor << "," << recipient << "," << money_file << "," << Service_charge << "," << date << endl;
    myfile.close();
}
bool BankAccount :: CheckTransfer_AccountMoneyCustomerOther(int money,string username){
    int Moneyint;
    stringstream ss;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= (money+10)){
                return true;
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_AccountMoneyBankClerkOther(int money,string accountNumber){
    int Moneyint;
    stringstream ss;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= (money+10)){
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_AccountMoneyCustomer(int money,string username){
    int Moneyint;
    stringstream ss;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(username == temp->Username){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_AccountMoneyBankClerk(int money,string accountNumber){
    int Moneyint;
    stringstream ss;
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(accountNumber == temp->AccountNumber){
            ss << temp->Money; 
            ss >> Moneyint; 
            ss.clear(); 
            if(Moneyint >= money){
                return true;    
            }
            else{
                return false;
            }
        }    
    }
}
bool BankAccount :: CheckTransfer_AccountMoneyOther(string Recipient_account){
    for(temp = HeadInfo_BankAccount ; temp != NULL ; temp = temp->link){ 
        if(Recipient_account == temp->AccountNumber){
            return true;
        }
    }
    return false;
}



