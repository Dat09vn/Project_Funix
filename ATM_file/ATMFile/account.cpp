#include<iostream>
#include<iomanip>
#include"account.h"

using namespace std;

// Tao moi tai khoan:
// Nhap so tai khoan, ten chu tai khoan, loai tai khoan
// va so du ban dau tu ban phim
void Account::CreateAccount()
{
	cin.ignore();
	do
	{
		cout << "Nhap so tai khoan: ";
		cin >> account_number_;
	} while (account_number_ <= 0);

	cout << "Nhap ten tai khoan: ";
	cin.ignore();
	cin.getline(name_, 100);

	do
	{
		cout << "Nhap loai tai khoan: ";
		cin >> type_;
	} while (type_ != 'N' && type_ != 'V');

	do
	{
		cout << "Nhap so du ban dau: ";
		cin >> balance_;
	} while (balance_ <= 0);
}

// Sua doi tai khoan:
// Nhap moi ten chu tai khoan, loai tai khoan va so du
void Account::Modify()
{
	cout << "\nNhap thong tin de thay doi:";
	cout << "\nTen chu tai khoan: ";
	cin.ignore();
	cin.getline(name_, 100);

	do
	{
		cout << "Loai tai khoan : ";
		cin >> type_;
	} while (type_ != 'N' && type_ != 'V');

	do
	{
		cout << "So du : ";
		cin >> balance_;
	} while (balance_ <= 0);
}

// Nap them tien vao tai khoan
void Account::Deposit(int amount)
{
	balance_ = balance_ + amount;
}

// Rut tien tu tai khoan
void Account::Withdraw(int amount)
{
	balance_ = balance_ - amount;
}

// Hien thi thong tin tai khoan (khong in theo dinh dang)
// Thong tin hien thi tren 4 dong:
// Dong 1: So tai khoan
// Dong 2: Ten chu tai khoan
// Dong 3: Loai tai khoan
// Dong 4: So du tai khoan
void Account::PrintAccount() const
{
	cout << "\nSo tai khoan: " << account_number_;
	cout << "\nTen chu tai khoan: " << name_;
	cout << "\nLoai tai khoan: " << type_;
	cout << "\nSo du tai khoan: " << balance_ << endl;
}

// In ra thong tin tai khoan tren mot dong theo dinh dang
// So tai khoan: do rong 11 ky tu, can le trai
// Ten chu tai khoan: do rong 19 ky tu, can le trai
// Loai tai khoan: do rong 8 ky tu, can le trai
// So du tai khoan: do rong 14 ky tu, can le trai
void Account::PrintAccountInFormat() const
{
	cout << setw(11) << left << account_number_ << setw(19) << left << name_ << setw(8) << left << type_ << setw(14) << left << balance_ << endl;
}

// Lay ra so tai khoan
int Account::GetAccountNumber() const
{
	return account_number_;
}

// Lay ra so du
int Account::GetBalance() const
{
	return balance_;
}

// Lay ra kieu tai khoan
char Account::GetType() const
{
	return type_;
}