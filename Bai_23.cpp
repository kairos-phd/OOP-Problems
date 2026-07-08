#include <bits/stdc++.h>

using namespace std;

class TB1
{
protected:
    string maThietBi;
    string tenThietBi;
    double dungLuongPin;
    double dongTieuThu;

public:
    TB1()
    {
        maThietBi = "";
        tenThietBi = "";
        dungLuongPin = 0;
        dongTieuThu = 0;
    }

    void nhap()
    {
        cout << "Nhap ma thiet bi: "; cin >> maThietBi;
        cout << "Nhap ten thiet bi: "; cin >> tenThietBi;
        cout << "Nhap dung luong pin: "; cin >> dungLuongPin;
        cout << "Nhap dong tieu thu: "; cin >> dongTieuThu;
    }

    void xuat()
    {
        cout << "ma thiet bi: " << maThietBi << endl;
        cout << "ten thiet bi: " << tenThietBi << endl;
        cout << "dung luong pin: " << dungLuongPin << endl;
        cout << "dong tieu thu: " << dongTieuThu << endl;
        cout << "Thoi gian hoat dong uoc luong: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        if(dongTieuThu == 0) return 0; return dungLuongPin / dongTieuThu;
    }

};

class TB2 : public TB1
{
public:
    TB2 operator=(TB2 a)
    {
        maThietBi = a.maThietBi;
        tenThietBi = a.tenThietBi;
        dungLuongPin = a.dungLuongPin;
        dongTieuThu = a.dongTieuThu;
        return *this;
    }

    bool operator>(TB2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong thiet bi IoT toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    TB2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap thiet bi IoT thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] > ds[i]){ TB2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach giam dan" << endl;
    for(int i=0;i<n;i++){ cout << "\nthiet bi IoT thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
