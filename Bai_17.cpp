#include <bits/stdc++.h>

using namespace std;

class BoMach_PCB
{
private:
    string maBoMach;
    double chieuDai;
    double chieuRong;
    int soLopMach;

public:
    BoMach_PCB()
    {
        maBoMach = "";
        chieuDai = 0;
        chieuRong = 0;
        soLopMach = 0;
    }

    void nhap()
    {
        cout << "Nhap ma bo mach: "; cin >> maBoMach;
        cout << "Nhap chieu dai: "; cin >> chieuDai;
        cout << "Nhap chieu rong: "; cin >> chieuRong;
        cout << "Nhap so lop mach: "; cin >> soLopMach;
    }

    void xuat()
    {
        cout << "ma bo mach: " << maBoMach << endl;
        cout << "chieu dai: " << chieuDai << endl;
        cout << "chieu rong: " << chieuRong << endl;
        cout << "so lop mach: " << soLopMach << endl;
    }

    double tinhDienTich(){ return chieuDai * chieuRong; }
    int getSoLopMach(){ return soLopMach; }

};

int main()
{
    int n;
    cout << "Nhap so luong bo mach PCB: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    BoMach_PCB *ds = new BoMach_PCB[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap bo mach PCB thu " << i + 1 << endl;
        ds[i].nhap();
    }
    int viTriMin = -1;
    for (int i = 0; i < n; i++) if (ds[i].getSoLopMach() >= 4)
        if (viTriMin == -1 || ds[i].tinhDienTich() < ds[viTriMin].tinhDienTich()) viTriMin = i;
    if (viTriMin == -1) cout << "\nKhong co bo mach nao co so lop mach >= 4" << endl;
    else { cout << "\nBo mach co dien tich nho nhat va so lop mach >= 4:" << endl; ds[viTriMin].xuat(); cout << "Dien tich: " << ds[viTriMin].tinhDienTich() << endl; }

    delete[] ds;
    return 0;
}
