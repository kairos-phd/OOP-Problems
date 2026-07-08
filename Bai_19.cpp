#include <bits/stdc++.h>

using namespace std;

class GiaoThucMang
{
private:
    string tenGiaoThuc;
    int congMacDinh;
    int doDaiHeader;

public:
    GiaoThucMang()
    {
        tenGiaoThuc = "";
        congMacDinh = 0;
        doDaiHeader = 0;
    }

    void nhap()
    {
        cout << "Nhap ten giao thuc: "; cin >> tenGiaoThuc;
        cout << "Nhap cong mac dinh: "; cin >> congMacDinh;
        cout << "Nhap do dai header: "; cin >> doDaiHeader;
    }

    void xuat()
    {
        cout << "ten giao thuc: " << tenGiaoThuc << endl;
        cout << "cong mac dinh: " << congMacDinh << endl;
        cout << "do dai header: " << doDaiHeader << endl;
    }

    string getTenGiaoThuc(){ return tenGiaoThuc; }

};

int main()
{
    int n;
    cout << "Nhap so luong giao thuc mang: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    GiaoThucMang *ds = new GiaoThucMang[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap giao thuc mang thu " << i + 1 << endl;
        ds[i].nhap();
    }
    bool co = false; cout << "\nCac giao thuc TCP hoac IP:" << endl;
    for (int i = 0; i < n; i++) if (ds[i].getTenGiaoThuc() == "TCP" || ds[i].getTenGiaoThuc() == "IP")
    { co = true; ds[i].xuat(); }
    if (!co) cout << "Khong co giao thuc TCP hoac IP" << endl;

    delete[] ds;
    return 0;
}
