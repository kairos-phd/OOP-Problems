#include <bits/stdc++.h>

using namespace std;

class QLLK
{
protected:
    string maLinhKien;
    string tenLinhKien;

public:
    QLLK()
    {
        maLinhKien = "";
        tenLinhKien = "";
    }

    void nhap()
    {
        cout << "Nhap ma linh kien: "; cin >> maLinhKien;
        cout << "Nhap ten linh kien: "; cin >> tenLinhKien;
    }

    void xuat()
    {
        cout << "ma linh kien: " << maLinhKien << endl;
        cout << "ten linh kien: " << tenLinhKien << endl;
    }
};

class SL : public QLLK
{
private:
    int soLuongSanPham;
    double giaThanh;

public:
    SL() : QLLK()
    {
        soLuongSanPham = 0;
        giaThanh = 0;
    }

    void nhap()
    {
        QLLK::nhap();
        cout << "Nhap so luong san pham: "; cin >> soLuongSanPham;
        cout << "Nhap gia thanh: "; cin >> giaThanh;
    }

    void xuat()
    {
        QLLK::xuat();
        cout << "so luong san pham: " << soLuongSanPham << endl;
        cout << "gia thanh: " << giaThanh << endl;
    }

    double tinhGiaTri(){ return soLuongSanPham * giaThanh; }
    bool operator==(SL a){ return tinhGiaTri() == a.tinhGiaTri(); }
    bool operator>(SL a){ return tinhGiaTri() > a.tinhGiaTri(); }

};

int main()
{
    int n;
    cout << "Nhap so luong linh kien: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    SL *ds = new SL[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap linh kien thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vt=0; for(int i=1;i<n;i++) if(ds[i] > ds[vt]) vt=i;
    cout << "\nLinh kien co gia tri cao nhat:" << endl; ds[vt].xuat(); cout << "Gia tri: " << ds[vt].tinhGiaTri() << endl;

    delete[] ds;
    return 0;
}
