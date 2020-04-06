#include <iostream>
#include <string>
using namespace std;

bool login(string &enterID);
void menu();
void stop(int temp);
void run(int &speed, int temp, int *arr_speed);

bool checkDigit(string number);

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

void enterArrayID(int *arr, int n);
void printArrayID(int *arr, int n);
bool checkArrayID(int arr[], int new_array[], int n);

void warningOverSpeed(int speed, int temp);
void enterArraySpeed(int *arr, int n);
void setSafeDistance(int *arr_speed);
void safeStoppingDistance(int speed, int temp, int *arr);

int main()
{
	string enterID;
	string option_s;

	int option = 0;
	//bien temp de luu gia tri cu cua option
	int temp = 0;
	int speed = 0;

	//mang 3 cap toc do
	int arr_speed[3];

	cout << "Ma so ca nhan: ";
	cin >> enterID;
	//Neu mang nhap vao khong trung voi ma so cai san thi dung chuong trinh
	if (login(enterID) == false)
	{
		std::cout << "\nBan nhap sai ma so ca nhan." << std::endl;
		std::cout << "\nChao tam biet." << std::endl;
		system("pause");
		return 0;
	}

	system("pause");
	system("cls");
	//cai dat 3 cap toc do
	setSafeDistance(arr_speed);
	system("pause");
	system("cls");
	std::cout << "Xin chao: " << enterID << std::endl;

	do
	{
		//Nhap chuoi option_s sau do kiem tra co phai kieu so,
		//Neu dung kieu so thi kiem tra range 1-5
		do
		{
			safeStoppingDistance(speed, temp, arr_speed);
			warningOverSpeed(speed, temp);
			menu();
			cout << "\n\nXin moi nhap tu 1-5" << endl;
			cin >> option_s;
			if (checkDigit(option_s) == true)
			{
				option = stoi(option_s);
			}
			else
			{
				option = 0;
			}
			system("cls");
		} while (option < 1 || option > 5);

		//Chon cac che do dieu khien
		//TH 1-3 la che do dung P/N
		//TH 2-4 la che do chay lui tien R/D
		switch (option)
		{
		case 1:
			if (speed == 0)
			{
				temp = option;
				stop(temp);
			}
			else
			{
				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
			}
			break;
		case 2:
			if (speed == 0 || temp == 2)
			{
				//Toc do mac dinh ban dau la 7km/h
				speed = 7;
				temp = option;
				run(speed, option, arr_speed);
			}
			else
			{
				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
			}
			break;
		case 3:
			if (speed == 0)
			{
				temp = option;
				stop(temp);
			}
			else
			{
				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
			}
			break;
		case 4:
			if (speed == 0 || temp == 4)
			{
				speed = 7;
				temp = option;
				run(speed, option, arr_speed);
			}
			else
			{
				std::cout << "Hay chac chan xe da dung va van toc bang 0 km/h" << std::endl;
			}
			break;
		case 5:
			std::cout << "\n\nCam on ban da su dung ung dung." << std::endl;
			break;
		default:
			break;
		}
	} while (option != 5);
	return 0;
}

//Dang nhap tai khoan
bool login(string &enterID)
{
	//Chuoi ma so ca nhan duoc cai dat san
	string ID = "12348765";
	//mang ma so ca nhan de so sanh voi mang nhap vao
	int arr_ID[8];
	int enter_arr[8];

	//nhap chuoi ID
	while (enterID != "12345678")
	{
		system("cls");
		cout << "Xin moi nhap lai ma so ca nhan: ";
		cin >> enterID;
	}

	//chuyen chuoi ID cai san thanh mang kieu int
	for (int i = 0; i < 8; ++i)
	{
		arr_ID[i] = ID[i] - '0';
	}

	cout << "Nhap ma so ca nhan, mang " << 8 << " so" << endl;
	enterArrayID(enter_arr, 8);
	std::cout << "\nMang ma so ca nhan truoc khi sap xep:" << std::endl;
	printArrayID(arr_ID, 8);
	std::cout << "\nMang nhap vao truoc khi sap xep:" << std::endl;
	printArrayID(enter_arr, 8);

	bubbleSort(arr_ID, 8);
	selectionSort(enter_arr, 8);

	std::cout << "\n--->Mang ma so ca nhan sau khi sap xep:" << std::endl;
	printArrayID(arr_ID, 8);
	std::cout << "\n--->Mang nhap vao sau khi sap xep:" << std::endl;
	printArrayID(enter_arr, 8);

	//Kiem tra 2 mang sau khi sap xep co bang nhau khong
	return checkArrayID(arr_ID, enter_arr, 8);
}

//Hien thi man hinh chinh
void menu()
{
	std::cout << "\nXin moi lua chon:" << std::endl;
	std::cout << "1. P" << std::endl;
	std::cout << "2. R" << std::endl;
	std::cout << "3. N" << std::endl;
	std::cout << "4. D" << std::endl;
	std::cout << "5. Power off" << std::endl;
}

//Chon che do dung P/N
//Dua ra canh bao su dung phanh tay, dua van toc = 0km/h
void stop(int temp)
{
	if (temp == 1)
	{
		std::cout << "Da ve so P" << std::endl;
		std::cout << "\nChu y su dung phanh tay de dam bao an toan" << std::endl;
	}
	else if (temp == 3)
	{
		std::cout << "Da ve so N" << std::endl;
		std::cout << "\nChu y su dung phanh tay de dam bao an toan" << std::endl;
	}
}

//Chon che do chay D/R
//Kiem tra khoang cach an toan va canh bao toc do
//Tang giam toc do moi lan +-5
void run(int &speed, int temp, int *arr_speed)
{
	string option_run_s;
	int option_run;
	do
	{
		do
		{
			safeStoppingDistance(speed, temp, arr_speed);
			warningOverSpeed(speed, temp);
			std::cout << "\n\nMoi lua chon:" << std::endl;
			std::cout << "1. Tang toc" << std::endl;
			std::cout << "2. Giam toc" << std::endl;
			std::cout << "3. Phanh" << std::endl;
			std::cout << "4. Tro ve menu" << std::endl;
			cout << "\n\nXin moi nhap tu 1-4" << endl;

			cin >> option_run_s;
			if (checkDigit(option_run_s) == true)
			{
				option_run = stoi(option_run_s);
			}
			else
			{
				option_run = 0;
			}
			system("cls");
		} while (option_run < 1 || option_run > 4);

		switch (option_run)
		{
		case 1:
			speed = speed + 5;
			//Toc do tang toc ban dau mac dinh la 7km/h
			if (speed == 5)
				speed = 7;
			break;
		case 2:
			speed = speed - 5;
			if (speed == 2 || speed <= 0)
				speed = 0;
			break;
		case 3:
			speed = 0;
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (option_run != 4);
}

//Kiem tra chuoi nhap vao la dang so
bool checkDigit(string number)
{
	for (int i = 0; i < number.length(); ++i)
	{
		if (isdigit(number[i]) == false)
		{
			return false;
		}
	}
	return true;
}

//Ham doi cho
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Sap xep mang theo thuat toan noi bot
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

//Sap xep mang theo thuat toan lua chon
void selectionSort(int arr[], int n)
{
	int *i, *j, *min_idx;
	//Duyet mang theo pointer
	for (i = arr; i < arr + n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < arr + n; j++)
		{
			if (*j < *min_idx)
				min_idx = j;
		}
		swap(min_idx, i);
	}
}

//Ham nhap mang ID
void enterArrayID(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array ID[" << i << "] = ";
		cin >> arr[i];
	}
}

//Ham in mang ID
void printArrayID(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Ham nhap mang 3 cap toc do
void enterArraySpeed(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array Speed[" << i << "] = ";
		cin >> arr[i];
	}
}

//Ham so sanh 2 mang ID bang nhau
bool checkArrayID(int arr_ID[], int new_array[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr_ID[i] != new_array[i])
			return false;
	}
	return true;
}

//Nhap mang 3 cap toc do sau do sap xep tang dan
void setSafeDistance(int *arr_speed)
{
	std::cout << "Nhap 3 muc van toc cai dat: " << std::endl;
	enterArraySpeed(arr_speed, 3);
	bubbleSort(arr_speed, 3);
	std::cout << "Cai dat van toc canh bao khoang cach an toan voi 3 muc van toc:" << std::endl;
	std::cout << "Van toc muc 1: " << arr_speed[0] << " km/h" << std::endl;
	std::cout << "Van toc muc 2: " << arr_speed[1] << " km/h" << std::endl;
	std::cout << "Van toc muc 3: " << arr_speed[2] << " km/h" << std::endl;
}

//Thiet lap khoang cach an toan theo 3 cap toc do
void safeStoppingDistance(int speed, int temp, int *arr_speed)
{
	if (temp == 2 || temp == 4)
	{
		if (speed < arr_speed[0])
		{
			std::cout << "\nBan chu y giu khoang cach toi thieu la 20m" << std::endl;
		}
		if (speed >= arr_speed[0] && speed <= arr_speed[1])
		{
			std::cout << "\nBan chu y giu khoang cach toi thieu la 55m" << std::endl;
		}
		if (speed > arr_speed[1] && speed <= arr_speed[2])
		{
			std::cout << "\nBan chu y giu khoang cach toi thieu la 70m" << std::endl;
		}
		if (speed > arr_speed[2])
		{
			std::cout << "\nBan chu y giu khoang cach toi thieu la 100m" << std::endl;
		}
	}
}

//Thiet lap toc do an toan cho che do D/R
void warningOverSpeed(int speed, int temp)
{
	if (temp == 4)
	{
		std::cout << "\n----Che do D, toc do hien tai: " << speed << " km/h" << std::endl;
		if (speed > 60)
		{
			std::cout << "\nToc do nguy hiem, ban nen giam toc do" << std::endl;
		}
	}
	else if (temp == 2)
	{
		std::cout << "\n----Che do R, toc do hien tai: " << speed << " km/h" << std::endl;
		if (speed > 20)
		{
			std::cout << "\nToc do nguy hiem, ban nen giam toc do" << std::endl;
		}
	}
	else if (temp == 1 || temp == 3)
	{
		std::cout << "\n----Toc do hien tai: " << speed << " km/h" << std::endl;
	}
}