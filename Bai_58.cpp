#include <bits/stdc++.h>

using namespace std;

class VDK1
{
protected:
    string tenViDieuKhien;
    int soChan;
    double dienApHoatDong;

public:
    VDK1()
    {
        tenViDieuKhien = "";
        soChan = 0;
        dienApHoatDong = 0;
    }
    void nhap()
    {
        cout << "Nhap ten vi dieu khien: "; cin >> tenViDieuKhien;
        cout << "Nhap so chan: "; cin >> soChan;
        cout << "Nhap dien ap hoat dong: "; cin >> dienApHoatDong;
    }
    void xuat()
    {
        cout << "ten vi dieu khien: " << tenViDieuKhien << endl;
        cout << "so chan: " << soChan << endl;
        cout << "dien ap hoat dong: " << dienApHoatDong << endl;
    }
};

class VDK2 : public VDK1
{
private:
    int soLuongBoTimer;

public:
    VDK2() : VDK1()
    {
        soLuongBoTimer = 0;
    }
    void nhap()
    {
        VDK1::nhap();
        cout << "Nhap so luong bo timer: "; cin >> soLuongBoTimer;
    }
    void xuat()
    {
        VDK1::xuat();
        cout << "so luong bo timer: " << soLuongBoTimer << endl;
    }

    VDK2 operator=(VDK2 a){ tenViDieuKhien=a.tenViDieuKhien; soChan=a.soChan; dienApHoatDong=a.dienApHoatDong; soLuongBoTimer=a.soLuongBoTimer; return *this; }
    bool operator<(VDK2 a){ return soLuongBoTimer < a.soLuongBoTimer; }

};

int main()
{
    int n;
    cout << "Nhap so luong vi dieu khien: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    VDK2 *ds = new VDK2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap vi dieu khien thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i] < ds[j]){ VDK2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nThong tin 2 vi dieu khien co so luong bo timer lon nhat" << endl;
    int sl=n<2?n:2; for(int i=0;i<sl;i++){ cout << "\nVi dieu khien thu " << i+1 << endl; ds[i].xuat(); }

    delete[] ds;
    return 0;
}
