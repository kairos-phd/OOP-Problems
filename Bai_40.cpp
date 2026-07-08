#include <bits/stdc++.h>

using namespace std;

class DuLieu1
{
protected:
    string maBanGhi;
    string thoiGian;
    double giaTriCamBien;
    string trangThaiKetNoi;

public:
    DuLieu1()
    {
        maBanGhi = "";
        thoiGian = "";
        giaTriCamBien = 0;
        trangThaiKetNoi = "";
    }

    void nhap()
    {
        cout << "Nhap ma ban ghi: "; cin >> maBanGhi;
        cout << "Nhap thoi gian: "; cin >> thoiGian;
        cout << "Nhap gia tri cam bien: "; cin >> giaTriCamBien;
        cout << "Nhap trang thai ket noi: "; cin >> trangThaiKetNoi;
    }

    void xuat()
    {
        cout << "ma ban ghi: " << maBanGhi << endl;
        cout << "thoi gian: " << thoiGian << endl;
        cout << "gia tri cam bien: " << giaTriCamBien << endl;
        cout << "trang thai ket noi: " << trangThaiKetNoi << endl;
        cout << "Gia tri cam bien: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return giaTriCamBien;
    }

    bool hopLe(){ return trangThaiKetNoi=="ketnoi" || trangThaiKetNoi=="KetNoi" || trangThaiKetNoi=="connected" || trangThaiKetNoi=="Connected" || trangThaiKetNoi=="1"; }

};

class DuLieu2 : public DuLieu1
{
public:
    DuLieu2 operator=(DuLieu2 a)
    {
        maBanGhi = a.maBanGhi;
        thoiGian = a.thoiGian;
        giaTriCamBien = a.giaTriCamBien;
        trangThaiKetNoi = a.trangThaiKetNoi;
        return *this;
    }

    bool operator<(DuLieu2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong ban ghi toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    DuLieu2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap ban ghi thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[j] < ds[i]){ DuLieu2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    bool co=false; cout << "\nCac ban ghi hop le:" << endl;
    for(int i=0;i<n;i++) if(ds[i].hopLe()){ co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co ban ghi hop le" << endl;
    return 0;
}
