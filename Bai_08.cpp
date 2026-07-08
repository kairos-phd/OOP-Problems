#include <bits/stdc++.h>

using namespace std;

class ThietBiGateway
{
private:
    string tenThietBi;
    string diaChiIP;
    int soNode;
    string chuanKetNoi;

public:
    ThietBiGateway()
    {
        tenThietBi = "";
        diaChiIP = "";
        soNode = 0;
        chuanKetNoi = "";
    }

    void nhap()
    {
        cout << "Nhap ten thiet bi: "; cin >> tenThietBi;
        cout << "Nhap dia chi IP: "; cin >> diaChiIP;
        cout << "Nhap so luong node cam bien: "; cin >> soNode;
        cout << "Nhap chuan ket noi khong day: "; cin >> chuanKetNoi;
    }

    void xuat()
    {
        cout << "ten thiet bi: " << tenThietBi << endl;
        cout << "dia chi IP: " << diaChiIP << endl;
        cout << "so luong node cam bien: " << soNode << endl;
        cout << "chuan ket noi khong day: " << chuanKetNoi << endl;
    }

    int getSoNode(){ return soNode; }

};

int main()
{
    int n;
    cout << "Nhap so luong Gateway: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    ThietBiGateway *ds = new ThietBiGateway[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap Gateway thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMax = 0;
    for (int i = 1; i < n; i++)
        if (ds[i].getSoNode() > ds[viTriMax].getSoNode()) viTriMax = i;
    cout << "\nGateway quan ly nhieu node cam bien nhat:" << endl;
    ds[viTriMax].xuat();

    delete[] ds;
    return 0;
}
