#include <bits/stdc++.h>

using namespace std;

class hoadon1
{
protected:
    string maKhachHang;
    string tenKhachHang;
    int soDienCu;

public:
    hoadon1()
    {
        maKhachHang = "";
        tenKhachHang = "";
        soDienCu = 0;
    }

    void nhap()
    {
        cout << "Nhap ma khach hang: "; cin >> maKhachHang;
        cout << "Nhap ten khach hang: "; cin >> tenKhachHang;
        cout << "Nhap so dien cu: "; cin >> soDienCu;
    }

    void xuat()
    {
        cout << "ma khach hang: " << maKhachHang << endl;
        cout << "ten khach hang: " << tenKhachHang << endl;
        cout << "so dien cu: " << soDienCu << endl;
    }
};

class hoadon2 : public hoadon1
{
private:
    int soDienMoi;

public:
    hoadon2() : hoadon1()
    {
        soDienMoi = 0;
    }

    void nhap()
    {
        hoadon1::nhap();
        cout << "Nhap so dien moi: "; cin >> soDienMoi;
    }

    void xuat()
    {
        hoadon1::xuat();
        cout << "so dien moi: " << soDienMoi << endl;
    }

    int tinhSoDien(){ return soDienMoi - soDienCu; }
    double tinhTienDien(){ return tinhSoDien() * 5000; }
    bool operator>(hoadon2 a){ return tinhTienDien() > a.tinhTienDien(); }

};

int main()
{
    int n;
    cout << "Nhap so luong khach hang: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    hoadon2 *ds = new hoadon2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap khach hang thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[j] > ds[i]){ hoadon2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach khach hang giam dan theo tien dien" << endl;
    for(int i=0;i<n;i++){ cout << "\nKhach hang thu " << i+1 << endl; ds[i].xuat(); cout << "Tien dien: " << ds[i].tinhTienDien() << endl; }

    delete[] ds;
    return 0;
}
