#include "product.h"

// Nhap thong tin san pham, bao gom
// ten san pham, nam san xuat va gia nhap
void Product::Input() 
{
	cout << "Ten san pham:";
	cin.ignore();			
	getline(std::cin, name_);
	cout << "Nam san xuat:";
	cin >> production_year_;
	cout << "Gia nhap:";
	cin >> original_price_;
}

// In ra thong tin san pham tren 1 dong theo dinh dang sau
// Do rong 25 ky tu cho ten san pham, can le phai
// Do rong 10 ky tu cho nam san xuat, can le phai
// Do rong 20 ky tu cho gia nhap, can le phai
void Product::Output() 
{
	cout << setw(25) << GetName()  << setw(15) << GetOriginalPrice();
}

// Tra ve ten san pham
string Product::GetName()
{		
	return name_;
};

// Tra ve nam san xuat
int Product::GetProductionYear() {
	//your code here
	return production_year_;
}

// Tra ve gia goc
long Product::GetOriginalPrice() 
{
	return original_price_;
}