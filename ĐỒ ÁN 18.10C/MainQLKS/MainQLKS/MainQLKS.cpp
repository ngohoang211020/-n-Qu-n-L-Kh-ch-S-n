#include <iostream>
#include "ListCustomer.h"
#include <fstream>
int main()
{
	int choice;
	ListCustomer listTry;
	do {	
		Customer x;
		cout << "Nhap cong viec can thuc hien: ";
		cin >> choice;
		switch (choice) {
		case 1:
			listTry.Indanhsach();
			break;
		case 2:
			listTry.Add();
			break;
		case 3:
			listTry.Delete();
			break;
		default:
			cout << "Out";
		}
	} while (choice > 0);
	
	Customer x;
	x.nhap();
	x.xuat();
	cout << "Done" << endl;
	return 0;
}

