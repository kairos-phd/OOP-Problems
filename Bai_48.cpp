#include <bits/stdc++.h>

using namespace std;

class UPS1
{
protected:
    string maUPS;
    double thoiGianLuuDien;
    double congSuat;

public:
    UPS1()
    {
        maUPS = "";
        thoiGianLuuDien = 0;
        congSuat = 0;
    }

    void nhap()
    {
        cout << "Nhap ma UPS: "; cin >> maUPS;
        cout << "Nhap thoi gian luu dien: "; cin >> thoiGianLuuDien;
        cout << "Nhap cong suat: "; cin >> congSuat;
    }

    void xuat()
    {
        cout << "ma UPS: " << maUPS << endl;
        cout << "thoi gian luu dien: " << thoiGianLuuDien << endl;
        cout << "cong suat: " << congSuat << endl;
    }
};

class UPS2 : public UPS1
{
private:
    string nuocSanXuat;

public:
    UPS2() : UPS1()
    {
        nuocSanXuat = "";
    }

    void nhap()
    {
        UPS1::nhap();
        cout << "Nhap nuoc san xuat: "; cin >> nuocSanXuat;
    }

    void xuat()
    {
        UPS1::xuat();
        cout << "nuoc san xuat: " << nuocSanXuat << endl;
    }

    bool operator>(UPS2 a){ return congSuat > a.congSuat; }
    double getCongSuat(){ return congSuat; }
    string getNuocSanXuat(){ return nuocSanXuat; }

};

int main()
{
    int n;
    cout << "Nhap so luong bo UPS: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    UPS2 *ds = new UPS2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap bo UPS thu " << i+1 << endl;
        ds[i].nhap();
    }
    double m; cout << "\nNhap gia tri cong suat m: "; cin >> m;
    bool co=false; cout << "\nDanh sach UPS san xuat o USA va cong suat lon hon m" << endl;
    for(int i=0;i<n;i++) if(ds[i].getNuocSanXuat()=="USA" && ds[i].getCongSuat() > m){ co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co UPS phu hop" << endl;

    delete[] ds;
    return 0;
}
