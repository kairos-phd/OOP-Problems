#include <bits/stdc++.h>

using namespace std;

class TuDien
{
private:
    string ma;
    double dungLuong;
    double dienApDinhMuc;

public:
    TuDien()
    {
        ma = "";
        dungLuong = 0;
        dienApDinhMuc = 0;
    }

    void nhap()
    {
        cout << "Nhap ma linh kien: "; cin >> ma;
        cout << "Nhap dung luong C (uF): "; cin >> dungLuong;
        cout << "Nhap dien ap dinh muc: "; cin >> dienApDinhMuc;
    }

    void xuat()
    {
        cout << "ma linh kien: " << ma << endl;
        cout << "dung luong C (uF): " << dungLuong << endl;
        cout << "dien ap dinh muc: " << dienApDinhMuc << endl;
    }

    bool anToan(double X){ return dienApDinhMuc >= X; }
    double getDungLuong(){ return dungLuong; }

};

int main()
{
    int n;
    cout << "Nhap so luong tu dien: "; cin >> n;
    if (n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    TuDien *ds = new TuDien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap tu dien thu " << i + 1 << endl;
        ds[i].nhap();
    }
    double X; cout << "\nNhap dien ap nguon X: "; cin >> X;
    int demDungLuong = 0, demAnToan = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].getDungLuong() > 100) demDungLuong++;
        if (ds[i].anToan(X)) demAnToan++;
    }
    cout << "So tu dien co dung luong lon hon 100uF: " << demDungLuong << endl;
    cout << "So tu dien an toan voi nguon X: " << demAnToan << endl;

    delete[] ds;
    return 0;
}
