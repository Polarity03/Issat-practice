//Order management system

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int choice;
int counter = 0;

string OrderID[50];
string CustomerName[50];
int NumOfMagwinyas[50];
float TotalCost[50];

int main()
{
	do {
		cout<< "\n---> Order management system <---" << endl;
		cout<< "1. Add a new order" << endl;
		cout<< "2. Display all orders" << endl;
		cout << "3. Find order by order ID" << endl;
		cout << "4. Calculate total revenue" << endl;
		cout<< "5. Exit" << endl;
		cout<< "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			if (counter < 50) {
				cout << "Enter order ID: ";
				cin >> OrderID[counter];

				cout << "Enter customer name: ";
				cin.ignore();
				getline(cin, CustomerName[counter]);

				cout << "Enter number of Magwinyas: ";
				cin >> NumOfMagwinyas[counter];
				
				cout << "Enter total cost: ";
				cin >> TotalCost[counter];

				counter++;
			}
			else {
				cout << "Order limit reached. Cannot add more orders." << endl;
			}
		}
		if (choice == 2) {
			cout << "\n---> All Orders <---" << endl;
			for (int Orders = 0; Orders < counter; Orders++) {
				cout << "Order ID: " << OrderID[Orders] << endl;
				cout << "Customer Name: " << CustomerName[Orders] << endl;
				cout << "Number of Magwinyas: " << NumOfMagwinyas[Orders] << endl;
				cout << "Total Cost: " << TotalCost[Orders] << endl;
				cout << "-------------------------" << endl;
			}
		}
		if (choice == 3) {
			string SearchID;
			int Found = 0;

			cout << "Enter order ID to search: ";
			cin >> SearchID;

			for (int Orders = 0; Orders < counter; Orders++)
			{
				if (OrderID[Orders] == SearchID)
				{
					cout << "Order ID: " << OrderID[Orders] << endl;
					cout << "Customer Name: " << CustomerName[Orders] << endl;
					cout << "Number of Magwinyas: " << NumOfMagwinyas[Orders] << endl;
					cout << "Total Cost: " << TotalCost[Orders] << endl;

					Found = 1;
					break;
				}
			}

			if (Found == 0)
			{
				cout << "Order not found." << endl;
			}
		}
		if (choice == 4){
			float TotalRevenue = 0;

			for (int Orders = 0; Orders < counter; Orders++)
			{
				TotalRevenue = TotalRevenue + TotalCost[Orders];
			}

			cout << "\n---> Total Revenue <---" << endl;
			cout << "Total revenue: R" << TotalRevenue << endl;
		}
	} while (choice != 5);

	return 0;
}
