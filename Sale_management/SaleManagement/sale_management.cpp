#include "order.h"

using namespace std;

int main()
{
	Order orders[11];	
	int n{};
	do
	{
		cout << "So hoa don: ";
		cin >> n;
	} while (n < 1 || n > 10);

	cout << "\nNhap thong tin cac hoa don:" << endl;
	orders->GenerateOrders(orders, n);	

	cout << "\nDanh sach hoa don sau khi sap xep tien lai giam dan:" << endl;
	orders->PrintOrders(orders, n);
	cout << endl;

	cout << "\nTong tien cac hoa don: " << setw(47) << "" << setw(20) << GetSumSubTotal(orders, n) << endl;
	
	cout << "\nCac hoa don co tien thue cao nhat " << endl;
	PrintOrdersWithMaxTAX(orders,n);

	system("pause");
	return 0;
}

