#include <bits/stdc++.h>

using namespace std;

class NguonDC
{
private:
    string hangSanXuat;
    double Vmax;
    double Imax;

public:
    NguonDC()
    {
        hangSanXuat = "";
        Vmax = 0;
        Imax = 0;
    }

    void nhap()
    {
        cout << "Nhap hang san xuat: "; cin >> hangSanXuat;
        cout << "Nhap dien ap dau ra toi da: "; cin >> Vmax;
        cout << "Nhap dong dien dau ra toi da: "; cin >> Imax;
    }

    void xuat()
    {
        cout << "hang san xuat: " << hangSanXuat << endl;
        cout << "dien ap dau ra toi da: " << Vmax << endl;
        cout << "dong dien dau ra toi da: " << Imax << endl;
    }

    double tinhPmax(){ return Vmax * Imax; }

};

int main()
{
    int n;
    cout << "Nhap so luong bo nguon DC: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    NguonDC *ds = new NguonDC[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap bo nguon DC thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++) if (ds[i].tinhPmax() > ds[viTriMax].tinhPmax()) viTriMax = i;
    cout << "\nBo nguon co cong suat lon nhat:" << endl;
    ds[viTriMax].xuat();
    cout << "Pmax: " << ds[viTriMax].tinhPmax() << endl;

    delete[] ds;
    return 0;
}
