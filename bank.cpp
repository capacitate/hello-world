#include <iostream>

using namespace::std;
const int NAME_LEN = 20;

typedef struct _Account
{
	int id;
	int balance;
	char name[NAME_LEN];
} Account;

Account pArray[100];
int index = 0;

void PrintMenu();
void MakeAccount();
void Deposit();
void Withdraw();
void Inquire();

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void)
{
	int choice;

	while(1){
		PrintMenu();
		cout << "Make a choice : ";
		cin >> choice;

		switch(choice){
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				Deposit();
				break;
			case WITHDRAW:
				Withdraw();
				break;
			case INQUIRE:
				Inquire();
				break;
			case EXIT:
				return 0;
			default:
				cout << "Illegal selection.." << endl;
				break;
		}
	}
	return 0;
}

void PrintMenu()
{
	cout << "===Menu===" << endl;
	cout << "1. Make an account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Inquire" << endl;
	cout << "5. Exit" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "Make an account ---" << endl;
	cout << "Account ID : ";	cin >> id;
	cout << "Name : ";		cin >> name;
	cout << "Balance : ";		cin >> balance;

	pArray[index].id = id;
	pArray[index].balance = balance;
	strcpy(pArray[index].name, name);

	index++;
}

void Deposit()
{
	int money;
	int id;

	cout << "Account ID : ";	cin >> id;
	cout << "Deposit : ";		cin >> money;

	for(int i = 0; i < index; i++)
	{
		if(pArray[i].id == id)
		{
			pArray[i].balance += money;
			cout << "complete" << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl;
}

void Withdraw()
{
	int money;
	int id;

	cout << "Accoutn ID : ";	cin >> id;
	cout << "Withdraw : ";		cin >> money;

	for(int i = 0; i < index; i++)
	{
		if(pArray[i].id ==  id)
		{
			if(pArray[i].balance < money)
			{
				cout << "run out of money" << endl;
				return;
			}

			pArray[i].balance -= money;
			cout << "complete" << endl;
			return;
		}
	}

	cout << "Invalid ID" << endl;
}

void Inquire()
{
	for(int i = 0; i < index; i++)
	{
		cout << "Account ID : " << pArray[i].id << endl;
		cout << "Name : " << pArray[i].name << endl;
		cout << "Balance : " << pArray[i].balance << endl;
	}
}
