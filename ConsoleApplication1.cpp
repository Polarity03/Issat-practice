// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

// Decimal to Binary
void decimalToBinary(int num) {
    int binary[32], i = 0;

    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    cout << "Binary: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
    cout << endl;
}

// Binary to Decimal
void binaryToDecimal(int num) {
    int decimal = 0, base = 1, remainder;

    while (num > 0) {
        remainder = num % 10;
        decimal += remainder * base;
        base *= 2;
        num /= 10;
    }

    cout << "Decimal: " << decimal << endl;
}

// Hexadecimal to Decimal
void HexadecimalToDecimal(string hex) {
	int decimal = 0, i= 0, value = 0;

	while (i < hex.length()) {
		char digit = hex[i];

		if (digit >= '0' && digit <= '9')
			decimal = decimal * 16 + (digit - '0');

		else if (digit >'A' && digit <= 'F')
			decimal = decimal * 16 + (digit - 'A' + 10);

		else if (digit >'a' && digit <= 'f')
			decimal = decimal * 16 + (digit - 'a' + 10);

		else {
			cout<<"Invalid hexadecimal number";

		}

		decimal = decimal * 16 + value;
		i++;	
	}

	cout<< "Decimal = "<< decimal<< endl;

}
// Random integer to Binary
void Demo() {
	int number = rand() % 100 + 1;
	string binary = "";

	cout<< "Random integer is: "<< number << endl;

	while (number > 0) {
		binary = char((number % 2) + '0') + binary;
		number = number / 2;	
	}
	cout<< "Your binary number is: "<< binary << endl;

}

int main() {
    int choice, num;
	string hex;

    do {
        cout << "\n---Conversion Menu ---" << endl;
        cout << "1. Decimal to Binary" << endl;
        cout << "2. Binary to Decimal" << endl;
		cout << "3. Hexadecimal to Decimal" << endl;
		cout << "4. Demo (Generate and convert random integers to binary) " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter decimal number: ";
                cin >> num;
                decimalToBinary(num);
                break;

            case 2:
                cout << "Enter binary number: ";
                cin >> num;
                binaryToDecimal(num);
                break;

			case 3:
				cout<<"Enter Hexadecimal number: ";
				cin >> hex;
				HexadecimalToDecimal(hex);
				break;

			case 4:
				srand(time(0));
				Demo();
				break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } 
	while (choice != 5);

    return 0;
}