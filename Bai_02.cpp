#include <bits/stdc++.h>

using namespace std;

class QLLK
{
	private:
		string ma;
		string ten;
		int soluong;
		double thongsochinh;
		
	public:
		
		QLLK()
		{
			ma = "";
			ten = "";
			soluong = 0;
			thongsochinh = 0;
		}
		
		QLLK(string m, string t, int sl, double ts)
		{
			ma = m ;
			ten = t;
			soluong = sl;
			thongsochinh = ts;
		}
		
		void nhap()
		{
			cout << "Nhap ma linh kien: ";
			cin >> ma;
			
			cout << "Nhap ten linh kien: ";
			cin >> ten;
			
			cout << "Nhap so luong: ";
			cin >> soluong;
			
			cout << "Nhap thong so chinh: ";
			cin >> thongsochinh;
		}
		
		void xuat()
		{
			cout << "Ma linh kien: " << ma << endl;
			cout << "Ten linh kien: " << ten << endl;
			cout << "So luong: " << soluong << endl;
			cout << "Thong so chinh: " << thongsochinh << endl;
		}
		
		bool laDienTro()
		{
			if (ten == "dien_tro" || ten == "Dien_tro" || ten == "dientro")
				return true;
			else 
				return false;
		}
		
		double getthongsochinh()
		{
			return thongsochinh;
		}
};

int main ()
{
	int n;
	
	cout << "Nhap so luong linh kien: ";
	cin >> n;
	
	if (n <= 0)
	{
		cout << "so luong khong hop le" << endl;
		return 0;
	}
	
	QLLK *ds = new QLLK[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap linh kien thu: " << i + 1 << endl;
		ds[i].nhap();
	}
	
	cout << "\nDanh sach linh kien " << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nLinh kien thu" << i + 1 << endl;
		ds[i].xuat();
	}
	
	int viTriMax = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (ds[i].laDienTro())
		{
			if (viTriMax == -1 || ds[i].getthongsochinh() > ds[viTriMax].getthongsochinh())
			{
				viTriMax = i;
			}
		}
	}
	
	cout << "\nKet qua tim kiem " << endl;
	
	if (viTriMax == -1)
	{
		cout << "khong co linh kien dien tro trong danh sach" << endl;	
	}
	else
	{
		cout << "Linh kien dien tro co gia tri cao nhat: " << endl;
		ds[viTriMax].xuat();
	}
	
	delete[] ds;
	return 0;
}
