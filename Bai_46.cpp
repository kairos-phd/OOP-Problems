#include <bits/stdc++.h>

using namespace std;

class pin1
{
protected:
    string maPin;
    double dungLuong;
    double dienAp;

public:
    pin1()
    {
        maPin = "";
        dungLuong = 0;
        dienAp = 0;
    }

    void nhap()
    {
        cout << "Nhap ma pin: "; cin >> maPin;
        cout << "Nhap dung luong: "; cin >> dungLuong;
        cout << "Nhap dien ap: "; cin >> dienAp;
    }

    void xuat()
    {
        cout << "ma pin: " << maPin << endl;
        cout << "dung luong: " << dungLuong << endl;
        cout << "dien ap: " << dienAp << endl;
    }
};

class pin2 : public pin1
{
private:
    int soLanSac;

public:
    pin2() : pin1()
    {
        soLanSac = 0;
    }

    void nhap()
    {
        pin1::nhap();
        cout << "Nhap so lan sac: "; cin >> soLanSac;
    }

    void xuat()
    {
        pin1::xuat();
        cout << "so lan sac: " << soLanSac << endl;
    }

    bool laOld(){ return soLanSac > 100; }

};

int main()
{
    int n;
    cout << "Nhap so luong pin: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    pin2 *ds = new pin2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap pin thu " << i+1 << endl;
        ds[i].nhap();
    }
    int demOld=0, demNew=0;
    for(int i=0;i<n;i++) if(ds[i].laOld()) demOld++; else demNew++;
    cout << "\nSo luong pin old: " << demOld << endl;
    cout << "So luong pin new: " << demNew << endl;

    delete[] ds;
    return 0;
}
