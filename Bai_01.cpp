#include <bits/stdc++.h>

using namespace std;

class LinhKien
{
	protected: 
		string ma;
		string ten;
		double gia;
		
	public:
		LinhKien()
		{
			ma = "";
			ten = "";
			gia = 0;
		}
		
		LinhKien(string m, string t, double g)
		{
			ma = m;
			ten = t;
			gia = g;
		}
		
		void nhap()
		{
			cout << "Nhap ma linh kien: ";
			getline(cin, ma);
			
			cout << "Nhap ten linh kien: ";
			getline(cin, ten);
			
			cout << "Nhap gia thanh: ";
			cin >> gia;
		}
		
		void xuat()
		{
			cout << "Ma linh kien: " << ma << endl;
			cout << "Ten linh kien: " << ten << endl;
			cout << "Gia thanh: " << gia << endl;
		}
		
		double getGia()
		{
			return gia;
		}
};

class Diod : public LinhKien
{
	private:
		double VD;
		double Imax;
	public:
	
	Diod() : LinhKien()
	{
		VD = 0;
		Imax = 0;
	}
	
	Diod(string m, string t, double g, double vd, double imax) : LinhKien(m, t, g)
	{
		VD = vd;
		Imax = imax;
	}
	
	void nhap()
	{
		LinhKien::nhap();
		
		cout << "Nhap dien ap ghim VD: ";
		cin >> VD;
		
		cout << "Nhap dong cuc dai Imax: ";
		cin >> Imax; 
		
		cin.ignore();
	}
	
	void xuat()
	{
		LinhKien::xuat();
		
		cout << "Dien ap ghim VD: " << VD << "V" << endl;
		cout << "Dong cuc dai Imax: " << Imax << "A" << endl;
	}
	
	double getVD()
	{
		return VD;
	}
};

int main()
{
	int n;
	
	cout << "Nhap so luong diode: ";
	cin >> n;
	cin.ignore();
	
	if(n <= 0)
	{
		cout << "So luong diode khong hop le!" << endl;
		return 0;
	}
	
	Diod *ds = new Diod[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin diode thu " << i + 1 << endl;
		ds[i].nhap();
	}
	
	int viTriMin = -1;
	
	for (int i = 0; i < n; i++)
	{
		if (ds[i].getVD() == 0.7)
		{
			if (viTriMin == -1 || ds[i].getGia() < ds[viTriMin].getGia())
			{
				viTriMin = i;
			}
		}
	}
	
	cout << "Diod co VD = 0.7v va gia re nhat" << endl;
	
	if (viTriMin == -1)
	{
		cout << "Khong co diod nao co VD = 0.7" << endl;
	}
	else 
	{
		ds[viTriMin].xuat();
	}
	
	delete[] ds;
	
	return 0;
}


