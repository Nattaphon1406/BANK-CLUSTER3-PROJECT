#include "Information.h"
Information :: Info :: Info(Customer Data){
      customer = Data;
      link = NULL;
}
Information :: Info :: Info(BankAccount Data){
      bankaccount = Data;
      link = NULL;
}
Information :: Info :: Info(BankClerk Data){
      bankclerk = Data;
      link = NULL;
}
Information :: Information(){
      HeadInfo = NULL;
      TailInfo = NULL;
      CountAmount = 0;
}
Information :: ~Information(){
      Info *Value = HeadInfo;  
      for(int i=1;i<CountAmount;i++){
            Value = HeadInfo;
            HeadInfo = HeadInfo->link;
            delete Value;
            Value = NULL;
      }    
      HeadInfo = NULL;
      TailInfo = NULL;
}
void Information :: LoadFileRegisterCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ifstream Write;
      Customer Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
      Write.open("RegisterAccountCustomer.dat");
      if(Write.fail()){
        cout << "Can not Write File 'RegisterAccountCustomer.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              TypeAccount = Line.substr(0,Line.find(','));
              Money = Line.erase(0,Line.find(',')+1);
              Data.SetInfoCustomer(Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money);
              AddInfoRegisterCustomer(Data);
          }
          Write.close();
      }
}
void Information :: LoadFileBankAccount(){
      string Name,AccountNumber,Money,Username,Password,Line;
      ifstream Write;
      BankAccount Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
      Write.open("BankAccount.dat");
      if(Write.fail()){
        cout << "Can not Write File 'BankAccount.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              AccountNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Money = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Username = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Password = Line.erase(0,Line.find(',')+1);
              Data.SetInfoBankAccount(Name,AccountNumber,Money,Username,Password);
              AddInfoBankAccount(Data);
          }
          Write.close();
      }
}
void Information :: LoadFileBankClerk(){
      string Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password,Line;
      ifstream Write;
<<<<<<< Updated upstream
      BankClerk Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
      Write.open("BankAccount.dat");
=======
      Count_BankClerk = 0;
      HeadInfo_BankClerk = NULL;
      TailInfo_BankClerk = NULL;
      Write.open("BankClerk.dat");
>>>>>>> Stashed changes
      if(Write.fail()){
        cout << "Can not Write File 'BankAccount.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              ClerkID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Password = Line.erase(0,Line.find(',')+1);
              Data.SetInfoBankClerk(Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password);
              AddInfoBankClerk(Data);
          }
          Write.close();
      }
}
void Information :: AddInfoRegisterCustomer(Customer Data){
      Info *newCustomer = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newCustomer;
                TailInfo = newCustomer;
            }
            else{
                TailInfo->link = newCustomer;
                TailInfo = newCustomer;
            }
            CountAmount++;
}
void Information :: AddInfoBankAccount(BankAccount Data){
      Info *newBankAccount = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newBankAccount;
                TailInfo = newBankAccount;
            }
            else{
                TailInfo->link = newBankAccount;
                TailInfo = newBankAccount;
            }
            CountAmount++;
}
void Information :: AddInfoBankClerk(BankClerk Data){
      Info *newBankClerk = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newBankClerk;
                TailInfo = newBankClerk;
            }
            else{
                TailInfo->link = newBankClerk;
                TailInfo = newBankClerk;
            }
            CountAmount++;
}
void Information :: RemoveInfoRegisterCustomer(int Number){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(int i = 1; i < CountAmount; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: RemoveInfoBankAccount(string AccountNumber){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(Info *i = HeadInfo; i != NULL; i = i->link){
            if(i->bankaccount.getAccountNumber() == AccountNumber){
                  if(i==HeadInfo){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: RemoveInfoBankClerk(int Number){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(int i = 1; i < CountAmount; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: SaveInfoRegisterCustomerToFile(){
      ofstream Write("RegisterAccountCustomer.dat");
        if(Write){
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->customer.getName() << "," << i->customer.getCitizenID() << "," << i->customer.getBirthDate() << "," << i->customer.getPhoneNumber() << "," << i->customer.getTypeAccount() << "," << i->customer.getMoney() << endl;
            }
        }
      Write.close();
}
void Information :: SaveInfoCustomerToFile(){
      ofstream Write("BankAccount.dat");
        if(Write){
<<<<<<< Updated upstream
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->bankaccount.getName() << "," << i->bankaccount.getAccountNumber() << "," << i->bankaccount.getMoney() << "," << i->bankaccount.getUsername() << "," << i->bankaccount.getPassword() << endl;
=======
            for(Info_BankAccount *i = HeadInfo_BankAccount; i != NULL; i = i->link){
                Write << i->Name << "," << i->AccountNumber << "," << i->Money << "," << i->Username << "," << i->Password << endl;
            }
        }
      Write.close();
}
string Information :: GenerateAccountNumber(int number){
      Info_Customer *generate = HeadInfo_Customer;
      string firstAccountNumber,strYear;
      string tempCitizenID,tempbirthyear,tempbirthday,tempbirthmonth,temptype;
      int year;
      stringstream tempYear;
      time_t now = time(0);
      tm *ltm = localtime(&now);
      for(int i = 0; i < number; i++){
            if(i+1 == number){
                  //////// make year //////////
                        year = 1900 + ltm->tm_year;
                        tempYear << year;
                        tempYear >> strYear;
                  /////////////////////////////
                  temptype = generate->TypeAccount;
                  tempbirthyear = strYear.substr(2,2);
                  tempCitizenID = generate->CitizenID.substr(11,2);
                  tempbirthday = generate->BirthDate.substr(0,2);
                  tempbirthmonth = generate->BirthDate.substr(generate->BirthDate.find("-")+1,2);
                  firstAccountNumber =  temptype + tempbirthyear + tempCitizenID + tempbirthday + tempbirthmonth;
            }
            generate = generate->link;
      }
      return firstAccountNumber;
}
string Information :: GenerateUsername(int number){
      Info_Customer *username;
      username = HeadInfo_Customer;
      string generatedUsername;
      string tempName,tempCitizenId;
      for(int i = 0; i < number; i++){
            if(i+1 == number){
                  tempName = username->Name.substr(0,username->Name.find(" "));
                  tempCitizenId = username->CitizenID.substr(4,3);
                  generatedUsername = tempName + tempCitizenId;
            }
            username = username->link;
      }
      return generatedUsername;
}
string Information :: GeneratePassword(int number){
      string username,password;
      username = GenerateUsername(number);
      password = "";
      for(int j =  username.length()-1; j >= 0; j--){
            password += username[j];
      }
      return password;
}
void Information :: SaveInfoRegisterToFileBankAccount(int number){
      LoadFileRegisterCustomer();
      Info_Customer *Data_Customer;
      Data_Customer = HeadInfo_Customer;
      ofstream Write("BankAccount.dat",ios::app);
        if(Write){
            for(int i = 0; i < number; i++){
                  if(i+1 == number){
                        Write << Data_Customer->Name << "," << GenerateAccountNumber(number) << "," << Data_Customer->Money << "," << GenerateUsername(number) << "," << GeneratePassword(number) << endl;
                  }
                  Data_Customer = Data_Customer->link;
>>>>>>> Stashed changes
            }
        }
      Write.close();
}
void Information :: SaveInfoBankClerkToFile(){
      ofstream Write("BankClerk.dat");
        if(Write){
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->bankclerk.getName() << "," << i->bankclerk.getCitizenID() << "," << i->bankclerk.getBirthDate() << "," << i->bankclerk.getPhoneNumber() << "," << i->bankclerk.getClerkID() << "," << i->bankclerk.getPassword() << endl;
            }
        }
      Write.close();
}
<<<<<<< Updated upstream
void Information :: Show(){
      for(Info *i = HeadInfo; i != NULL; i = i->link){
            cout << i->customer.getName() << "," << i->customer.getCitizenID() << "," << i->customer.getBirthDate() << "," << i->customer.getPhoneNumber() << "," << i->customer.getTypeAccount() << "," << i->customer.getMoney() << endl;
            //cout << i->bankclerk.getName() << "," << i->bankclerk.getCitizenID() << "," << i->bankclerk.getBirthDate() << "," << i->bankclerk.getPhoneNumber() << "," << i->bankclerk.getClerkID() << "," << i->bankclerk.getPassword() << endl;
            //cout << i->bankaccount.getName() << "," << i->bankaccount.getAccountNumber() << "," << i->bankaccount.getMoney() << "," << i->bankaccount.getUsername() << "," << i->bankaccount.getPassword() << endl;
=======
void Information :: ShowRegistercustomer(){
      LoadFileRegisterCustomer();
      int count = 1;
      for(Info_Customer *i = HeadInfo_Customer; i != NULL; i = i->link){
            cout << count++ << "." << "\t" << i->Name << endl;
            //cout << i->Name << "," << i->CitizenID << "," << i->BirthDate << "," << i->PhoneNumber << "," << i->TypeAccount << "," << i->Money << endl;
            //cout << i->Name << "," << i->CitizenID << "," << i->BirthDate << "," << i->PhoneNumber << "," << i->ClerkID << "," << i->Password << endl;
            //cout << i->Name << "," << i->AccountNumber << "," << i->Money << "," << i->Username << "," << i->Password << endl;
      }
}
void Information :: ShowBankclerk(){
      for(Info_BankClerk *i = HeadInfo_BankClerk; i != NULL; i = i->link){
            cout << i->Name << "," << i->CitizenID << "," << i->BirthDate << "," << i->PhoneNumber << "," << i->ClerkID << "," << i->Password << endl;
      }
}
void Information :: ShowBankAccount(){
      for(Info_BankAccount *i = HeadInfo_BankAccount; i != NULL; i = i->link){
            cout << i->Name << "," << i->AccountNumber << "," << i->Money << "," << i->Username << "," << i->Password << endl;
>>>>>>> Stashed changes
      }
}