#include <bits/stdc++.h>

using namespace std;

class thongtin1
{
protected:
    string hoten;
    int namsinh;
    string lop;

public:
    thongtin1()
    {
        hoten = "";
        namsinh = 0;
        lop = "";
    }

    void nhap()
    {
        cout << "Nhap ho ten: "; cin >> hoten;
        cout << "Nhap nam sinh: "; cin >> namsinh;
        cout << "Nhap lop: "; cin >> lop;
    }

    void xuat()
    {
        cout << "ho ten: " << hoten << endl;
        cout << "nam sinh: " << namsinh << endl;
        cout << "lop: " << lop << endl;
    }
};

class thongtin2 : public thongtin1
{
private:
    int soLuongDeTai;

public:
    thongtin2() : thongtin1()
    {
        soLuongDeTai = 0;
    }

    void nhap()
    {
        thongtin1::nhap();
        cout << "Nhap so luong de tai khoa hoc tham gia: "; cin >> soLuongDeTai;
    }

    void xuat()
    {
        thongtin1::xuat();
        cout << "so luong de tai khoa hoc tham gia: " << soLuongDeTai << endl;
    }

    bool operator>(thongtin2 a){ return soLuongDeTai > a.soLuongDeTai; }

};

int main()
{
    int n;
    cout << "Nhap so luong sinh vien: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    thongtin2 *ds = new thongtin2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap sinh vien thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[j] > ds[i]){ thongtin2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach sinh vien giam dan theo so luong de tai" << endl;
    for(int i=0;i<n;i++){ cout << "\nSinh vien thu " << i+1 << endl; ds[i].xuat(); }

    delete[] ds;
    return 0;
}
