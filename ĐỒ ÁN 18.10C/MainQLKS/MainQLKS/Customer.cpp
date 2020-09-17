#include "Customer.h"
#include <fstream>

//tinh tổng số ngày từ 0/0/0 đến hiện tại
int Sumday(int year, int month, int day) {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;

}

void Customer::nhap() {
	string Mahoadon, Ten, Cmnd, Tenphong; 
	bool Gioitinh;
	Date Ngayden, Ngaydi; 
	
	fstream input("C:\\Users\\HP\\Desktop\\docfileDoAn.txt", ios::in);

	//nhap ma hoa don
	do
	{
		cout << "\nMa hoa don: ";
		getline(input, Mahoadon);
		if(Mahoadon.length() != 9){
			cout << "Ma hoa don gom co 9 ki tu!!" << endl;
			cout << "Nhap lai ma hoa don!!" << endl;
		}
	} while (Mahoadon.length() != 9);
	//nhap ten
	cout << "Nhap ten: ";
	//cin.ignore();
	getline(input,Ten);
	//nhap so cmnd
	do
	{
		cout << "Nhap so cmnd: ";
		getline(input,Cmnd);
		if (Cmnd.length() == 9) {
			break;
		}
		else {
			cout << "So CMND da nhap khong phu hop!!" << endl;
			cout << "CMND phai gom co 9 so!!" << endl;
		}
	} while (true);
	//nhap gioi tinh
	cout << "Nhap gioi tinh" << endl;
	cout << "1: Nam" << endl;
	cout << "2: Nu" << endl;
	int temp;
	input >> temp;
	if (temp == 1) {
		Gioitinh = true;
	}
	else {
		Gioitinh = false;
	}
	//nhap ten phong
	do
	{
		cout << "Nhap ten phong: ";
		getline(input, Tenphong);
		if (Tenphong.length() != 4) {
			cout << "Ten phong da nhap khong phu hop!!" << endl;
			cout << "Ten phong chi gom 4 ki tu!!" << endl;
		}
		else if (Tenphong[0] < 65 || Tenphong[0]>90) {	//Cái ni có 3 loại phòng A B C thôi chắc không cần 90 mô hè?
			cout << "Ten phong da nhap khong phu hop!!" << endl;
			cout << "Ten phai bat dau bang 1 chu cai in hoa!!" << endl;
		}
		else {
			break;
		}
	} while (true);
	//ngay den
	cout << "Nhap ngay den:" << endl;
	Ngayden.setDate();
	//ngay di
	do{
		cout << "Nhap ngay di:" << endl;
		Ngaydi.setDate();
		int numberOfDays = Sumday(Ngaydi.getYear(), Ngaydi.getMonth(), Ngaydi.getDay()) - Sumday(Ngayden.getYear(), Ngayden.getMonth(), Ngayden.getDay());
		cout << numberOfDays;
		if (numberOfDays >= 0) { break; }
		else {
			cout << "Ngay da nhap khong dung!!!" << endl;
		}
	} while (true);
	input.close(); // Đóng file
	this->mahoadon = Mahoadon;
	this->ten = Ten;
	this->cmnd = Cmnd;
	this->tenphong = Tenphong;
	this->gioitinh = Gioitinh;
	this->ngayden = Ngayden;
	this->ngaydi = Ngaydi;
}
void Customer::xuat() {
	string gender;
	int dongia, tienphong;
	//gender
	if (gioitinh == true) gender = "Nam";
	else gender = "Nu";
	//loai phong
	loaiphong = tenphong[0];
	//dongia
	if (loaiphong == "A") dongia = 400;
	else if (loaiphong == "B") dongia = 300;
	else dongia = 250;
	//tien phong
	int numberOfDays = Sumday(ngaydi.getYear(), ngaydi.getMonth(), ngaydi.getDay()) - Sumday(ngayden.getYear(), ngayden.getMonth(), ngayden.getDay());
	tienphong = (numberOfDays+1) * dongia;
	//in thong tin theo format
	cout << setw(12) <<left<< mahoadon << setw(18) << left << ten << setw(11) << left << cmnd << setw(5)  << left << gender << setw(6)  << tenphong << setw(3) << left << loaiphong;
	cout << setw(2)<<left<<"  ";
	ngayden.show();
	cout << setw(2) << left << "  ";
	ngaydi.show();
	cout << setw(2) << left << " ";
	cout << setw(3) << left << dongia << setw(7)<< right << tienphong << endl;
}
