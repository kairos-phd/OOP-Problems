#include <bits/stdc++.h>

using namespace std;

class TBQ1
{
protected:
    string maThietBi;
    double khoangCachTruyen;
    double tocDoKetNoi;

public:
    TBQ1()
    {
        maThietBi = "";
        khoangCachTruyen = 0;
        tocDoKetNoi = 0;
    }
    void nhap()
    {
        cout << "Nhap ma thiet bi: "; cin >> maThietBi;
        cout << "Nhap khoang cach truyen: "; cin >> khoangCachTruyen;
        cout << "Nhap toc do ket noi: "; cin >> tocDoKetNoi;
    }
    void xuat()
    {
        cout << "ma thiet bi: " << maThietBi << endl;
        cout << "khoang cach truyen: " << khoangCachTruyen << endl;
        cout << "toc do ket noi: " << tocDoKetNoi << endl;
    }
};

class TBQ2 : public TBQ1
{
private:
    int soCongKetNoi;

public:
    TBQ2() : TBQ1()
    {
        soCongKetNoi = 0;
    }
    void nhap()
    {
        TBQ1::nhap();
        cout << "Nhap so cong ket noi: "; cin >> soCongKetNoi;
    }
    void xuat()
    {
        TBQ1::xuat();
        cout << "so cong ket noi: " << soCongKetNoi << endl;
    }

    int operator+(TBQ2 a){ return soCongKetNoi + a.soCongKetNoi; }
    double getKhoangCachTruyen(){ return khoangCachTruyen; }
    int getSoCongKetNoi(){ return soCongKetNoi; }

};

int main()
{
    int n;
    cout << "Nhap so luong thiet bi quang: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    TBQ2 *ds = new TBQ2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap thiet bi quang thu " << i+1 << endl; ds[i].nhap(); }
    int tong=0; for(int i=0;i<n;i++) if(ds[i].getKhoangCachTruyen() > 5) tong += ds[i].getSoCongKetNoi();
    cout << "\nTong so cong ket noi cua thiet bi co khoang cach truyen > 5km: " << tong << endl;

    delete[] ds;
    return 0;
}
