#include <iostream>
#include "ListCustomer.h"
#include <fstream>
int main()
{
	/*fstream ifs("c:\\users\\hp\\desktop\\-n-qu-n-l-kh-ch-s-n\\đồ án 18.10c\\mainqlks\\mainqlks\\danhsach.txt");
	customer* customers = new customer[10];
	string mahoadon, ten, cmnd, tenphong, loaiphong;
	bool gioitinh;
	date ngayden, ngaydi;
	int tienphong, dongia;
	size_t i = 0;
	while (!ifs.eof()) {
		cin.ignore();
		ifs >> mahoadon;
		ifs >> ten;
		ifs >> cmnd;
		ifs >> gioitinh;
		ifs >> tenphong;
		ifs >> ngayden.setday();
		ifs >> ngaydi;

	}*/
	int choice;
	//x.nhap();
	//x.xuat();
	ListCustomer listTry;
	
	//listTry.Add();
	//listTry.Indanhsach();
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

