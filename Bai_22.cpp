#include <bits/stdc++.h>

using namespace std;

class RF1
{
protected:
    string maModule;
    double tanSo;
    double congSuatPhat;
    double tocDoDuLieu;

public:
    RF1()
    {
        maModule = "";
        tanSo = 0;
        congSuatPhat = 0;
        tocDoDuLieu = 0;
    }

    void nhap()
    {
        cout << "Nhap ma module: "; cin >> maModule;
        cout << "Nhap tan so: "; cin >> tanSo;
        cout << "Nhap cong suat phat: "; cin >> congSuatPhat;
        cout << "Nhap toc do du lieu: "; cin >> tocDoDuLieu;
    }

    void xuat()
    {
        cout << "ma module: " << maModule << endl;
        cout << "tan so: " << tanSo << endl;
        cout << "cong suat phat: " << congSuatPhat << endl;
        cout << "toc do du lieu: " << tocDoDuLieu << endl;
        cout << "Chi so hieu qua truyen: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        if(congSuatPhat == 0) return 0; return tocDoDuLieu / congSuatPhat;
    }

};

class RF2 : public RF1
{
public:
    RF2 operator=(RF2 a)
    {
        maModule = a.maModule;
        tanSo = a.tanSo;
        congSuatPhat = a.congSuatPhat;
        tocDoDuLieu = a.tocDoDuLieu;
        return *this;
    }

    bool operator<(RF2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong module RF toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    RF2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap module RF thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vtMax=0, vtMin=0;
    for(int i=1;i<n;i++){ if(ds[vtMax] < ds[i]) vtMax=i; if(ds[i] < ds[vtMin]) vtMin=i; }
    cout << "\nmodule RF lon nhat:" << endl; ds[vtMax].xuat();
    cout << "\nmodule RF nho nhat:" << endl; ds[vtMin].xuat();
    return 0;
}
