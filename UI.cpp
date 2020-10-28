#include "UI.h"
UI::UI(){
    username = " ";
    password = "";
    accountNumber = "";
    name = "";
    citizenID = "";
    birthDate = "";
    phoneNumber = "";
    typeAccount = "";
    money = 0;
    Recipient_account = "";
}
UI::~UI(){
    username = " ";
    password = "";
    accountNumber = "";
    name = "";
    citizenID = "";
    birthDate = "";
    phoneNumber = "";
    typeAccount = "";
    money = 0;
    Recipient_account = "";
}
void UI::print_MainMenu(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/BankCluster3.txt");
	while(getline(myfile,line)){
		cout  << left << setw(45) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "============ Menu ============" << endl;
    cout << setw(80) << " " << "1. Login" << endl;
    cout << setw(80) << " " << "2. Register" << endl;
    cout << setw(80) << " " << "3. Exit" << endl;
    cout << setw(80) << " " << "===============================" << endl;
    cout << setw(80) << " " << "Enter: "; 
}
void UI::print_Login(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Login.txt");
	while(getline(myfile,line)){
		cout  << left << setw(80) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "============ Login ============" << endl;
    cout << setw(80) << " " << "Username: ";
    cin >> username;
    cout << setw(80) << " " << "Password: ";
    cin >> password;
    cout << setw(80) << " " << "===============================" << endl;
}
void UI::print_Register(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Register.txt");
	while(getline(myfile,line)){
		cout  << left << setw(65) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "=========== Register ==========" << endl;
    cout << setw(80) << " " << "1. Register Customer" << endl;
    cout << setw(80) << " " << "2. Register BankClerk" << endl;
    cout << setw(80) << " " << "3. Back" << endl;
    cout << setw(80) << " " << "===============================" << endl;
    cout << setw(80) << " " << "Enter: ";
}
int UI::Checklogin(){
    if(Obj_Customer.login(username,password)){
        return 1;
    }
    else if(Obj_BankClerk.login(username,password)){
        return 2;
    }
    //It has Funtion Check Username and Password
    return 3;
}
void UI::printmenuRegister_Customer(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/RegisterCustomer.txt");
	while(getline(myfile,line)){
		cout  << left << setw(40) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "====== Register Customer ======" << endl;
    cout << setw(80) << " " << "Name: ";
    Obj_Customer.AddName();
    cout << setw(80) << " " << "CitizenID: ";
    Obj_Customer.AddCitizenID();
    cout << setw(80) << " " << "BirthDate: ";
    Obj_Customer.AddBirthDate();
    cout << setw(80) << " " << "Tel: ";
    Obj_Customer.AddPhoneNumber();
    cout << setw(80) << " "  << "========= TypeAccount =========" << endl;
    cout << setw(80) << " " << "1. DepositAccount [  500 Bath]" << endl;
    cout << setw(80) << " " << "2. SavingAccount  [20000 Bath]" << endl;
    cout << setw(80) << " " << "===============================" << endl;
    cout << setw(80) << " " << "TypeAccount: ";
    Obj_Customer.AddTypeAccount();
    if(Obj_Customer.AddMoney()){
        Obj_Customer.Registercustomer();
    }
    cout << setw(80) << " " << "===============================" << endl;
}
void UI::printmenuRegister_BankClerk(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/RegisterBankClerk.txt");
	while(getline(myfile,line)){
		cout  << left << setw(83) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "====== Register BankClerk =====" << endl;
    cout << setw(80) << " " << "Name: ";
    Obj_BankClerk.AddName();
    cout << setw(80) << " " << "CitizenID: ";
    Obj_BankClerk.AddCitizenID();
    cout << setw(80) << " " << "BirthDate: ";
    Obj_BankClerk.AddBirthDate();
    cout << setw(80) << " " << "Tel: ";
    Obj_BankClerk.AddPhoneNumber();
    cout << setw(80) << " " << "Username: ";
    Obj_BankClerk.AddClerkID();
    cout << setw(80) << " " << "Password: ";
    Obj_BankClerk.AddPassword();
    Obj_BankClerk.Registercustomer();
    cout << setw(80) << " " << "===============================" << endl;
}
void UI::print_menuClerk(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Menu.txt");
	while(getline(myfile,line)){
		cout  << left << setw(83) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "==================== MENU ====================" << endl;
    cout << setw(80) << " " << "1. Deposition" << endl;
    cout << setw(80) << " " << "2. Withdraw" << endl;
    cout << setw(80) << " " << "3. Transfer" << endl;
    cout << setw(80) << " " << "4. Pay Bill" << endl;
    cout << setw(80) << " " << "5. Money Exchange" << endl;
    cout << setw(80) << " " << "6. Statement" << endl;
    cout << setw(80) << " " << "7. MenageRegister" << endl;
    cout << setw(80) << " " << "8. RemovedAccount" << endl;
    cout << setw(80) << " " << "9. Logout" << endl;
    cout << setw(80) << " " << "==============================================" << endl;
    cout << setw(80) << " " << "Enter: ";
}
void UI::print_menuCustomer(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Menu.txt");
	while(getline(myfile,line)){
		cout  << left << setw(83) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    cout << setw(80) << " " << "==================== MENU ====================" << endl;
    cout << setw(80) << " " << "1. Transfer" << endl;
    cout << setw(80) << " " << "2. Pay Bill" << endl;
    cout << setw(80) << " " << "3. Statement" << endl;
    cout << setw(80) << " " << "4. Logout" << endl;
    cout << setw(80) << " " << "==============================================" << endl;
    cout << setw(80) << " " << "Enter: ";
}
void UI::printInfoFromFileRegister(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/ManageRegister.txt");
	while(getline(myfile,line)){
		cout  << left << setw(50) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    Obj_Customer.LoadFileRegisterCustomer();
    cout << setw(80) << " " << "============ RegisterCustomerFile ============" << endl;
    cout << setw(80) << " " << "No." << "\t" << "Name" << endl;
    cout << setw(80) << " " << "==============================================" << endl;
    Obj_Customer.ShowRegistercustomer();
    cout << setw(80) << " " << "==============================================" << endl;
    cout << setw(80) << " " << "Enter: ";
}
void UI::MenageRegister(int Number){
    cout << setw(80) << " " << "1.ConfirmRegister" << endl;
    cout << setw(80) << " " << "2.RemoveRegister" << endl;
    cout << setw(80) << " " << "Enter: ";
    Obj_BankClerk.MenuMenageRegister(Number);
}
void UI::RemoveBankAccount(){
        Information Info_Customer;
        string AccountNumber;
        fstream myfile;
	    string line;
        RemovedAgain :
        Info_Customer.LoadFileBankAccount();
        cout << "\n\n" << endl;
        myfile.open("Interface/RemovedAccount.txt");
        while(getline(myfile,line)){
            cout << setw(40) << " "<< line << endl;
        }
        myfile.close(); 
        cout << endl << endl << endl << endl;
        cout << setw(80) << " " << "Enter Account Number : ";
        cin >> AccountNumber;
        
        if(Info_Customer.RemoveInfoBankAccount(AccountNumber)==true){
            Info_Customer.SaveInfoCustomerToFile();
        }
        else if(Info_Customer.RemoveInfoBankAccount(AccountNumber)==false){
            cout << setw(80) << " " << "ACCOUNT NOT FOUND" << endl;
            goto RemovedAgain;
        } 
        
}

void UI::print_MoneyExchange(){
    system("cls");
    fstream myfile;
    string line;
    cout << "\n\n" << endl;
	myfile.open("Interface/moneyexchange.txt");
	while(getline(myfile,line)){
		cout << left << setw(35) << " " << line << endl;
	}
    myfile.close();
    int PaymentType,CurrencyType;
    float MoneyAmountForeign,MoneyAmountBaht;
    string AccountNumber;
    do{
        cout << left << setw(80) << " " << "========= Money Exchange ========= " << endl;
        cout << left << setw(80) << " " << "------- Foreign Currency -------" << endl;
        cout << left << setw(80) << " " << "1. JPY(Yen)" << endl;
        cout << left << setw(80) << " " << "2. USD(Dollar)" << endl;
        cout << left << setw(80) << " " << "3. CNY(Yuan)" << endl;
        cout << left << setw(80) << " " << "4. KRW(Won)" << endl;
        cout << left << setw(80) << " " << "5. GBR(Pound)" << endl;
        cout << left << setw(80) << " " << "6. EUR(Euro)" << endl;
        cout << left << setw(80) << " " << "7. EXIT " << endl;
        cout << left << setw(80) << " " << "---------------------------- " << endl;
        cout << left << setw(80) << " " << "Enter Currency Type : ";	
        cin >> CurrencyType;

        if(CurrencyType != 7){
            cout << "           Enter Money Amount(Foreign currency) : ";
            cin >> MoneyAmountForeign;

            do{
                system("cls");
                cout << left << setw(80) << " " << "------- Payment Type ------- " << endl;
                cout << left << setw(80) << " " << "1. Cash " << endl;
                cout << left << setw(80) << " " << "2. Bank Account " << endl;
                cout << left << setw(80) << " " << "3. Return to choose new Currency or Exit" << endl;
                cout << left << setw(80) << " " << "---------------------------- " << endl;                
                cout << left << setw(80) << " " << "Enter Type of Payment : ";
                cin >> PaymentType;

                Obj_MoneyExchange.SetMoneyExchange(CurrencyType,MoneyAmountForeign,PaymentType);
                Obj_MoneyExchange.ExchangeCalculate(CurrencyType);

                if(PaymentType == 1){
                    system("cls");
                    Obj_MoneyExchange.ShowPaymentMoney();
                    cout << endl;
                    cout << left << setw(80) << " " << "---------- Cash ------------ " << endl;
                    cout << left << setw(80) << " " << "Enter Money Amount(Baht) : ";
                    cin >> MoneyAmountBaht;            
                    cout << left << setw(80) << " " << "---------------------------- " << endl;

                    Obj_MoneyExchange.ShowBillCash(MoneyAmountBaht);
                }
                else if(PaymentType == 2){
                    system("cls");
                    Obj_MoneyExchange.ShowPaymentMoney();
                    cout << endl;
                    cout << left << setw(80) << " " << "------- Bank Account ------- " << endl;
                    cout << left << setw(80) << " " << "Enter Account Number : ";
                    cin >> AccountNumber;            
                    cout << left << setw(80) << " " << "---------------------------- " << endl;

                    Obj_MoneyExchange.SetAccount(AccountNumber);
                    Obj_BankAccount.LoadFileBankAccount();
                    if(Obj_BankAccount.CheckAccount(AccountNumber) == 1){
                        string Balance,balance;
                        Balance = Obj_BankAccount.getBalance(AccountNumber);
                        balance = Obj_MoneyExchange.ShowBillAccount(Balance);
                        
                        Obj_BankAccount.updateExchangeMoney_to_BankAccount(balance,AccountNumber);
                    }
                    else if(Obj_BankAccount.CheckAccount(AccountNumber) == 0){
                        cout << left << setw(80) << " " <<"!!!!Invalid Account Number!!!!" <<endl;
                    }

                } 
            }while(PaymentType != 3); //check menu PaymentType
            cout << left << setw(80) << " " << "================================== " << endl;
        }// if check CurrencyType
    }while(CurrencyType != 7);//check menu CurrencyType
}
void UI :: Withdraw(){
        system("cls");
    string Account;
    unsigned long int withdraw;
    Obj_BankAccount.LoadFileBankAccount();
    //Obj_BankAccount.ShowBankAccount();
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/withdraw.txt");
	while(getline(myfile,line)){
		cout  << left << setw(60) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    do{
        cout<<setw(80)<<" "<<"========= Withdraw ========="<<endl
            <<setw(80)<<left<<" "<<"Enter Account Number: ";
        cin>>Account;
        cout<<setw(80)<<left<<" "<<"============================"<<endl;
    }while(!Obj_BankAccount.CheckAccount(Account));
    
    do{
        
        cout<<setw(80)<<left<<" "<<"========= Withdraw ========="<<endl
            <<setw(80)<<left<<" "<<"Owner Name: "<<Obj_BankAccount.getName()<<endl
            <<setw(80)<<left<<" "<<"Enter Withdraw Amount: ";
    cin>>withdraw;
    if(Obj_BankAccount.getMoney()<=100){
        cout<<setw(80)<<left<<" "<<"Can't Withdraw"<<endl;
        goto b1;
    }
    }while (withdraw%100!=0 || withdraw<100 || withdraw > Obj_BankAccount.getMoney());
    Obj_BankAccount.Withdraw(withdraw);
    Obj_BankAccount.WithdrawBill(withdraw);
    b1:
    cout<<" "<<setw(80)<<left<<"Account Balance :"<<Obj_BankAccount.getMoney()<<endl;
    //Obj_BankAccount.SaveInfoCustomerToFile();
    system("pause");
}
void UI::print_getDeposit(){
   // bool check_account;
    do{
        system("cls");
        fstream myfile;
	    string line;
	    cout << "\n\n" << endl;
	    myfile.open("Interface/Deposit.txt");
	    while(getline(myfile,line)){
            cout << setw(74) << " " << line << endl;
        }
        myfile.close();
		cout << setw(90) << " " << endl;
        Obj_BankAccount.LoadFileBankAccount();
        cout << setw(65) << " " << "============================== Deposition ==============================" << endl;
        cout  << setw(65) << " "  << "Please enter account number" << endl;
        cout  << setw(65) << " "  << "Enter: ";
        cin >> accountNumber;
        if(Obj_BankAccount.CheckAccount(accountNumber) == true)
        {
            system("cls");
            cout << setw(65) << " "  << "*** Account number correct *** " << endl;
            if(accountNumber[0] == '1')
            {
                cout << setw(65) << " "  << "Type account: Savings account" << endl;
                cout << setw(65) << " "  << "*********************************************" << endl;
                do{
                    cout << setw(65) << " "  << "money amount of deposition" << endl;
                    cout << setw(65) << " " << "Enter: ";
                    cin >> money;
                    Obj_BankAccount.setData_deposit(accountNumber,money);
                    cout << setw(65) << " "  << "=======================================================================" << endl;
                    if(money > 0){
                        Obj_BankAccount.setBalance();
                        Obj_BankAccount.CalculateInterest(accountNumber);
                        Obj_BankAccount.AddMoney();
                    }
                    else{
                        system("cls");
                        cout << setw(65) << " "  << "amount of deposition incoorect!!" << endl;
                        break;
                        
                    }
                }while(money == 0);
            }
            else if(accountNumber[0] == '2')
            {
                system("cls");
                cout << setw(65) << " "  << "Type account: fixed deposit account" << endl;
                cout << setw(65) << " "  << "*********************************************" << endl;
                do{
                    cout << setw(65) << " " << "money amount of deposition" << endl;
                    cout << setw(65) << " " << "Enter: ";
                    cin >> money;
                    Obj_BankAccount.setData_deposit(accountNumber,money);
                    cout << "=======================================================================" << endl;
                    if(money == 30000)
                    {
                        Obj_BankAccount.setBalance();
                        Obj_BankAccount.CalculateInterest(accountNumber);
                        Obj_BankAccount.AddMoney();
                    }
                    else
                    {
                        system("cls");
                        cout << setw(65) << " " << "amount of deposition incoorect!!" << endl;
                        break;
                       
                    }
                }while(money != 30000);
            }
        }
        else
        {
            system("cls");
            cout << setw(65) << " "  << "*** Data not found!! ***" << endl;
            cout << setw(65) << " " << "Please do the deposition list again" << endl;
            break;
        }
    }while(!Obj_BankAccount.CheckAccount(accountNumber));
}
/*void UI::SvaeRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,int money){
    Information Info_Customer;
    Info_Customer.LoadFileRegisterCustomer();
}
void UI::SaveRegisterBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
    Information Info_BankClerk;
    Info_BankClerk.LoadFileBankClerk();
}
void UI::SaveInfoCustomerToBankAccount(string name,string accountNumber,string money,string username,string password){
    Information Info_BankAccount;
    Info_BankAccount.LoadFileRegisterCustomer();
}*/
void UI::PayBill(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/paybill.txt");
	while(getline(myfile,line)){
		cout  << left << setw(75) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    Obj_BankAccount.LoadFileBankAccount();
    string type,chooseGroup, user;
    unsigned long int amount;
    int temp;
    
    temp = Obj_BankAccount.CheckUser(username);//check customer or bankclerk
    if(temp==true){ 
        type = "customer";
        cout << setw(80) << " " << "=========AccoutNumber=========" << endl;
	    cout << setw(80) << " " << "Input account : ";
	    cin >> accountNumber;
        temp = Obj_BankAccount.CheckAccount(accountNumber);
        if(temp == true){
            do{
                cout << setw(80) << " " << "===================Customer====================" << endl;
                cout << setw(80) << " " << "===================GroupBill===================" << endl;
                cout << setw(80) << " " << "1.Water bill" << endl;
                cout << setw(80) << " " << "2.Electricity bill" << endl;
                cout << setw(80) << " " << "3.Phone bill" << endl;
                cout << setw(80) << " " << "4.Exit" << endl;
                cout << setw(80) << " " << "===============================================" << endl;	
                cout << setw(80) << " " << "Enter: ";
                cin >> chooseGroup;
                system("cls");
            }while(chooseGroup!="1"&&chooseGroup!="2"&&chooseGroup!="3"&&chooseGroup!="4");
            if(chooseGroup == "4"){
                cout << "Amount to pay the bill: ";
                cin >> amount;
                Obj_BankAccount.payBill(type,chooseGroup,amount);
            }
        }else{
            cout << "AccoutNumber Not found" << endl;
        }
    }
    else if(temp==false){
        type = "Bankclerk";
        do{
            cout << setw(80) << " " << "================== Bankclerkr ==================" << endl;
            cout << setw(80) << " " << "===================GroupBill===================" << endl;
            cout << setw(80) << " " << "1.Water bill" << endl;
            cout << setw(80) << " " << "2.Electricity bill" << endl;
            cout << setw(80) << " " << "3.Phone bill" << endl;
            cout << setw(80) << " " << "4.Exit" << endl;
            cout << setw(80) << " " << "===============================================" << endl;	
            cout << setw(80) << " " << "Enter: ";
            cin >> chooseGroup;
            system("cls");
        }while(chooseGroup!="1"&&chooseGroup!="2"&&chooseGroup!="3"&&chooseGroup!="4");
        if(chooseGroup != "4"){
            cout << setw(80) << " " << "Amount to pay the bill: ";
            cin >> amount;
            Obj_BankAccount.payBill(type,chooseGroup,amount);
        }
    }
}

bool UI::transfer_firstPage(){
    system("cls");
    fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Transfer.txt");
	while(getline(myfile,line)){
		cout  << left << setw(60) << " "<< line << endl;
	}
    cout << endl << endl << endl << endl;
    Obj_BankAccount.LoadFileBankAccount();
    cout << setw(80)<< " " <<"===============Transfer================" << endl;
	cout << setw(80)<< " " <<"Transferor account : ";
	cin >> accountNumber;
    if(Obj_BankAccount.CheckTransfer_Account(accountNumber) == true){
        do{
		cout << setw(80)<< " " <<"Recipient account : ";
		cin >> Recipient_account;
        }while(Recipient_account.length() != 10);
        do{
            cout << setw(80)<< " " <<"Amount : ";
            cin >> money;
        }while(money > 50000); 
        cout <<  setw(80)<< " " <<"=======================================" << endl;
        return true;
    }
	return false;
}    

void UI::Ready_transfer(){
    system("cls");
    cout << setw(80) << " " <<"=========================================" << endl;
	cout << setw(80) << " " <<"Ready to transfer" << endl;
	cout << setw(80) << " " <<"1.Confirm" << endl;
	cout << setw(80) << " " <<"2.Modify"<< endl;
	cout << setw(80) << " " <<"3.Cancal"<< endl;
	cout << setw(80) << " " <<"==========================================" << endl;
	cout << setw(80) << " " <<"Enter : ";
}
void UI::Bill_BankClerk(){
    system("cls");
    if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == true){
        stringstream ss;
        string transferor,recipient,money_file,Service_charge,date;
        Obj_BankAccount.CheckTransfer_DeductMoneyBankclerk(money,accountNumber);
        Obj_BankAccount.CheckTransfer_AddMoney(money,Recipient_account);
        cout << setw(80) << " " <<"======================Success=======================" << endl;
        cout << setw(80) << " " <<"   Form                                             " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_TransferorBC(accountNumber) << endl;
        cout << setw(80) << " " <<"      Account number : " << accountNumber << endl;
        cout << setw(80) << " " <<"   To                                               " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_recipient(Recipient_account) << endl;
        cout << setw(80) << " " <<"      Account number : " << Recipient_account << endl;
        cout << setw(80) << " " <<"  ------------------------------------------------  " << endl;
        cout << setw(80) << " " <<"   Amount : " << money << endl;
        cout << setw(80) << " " <<"   Service charge : " << "0" << endl;
        cout << setw(80) << " " <<"   Balance : " << Obj_BankAccount.getmoneyBC(accountNumber) << endl;
        cout << setw(80) << " " <<"   Transaction date : " << Obj_BankAccount.getDateandTimeTransfer() << endl;
        cout << setw(80) << " " <<"====================================================" << endl;
        ss << money; 
        ss >> money_file; 
        ss.clear(); 
        transferor = accountNumber;
        recipient = Recipient_account;
        Service_charge = "0";
        date = Obj_BankAccount.getDateandTimeTransfer();
        Obj_BankAccount.statementTransfer_customer(transferor,recipient,money_file,Service_charge,date);
    }
    else if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == false){
        stringstream ss;
        string transferor,recipient,money_file,Service_charge,date;
        Obj_BankAccount.CheckTransfer_DeductMoneyBankOtherBC(money,accountNumber);
        cout << setw(80) << " " <<"======================Success=======================" << endl;
        cout << setw(80) << " " <<"   Form                                             " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_TransferorBC(accountNumber) << endl;
        cout << setw(80) << " " <<"      Account number : " << accountNumber << endl;
        cout << setw(80) << " " <<"   To                                               " << endl;
        cout << setw(80) << " " <<"      name : " << "-" << endl;
        cout << setw(80) << " " <<"      Account number : " << Recipient_account << endl;
        cout << setw(80) << " " <<"  ------------------------------------------------  " << endl;
        cout << setw(80) << " " <<"   Amount : " << money << endl;
        cout << setw(80) << " " <<"   Service charge : " << "10" << endl;
        cout << setw(80) << " " <<"   Balance : " << Obj_BankAccount.getmoneyBC(accountNumber) << endl;
        cout << setw(80) << " " <<"   Transaction date : " << Obj_BankAccount.getDateandTimeTransfer() << endl;
        cout << setw(80) << " " <<"====================================================" << endl;
        ss << money; 
        ss >> money_file; 
        ss.clear(); 
        transferor = accountNumber;
        recipient = Recipient_account;
        Service_charge = "10";
        date = Obj_BankAccount.getDateandTimeTransfer();
        Obj_BankAccount.statementTransfer_customer(transferor,recipient,money_file,Service_charge,date);
    }
}
bool UI::transfer_FirstPage(){
    Obj_BankAccount.LoadFileBankAccount();
    system("cls");
    cout << setw(80) << " " <<"================Transfer=================" << endl;
    do{
		cout << setw(80) << " " <<"Recipient account : ";
		cin >> Recipient_account;
	}while(Recipient_account.length() != 10);
    do{
		cout << setw(80) << " " <<"Amount : ";
		cin >> money;
	}while(money > 50000);
    cout << setw(80) << " " <<"==========================================" << endl;
    return true;
} 
void UI::Bill_Customer(){
    system("cls");
    if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == true){
        stringstream ss;
        string transferor,recipient,money_file,Service_charge,date;
        Obj_BankAccount.CheckTransfer_DeductMoneyCustomer(money,username);
        Obj_BankAccount.CheckTransfer_AddMoney(money,Recipient_account);
        cout << setw(80) << " " <<"======================Success=======================" << endl;
        cout << setw(80) << " " <<"   Form                                             " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_TransferorCT(username) << endl;
        cout << setw(80) << " " <<"      Account number : " << Obj_BankAccount.getAccountNumber(username) << endl;
        cout << setw(80) << " " <<"   To                                               " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_recipient(Recipient_account) << endl;
        cout << setw(80) << " " <<"      Account number : " << Recipient_account << endl;
        cout << setw(80) << " " <<"  ------------------------------------------------  " << endl;
        cout << setw(80) << " " <<"   Amount : " << money << endl;
        cout << setw(80) << " " <<"   Service charge : " << "0" << endl;
        cout << setw(80) << " " <<"   Balance : " << Obj_BankAccount.getmoneyCT(username) << endl;
        cout << setw(80) << " " <<"   Transaction date : " << Obj_BankAccount.getDateandTimeTransfer() << endl;
        cout << setw(80) << " " <<"====================================================" << endl;
        ss << money; 
        ss >> money_file; 
        ss.clear(); 
        transferor = Obj_BankAccount.getAccountNumber(username);
        recipient = Recipient_account;
        Service_charge = "0";
        date = Obj_BankAccount.getDateandTimeTransfer();
        Obj_BankAccount.statementTransfer_customer(transferor,recipient,money_file,Service_charge,date);
    }
    else if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == false){
        stringstream ss;
        string transferor,recipient,money_file,Service_charge,date;
        Obj_BankAccount.CheckTransfer_DeductMoneyBankOtherCT(money,username);
        cout << setw(80) << " " <<"======================Success=======================" << endl;
        cout << setw(80) << " " <<"   Form                                             " << endl;
        cout << setw(80) << " " <<"      name : " << Obj_BankAccount.getname_TransferorCT(username) << endl;
        cout << setw(80) << " " <<"      Account number : " << Obj_BankAccount.getAccountNumber(username) << endl;
        cout << setw(80) << " " <<"   To                                               " << endl;
        cout << setw(80) << " " <<"      name : " << "-" << endl;
        cout << setw(80) << " " <<"      Account number : " << Recipient_account << endl;
        cout << setw(80) << " " <<"  ------------------------------------------------  " << endl;
        cout << setw(80) << " " <<"   Amount : " << money << endl;
        cout << setw(80) << " " <<"   Service charge : " << "10" << endl;
        cout << setw(80) << " " <<"   Balance : " << Obj_BankAccount.getmoneyCT(username) << endl;
        cout << setw(80) << " " <<"   Transaction date : " << Obj_BankAccount.getDateandTimeTransfer() << endl;
        cout << setw(80) << " " <<"====================================================" << endl;
        ss << money; 
        ss >> money_file; 
        ss.clear(); 
        transferor = Obj_BankAccount.getAccountNumber(username);
        recipient = Recipient_account;
        Service_charge = "10";
        date = Obj_BankAccount.getDateandTimeTransfer();
        Obj_BankAccount.statementTransfer_customer(transferor,recipient,money_file,Service_charge,date);
    }
}
bool UI::NotEnough_moneyCustomer(){
    if(Obj_BankAccount.CheckTransfer_AccountMoneyOther(Recipient_account) == true){
        if(Obj_BankAccount.CheckTransfer_AccountMoneyCustomer(money,username)==true){
            return true;
        }
        else{
            cout << setw(80) << " " <<"======Not enough money======" << endl;
            return false;
        }
    }
    else if(Obj_BankAccount.CheckTransfer_AccountMoneyOther(Recipient_account) == false){
        if(Obj_BankAccount.CheckTransfer_AccountMoneyCustomerOther(money,username)==true){
            return true;
        }
        else{
            cout << setw(80) << " " <<"======Not enough money======" << endl;
            return false;
        }
    }   
    return false;
}
bool UI::NotEnough_moneyBankClerk(){
    if(Obj_BankAccount.CheckTransfer_AccountMoneyOther(Recipient_account) == true){
        if(Obj_BankAccount.CheckTransfer_AccountMoneyBankClerk(money,accountNumber)==true){
            return true;
        }
        else{
            cout << setw(80) << " " <<"======Not enough money======" << endl;
            return false;
        }
    }
    else if(Obj_BankAccount.CheckTransfer_AccountMoneyOther(Recipient_account) == false){
        if(Obj_BankAccount.CheckTransfer_AccountMoneyBankClerkOther(money,accountNumber)==true){
            return true;
        }
        else{
            cout << setw(80) << " " <<"======Not enough money======" << endl;
            return false;
        }
    }   
    return false;
}
void UI::printMenu_statement(){
    Statement s;
    string number;
    BankAccount tempState;
    string tempAccountNumber;
     fstream myfile;
    string line;
    int count;
    int n;
        n = Checklogin();
        if(n==1){
            do{
                system("cls");
               
                myfile.open("Interface/Statement.txt");
                while(getline(myfile,line)){
                    cout << setw(65) << " "<< line << endl;
                }
                myfile.close();
                cout<<setw(80)<<"========Statement Customer========"<<endl;
                cout<<setw(80)<<"1.Deposition"<<endl;
                cout<<setw(80)<<"2.Withdraw"<<endl;
                cout<<setw(80)<<"3.Transfer"<<endl;
                cout<<setw(80)<<"4.Pay Bill"<<endl;
                cout<<setw(80)<<"5.MoneyExchangAccount"<<endl;
                cout<<setw(80)<<"6.Back"<<endl;
                cout<<setw(80)<<"==================================="<<endl;
                cout<<endl; 
                cout<<setw(80)<<"Enter choice Number:";  
                cin>>setw(80)>>count;  

                if(count == 1){
                    tempState.LoadFileBankAccount();
                    tempAccountNumber = tempState.getAccountNumber(username);
                    s.ReadFile_deposit();
                    s.printData_deposit(tempAccountNumber);
                    s.~Statement();
                    system("cls");
                }else if(count == 2){
                    tempState.LoadFileBankAccount();
                    tempAccountNumber = tempState.getAccountNumber(username);
                    s.Readfile_withdraw();
                    s.printData_withdraw(tempAccountNumber);
                    s.~Statement();
                    system("cls");
                }else if(count == 3){
                    tempState.LoadFileBankAccount();
                    tempAccountNumber = tempState.getAccountNumber(username);
                    s.Readfile_Transfer();
                    s.printData_Transfer(tempAccountNumber);
                    s.~Statement();
                    system("cls");
                }else if(count == 4){
                     tempState.LoadFileBankAccount();
                    tempAccountNumber = tempState.getAccountNumber(username);
                    s.Readfile_PlayBill();
                    s.printData_PlayBill(tempAccountNumber);
                    s.~Statement();
                    system("cls");
                }else if(count == 5){
                    tempState.LoadFileBankAccount();
                    tempAccountNumber = tempState.getAccountNumber(username);
                    s.Readfile_moneyExchange();
                    s.printData_moneyExchange(tempAccountNumber);
                    s.~Statement();
                    system("cls");
                }//else if

            }while(count != 6);
        }else if(n==2){
            do{
                system("cls");
                myfile.open("Interface/Statement.txt");
                while(getline(myfile,line)){
                    cout << setw(65) << " "<< line << endl;
                }
                cout<<setw(80) << " " <<"========Statement Employees========"<<endl;
                cout<<setw(80) << " " <<"1.Deposition"<<endl;
                cout<<setw(80) << " " <<"2.Withdraw"<<endl;
                cout<<setw(80) << " " <<"3.Transfer"<<endl;
                cout<<setw(80) << " " <<"4.PlayBill"<<endl;
                cout<<setw(80) << " " <<"5.MoneyExchangAccount"<<endl;
                cout<<setw(80) << " " <<"6.Back"<<endl;
                cout<<setw(80) << " " <<"==================================="<<endl;
                cout<<setw(80) << " " <<"Enter choice Number:";  
                cin >>count;  

                if(count == 1){
                    s.ReadFile_deposit();
                    s.printstatement_deposit();
                    s.~Statement();
                    system("cls");
                }else if(count == 2){
                    s.Readfile_withdraw();
                    s.printstatement_withdraw();
                    s.~Statement();
                    system("cls");
                }else if(count == 3){
                    s.Readfile_Transfer();
                    s.printstatement_Transfer();
                    s.~Statement();
                    system("cls");
                }else if(count == 4){
                    s.Readfile_PlayBillBankclerk();
                    s.printstatement_PlayBillBankclerk();
                    s.~Statement();
                    system("cls");
                }else if(count == 5){
                    s.Readfile_moneyExchange();
                    s.printstatement_momeyExchange();
                    s.~Statement();
                    system("cls");
                }

            }while(count != 6);
        } //else if 
}