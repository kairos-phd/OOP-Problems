#include <bits/stdc++.h>

using namespace std;

class VMTH 
{
	public:
		virtual void input()
		{
		}
		
		virtual void output()
		{
		}
		
		virtual void hienthiChucNang()
		{
			cout << "Day la vi mach tich hop" << endl;
		}
		
		virtual ~VMTH()
		{
		}
};

class IC_So : public VMTH
{
	private:
		int LogicGate;
		string hoIC;
	public:
		IC_So()
		{
			LogicGate = 0;
			hoIC = "";
		}
		
		void input()
		{
			cout << "Nhap so cong Logic: " << endl;
			cin >> LogicGate;
			
			cout << "Nhap ho IC: " << endl;
			cin >> hoIC;
		}
		
		void output()
		{
			cout << "So cong Logic: " << LogicGate << endl;
			cout << "Ho IC: " << hoIC << endl;
			cout << "Loai IC: IC so" << endl;
		}
		
		void hienthiChucNang()
		{
			cout << "Chuc nang: Xu ly tin hieu so, thuc hien cac phep logic" << endl;
		}
};

class IC_TuongTu : public VMTH
{
	private:
		double CMRR;
		int TangKhuechDai;
	public:
		IC_TuongTu()
		{
			CMRR = 0;
			TangKhuechDai = 0;
		}
		
	void input()
	{
		cout << "Nhap so CMRR: " << endl;
		cin >> CMRR;
		
		cout << "Nhap so tang khuech dai " << endl;
		cin >> TangKhuechDai;
	}
		
	void output()
	{
		cout << "He so CMRR: " << CMRR << endl;
		cout << "So tang khuech dai: " << TangKhuechDai << endl;
		cout << "Loai IC: IC_TuongTu " << endl;
	}
	
	void hienthiChucNang()
	{
		cout << "Chuc nang: Xu ly tin hieu tuong tu, khuech dai va loc tin hieu " << endl;	
	}	
};

int main()
{
	int n;
	
	cout << "Nhap so luong IC can quan ly: " << endl;
	cin >> n;
	
	if(n <= 0)
	{
		cout << "So luong IC khong hop le " << endl;
		return 0;
	}
	
	VMTH **ds = new VMTH*[n];
	
	for(int i = 0; i < n; i++)
	{
		int loai;
		
		cout << "\nNhap loai IC thu " << i + 1 << endl;
		cout << "1. IC So " << endl;
		cout << "2. IC TuongTu " << endl;
		cout << "Chon loai " << endl;
		cin >> loai;
		
		if(loai == 1)
		{
			ds[i] = new IC_So;
		}
		else
		{
			ds[i] = new IC_TuongTu;
		}
		
		ds[i]->input();
	} 
	
	cout << "\nDanh sach IC " << endl;
	
	for(int i = 0; i < n; i++)
	{
		cout << "\nIC thu: " << i + 1 << endl;
		ds[i]->output();
		ds[i]->hienthiChucNang();
	}
	
	for (int i = 0; i < n; i++)
	{
		delete ds[i];
	}
	
	delete[] ds;
	
	return 0;
}

