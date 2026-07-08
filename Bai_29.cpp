#include <bits/stdc++.h>

using namespace std;

class Mach1
{
protected:
    string maMach;
    double dienApVao;
    double dienApRa;
    double dongTai;

public:
    Mach1()
    {
        maMach = "";
        dienApVao = 0;
        dienApRa = 0;
        dongTai = 0;
    }

    void nhap()
    {
        cout << "Nhap ma mach: "; cin >> maMach;
        cout << "Nhap dien ap vao: "; cin >> dienApVao;
        cout << "Nhap dien ap ra: "; cin >> dienApRa;
        cout << "Nhap dong tai: "; cin >> dongTai;
    }

    void xuat()
    {
        cout << "ma mach: " << maMach << endl;
        cout << "dien ap vao: " << dienApVao << endl;
        cout << "dien ap ra: " << dienApRa << endl;
        cout << "dong tai: " << dongTai << endl;
        cout << "Cong suat tai: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return dienApRa * dongTai;
    }

};

class Mach2 : public Mach1
{
public:
    Mach2 operator=(Mach2 a)
    {
        maMach = a.maMach;
        dienApVao = a.dienApVao;
        dienApRa = a.dienApRa;
        dongTai = a.dongTai;
        return *this;
    }

    bool operator<(Mach2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong mach dien tu toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Mach2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap mach dien tu thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[i] < ds[j]){ Mach2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach giam dan" << endl;
    for(int i=0;i<n;i++){ cout << "\nmach dien tu thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}

