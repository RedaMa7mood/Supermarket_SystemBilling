#include <iostream>
#include <fstream>
#include <sstream> 
#include<Windows.h>
using namespace std;

class shopping
{
private:
	int  pcode; 
	float price; 
	float discount;
	string pname;

public :
	shopping()
	{
		pcode = 0;
		price = 0;
		discount = 0;
		pname = "";
	}
	void menu();
	void adminstrator();
	void buyer();
	void add();

	void edit();
	void removee();
	void list();
	void receipt();

};
void shopping::menu()
{
	
	bool close=true;
	do {
		system("cls");
		int choice;
		string email;
		string password;
		cout << "\t\t\t\t______________________________________________\n";
		cout << "\t\t\t\t									           \n";
		cout << "\t\t\t\t             Supermarket Main Menu            \n";
		cout << "\t\t\t\t									           \n";
		cout << "\t\t\t\t______________________________________________\n";
		cout << "\t\t\t\t									           \n";
		cout << "\t\t\t\t		1)Adminstrator			|\n";
		cout << "\t\t								|\n";
		cout << "\t\t\t\t		2)Buyer		         	|\n";
		cout << "\t\t								|\n";
		cout << "\t\t\t\t		3)Exit		         	|\n";
		cout << "\t\t								|\n";

		cout << "\n\t\t\t Please select : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\t\t\t\t  ______________________________________________";

			cout << "\n\n\t\t\t\t\t\t   Please Login \n";
			cout << "\t\t\t\t  ______________________________________________\n\n";

			cout << "\t\t\t   Enter Email : \n\t\t\t\t";
			cin >> email;
			cout << "\t\t\t   Enter Password :\n\t\t\t\t";
			cin >> password;

			if (email == "reda@gmail.com" and password == "123456")
			{
				adminstrator();
			}
			else
			{
				cout << "Invalid email or password Try again";
				Sleep(2000);
			

			}
			break;
		case 2:
		{
			buyer();
			break;
		}
		case 3:
		{
			close = false;
			break;
		}
		default:
			cout << "Please select from those operations ";
			break;
		}

	} while (close);
	
	

}

void shopping::adminstrator()
{

	bool close = false;
	do {

		system("cls");
		int choice;
		cout << "\t\t\t Adminstrator Menu\n";
		cout << "\t\t\t____1) Add product_______|\n";
		cout << "\t\t\t____2) Modify product____|\n";
		cout << "\t\t\t____3) delete product____|\n";
		cout << "\t\t\t____4) Back to main menu_|\n";
		cout << "\n\t\t\tEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			removee();
			break;
		case 4:
			close = true;
			break;
		default:
			cout << "Invalid choice!\n";
		}

	} while (!close);
	

}
void shopping::buyer()
{
	
	int close = false;
	do
	{
		system("cls");
		int choice;
		cout << "\t\t\t Buyer Menu\n";
		cout << "\t\t\t__________________\n";
		cout << "\t\t\t 1) Buy product\n";
		cout << "\t\t\t 2) Go Back \n\n\n";
		cout << "\n\t\t\tEnter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			receipt();
			break;
		case 2:
			close = true;
			break;

		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (!close);
	

}
void shopping::add()
{
	fstream data;
	int code;
	float pri, dis;
	string name;
	int token = 0;
	cout << "\n\t\t\t Add new product\n";
	cout << "\tcode of product : ";
	cin >> pcode;
	cout << "\tname of product : ";
	cin >> pname;
	cout << "\tprice of product :";
	cin >> price;
	cout << "\tdiscount of product :";
	cin >> discount;

	data.open("database.txt", ios::in);
	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << discount << '\n';
		data.close();
	}
	else {
		data >> code >> name >> pri >> dis;
		while (!data.eof()) {
			if (code == pcode)
			{
				token++;
			}
			data >> code >> name >> pri >> dis;
		}
		data.close();

		if (token >0) {
			cout << "\n\t\t Product already exists. Please enter a different product code.\n";
			Sleep(3000);
			return; // Exit the function to avoid adding the duplicate product
		}
		else {
			data.open("database.txt", ios::app | ios::out);
			data << " " << pcode << " " << pname << " " << price << " " << discount << '\n';
			data.close();
		}
	}
	cout << "\n\t\t Record inserted !";
	Sleep(3000);
	system("cls");
}

void shopping::edit()
{
	fstream data, data1;
	int pkey;
	int code;
	float pri;
	float dis;
	string name;
	int token=0;
	
	cout << "\n\n\t\t\t Modify the Record \n";
	cout << "\t\t\t product code : ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n file doesn`t exist! ";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> discount;
		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\t\t product new code :";
				cin >> code;
				cout << "\n\t\t product new name :";
				cin >> name;
				cout << "\n\t\t product new price :";
				cin >> pri;
				cout << "\n\t\t product new discount :";
				cin >> dis;
				data1 << " " << code << " " << name << " " << pri<<" " << dis << '\n';
				token++;
			}
			else
			{
				data1 <<" "<< pcode << " "<< pname << " " << price << " " << discount<<'\n';

			}
			data >> pcode >> pname >> price >> discount;

		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");
    
			if (token == 0)
			{
				cout << "Rcord not found !\n";
			}
			else
			{
				cout << "\n\t\t\t\tYour Modification has been done...\n";
			}
	}

	Sleep(3000);


}
void shopping::removee()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\t\t\t Delete product\n";
	cout << "Enter product code : ";
	cin >> pkey;

	data.open("database.txt", ios::in);
		if (!data)
		{
			cout << "\n file doesn`t exist!\n ";

		}
		else
		{
			data1.open("database1.txt", ios::app | ios::out);
			data >> pcode >> pname >> price >> discount;
			while (!data.eof())
			{
				if (pkey == pcode)
				{
					cout << "\t\t Product deleted successfully\n";
					token++;
				}
				else
				{
					data1 << " " << pcode << " " << pname << " " << price << " " << discount << '\n';

				}
				data >> pcode >> pname >> price >> discount;

			}
			data.close();
			data1.close();
			remove("database.txt");
			rename("database1.txt", "database.txt");

			if (token == 0)
			{
				cout << "Rcord not found !\n";
			}

		}

		Sleep(3000);
	

}
void shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);

	cout << "\n_________________________________________\n";
	cout << "ProNo\t|\tName\t|\tPrice\n";
	cout << "__________________________________________\n";
	data >> pcode >> pname >> price >> discount;
	while (!data.eof())
	{
		cout << pcode << "\t|\t" << pname << "\t|\t" << price << "\t|\t" << '\n';
		data >> pcode >> pname >> price >> discount;

	}

	data.close();

}
struct Product
{
	int code;
	int quant;
};

void shopping::receipt()
{
	fstream data;
	Product p [100]{};
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;
	char choice;
	cout << "\t\t\t Welcome To Receipt\n ";

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "Empty database\n";
	}
	else
	{
		data.close();
		list();
		cout << "\n\n_______-----_____________-----_________\n";
	    cout << "|          Please place order         |\n";
		cout << "-------_____-------------_____---------\n";

		do{
			bool duplicate = false;
		cout << "\nEnter product code : ";
		cin >> p[c].code;
		cout << "Enter product quantity : ";
		cin >> p[c].quant;
		for (int i = 0; i < c; i++)
		{
			if (p[c].code == p[i].code) 
			{
				cout << "Duplicate product code additional quantity!\n";
				p[i].quant += p[c].quant;
				duplicate = true;
				break;
	        }
		}
		if (!duplicate)
		{
			c++;
		}
		cout << "do you want to buy another product ? if yes press [Y or y] else [N,n]... ";
		cin >> choice;

		} while (choice == 'y' || choice == 'Y');

		
		cout << "\n\t\t\t__________________________RECEIPT________________________\n";
		cout << "\n Product NO\t Product Name\t Qunatity\t Price\t Amount\t Amount With discount\n";
		for (int i = 0;i < c;i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> discount;
			while (!data.eof())
			{
				if (pcode == p[i].code) {
					amount = price * p[i].quant;
					dis = amount - (amount * dis / 100);
					total += dis;
					cout << pcode << "\t\t" << pname << "\t\t" << p[i].quant << "\t\t" << price << "\t\t" << amount << "\t\t" << dis<<'\n';
				}
				data >> pcode >> pname >> price >> discount;

			}
		}
		data.close();

    
	}
	system("cls");
	Sleep(3000);
	cout << "\n Total Bill is : " << total;
	cout << endl;
	cout << "thank you for shopping......\n";
	Sleep(2000);


}

int main()
{
	shopping s;
	s.menu();
}

