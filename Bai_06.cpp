#include <bits/stdc++.h>

using namespace std;

class ThietBiDo
{
	private:
		string ma;
		string ten;
		double daidomax;
		double accuracy;
	public:
		ThietBiDo()
		{
			ma = "";
			ten = "";
			daidomax = 0;
			accuracy = 0;
		}
		
	void input()
	{
		cout << "Nhap ma thiet bi: " << endl;
		cin >> ma;
		
		cout << "Nhap ten thiet bi: " << endl;
		cin >> ten;
		
		cout << "Nhap do dai toi da: " << endl;
		cin >> daidomax;
		
		cout << "Nhap do chinh xac: " << endl;
		cin >> accuracy;
	}
	
	void output()
	{
		cout << "Ma thiet bi la: " << ma <<  endl;
		cout << "Ten thiet bi la: " << ten <<  endl;
		cout << "Do dai toi da la: " << daidomax << endl;
		cout << "Do chinh xac la: " << accuracy << endl;
	}
	
	double getaccuracy()
	{
		return accuracy;
	}
};

int main ()
{
	int n;
	
	cout << "Nhap so luong thiet bi: " << endl;
	cin >> n;
	
	if (n <= 0) 
	{
		cout << "So luong thiet bi khong hop le " << endl;
		return 0;
	}
	
	ThietBiDo *ds = new ThietBiDo[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thiet bi do thu " << i + 1 << endl;
		ds[i].input();
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].getaccuracy() < ds[j].getaccuracy())
			{
				ThietBiDo tam = ds[i];
				ds[i] = ds[j];
				ds[j] = tam;
			}
		}
	}
	
	cout << "\nDanh sach thiet bi do sau khi sap xep giam dan theo do chinh xac " << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nThiet bi do thu " << i + 1 << endl;
		ds[i].output();	
	}
	
	delete[] ds;
	
	return 0;
}
