#include <bits/stdc++.h>

using namespace std;

class CuonCam
{
private:
    string maLinhKien;
    double L;
    double f;

public:
    CuonCam()
    {
        maLinhKien = "";
        L = 0;
        f = 0;
    }

    void nhap()
    {
        cout << "Nhap ma linh kien: "; cin >> maLinhKien;
        cout << "Nhap do tu cam L (mH): "; cin >> L;
        cout << "Nhap tan so dong dien f: "; cin >> f;
    }

    void xuat()
    {
        cout << "ma linh kien: " << maLinhKien << endl;
        cout << "do tu cam L (mH): " << L << endl;
        cout << "tan so dong dien f: " << f << endl;
    }

    double tinhZL(){ return 2 * 3.14 * f * L / 1000; }

};

int main()
{
    int n;
    cout << "Nhap so luong cuon cam: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CuonCam *ds = new CuonCam[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap cuon cam thu " << i + 1 << endl;
        ds[i].nhap();
    }
    bool co = false; cout << "\nCac cuon cam co ZL > 50:" << endl;
    for (int i = 0; i < n; i++) if (ds[i].tinhZL() > 50)
    { co = true; ds[i].xuat(); cout << "Cam khang ZL: " << ds[i].tinhZL() << endl; }
    if (!co) cout << "Khong co cuon cam nao co ZL > 50" << endl;

    delete[] ds;
    return 0;
}
