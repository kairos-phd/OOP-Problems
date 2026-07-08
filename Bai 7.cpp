#include <bits/stdc++.h>

using namespace std;

class BoMachNhung
{
private:
    string maMach;
    string tenMach;
    string viXuLy;
    double giaThanh;

public:
    BoMachNhung()
    {
        maMach = "";
        tenMach = "";
        viXuLy = "";
        giaThanh = 0;
    }

    void nhap()
    {
        cout << "Nhap ma mach: ";
        cin >> maMach;

        cout << "Nhap ten mach: ";
        cin >> tenMach;

        cout << "Nhap vi xu ly chinh: ";
        cin >> viXuLy;

        cout << "Nhap gia thanh: ";
        cin >> giaThanh;
    }

    void xuat()
    {
        cout << "Ma mach: " << maMach << endl;
        cout << "Ten mach: " << tenMach << endl;
        cout << "Vi xu ly chinh: " << viXuLy << endl;
        cout << "Gia thanh: " << giaThanh << endl;
    }

    string getViXuLy()
    {
        return viXuLy;
    }

    double getGiaThanh()
    {
        return giaThanh;
    }
};

int main()
{
    int n;

    cout << "Nhap so luong bo mach: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "So luong khong hop le!" << endl;
        return 0;
    }

    BoMachNhung *ds = new BoMachNhung[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap bo mach thu " << i + 1 << endl;
        ds[i].nhap();
    }

    int viTriMin = -1;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].getViXuLy() == "ESP32")
        {
            if (viTriMin == -1 || ds[i].getGiaThanh() < ds[viTriMin].getGiaThanh())
            {
                viTriMin = i;
            }
        }
    }

    if (viTriMin == -1)
    {
        cout << "\nKhong co bo mach nao dung vi xu ly ESP32" << endl;
    }
    else
    {
        cout << "\nBo mach dung ESP32 co gia re nhat:" << endl;
        ds[viTriMin].xuat();
    }

    delete[] ds;

    return 0;
}
