#include <bits/stdc++.h>

using namespace std;

class LedMaTran
{
private:
    string maLinhKien;
    int soHang;
    int soCot;
    string mauSac;

public:
    LedMaTran()
    {
        maLinhKien = "";
        soHang = 0;
        soCot = 0;
        mauSac = "";
    }

    void nhap()
    {
        cout << "Nhap ma linh kien: "; cin >> maLinhKien;
        cout << "Nhap so hang: "; cin >> soHang;
        cout << "Nhap so cot: "; cin >> soCot;
        cout << "Nhap mau sac: "; cin >> mauSac;
    }

    void xuat()
    {
        cout << "ma linh kien: " << maLinhKien << endl;
        cout << "so hang: " << soHang << endl;
        cout << "so cot: " << soCot << endl;
        cout << "mau sac: " << mauSac << endl;
    }

    int tinhSoBong(){ return soHang * soCot; }

};

int main()
{
    int n;
    cout << "Nhap so luong LED ma tran: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    LedMaTran *ds = new LedMaTran[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap LED ma tran thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++) if (ds[i].tinhSoBong() > ds[viTriMax].tinhSoBong()) viTriMax = i;
    cout << "\nLED ma tran co so bong LED don nhieu nhat:" << endl;
    ds[viTriMax].xuat();
    cout << "Tong so bong LED don: " << ds[viTriMax].tinhSoBong() << endl;

    delete[] ds;
    return 0;
}
