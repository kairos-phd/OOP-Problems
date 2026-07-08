#include <bits/stdc++.h>

using namespace std;

class UART1
{
protected:
    string maBanTin;
    double tocDoBaud;
    int soByteDuLieu;
    int soBitPhuTro;

public:
    UART1()
    {
        maBanTin = "";
        tocDoBaud = 0;
        soByteDuLieu = 0;
        soBitPhuTro = 0;
    }

    void nhap()
    {
        cout << "Nhap ma ban tin: "; cin >> maBanTin;
        cout << "Nhap toc do baud: "; cin >> tocDoBaud;
        cout << "Nhap so byte du lieu: "; cin >> soByteDuLieu;
        cout << "Nhap so bit phu tro: "; cin >> soBitPhuTro;
    }

    void xuat()
    {
        cout << "ma ban tin: " << maBanTin << endl;
        cout << "toc do baud: " << tocDoBaud << endl;
        cout << "so byte du lieu: " << soByteDuLieu << endl;
        cout << "so bit phu tro: " << soBitPhuTro << endl;
        cout << "Thoi gian truyen: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        if(tocDoBaud == 0) return 0; return (soByteDuLieu * 8.0 + soBitPhuTro) / tocDoBaud;
    }

};

class UART2 : public UART1
{
public:
    UART2 operator=(UART2 a)
    {
        maBanTin = a.maBanTin;
        tocDoBaud = a.tocDoBaud;
        soByteDuLieu = a.soByteDuLieu;
        soBitPhuTro = a.soBitPhuTro;
        return *this;
    }

    bool operator>(UART2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong ban tin UART toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    UART2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap ban tin UART thu " << i+1 << endl;
        ds[i].nhap();
    }
    int vt=0;
    for(int i=1;i<n;i++) if(ds[i] > ds[vt]) vt=i;
    cout << "\nban tin UART co gia tri lon nhat:" << endl;
    ds[vt].xuat();
    return 0;
}
