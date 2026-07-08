#include <bits/stdc++.h>

using namespace std;

class LocSo1
{
protected:
    string maBoLoc;
    double tanSoLayMau;
    double tanSoCat;
    int bacBoLoc;

public:
    LocSo1()
    {
        maBoLoc = "";
        tanSoLayMau = 0;
        tanSoCat = 0;
        bacBoLoc = 0;
    }

    void nhap()
    {
        cout << "Nhap ma bo loc: "; cin >> maBoLoc;
        cout << "Nhap tan so lay mau: "; cin >> tanSoLayMau;
        cout << "Nhap tan so cat: "; cin >> tanSoCat;
        cout << "Nhap bac bo loc: "; cin >> bacBoLoc;
    }

    void xuat()
    {
        cout << "ma bo loc: " << maBoLoc << endl;
        cout << "tan so lay mau: " << tanSoLayMau << endl;
        cout << "tan so cat: " << tanSoCat << endl;
        cout << "bac bo loc: " << bacBoLoc << endl;
        cout << "Tan so cat: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return tanSoCat;
    }

    bool kiemTra(){ return tanSoCat < tanSoLayMau / 2; }

};

class LocSo2 : public LocSo1
{
public:
    LocSo2 operator=(LocSo2 a)
    {
        maBoLoc = a.maBoLoc;
        tanSoLayMau = a.tanSoLayMau;
        tanSoCat = a.tanSoCat;
        bacBoLoc = a.bacBoLoc;
        return *this;
    }

    bool operator<(LocSo2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong bo loc so toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    LocSo2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap bo loc so thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] < ds[i]){ LocSo2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach tang dan" << endl;
    for(int i=0;i<n;i++){ cout << "\nbo loc so thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
