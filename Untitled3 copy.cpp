#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	fstream myfile;
	string line;
	cout << "\n\n" << endl;
	myfile.open("Interface/Deposit.txt");
	while(getline(myfile,line)){
		cout << setw(90) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/withdraw.txt");
	while(getline(myfile,line)){
		cout << setw(85) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/Transfer.txt");
	while(getline(myfile,line)){
		cout << setw(83) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/Statement.txt");
	while(getline(myfile,line)){
		cout << setw(78) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/paybill.txt");
	while(getline(myfile,line)){
		cout << setw(88) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/RemovedAccount.txt");
	while(getline(myfile,line)){
		cout << setw(58) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;
	myfile.open("Interface/moneyexchange.txt");
	while(getline(myfile,line)){
		cout << setw(58) << " "<< line << endl;
	}
	myfile.close();
	cout << "\n\n" << endl;	
	myfile.open("Interface/ManageRegister.txt");
	while(getline(myfile,line)){
		cout << setw(58) << " "<< line << endl;
	}
	myfile.close();
}
