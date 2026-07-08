#include <bits/stdc++.h>

using namespace std;

class DoiTuongDo1
{
protected:
    string maDiemDo;
    double dienAp;
    double dongDien;
    double nhietDo;

public:
    DoiTuongDo1()
    {
        maDiemDo = "";
        dienAp = 0;
        dongDien = 0;
        nhietDo = 0;
    }

    void nhap()
    {
        cout << "Nhap ma diem do: "; cin >> maDiemDo;
        cout << "Nhap dien ap: "; cin >> dienAp;
        cout << "Nhap dong dien: "; cin >> dongDien;
        cout << "Nhap nhiet do: "; cin >> nhietDo;
    }

    void xuat()
    {
        cout << "ma diem do: " << maDiemDo << endl;
        cout << "dien ap: " << dienAp << endl;
        cout << "dong dien: " << dongDien << endl;
        cout << "nhiet do: " << nhietDo << endl;
        cout << "Cong suat tuc thoi: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return dienAp * dongDien;
    }

};

class DoiTuongDo2 : public DoiTuongDo1
{
public:
    DoiTuongDo2 operator=(DoiTuongDo2 a)
    {
        maDiemDo = a.maDiemDo;
        dienAp = a.dienAp;
        dongDien = a.dongDien;
        nhietDo = a.nhietDo;
        return *this;
    }

    bool operator>(DoiTuongDo2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong diem do toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    DoiTuongDo2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap diem do thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vt=0;
    for(int i=1;i<n;i++) if(ds[i] > ds[vt]) vt=i;
    cout << "\ndiem do co gia tri lon nhat:" << endl;
    ds[vt].xuat();
    return 0;
}
