#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "account.h"
using namespace std;

void CreateAccount();
void SearchAndPrintAccount(int);
void SearchAndModifyAccount(int);
void DeleteAccount(int);
void PrintAllAccountInFormat();
void DepositOrWithdraw(int, int);

int main()
{
	char menu_option;
	int account_number; 
	do
	{
		system("cls");
		cout << "\n\n\n\tMenu";
		cout << "\n\n\t1. Tao tai khoan";
		cout << "\n\n\t2. Nop tien";
		cout << "\n\n\t3. Rut tien";
		cout << "\n\n\t4. Tra cuu tai khoan";
		cout << "\n\n\t5. Danh sach tai khoan";
		cout << "\n\n\t6. Xoa tai khoan";
		cout << "\n\n\t7. Sua tai khoan";
		cout << "\n\n\t8. Thoat";
		cout << "\n\n\tChon menu (so tu 1 den 8) ";
		cin >> menu_option;
		system("cls");
		switch (menu_option)
		{
			case '1':
				CreateAccount();
				cout << "\n\n\nTai khoan da duoc luu thanh cong" << endl;
				break;

			case '2':
				cout << "\n\n\tChon so tai khoan: ";
				cin >> account_number;
				DepositOrWithdraw(account_number, 1);
				break;
			case '3':
				cout << "\n\n\tChon tai khoan: ";
				cin >> account_number;
				DepositOrWithdraw(account_number, 2);
				break;
			case '4':
				cout << "\n\n\tNhap so tai khoan: ";
				cin >> account_number;
				SearchAndPrintAccount(account_number);
				cout << "\nPress Enter to continue.";
				break;
			case '5':
				PrintAllAccountInFormat();
				cout << "\nPress Enter to continue.";
				break;
			case '6':
				cout << "\n\n\tNhap so tai khoan: ";
				cin >> account_number;
				DeleteAccount(account_number);
				break;
			case '7':
				cout << "\n\n\tNhap so tai khoan: ";
				cin >> account_number;
				SearchAndModifyAccount(account_number);
				break;
			case '8':
				cout << "\n\n\nCam on ban da su dung dich vu, hen gap lai";
				break;
			default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (menu_option != '8');
	return 0;
}

// Tao mot tai khoan bang cach nhap tu ban phim
// roi luu tai khoan vua tao vao file "account.dat"
void CreateAccount()
{
	Account account;
	account.CreateAccount();
	ofstream out_file("account.dat", ios_base::app,ios_base::binary);
	//your code here
	if (out_file.is_open()) {
		out_file.write((char*)&account, sizeof(Account));
	}
	out_file.close();
}

// Tim tai khoan co so tai khoan la account_number trong file "account.dat"
// Roi nop hoac rut tien vao tai khoan tim duoc
// option = 1: nop tien
// option = 2: rut tien
// So tien nop hoac rut duoc nhap tu ban phim
// Sau cung, luu tai khoan vua sua doi vao file "account.dat"
void DepositOrWithdraw(int account_number, int option)
{
	int amount; // So tien muon rut/nop duoc nhap tu ban phim
	bool found = false;
	Account account;
	fstream file;
	int index = 0;

	file.open("account.dat", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "“Khong mo duoc file, hay an phim enter de quay lai menu chinh" << endl;
		return;
	}

	while (!file.eof() && found == false)
	{
		file.read(reinterpret_cast<char*> (&account), sizeof(Account));

		if (account.GetAccountNumber() == account_number)
		{
			account.PrintAccount();
			if (option == 1)
			{
				cout << "\n\n\tNop tien ";
				cout << "\n\nNhap so tien nop: ";
				cin >> amount;
				account.Deposit(amount);
			}
			else if (option == 2)
			{
				cout << "\n\n\tRut tien ";
				cout << "\n\nNhap so tien rut: ";
				cin >> amount;
				account.Withdraw(amount);
			}
			if (file.is_open()) {
				std::streampos pos(index * sizeof(Account));           
				file.seekp(pos);  
				file.write((char*)&account, sizeof(Account));
				file.close();
			}
			cout << "\n\n\t Giao dich thuc hien thanh cong";
			found = true;
		}
		index = index++;
	}
	file.close();
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}

// Tim va in tai khoan co so tai khoan la account_number (không in theo dinh dang)
// Tim tai khoan trong file "account.dat"
void SearchAndPrintAccount(int account_number)
{
	Account account;
	bool found = false;
	ifstream in_file;
	in_file.open("account.dat",ios::binary);
	if (!in_file)
	{
		cout << "Khong mo duoc file, hay nhan enter de quay lai menu." << endl;
		return;
	}
	cout << "\nKet qua tim kiem:\n";
	while (!in_file.eof() && found == false){
		in_file.read(reinterpret_cast<char*> (&account), sizeof(Account));

		if (in_file.good()) 
		{	
			if (account.GetAccountNumber() == account_number)
			{
				found = true;
				account.PrintAccount();
			}
		}
	}
	in_file.close();
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}

// In ra tat ca cac tai khoan luu trong file "account.dat" theo dinh dang
// Moi tai khoan in tren mot dong
void PrintAllAccountInFormat()
{
	Account account;
	ifstream in_file;
	in_file.open("account.dat", ios::binary);
	if (!in_file)
	{
		cout << "Khong mo duoc file, hay nhan enter de quay lai menu." << endl;
		return;
	}
	cout << "\n\n\t\tDanh sach tai khoan:\n\n";
	cout << "====================================================\n";
	cout << "So TK      Chu TK             Loai    So du\n";
	cout << "====================================================\n";
	while (in_file.read(reinterpret_cast<char*> (&account), sizeof(Account)))
	{
		account.PrintAccountInFormat();
	}
	in_file.close();
}

// Tim tai khoan co so tai khoan la account_number (khong in theo dinh dang)
// trong file "account.dat"
// Sau do cho phep nguoi dung sua doi tai khoan nay
// bang cach thay doi ten chu tai khoan, loai tai khoan va so du
// Cuoi cung, luu thay doi vao file "account.dat"
void SearchAndModifyAccount(int account_number)
{
	bool found = false;
	Account account;
	fstream file;
	int index = 0;

	file.open("account.dat", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "Khong mo duoc file, hay nhan enter de quay lai menu." << endl;
		return;
	}

	while (!file.eof() && found == false)
	{
		file.read(reinterpret_cast<char*> (&account), sizeof(Account));

		if (account.GetAccountNumber() == account_number)
		{
			account.Modify();
			if (file.is_open()) {
				std::streampos pos(index * sizeof(Account));        
				file.seekp(pos);    
				file.write((char*)&account, sizeof(Account));
				file.close();
			}
			cout << "\n\n\t Tai khoan da sua thanh cong";
			found = true;
		}
		index = index++;
	}
	file.close();
	if (found == false)
		cout << "\n\nKhong tim thay tai khoan";
}

// Tim tai khoan co so tai khoan la account_number
// trong file "account.dat"
// Sau do xoa tai khoan nay trong file "account.dat"
void DeleteAccount(int account_number)
{
	Account account;
	ifstream in_file;
	ofstream out_file;
	in_file.open("account.dat", ios::binary);

	if (!in_file)
	{
		cout << "Khong mo duoc file, hay nhan enter de quay lai menu." << endl;
		return;
	}

	// Luu tat ca cac tai khoan trong file "account.dat", tru tai khoan muon xoa vao file "temp.dat"
	out_file.open("temp.dat", ios::binary);
	in_file.seekg(0, ios::beg);
	while (in_file.read(reinterpret_cast<char *> (&account), sizeof(Account)))
	{
		if (account.GetAccountNumber() != account_number)
		{
			if (out_file.is_open()) {
				out_file.write(reinterpret_cast<char*> (&account), sizeof(Account));
			}
		}
	}

	// Dong cac file da mo, xoa file "account.dat", doi ten file "temp.dat" thanh "account.dat"
	in_file.close();
	out_file.close();
	remove("account.dat");
	rename("temp.dat", "account.dat");

	cout << "\n\n\tTai khoan da xoa thanh cong";
}


