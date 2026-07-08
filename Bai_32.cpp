#include <bits/stdc++.h>

using namespace std;

class Pin1
{
protected:
    string maPin;
    double dungLuong;
    double dienAp;
    double dongTieuThu;

public:
    Pin1()
    {
        maPin = "";
        dungLuong = 0;
        dienAp = 0;
        dongTieuThu = 0;
    }

    void nhap()
    {
        cout << "Nhap ma pin: "; cin >> maPin;
        cout << "Nhap dung luong: "; cin >> dungLuong;
        cout << "Nhap dien ap: "; cin >> dienAp;
        cout << "Nhap dong tieu thu: "; cin >> dongTieuThu;
    }

    void xuat()
    {
        cout << "ma pin: " << maPin << endl;
        cout << "dung luong: " << dungLuong << endl;
        cout << "dien ap: " << dienAp << endl;
        cout << "dong tieu thu: " << dongTieuThu << endl;
        cout << "Nang luong danh dinh: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return dungLuong * dienAp;
    }

};

class Pin2 : public Pin1
{
public:
    Pin2 operator=(Pin2 a)
    {
        maPin = a.maPin;
        dungLuong = a.dungLuong;
        dienAp = a.dienAp;
        dongTieuThu = a.dongTieuThu;
        return *this;
    }

    bool operator>(Pin2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong pin toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Pin2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap pin thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] > ds[i]){ Pin2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach giam dan" << endl;
    for(int i=0;i<n;i++){ cout << "\npin thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
