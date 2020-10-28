#include"Statement.h"
Statement::Deposit::Deposit(string name,string account,string money,string balance,string date,string time){
		link = NULL;
		this->Name = name;
		this->AccountNumber = account;
		this->AmountMoney = money;
		this->Balance = balance;
		this->Date = date;
		this->Time = time;
}//node Deposit
Statement::withdraw::withdraw(string name,string account,string money,string balance,string date,string time){
		link = NULL;
		this->Name = name;
		this->AccountNumber = account;
		this->AmountMoney = money;
		this->Balance = balance;
		this->date = date;
		this->time = time;
}//node withdraw
Statement::MoneyExchange::MoneyExchange(string number,string currency,string money,string debited,string balance,string date,string time){
		link = NULL;
		//this->Name = name;
		this->AccountNumber = number;
		this->Currency = currency;
		this->AmountMoney = money;
		this->AmountDebited = debited;
		this->Balance = balance;
		this->Date = date;
		this->Time = time;
}//node for moneyExchange
Statement::PlayBill::PlayBill(string name,string account,string type,string money,string date,string time){
		link = NULL;
		this->Name = name;
		this->AccountNumber = account;
		this->Type = type;
		this->Amountmoney = money;
		//this->Balance = balance;
		this->Date = date;
		this->Time = time;
}//node for playbill
Statement::PlayBillBankclerk::PlayBillBankclerk(string type,string money,string date,string time){
		link = NULL;
		this->Type = type;
		this->Amountmoney = money;
		this->Date = date;
		this->Time = time;
}
Statement::Transfer::Transfer(string numberT,string numberR ,string money,string balance,string date,string time){
		link = NULL;
		this->AccountNumberT = numberT;
		this->AccountNumberR = numberR;
		this->Amountmoney = money;
		this->Balance = balance;
		this->Date = date;
		this->Time = time;

}
Statement::Statement(){
		head_deposit = NULL;
		tail_deposit = NULL;
		count_deposit = 0;
		head_withdraw = NULL;
		tail_withdraw = NULL;
		count_withdraw = 0;
		head_moneyExchange = NULL;
		tail_moneyExchange = NULL;
		count_moneyExchange = 0;
		head_playBill = NULL;
		tail_playBill = NULL;
		count_playBill = 0;
		head_Transfer = NULL;
		tail_Transfer = NULL;
		count_Transfer = 0;
		head_PlayBillBankclerk = NULL;
		tail_PlayBillBankclerk = NULL;
		count_PlayBillBankclerk = 0;
}//Statement
Statement::~Statement(){
		head_deposit = NULL;
		tail_deposit = NULL;
		count_deposit = 0;
		head_withdraw = NULL;
		tail_withdraw = NULL;
		count_withdraw = 0;
		head_moneyExchange = NULL;
		tail_moneyExchange = NULL;
		count_moneyExchange = 0;
		head_playBill = NULL;
		tail_playBill = NULL;
		count_playBill = 0;
		head_Transfer = NULL;
		tail_Transfer = NULL;
		count_Transfer = 0;
		head_PlayBillBankclerk = NULL;
		tail_PlayBillBankclerk = NULL;
		count_PlayBillBankclerk = 0;
}//~Statement
void Statement::AddData_deposit(string name,string account,string balance ,string money,string date,string time){
	Deposit *NewNode = new Deposit(name,account,balance,money,date,time);
		if(head_deposit == NULL){
			head_deposit = NewNode;
			tail_deposit = NewNode;
			count_deposit++;
    	}else{
			tail_deposit->link = NewNode;
			tail_deposit = NewNode;
			count_deposit++;
		}//else if
}//Add node deposit
bool Statement::ReadFile_deposit(){
	string fileName,filein,name,account,balance,money,date,time;
	fileName = "StatemenDeposit.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}//if
		else{
			while(getline(infile,filein)){
				name = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				account = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				balance = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_deposit(name,account,balance,money,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}//Readfiledeposit
void Statement::printName(string number){
	for(Deposit *i = head_deposit;i!=NULL;i=i->link){
		if(i->AccountNumber == number){
			cout << i->Name << endl;	
		}//if
	}//for
}//printName for deposit
void Statement::printData_deposit(string number){
	cout<<"======================================= Statement Deposition ==========================================================="<<endl;
	cout<<"Name:"; 
	printName(number);
				cout<<"AmountMoney"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<endl;
		for(Deposit *i = head_deposit;i!=NULL;i=i->link){
			if(i->AccountNumber == number){
				cout<<i->AmountMoney <<"\t\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t\t"<<i->Time<<endl;
			}//if
		}//for
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
}//prinDatadeposit cutomer
void Statement::printstatement_deposit(){
	cout<<"======================================= Statement Deposition =========================================================================="<<endl;
	cout<<"Name"<<setw(33)<<"\t"<<"AccountNumber"<<"\t\t"<<"AmountMoney"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for(Deposit *i = head_deposit;i!=NULL;i=i->link){
			cout<<setw(25)<<left<<i->Name<<setw(9)<<"\t"<<i->AccountNumber<<"\t\t"<<i->AmountMoney <<"\t\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t"<<i->Time<<endl;
		}//for
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}//printstatement Actor
void Statement::AddData_withdraw(string name,string account,string money,string balance,string date,string time){
	withdraw *NewNode = new withdraw(name,account,money,balance,date,time);
		if(head_withdraw == NULL){
			head_withdraw = NewNode;
        	tail_withdraw = NewNode;
        	count_withdraw++;
    	}else{
			tail_withdraw->link = NewNode;
			tail_withdraw = NewNode;
			count_withdraw++;
		}//else if
}//AddData for withdraw
bool Statement::Readfile_withdraw(){
	string fileName,filein,name,account,money,balance,date,time;
	fileName = "WithdrawStatement.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}//if
		else{
			while(getline(infile,filein)){
				name = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				account = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				balance =  filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_withdraw(name,account,money,balance,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}//Readfile for withdraw
void Statement::printName_withdraw(string number){
	for(withdraw *i = head_withdraw;i!=NULL;i=i->link){
		if(i->AccountNumber == number){
		cout<<i->Name << endl;	
		}//if
	}//for
}//printName for withdraw
void Statement::printData_withdraw(string number){
	cout<<"======================================= Statement Withdraw ==========================================================="<<endl;
	cout<<"Name:";
	printName_withdraw(number); 
	cout<<"Withdraw"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<endl;
		for(withdraw *i = head_withdraw;i!=NULL;i=i->link){
			if(i->AccountNumber == number){
				cout<<i->AmountMoney <<"\t\t\t"<<i->Balance<<"\t\t"<<i->date<<"\t\t"<<i->time<<endl;
			}//if
		}//for
        cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
}//printData for withdraw
void Statement::printstatement_withdraw(){
	cout<<"======================================= Statement Withdraw ==========================================================="<<endl;
	cout<<"Name"<<setw(33)<<"\t"<<"AccountNumber"<<"\t\t"<<"Withdraw"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
	//cout<<"Name"<<setw(34)<<"AccountNumber"<<"\t\t"<<"AmountMoney"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for(withdraw *i = head_withdraw;i!=NULL;i=i->link){
			cout<<setw(25)<<left<<i->Name<<setw(9)<<"\t"<<i->AccountNumber<<"\t\t"<<i->AmountMoney<<"\t\t\t"<<i->Balance<<"\t\t"<<i->date<<"\t"<<i->time<<endl;
		}//for
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}//print for Actor
void Statement::AddData_moneyExchange(string number,string currency,string money,string debited,string balance,string date,string time){
	MoneyExchange *NewNode = new MoneyExchange(number,currency,money,debited,balance,date,time);
		if(head_moneyExchange == NULL){
			head_moneyExchange = NewNode;
        	tail_moneyExchange = NewNode;
        	count_moneyExchange++;
    	}else{
			tail_moneyExchange->link = NewNode;
			tail_moneyExchange = NewNode;
			count_moneyExchange++;
		}//else if
}//Add money
bool Statement::Readfile_moneyExchange(){
	string fileName,filein,number,currency,money,debited,balance,date,time;
	fileName = "MoneyExchangeAccount.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}else{
			while(getline(infile,filein)){
				number = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				currency = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				debited = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				balance = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_moneyExchange(number,currency,money,debited,balance,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}//Readfaile
void Statement::printName_moneyExchange(string number){
			for(MoneyExchange *i = head_moneyExchange;i!=NULL;i=i->link){
				if(i->AccountNumber == number){
					cout<<i->AccountNumber << endl;	
				}//if
			}//for
}//printname
void Statement::printData_moneyExchange(string number){
	cout<<"======================================= Statement moneyExchange =================================================================================="<<endl;
	cout<<"Account:";
	printName_moneyExchange(number); 
	cout<<"Currency"<<"\t\t"<<"AmountMoney"<<"\t\t"<<"AmountDebited"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for(MoneyExchange *i = head_moneyExchange;i!=NULL;i=i->link){
			if(i->AccountNumber == number){
				cout<<i->Currency <<"\t\t"<<i->AmountMoney<<"\t\t\t"<<i->AmountDebited<<"\t\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t"<<i->Time<<endl;
			}//if
		}//for
        cout<<"----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}//printdata customer
void Statement::printstatement_momeyExchange(){
	cout<<"======================================= Statement momeyExchange ====================================================================================="<<endl;
	cout<<"AccountNumber"<<"\t\t"<<"Currency"<<"\t\t"<<"AmountMoney"<<"\t\t"<<"AmountDebited"<<"\t\t"<<"Balance"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for(MoneyExchange *i = head_moneyExchange;i!=NULL;i=i->link){
			cout<<i->AccountNumber<<"\t\t"<<i->Currency<<"\t\t"<<i->AmountMoney<<"\t\t\t"<<i->AmountDebited<<"\t\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t"<<i->Time<<endl;
		}//for
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}//printstatement Actor
void Statement::AddData_PlayBill(string name,string account,string type,string money,string date,string time){
		PlayBill *NewNode = new PlayBill(name,account,type,money,date,time);
			if(head_playBill == NULL){
				head_playBill = NewNode;
        		tail_playBill = NewNode;
        		count_playBill++;
    		}else{
				tail_playBill->link = NewNode;
				tail_playBill = NewNode;
				count_playBill++;
		}//else if
}//add
bool Statement::Readfile_PlayBill(){
	string fileName,filein,name,account,type,money,date,time;
	fileName = "StatementCustomerBill.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}else{
			while(getline(infile,filein)){
				name = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				account = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				type = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_PlayBill(name,account,type,money,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}//Readfile
void Statement::printName_PlayBill(string number){
		for(PlayBill *i = head_playBill;i!=NULL;i=i->link){
			if(i->AccountNumber == number){
				cout<<i->Name << endl;
			}//if
		}//for
}//printname
void Statement::printData_PlayBill(string number){
	cout<<"======================================= Statement PlayBill ==========================================================="<<endl;
	cout<<"Name:";
	printName_PlayBill(number);
	cout<<"AccountNumber"<<"\t\t"<<"Type"<<"\t\t"<<"Amountmoney"<<"\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for(PlayBill *i = head_playBill;i!=NULL;i=i->link){
			if(i->AccountNumber == number){
				cout<<i->AccountNumber<<"\t\t"<<i->Type<<"\t"<<i->Amountmoney <<"\t\t"<<i->Date<<"\t"<<i->Time<<endl;
			}//if
		}//for

        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;		
}//printdata
void Statement::AddData_PlayBillBankclerk(string type,string money,string date,string time){
		PlayBillBankclerk *NewNode = new PlayBillBankclerk(type,money,date,time);
			if(head_PlayBillBankclerk == NULL){
				head_PlayBillBankclerk = NewNode;
        		tail_PlayBillBankclerk = NewNode;
        		count_PlayBillBankclerk++;
    		}else{
				tail_PlayBillBankclerk->link = NewNode;
				tail_PlayBillBankclerk = NewNode;
				count_PlayBillBankclerk++;
		}//else if
}
bool Statement::Readfile_PlayBillBankclerk(){
	string fileName,filein,type,money,date,time;
	fileName = "StatementBankclerkBill.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}else{
			while(getline(infile,filein)){
				type = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_PlayBillBankclerk(type,money,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}
void Statement::printstatement_PlayBillBankclerk(){
	cout<<"======================================= Statement PlayBillBankclerk ==========================================================================================="<<endl;
	cout<<"Type"<<"\t\t"<<"Amountmoney"<<"\t\t"<<"Date"<<"\t\t"<<"Time"<<endl;
		for( PlayBillBankclerk *i = head_PlayBillBankclerk;i!=NULL;i=i->link){
			cout<<i->Type<<"\t"<<i->Amountmoney<<"\t\t\t"<<i->Date<<"\t"<<i->Time<<endl;
		}//for
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void Statement::AddData_Transfer(string numberT,string numberR ,string money,string balance,string date,string time){
	Transfer *NewNode = new Transfer(numberT,numberR,money,balance,date,time);
		if(head_Transfer == NULL){
			head_Transfer = NewNode;
        	tail_Transfer = NewNode;
        	count_Transfer++;
    	}else{
			tail_Transfer->link = NewNode;
			tail_Transfer = NewNode;
			count_Transfer++;
		}//else if
}
bool Statement::Readfile_Transfer(){
	string fileName,filein,numberT,numberR,money,balance,date,time;
	fileName = "StatementTransfer.dat";
	ifstream infile;
	infile.open(fileName.c_str(),std::ios::in);
		if(infile.fail()){
			return false;
		}else{
			while(getline(infile,filein)){
				numberT = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				numberR = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				money = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				balance = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				time = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
				AddData_Transfer(numberT,numberR,money,balance,date,time);
			}//while
			return true;
		}//else
		infile.close();
		return false;
}
void Statement::printName_Transfer(string number){
	for(Transfer *i = head_Transfer;i!=NULL;i=i->link){
			if(i->AccountNumberT == number){
				cout<<i->AccountNumberT << endl;	
			}
		}//for
}

void Statement::printData_Transfer(string number){
	cout<<"======================================= Statement Transfer ==========================================================="<<endl;
	/*cout<<"Account:";
	printName_Transfer(number);*/
	cout<<"Amountmoney"<<"\t\t"<<"Service charge"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<endl;
		for(Transfer *i = head_Transfer;i!=NULL;i=i->link){
			if(i->AccountNumberT == number){
				cout<<i->Amountmoney<<"\t\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t\t"<<i->Time<<endl;
			}
		}//for

        cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
}
void Statement::printstatement_Transfer(){
	cout<<"======================================= Statement Transfer ==================================================================================================="<<endl;
	cout<<"AccountTransferor"<<"\t"<<"AccountRecipient"<<"\t"<<"AmountMoney"<<"\t"<<"Service charge"<<"\t\t"<<"Date"<<"\t\t\t"<<"Time"<<endl;
		for(Transfer *i = head_Transfer;i!=NULL;i=i->link){
			cout<<i->AccountNumberT<<"\t\t"<<i->AccountNumberR<<"\t\t"<<i->Amountmoney<<"\t\t"<<i->Balance<<"\t\t"<<i->Date<<"\t\t"<<i->Time<<endl;
		}//for
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}