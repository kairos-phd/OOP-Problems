#include <bits/stdc++.h>

using namespace std;

class nhanvien
{
protected:
    string hoten;
    int namsinh;
    double luongCoBan;

public:
    nhanvien()
    {
        hoten = "";
        namsinh = 0;
        luongCoBan = 0;
    }
    void nhap()
    {
        cout << "Nhap ho ten: "; cin >> hoten;
        cout << "Nhap nam sinh: "; cin >> namsinh;
        cout << "Nhap luong co ban: "; cin >> luongCoBan;
    }
    void xuat()
    {
        cout << "ho ten: " << hoten << endl;
        cout << "nam sinh: " << namsinh << endl;
        cout << "luong co ban: " << luongCoBan << endl;
    }
};

class kysu : public nhanvien
{
private:
    double troCap;
    double thoiGianTangCa;

public:
    kysu() : nhanvien()
    {
        troCap = 0;
        thoiGianTangCa = 0;
    }
    void nhap()
    {
        nhanvien::nhap();
        cout << "Nhap tro cap: "; cin >> troCap;
        cout << "Nhap thoi gian tang ca: "; cin >> thoiGianTangCa;
    }
    void xuat()
    {
        nhanvien::xuat();
        cout << "tro cap: " << troCap << endl;
        cout << "thoi gian tang ca: " << thoiGianTangCa << endl;
    }

    double tinhTongLuong(){ return luongCoBan*100 + thoiGianTangCa*20 + troCap; }
    bool operator>(kysu a){ return tinhTongLuong() > a.tinhTongLuong(); }

};

int main()
{
    int n;
    cout << "Nhap so luong ky su: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    kysu *ds = new kysu[n];
    for(int i=0;i<n;i++){ cout << "\nNhap ky su thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i] > ds[j]){ kysu tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach ky su tang dan theo luong" << endl;
    for(int i=0;i<n;i++){ cout << "\nKy su thu " << i+1 << endl; ds[i].xuat(); cout << "Tong luong: " << ds[i].tinhTongLuong() << endl; }

    delete[] ds;
    return 0;
}
