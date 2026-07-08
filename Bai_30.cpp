#include <bits/stdc++.h>

using namespace std;

class Song1
{
protected:
    string maTinHieu;
    double bienDo;
    double tanSo;
    double phaBanDau;

public:
    Song1()
    {
        maTinHieu = "";
        bienDo = 0;
        tanSo = 0;
        phaBanDau = 0;
    }

    void nhap()
    {
        cout << "Nhap ma tin hieu: "; cin >> maTinHieu;
        cout << "Nhap bien do: "; cin >> bienDo;
        cout << "Nhap tan so: "; cin >> tanSo;
        cout << "Nhap pha ban dau: "; cin >> phaBanDau;
    }

    void xuat()
    {
        cout << "ma tin hieu: " << maTinHieu << endl;
        cout << "bien do: " << bienDo << endl;
        cout << "tan so: " << tanSo << endl;
        cout << "pha ban dau: " << phaBanDau << endl;
        cout << "Tan so: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return tanSo;
    }

    double tinhChuKy(){ if(tanSo == 0) return 0; return 1/tanSo; }

};

class Song2 : public Song1
{
public:
    Song2 operator=(Song2 a)
    {
        maTinHieu = a.maTinHieu;
        bienDo = a.bienDo;
        tanSo = a.tanSo;
        phaBanDau = a.phaBanDau;
        return *this;
    }

    bool operator>(Song2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong tin hieu toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Song2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap tin hieu thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vtMax=0, vtMin=0;
    for(int i=1;i<n;i++){ if(ds[i] > ds[vtMax]) vtMax=i; if(ds[vtMin] > ds[i]) vtMin=i; }
    cout << "\ntin hieu lon nhat:" << endl; ds[vtMax].xuat();
    cout << "\ntin hieu nho nhat:" << endl; ds[vtMin].xuat();
    return 0;
}
