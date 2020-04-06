#include "order.h"
#include "product.h"

void Order::Input() {
	Product::Input();
	//your code here
	cout << "So luong:";
	cin >> quantity_;
	cout << "Gia ban:";
	cin >> sell_price_;
}

void Order::Output() 
{
	Product::Output();
	cout  << setw(15) << quantity_ << setw(15) << sell_price_ << setw(15) << GetSubTotal() << setw(10) << GetVAT() << setw(15) << GetProfit() << endl;
}

// Tra ve tong tien trong hoa don hien tai
// Tong tien = so luong san pham * gia ban 1 san pham
long Order::GetSubTotal() 
{
	return (quantity_ * sell_price_);
}

// Tra ve thue VAT cho hoa don hien tai
// Thue VAT = (tong tien trong hoa don hien tai)/10, lam tron ve so nguyen
long Order::GetVAT() 
{
	return (GetSubTotal() / 10);
}

// Tra ve loi nhuan (tien lai) tu hoa don hien tai
// Loi nhuan cho 1 san pham la hieu cua gia ban va gia nhap
long Order::GetProfit() 
{
	return (sell_price_ - GetOriginalPrice())*quantity_;
}

// Nhap vao n hoa don, luu trong mang orders
void Order::GenerateOrders(Order orders[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin hoa don: " << i + 1 << endl;
		//your code here
		orders[i].Input();
	}
}

// In ra thong tin tat ca cac hoa don trong mang dau vao - orders
void Order::PrintOrders(Order orders[], int n) {
	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham"<< setw(15) << "Gia nhap";
	cout << setw(15) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "VAT" << setw(15) << "Tien Lai" << endl;
	SortOrderByProfit(orders, n);
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << i + 1;
		orders[i].Output();
	}
}

// Tra ve gia tri VAT lon nhat cua hoa don trong mang orders cac hoa don dau vao
long GetMaxVAT(Order orders[], int n)
{
	long max = orders[0].GetVAT();
	for (int i = 1; i < n; i++)
	{
		if (max < orders[i].GetVAT())
		{
			max = orders[i].GetVAT();
		}
	}
	return max;
}


// Sap xep mang hoa don orders theo loi nhuan (tien lai) giam dan
void SortOrderByProfit(Order orders[], int n)
{
	bool haveSwap = false;
	for (int i = 0; i < n-1 ; i++)			
	{
		haveSwap = false;
		for (int j = n - 1; j > i; j--)
		{			
			if (orders[j].GetProfit() > orders[j - 1].GetProfit())
			{
				int temp{n};					
				orders[temp] =orders[j];		
				orders[j] = orders[j - 1];		
				orders[j - 1] = orders[temp];
				haveSwap = true;
			}
		}
		if (haveSwap == false)
			break;
	}
}

// In ra cac hoa don co thue VAT lon nhat trong mang orders cac hoa don dau vao
void PrintOrdersWithMaxTAX(Order orders[], int n)
{
	cout << endl;
	cout << setw(5) << "STT" << setw(25) << "Ten San Pham" << setw(15) << "Gia nhap";
	cout << setw(15) << "So Luong" << setw(15) << "Gia Ban" << setw(15) << "Thanh Tien";
	cout << setw(10) << "Thue" << setw(15) << "Tien Lai" << endl;
	for (int i = 0; i < n; i++)
	{
		if (orders[i].GetVAT() == GetMaxVAT(orders, n))	
		{
			cout << setw(5) << i + 1;	
			orders[i].Output();
		}
	}
}

// Tra ve tong tien tat ca cac hoa don trong mang orders
long GetSumSubTotal(Order orders[], int n)
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += orders[i].GetSubTotal();	
	}
	return sum;
}
