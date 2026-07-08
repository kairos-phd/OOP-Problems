#include <bits/stdc++.h>

using namespace std;

class Anten1
{
protected:
    string maAnten;
    double tanSoTrungTam;
    double doLoi;
    double suyHaoCap;

public:
    Anten1()
    {
        maAnten = "";
        tanSoTrungTam = 0;
        doLoi = 0;
        suyHaoCap = 0;
    }

    void nhap()
    {
        cout << "Nhap ma anten: "; cin >> maAnten;
        cout << "Nhap tan so trung tam: "; cin >> tanSoTrungTam;
        cout << "Nhap do loi: "; cin >> doLoi;
        cout << "Nhap suy hao cap: "; cin >> suyHaoCap;
    }

    void xuat()
    {
        cout << "ma anten: " << maAnten << endl;
        cout << "tan so trung tam: " << tanSoTrungTam << endl;
        cout << "do loi: " << doLoi << endl;
        cout << "suy hao cap: " << suyHaoCap << endl;
        cout << "Do loi hieu dung: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return doLoi - suyHaoCap;
    }

};

class Anten2 : public Anten1
{
public:
    Anten2 operator=(Anten2 a)
    {
        maAnten = a.maAnten;
        tanSoTrungTam = a.tanSoTrungTam;
        doLoi = a.doLoi;
        suyHaoCap = a.suyHaoCap;
        return *this;
    }

    bool operator<(Anten2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong anten toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Anten2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap anten thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vt=0;
    for(int i=1;i<n;i++) if(ds[vt] < ds[i]) vt=i;
    cout << "\nanten co gia tri lon nhat:" << endl;
    ds[vt].xuat();
    return 0;
}
