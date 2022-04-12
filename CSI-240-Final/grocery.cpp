#include "grocery.h"


void startMenu() 
{
	switch (login())
	{
	case 'a':
		adminMenu();
		break;
	case 'c':
		customerMenu();
		break;
	default:
		//throw exception
		break;
	}
}

//Mikey
//Output char depending on result: a, or c
char login() 
{
	string username;
	string password;
	cout << "Username: ";
	cin >> username;
	cout  << "\nPassword: ";
	cin >> password;

	ifstream login;
	login.open("login.dat");
	if (!login.is_open())
	{
		throw Exceptions("Error - File cannot be found");
	}
	else
	{
		while (!login.eof())
		{
			string temp;
			getline(login, temp);
			if (temp == username)
			{
				getline(login, temp);
				if (temp == password)
				{
					if (username == ADMIN_USER)
					{
						adminMenu();
						return 'a';
					}
					else
					{
						customerMenu();
						return 'c';
					}
				}
				else		
				throw Exceptions("Incorrect Password");
			}
		}
		throw Exceptions("Username does not exist");
	}
}

void adminMenu() 
{
	Inventory inventory;
	inventory.importInventory();

	int pickOption;
	cout << "Please Select How You'd Like to Proceed" << endl;
	cout << "[1] Add Item To Inventory" << endl;
	cout << "[2] Delete Item From Inventory" << endl;
	cout << "[3] Display Inventory" << endl;
	cout << "[4] Save and Quit" << endl;
	cout << "Please Select One To Continue: ";
	cin >> pickOption;
	switch (pickOption)
	{
	case 1:
		inventory.addToInventory();
		break;
	case 2: 
		//Delete item from inventory
		break;
	case 3:
		//Display Inventory
		break;
	default:
		// Load vector to file
		// Quit
		break;
	}
}

void customerMenu() 
{
	cout << "yo";
	//int pickOption;
	//switch (pickOption)
	//{
	//case 1:
	//	//Add Inventory Item to cart
	//	break;
	//case 2:
	//	//REmove Item form cart
	//	break;
	//case 3:
	//	//Display Cart
	//	break;
	//case 4: 
	//	//Checkout
	//	break;
	//default:
	//	//Quit
	//	break;
	//}
}

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::addToInventory()
{

}

void Inventory::displayInventory()
{
	for (string i : inventoryList) 
	{
		cout << i << endl;
	}
}

void Inventory::importInventory()
{
	ifstream inventoryFile;
	//check if file exists
	inventoryFile.open(INVENTORY_FILE_NAME);
	while (!inventoryFile.eof()) 
	{
		string newLine;
		getline(inventoryFile, newLine);
		inventoryList.push_back(newLine);
	}

	cout << "[[IMPORT SUCCESSFUL]]" << endl;
}

void Inventory::exportInventory()
{

}