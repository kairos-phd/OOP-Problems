#include <bits/stdc++.h>

using namespace std;

class CamBienNhiet
{
private:
    string maCamBien;
    double Tmin;
    double Tmax;
    double dienApNgoRa;

public:
    CamBienNhiet()
    {
        maCamBien = "";
        Tmin = 0;
        Tmax = 0;
        dienApNgoRa = 0;
    }

    void nhap()
    {
        cout << "Nhap ma cam bien: "; cin >> maCamBien;
        cout << "Nhap Tmin: "; cin >> Tmin;
        cout << "Nhap Tmax: "; cin >> Tmax;
        cout << "Nhap dien ap ngo ra: "; cin >> dienApNgoRa;
    }

    void xuat()
    {
        cout << "ma cam bien: " << maCamBien << endl;
        cout << "Tmin: " << Tmin << endl;
        cout << "Tmax: " << Tmax << endl;
        cout << "dien ap ngo ra: " << dienApNgoRa << endl;
    }

    double getTmax(){ return Tmax; }

};

int main()
{
    int n;
    cout << "Nhap so luong cam bien nhiet: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CamBienNhiet *ds = new CamBienNhiet[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap cam bien nhiet thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++) if (ds[i].getTmax() > ds[viTriMax].getTmax()) viTriMax = i;
    cout << "\nCam bien do duoc nhiet do cao nhat:" << endl;
    ds[viTriMax].xuat();

    delete[] ds;
    return 0;
}
