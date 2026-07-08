#include <iostream>
#include <string>

using namespace std;

class ThietBiDinhTuyen
{
	private:
		string mathietbi;
		string hangsanxuat;
		double tocdowan;
		int soconglan;
	public:
		
		ThietBiDinhTuyen()
		{
			mathietbi = "";
			hangsanxuat = "";
			tocdowan = 0;
			soconglan = 0;
		}
		
		ThietBiDinhTuyen(string ma, string hang, double wan, int lan)
		{
			mathietbi = ma;
			hangsanxuat = hang;
			tocdowan = wan;
			soconglan = lan;
		}
		
		void nhap()
		{
			cout << "Nhap ma thiet bi: ";
			cin >> mathietbi;
			
			cout << "Nhap hang san xuat: ";
			cin >> hangsanxuat;
			
			cout << "Nhap toc do cong WAN: ";
			cin >> tocdowan;
			
			cout<< "Nhap so cong lan: ";
			cin >> soconglan;
		}
		
		void xuat()
		{
			cout << "Ma thiet bi: " << mathietbi << endl;
			cout << "Hang san xuat: " << hangsanxuat << endl;
			cout << "Toc do cong WAN: " << tocdowan << "Gbps" << endl;
			cout << "So cong LAN: " << soconglan << endl;
		}
		
		double gettocdowan()
		{
			return tocdowan;
		}
};

int main()
{
	int n;
	
	cout << "Nhap so luong router: ";
	cin >> n;
	
	if (n <= 0)
	{
		cout << "So luong khong hop le" << endl;
		return 0;
	}
	
	ThietBiDinhTuyen *ds = new ThietBiDinhTuyen[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap router thu " << i + 1 << endl;
		ds[i].nhap();
	}
	
	cout << "\nDanh sach router co toc do WAN tu 10Gbps tro len" << endl;
	
	bool coRouter = false;
	
	for (int i = 0; i < n; i++)
	{
		if (ds[i].gettocdowan() >= 10)
		{
			coRouter = true;
			cout << "\nRouter thu " << i + 1 << endl;
			ds[i].xuat();
		}
	}
	
	if (coRouter == false)
	{
		cout << "Khong co router nao co toc do WAN tu 10Gbps tro len " << endl;
	}
	
	delete[] ds;
	return 0;
}
