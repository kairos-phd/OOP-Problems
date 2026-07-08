#include <bits/stdc++.h>

using namespace std;

class DienTro
{
private:
    string ma;
    double R;
    double saiSo;

public:
    DienTro()
    {
        ma = "";
        R = 0;
        saiSo = 0;
    }

    void nhap()
    {
        cout << "Nhap ma linh kien: "; cin >> ma;
        cout << "Nhap gia tri dien tro R: "; cin >> R;
        cout << "Nhap sai so (%): "; cin >> saiSo;
    }

    void xuat()
    {
        cout << "ma linh kien: " << ma << endl;
        cout << "gia tri dien tro R: " << R << endl;
        cout << "sai so (%): " << saiSo << endl;
    }

    double tinhRmax(){ return R * (1 + saiSo / 100); }
    double getR(){ return R; }

};

int main()
{
    int n;
    cout << "Nhap so luong dien tro: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    DienTro *ds = new DienTro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap dien tro thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++) if (ds[i].getR() > ds[viTriMax].getR()) viTriMax = i;
    cout << "\nDien tro co gia tri R lon nhat:" << endl;
    ds[viTriMax].xuat();
    cout << "Rmax: " << ds[viTriMax].tinhRmax() << endl;

    delete[] ds;
    return 0;
}
