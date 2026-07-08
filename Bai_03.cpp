#include <iostream>
#include <string>

using namespace std;

class CamBien
{
	protected:
		string ma;
		string viTri;
		double dienapnuoi;
	public:
		
		CamBien()
		{
			ma = "";
			viTri = "";
			dienapnuoi = 0;
		}
		
		CamBien(string m, string t, double u)
		{
			ma = m;
			viTri = t;
			dienapnuoi = u;
		}
		
		void nhap()
		{
			cout << "Nhap ma cam bien: ";
			cin >> ma;
			
			cout << "Nhap vi tri dat: ";
			cin >> viTri;
			
			cout << "Nhap dien ap nuoi: ";
			cin >> dienapnuoi;
		}
		
		void xuat ()
		{
			cout << "Ma cam bien: " << ma << endl;
			cout << "Vi tri dat: " << viTri << endl;
			cout << "Dien ap nuoi: " << dienapnuoi << endl;
		}
};

class CBKG : public CamBien
{
	private:
		double nongdo;
	public:
		CBKG() : CamBien()
		{
			nongdo = 0;
		}
		
		CBKG(string m, string vt, double u, double nd) : CamBien(m, vt, u)
		{
			nongdo = nd;
		}
		
		void nhap() 
		{
			CamBien::nhap();
			
			cout << "Nhap nong do phat hien toi thieu ppm: ";
			cin >> nongdo;
		}
		
		void xuat()
		{
			CamBien::xuat();
			
			cout  << "Nong do phat hien toi thieu: " << nongdo << "ppm" << endl;
		}
		
		double getnongdo()
		{
			return nongdo;
		}
};

int main()
{
	int n;
	
	cout << "Nhap so luong cam bien khi gas: ";
	cin >> n;
	
	if (n <= 0)
	{
		cout << "So luong khong hop le" << endl;
		return 0;
	}
	
	CBKG *ds = new CBKG[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap cam bien khi gas thu " << i + 1 << endl;
		ds[i].nhap();
	}
	
	int viTriMin = 0;
	
	for (int i = 1; i < n; i++)
	{
		if (ds[i].getnongdo() < ds[viTriMin].getnongdo())
		{
			viTriMin = i;
		}
	}
	
	cout << "\nCam bien khi gas nhay nhat la: " << endl;
	ds[viTriMin].xuat();
	
	delete[] ds;
	
	return 0;
}
