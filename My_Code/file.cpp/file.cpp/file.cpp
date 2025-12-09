#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
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

void clearline() 
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
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
//--------------------showmenu-------------------

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

	
	//--------------------addcontact--------------------

void addContact(ContactBook*a)
{
	if (a->size == MAX) 
	{
		cout << "ContactBook is full" << endl;
		return;
	}

	else 
	{
		clearline();
		// add contact.name
		string name;
		cout << "Pls enter name:" << endl;
		getline(cin,name);
		a->carr[a->size].name = name;


		// address 
		string address;
		cout << "Pls enter address:" << endl;
		getline(cin,address);

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
	}

	int age;
	bool validage = false;
	while (!validage)
	{
		cout << "Pls enter age:" << endl;
		cin >> age;
		if (cin.fail() || age < 0 || age > 150)
		{
			cout << "Pls enter numbers of age ( 0~150 ) " << endl;
			cout << "Debug : validage " << validage << endl;
			clearline();
			
		}
		else
		{
			a->carr[a->size].age = age;
			validage = true;
		}
	}
		
	int gender;
	bool validgender= false;
	while(!validgender)
	{
		cout << "Pls enter gender for 1.Male|| 2.Female " << endl;
		cin >> gender;

		if (cin.fail() || (gender != 1 && gender != 2))
		{
			cout << "Pls enter numbers" << endl;
			clearline();
		}
		else
		{
			a->carr[a->size].gender = gender;
			validgender = true;
		}
		
	}

	a->size++;
	cout << "Contact added successfully! Press Enter to continue..." << endl;
	clearline();
	cin.get();
	clearScreen();
	

};

//--------------------showmenu--------------------

void showContact(ContactBook* a)
{
	if (a->size == 0) 
	{
		cout <<" ContactBook is empty " << endl;
	}
	else
	{
		for (int i = 0; i < a->size; i++)
		{
			
			cout << "\n Name:" << a->carr[i].name << endl;
			cout << "address:" << a->carr[i].address << endl;
			cout << "phone:" << a->carr[i].phone << endl;
			cout << "age:" << a->carr[i].age << endl;
			cout << "gender:" << ((a->carr[i].gender)==1?"男":"女") << endl;
		}
	}
	cout << " Press Enter to continue..." << endl;
	clearline();
	cin.get();
	clearScreen();
	

};
void DeleteContact(ContactBook* a, string Deletename)
{
	if (a->size == 0)
	{
		cout << "ContactBook is emoty" << endl;
		clearline();
		cin.get();
		clearScreen();
		return;

	}
	else    // enter 0 exit . size[i]--;
	{
		clearline();
		bool validname = false;
		while (!validname)
		{
			cout << "Pls enter you wan to delete name . enter 0 Exit ." << endl;

			getline(cin, Deletename);

			if (Deletename.empty())
			{
				cout << "Name cannot be empty. Please try again." << endl;
				continue;
			}

			if (Deletename == "0")
			{
				cout << "Exit Delete ." << endl;
				return;
			}
			bool found = false;
			for (int i = 0; i < a->size; i++)
			{
				if (a->carr[i].name == Deletename)
				{
					found = true;
					char confirm;
					cout << " are you sure you want to  delete this contact. ( y/n ) " << endl;
					cin >> confirm;
					if (confirm == 'y' || confirm == 'Y')
					{
						for (int j = i; j < a->size - 1; j++)
						{
							a->carr[j] = a->carr[j + 1];
							validname = true;
							a->size--;
							cout << "Contact deleted successfully!" << endl;
							break;
						}
					}
					else if (confirm == 'n' || confirm == 'N')
					{
						cout << "Delete cancelled." << endl;
						break; // 跳出for循环，但不退出while循环
					}
					else
					{
						cout << "Invalid input. Please enter 'y' or 'n'." << endl;
						break; // 跳出for循环，重新开始
					}
				}

			}
			if (!found)
			{
				cout << "Contact not found." << endl;
			}

		}
		
	

	cout << " Press Enter to continue..." << endl;
	clearline();
	cin.get();
	clearScreen();
	}
};


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

			case 1:		addContact(&cb);
				//cout << "Add Contact" << endl;
				break;
			case 2:		showContact(&cb);
				//cout << "ShowContact" << endl;
				break;	
			case 3: {
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

	system("pause");
	return 0;
}