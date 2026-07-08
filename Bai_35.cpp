#include <bits/stdc++.h>

using namespace std;

class BaoDuong1
{
protected:
    string maThietBi;
    string tenThietBi;
    double soGioHoatDong;
    double chuKyBaoDuong;

public:
    BaoDuong1()
    {
        maThietBi = "";
        tenThietBi = "";
        soGioHoatDong = 0;
        chuKyBaoDuong = 0;
    }

    void nhap()
    {
        cout << "Nhap ma thiet bi: "; cin >> maThietBi;
        cout << "Nhap ten thiet bi: "; cin >> tenThietBi;
        cout << "Nhap so gio hoat dong: "; cin >> soGioHoatDong;
        cout << "Nhap chu ky bao duong: "; cin >> chuKyBaoDuong;
    }

    void xuat()
    {
        cout << "ma thiet bi: " << maThietBi << endl;
        cout << "ten thiet bi: " << tenThietBi << endl;
        cout << "so gio hoat dong: " << soGioHoatDong << endl;
        cout << "chu ky bao duong: " << chuKyBaoDuong << endl;
        cout << "So gio hoat dong: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return soGioHoatDong;
    }

    bool kiemTra(){ return soGioHoatDong >= chuKyBaoDuong; }

};

class BaoDuong2 : public BaoDuong1
{
public:
    BaoDuong2 operator=(BaoDuong2 a)
    {
        maThietBi = a.maThietBi;
        tenThietBi = a.tenThietBi;
        soGioHoatDong = a.soGioHoatDong;
        chuKyBaoDuong = a.chuKyBaoDuong;
        return *this;
    }

    bool operator>(BaoDuong2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong thiet bi toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    BaoDuong2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap thiet bi thu " << i+1 << endl;
        ds[i].nhap();
    }
    bool co=false;
    cout << "\nDanh sach canh bao:" << endl;
    for(int i=0;i<n;i++) if(ds[i].kiemTra()) { co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co doi tuong nao" << endl;
    return 0;
}
