#include <bits/stdc++.h>

using namespace std;

class NGUON1
{
protected:
    string maNguon;
    double congSuat;
    string trangThaiDienApDauRa;

public:
    NGUON1()
    {
        maNguon = "";
        congSuat = 0;
        trangThaiDienApDauRa = "";
    }

    void nhap()
    {
        cout << "Nhap ma nguon: "; cin >> maNguon;
        cout << "Nhap cong suat: "; cin >> congSuat;
        cout << "Nhap trang thai dien ap dau ra: "; cin >> trangThaiDienApDauRa;
    }

    void xuat()
    {
        cout << "ma nguon: " << maNguon << endl;
        cout << "cong suat: " << congSuat << endl;
        cout << "trang thai dien ap dau ra: " << trangThaiDienApDauRa << endl;
    }
};

class NGUON2 : public NGUON1
{
private:
    double giaTriDienApDauRa;

public:
    NGUON2() : NGUON1()
    {
        giaTriDienApDauRa = 0;
    }

    void nhap()
    {
        NGUON1::nhap();
        cout << "Nhap gia tri dien ap dau ra: "; cin >> giaTriDienApDauRa;
    }

    void xuat()
    {
        NGUON1::xuat();
        cout << "gia tri dien ap dau ra: " << giaTriDienApDauRa << endl;
    }

    bool operator==(NGUON2 a){ return giaTriDienApDauRa == a.giaTriDienApDauRa; }
    string getTrangThai(){ return trangThaiDienApDauRa; }
    double getGiaTriDienApDauRa(){ return giaTriDienApDauRa; }

};

int main()
{
    int n;
    cout << "Nhap so luong bo nguon: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    NGUON2 *ds = new NGUON2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap bo nguon thu " << i+1 << endl;
        ds[i].nhap();
    }
    int dem=0;
    for(int i=0;i<n;i++) if(ds[i].getTrangThai()=="DC" && ds[i].getGiaTriDienApDauRa()==15) dem++;
    cout << "\nSo bo nguon DC co gia tri dien ap dau ra bang 15V: " << dem << endl;

    delete[] ds;
    return 0;
}
