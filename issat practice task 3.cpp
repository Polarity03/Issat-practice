// issat practice task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
		cout<< "\n---Order management system---" << endl;
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
			cout << "\n---All Orders---" << endl;
			for (int orders = 0; orders < counter; orders++) {
				cout << "Order ID: " << OrderID[orders] << endl;
				cout << "Customer Name: " << CustomerName[orders] << endl;
				cout << "Number of Magwinyas: " << NumOfMagwinyas[orders] << endl;
				cout << "Total Cost: " << TotalCost[orders] << endl;
				cout << "-------------------------" << endl;
			}
		}
		if (choice == 3) {
			string searchID;
			int found = 0;

			cout << "Enter order ID to search: ";
			cin >> searchID;

			for (int orders = 0; orders < counter; orders++)
			{
				if (OrderID[orders] == searchID)
				{
					cout << "Order ID: " << OrderID[orders] << endl;
					cout << "Customer Name: " << CustomerName[orders] << endl;
					cout << "Number of Magwinyas: " << NumOfMagwinyas[orders] << endl;
					cout << "Total Cost: " << TotalCost[orders] << endl;

					found = 1;
					break;
				}
			}

			if (found == 0)
			{
				cout << "Order not found." << endl;
			}
		}
	} while (choice != 5);

	return 0;
}

