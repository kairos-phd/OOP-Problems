#include <bits/stdc++.h>

using namespace std;

class TramPhatSong
{
private:
    string maTram;
    string viTri;
    double congSuat;
    double tanSo;

public:
    TramPhatSong()
    {
        maTram = "";
        viTri = "";
        congSuat = 0;
        tanSo = 0;
    }

    void nhap()
    {
        cout << "Nhap ma tram: "; cin >> maTram;
        cout << "Nhap vi tri: "; cin >> viTri;
        cout << "Nhap cong suat phat: "; cin >> congSuat;
        cout << "Nhap tan so hoat dong: "; cin >> tanSo;
    }

    void xuat()
    {
        cout << "ma tram: " << maTram << endl;
        cout << "vi tri: " << viTri << endl;
        cout << "cong suat phat: " << congSuat << endl;
        cout << "tan so hoat dong: " << tanSo << endl;
    }

    double getTanSo(){ return tanSo; }

};

int main()
{
    int n;
    cout << "Nhap so luong tram BTS: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    TramPhatSong *ds = new TramPhatSong[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap tram BTS thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int dem = 0;
    cout << "\nDanh sach tram co tan so > 1800MHz" << endl;
    for (int i = 0; i < n; i++) if (ds[i].getTanSo() > 1800)
    {
        dem++; cout << "\nTram thu " << i + 1 << endl; ds[i].xuat();
    }
    cout << "\nSo tram phat o bang cao tan: " << dem << endl;

    delete[] ds;
    return 0;
}
