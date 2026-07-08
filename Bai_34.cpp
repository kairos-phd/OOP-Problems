#include <bits/stdc++.h>

using namespace std;

class Bus1
{
protected:
    string maBus;
    int soThietBiKetNoi;
    double tocDoTruyen;
    double tiLeLoiBit;

public:
    Bus1()
    {
        maBus = "";
        soThietBiKetNoi = 0;
        tocDoTruyen = 0;
        tiLeLoiBit = 0;
    }

    void nhap()
    {
        cout << "Nhap ma bus: "; cin >> maBus;
        cout << "Nhap so thiet bi ket noi: "; cin >> soThietBiKetNoi;
        cout << "Nhap toc do truyen: "; cin >> tocDoTruyen;
        cout << "Nhap ti le loi bit: "; cin >> tiLeLoiBit;
    }

    void xuat()
    {
        cout << "ma bus: " << maBus << endl;
        cout << "so thiet bi ket noi: " << soThietBiKetNoi << endl;
        cout << "toc do truyen: " << tocDoTruyen << endl;
        cout << "ti le loi bit: " << tiLeLoiBit << endl;
        cout << "Toc do truyen hieu dung: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return tocDoTruyen * (1 - tiLeLoiBit);
    }

};

class Bus2 : public Bus1
{
public:
    Bus2 operator=(Bus2 a)
    {
        maBus = a.maBus;
        soThietBiKetNoi = a.soThietBiKetNoi;
        tocDoTruyen = a.tocDoTruyen;
        tiLeLoiBit = a.tiLeLoiBit;
        return *this;
    }

    bool operator<(Bus2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong bus toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Bus2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap bus thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vt=0;
    for(int i=1;i<n;i++) if(ds[vt] < ds[i]) vt=i;
    cout << "\nbus co gia tri lon nhat:" << endl;
    ds[vt].xuat();
    return 0;
}
