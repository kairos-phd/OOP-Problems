#include <bits/stdc++.h>

using namespace std;

class BTS1
{
protected:
    string maTram;
    string tenTram;
    double congSuatPhat;

public:
    BTS1()
    {
        maTram = "";
        tenTram = "";
        congSuatPhat = 0;
    }
    void nhap()
    {
        cout << "Nhap ma tram: "; cin >> maTram;
        cout << "Nhap ten tram: "; cin >> tenTram;
        cout << "Nhap cong suat phat: "; cin >> congSuatPhat;
    }
    void xuat()
    {
        cout << "ma tram: " << maTram << endl;
        cout << "ten tram: " << tenTram << endl;
        cout << "cong suat phat: " << congSuatPhat << endl;
    }
};

class BTS2 : public BTS1
{
private:
    int soLuongThueBao;

public:
    BTS2() : BTS1()
    {
        soLuongThueBao = 0;
    }
    void nhap()
    {
        BTS1::nhap();
        cout << "Nhap so luong thue bao phuc vu: "; cin >> soLuongThueBao;
    }
    void xuat()
    {
        BTS1::xuat();
        cout << "so luong thue bao phuc vu: " << soLuongThueBao << endl;
    }

    BTS2 operator=(BTS2 a){ maTram=a.maTram; tenTram=a.tenTram; congSuatPhat=a.congSuatPhat; soLuongThueBao=a.soLuongThueBao; return *this; }
    bool operator>(BTS2 a){ return soLuongThueBao > a.soLuongThueBao; }

};

int main()
{
    int n;
    cout << "Nhap so luong tram BTS: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    BTS2 *ds = new BTS2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap tram BTS thu " << i+1 << endl; ds[i].nhap(); }
    int vt=0; for(int i=1;i<n;i++) if(ds[i] > ds[vt]) vt=i;
    cout << "\nTram BTS phuc vu nhieu thue bao nhat:" << endl; ds[vt].xuat();

    delete[] ds;
    return 0;
}
