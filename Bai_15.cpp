#include <bits/stdc++.h>

using namespace std;

class CapQuang
{
private:
    string maCap;
    string loaiCap;
    double chieuDai;
    double suyHaoMoiKm;

public:
    CapQuang()
    {
        maCap = "";
        loaiCap = "";
        chieuDai = 0;
        suyHaoMoiKm = 0;
    }

    void nhap()
    {
        cout << "Nhap ma cap: "; cin >> maCap;
        cout << "Nhap loai cap: "; cin >> loaiCap;
        cout << "Nhap chieu dai (m): "; cin >> chieuDai;
        cout << "Nhap do suy hao moi km: "; cin >> suyHaoMoiKm;
    }

    void xuat()
    {
        cout << "ma cap: " << maCap << endl;
        cout << "loai cap: " << loaiCap << endl;
        cout << "chieu dai (m): " << chieuDai << endl;
        cout << "do suy hao moi km: " << suyHaoMoiKm << endl;
    }

    double tinhSuyHaoTong(){ return suyHaoMoiKm * (chieuDai / 1000); }
    double getChieuDai(){ return chieuDai; }

};

int main()
{
    int n;
    cout << "Nhap so luong tuyen cap quang: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CapQuang *ds = new CapQuang[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap tuyen cap quang thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++) if (ds[i].getChieuDai() > ds[viTriMax].getChieuDai()) viTriMax = i;
    cout << "\nTuyen cap dai nhat:" << endl;
    ds[viTriMax].xuat();
    cout << "Suy hao tong: " << ds[viTriMax].tinhSuyHaoTong() << endl;

    delete[] ds;
    return 0;
}
