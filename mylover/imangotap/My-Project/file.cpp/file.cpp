
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define MAX 10

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void pauseScreen()
{
	cout << "Press Enter to continue..." << endl;
	cin.ignore(1000, '\n');
	cin.get();
};

struct Contact
{	
	string name;
	string address;
	string phone;
	int age=0;
	int gender=0; // 1.Male||2.Female

};

struct ContactBook
{
	int size=0;
	struct Contact carr[MAX];
	
};

//--------------------CreateMenu-------------------

void showmenu()
	{
		cout << "Menu:" << endl;
		cout << "1. Add Contact" << endl;
		cout << "2. ShowContact" << endl;
		cout << "3. DeleteContact" << endl;
		cout << "4. searchContact" << endl;
		cout << "5. Clear All Contact" << endl;
		cout << "6. Exit" << endl;
	};

//--------------------AddContact--------------------

void addContact(ContactBook*a)
{
	if (a->size == MAX) 
	{
		cout << "ContactBook is full" << endl;
		return;
	}

	else
	{
		// add contact.name
		string name;
		cout << "Pls enter name:" << endl;
		cin.ignore();
		getline(cin, name);
		a->carr[a->size].name = name;


		// address 
		string address;
		cout << "Pls enter address:" << endl;
		getline(cin, address);

		a->carr[a->size].address = address;


		// phone
		string phone;
		bool validphone = false;
		while (!validphone)
		{
			cout << "Pls enter phone:" << endl;
			getline(cin, phone);

			if (phone.length() < 8)
			{
				cout << "Invalid phone number" << endl;
			}

			else
			{
				a->carr[a->size].phone = phone;
				validphone = true;
			}
		}
		int age;
		bool validage = false;
		while (!validage)
		{
			cout << "Pls enter age:" << endl;
			cin >> age;
			if (cin.fail())
			{
				cout << "Pls enter numbers" << endl;
				cin.clear(); 
				cin.ignore(1000, '\n');  
			}
		    if (age < 0 || age>150)
			{
				cout << "Invalid age" << endl;
				cin.ignore(1000, '\n');
			}
			else
			{
				a->carr[a->size].age = age;
				cin.ignore(1000, '\n');
				validage = true;
			}

			int gender;
			bool validage = false;
			while (!validage)
			{
				cout << "Pls enter gender for 1.Male|| 2.Female " << endl;
				cin >> gender;
				if (cin.fail() || (gender != 1 && gender != 2))
				{
					cout << "Pls enter numbers" << endl;
				}
				else
				{
					a->carr[a->size].gender = gender;
				}
				break;
			}
		}

	} // else
	
	a->size++;
	cout << "Contact added successfully! Press Enter to continue..." << endl;
	

}; // viod

//--------------------showmenu--------------------

void showContact(ContactBook* a)
{
	if (a->size == 0) 
	{
		cout <<"ContactBook is empty" << endl;
		pauseScreen();
	}
	else
	{
		for (int i = 0; i < a->size; i++)
		{
			cout << "Name:" << a->carr[i].name << endl;
			cout << "Address:" << a->carr[i].address << endl;
			cout << "Phone:" << a->carr[i].phone << endl;
			cout << "Age:" << a->carr[i].age << endl;
			cout << "Gender:" <<(( a->carr[i].gender==1)?"男":"女") << endl;
		}
	}
	
};

//--------------------Delete Contact-----------------------

void DeleteContact(ContactBook* a, string Deletename)
{
	//  a->size == 0  return;
	//  while  >>  empty . 
	if (a->size==0)
	{
		cout << "Contact is empty ." << endl;
		
		pauseScreen();
		return;
	}
	while(1)
	{
		cout << "Pls enter you want delete to contact . Enter 0 to Exit ." << endl;
		getline(cin, Deletename);
		if (Deletename.empty())
		{
			cout << "valid Input . Pls enter again " << endl;
		}
		else if(Deletename=="0")
		{
			return;
		}
	}
	bool found = false;
	for(int i=0;i<a->size;i++)
	{
		if (a->carr[i].name == Deletename) 
		{
			char choose;
			cout << "are you sure to delete this contact ." << endl;
			cout << " -------------Delete Contact Info ---------------" << endl;

			cout << " Name： " << a->carr[i].name << endl;
			cout << " Address： " << a->carr[i].address << endl;
			cout << " Phone： " << a->carr[i].phone << endl;
			cout << " Age： " << a->carr[i].age << endl;

			cout << " Gender： " << ((a->carr[i].gender)==1?"男":"女") << endl;

			cin >> choose;
			if(choose=='y'||choose == 'Y')
			{
				for(int j=i;j < a->size-1;j++)
				{
					a->carr[j] = a->carr[j + 1];
					a->size--;
					found = true;
				}
			}
			else if (choose == 'n' || choose == 'N')
			{
				cout << " Cancell " << endl;
				break;
			}
			else 
			{
				cout << "valid Input " << endl;
				break;
			}
		}
		if(!found)
		{	
			cout << "cant found this contact ." << endl;
		}
	}
	
}

//--------------------main--------------------

int main() 
{
	ContactBook cb;
	bool exit = false;
	while (!exit)
	{   
		
		showmenu();
		int select = 0;

		cout << " Pls enter your select " << endl;
		cin >> select;
		
		
		switch (select)
		{

			case 1:
				clearScreen();
				addContact(&cb);
				//cout << "Add Contact" << endl;
				break;
			case 2:	
				clearScreen();
				showContact(&cb);
				//cout << "ShowContact" << endl;
				break;	
			case 3: 
				clearScreen();
				pauseScreen();
				{
				string name;
				DeleteContact(&cb,name);
				}
				//cout << "DeleteContact" << endl;
				break;
			case 4:
				//cout << "searchContact" << endl;
				break;
			case 5:
				//cout << "Clear All Contact" << endl;
				break;
			case 6:		
				cout << "Exit" << endl;
				exit = true;
				break;

			default:
				cout <<"Invalid Input"<<endl;
				break;

		}
		
	
	}

	return 0;
}