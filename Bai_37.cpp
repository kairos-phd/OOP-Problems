#include <bits/stdc++.h>

using namespace std;

class NhietDo1
{
protected:
    string maCamBien;
    double nhietDoHienTai;
    double nhietDoNhoNhat;
    double nhietDoLonNhat;

public:
    NhietDo1()
    {
        maCamBien = "";
        nhietDoHienTai = 0;
        nhietDoNhoNhat = 0;
        nhietDoLonNhat = 0;
    }

    void nhap()
    {
        cout << "Nhap ma cam bien: "; cin >> maCamBien;
        cout << "Nhap nhiet do hien tai: "; cin >> nhietDoHienTai;
        cout << "Nhap nhiet do nho nhat: "; cin >> nhietDoNhoNhat;
        cout << "Nhap nhiet do lon nhat: "; cin >> nhietDoLonNhat;
    }

    void xuat()
    {
        cout << "ma cam bien: " << maCamBien << endl;
        cout << "nhiet do hien tai: " << nhietDoHienTai << endl;
        cout << "nhiet do nho nhat: " << nhietDoNhoNhat << endl;
        cout << "nhiet do lon nhat: " << nhietDoLonNhat << endl;
        cout << "Do lech tuyet doi: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        double tb=(nhietDoNhoNhat+nhietDoLonNhat)/2; return fabs(nhietDoHienTai-tb);
    }

};

class NhietDo2 : public NhietDo1
{
public:
    NhietDo2 operator=(NhietDo2 a)
    {
        maCamBien = a.maCamBien;
        nhietDoHienTai = a.nhietDoHienTai;
        nhietDoNhoNhat = a.nhietDoNhoNhat;
        nhietDoLonNhat = a.nhietDoLonNhat;
        return *this;
    }

    bool operator<(NhietDo2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong cam bien nhiet do toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    NhietDo2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap cam bien nhiet do thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] < ds[i]){ NhietDo2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach tang dan" << endl;
    for(int i=0;i<n;i++){ cout << "\ncam bien nhiet do thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
