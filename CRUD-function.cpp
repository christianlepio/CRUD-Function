#include<iostream>
using namespace std;

int main(){
	string lname[100], fname[100], mname[100];
	int age[100], n;
	cout << "Enter the size of matrix: ";
	cin >> n;
	cin.ignore();
	cout << "\n";
	for(int i = 0 ; i < n ; i++){
		cout << "[" << i+1 << "] Enter Last Name: ";
		getline(cin  , lname[i]);
		cout << "[" << i+1 << "] Enter First Name: ";
		getline (cin , fname[i]);
		cout << "[" << i+1 << "] Enter Middle Name: ";
		getline(cin, mname[i]);
		cout << "[" << i+1 << "] Enter Age: ";
		cin >> age[i];
		cin.ignore();
		cout << endl << endl;
	}
	start:
	system("pause");
	system("cls");
	cout << "LAST\t\tFIRST\t\tMID\t\tAGE\n";
	for(int i = 0 ; i < n ; ++i){
		cout << lname[i] << "\t\t" << fname[i] << "\t\t" << mname[i] << "\t\t" << age[i] << "\n";
	}
	char choice;
	cout << "\n\nPress <D> to Delete\nPress <I> to Insert\nPress <U> to Update\nPress <S> to Search:\nPress <Q> to quit: ";
	cin >> choice;
	cin.ignore();
	choice = toupper(choice);
	if(choice == 'D'){
		int p;
		int flag = 0;
		string name;
		cout << "\nEnter Last_Name to be deleted: ";
		getline(cin, name);
		for(int i = 0 ; i < n ; i++){
			if(name == lname[i]){
				p = i;
				flag++;
				break;
			}
		}
		if(flag == 0){
			cout << name << " is not registered.\n";
			goto start;
		}
		for(int i = p; i < n ; i++){
			lname[i] = lname[i+1];
			fname[i] = fname[i+1];
			mname[i] = mname[i+1];
			age[i] = age[i+1];
		}
		n--;
		cout << "LAST\t\tFIRST\t\tMID\t\tAGE\n";
		for(int i = 0 ; i < n ; ++i){
			cout << lname[i] << "\t\t" << fname[i] << "\t\t" << mname[i] << "\t\t" << age[i] << "\n";
		}
		goto start;
	}
	else if(choice == 'I'){	
		cout << "\n\nEnter New Last_Name: ";
		getline(cin, lname[n]);
		cout << "Enter New First_Name: ";
		getline(cin, fname[n]);
		cout << "Enter New Middle_Name: ";
		getline(cin, mname[n]);
		cout << "Enter New Age: ";
		cin >> age[n];
		n++;
		cout << "LAST\t\tFIRST\t\tMID\t\tAGE\n";
		for(int i = 0 ; i < n ; ++i){
			cout << lname[i] << "\t\t" << fname[i] << "\t\t" << mname[i] << "\t\t" << age[i] << "\n";
		}
		goto start;
	}
	else if(choice == 'U'){
		int p;
		int flag = 0;
		string name;
		cout << "\nEnter Last_Name to be updated: ";
		getline(cin, name);
		for(int i = 0 ; i < n ; i++){
			if(name == lname[i]){
				p = i;
				flag++;
				break;
			}
		}
		if(flag == 0){
			cout << name << " is not registered.\n";
			goto start;
		}
		repeat:
		char choose;
		string new_name;
		int new_age;
		cout << "\nWhat to Update?\nPress <L> for Last_Name\nPress <F> for First_Name\nPress <M> for Middle_name\nPress <A> for Age: ";
		cin >> choose;
		choose = toupper(choose);
		cin.ignore();
		if(choose == 'L'){
			cout << "\nEnter New Last_Name: ";
			getline(cin, new_name);
			lname[p] = new_name;
		}
		else if(choose == 'F'){
			cout << "\nEnter New First_Name: ";
			getline(cin, new_name);
			fname[p] = new_name;
		}
		else if(choose == 'M'){
			cout << "\nEnter New Middle_Name: ";
			getline(cin, new_name);
			mname[p] = new_name;
		}
		else if(choose == 'A'){
			cout << "\nEnter New Age: ";
			cin >> new_age;
			age[p] = new_age;
		}
		else{
			cout << "\nInvalid Code. Try again...\n";
			goto repeat;
		}
		cout << "LAST\t\tFIRST\t\tMID\t\tAGE\n";
		for(int i = 0 ; i < n ; ++i){
			cout << lname[i] << "\t\t" << fname[i] << "\t\t" << mname[i] << "\t\t" << age[i] << "\n";
		}
		goto start;
	}
	else if(choice == 'S'){
		int p;
		int flag = 0;
		string name;
		cout << "\nEnter Last_Name to be searched: ";
		getline(cin, name);
		for(int i = 0 ; i < n ; i++){
			if(name == lname[i]){
				p = i;
				flag++;
				break;
			}
		}
		if(flag == 0){
			cout << name << " is not registered.\n";
			goto start;
		}
		cout << name << " is registered on row " << p+1 << endl;
		goto start;
	}
	else if(choice == 'Q'){
		cout << "Thank you. Goodbye...";
		return 0;
	}
	else{
		cout << "\n\nInvalid Code. Try again...\n";
		goto start;
	}
}
