#include <bits/stdc++.h>

using namespace std;

class sinhvien1
{
protected:
    string hoten;
    string lop;
    double diemChuyenCan;

public:
    sinhvien1()
    {
        hoten = "";
        lop = "";
        diemChuyenCan = 0;
    }

    void nhap()
    {
        cout << "Nhap ho ten: "; cin >> hoten;
        cout << "Nhap lop: "; cin >> lop;
        cout << "Nhap diem chuyen can: "; cin >> diemChuyenCan;
    }

    void xuat()
    {
        cout << "ho ten: " << hoten << endl;
        cout << "lop: " << lop << endl;
        cout << "diem chuyen can: " << diemChuyenCan << endl;
    }
};

class sinhvien2 : public sinhvien1
{
private:
    double diemThi;

public:
    sinhvien2() : sinhvien1()
    {
        diemThi = 0;
    }

    void nhap()
    {
        sinhvien1::nhap();
        cout << "Nhap diem thi: "; cin >> diemThi;
    }

    void xuat()
    {
        sinhvien1::xuat();
        cout << "diem thi: " << diemThi << endl;
    }

    double tinhDiemTrungBinh(){ return diemChuyenCan * 0.3 + diemThi * 0.7; }
    sinhvien2 operator=(sinhvien2 a){ hoten=a.hoten; lop=a.lop; diemChuyenCan=a.diemChuyenCan; diemThi=a.diemThi; return *this; }
    bool operator==(sinhvien2 a){ return tinhDiemTrungBinh() == a.tinhDiemTrungBinh(); }

};

int main()
{
    sinhvien2 a,b;
    cout << "Nhap sinh vien thu 1" << endl; a.nhap();
    cout << "\nNhap sinh vien thu 2" << endl; b.nhap();
    if(a == b) cout << "\nHai sinh vien co diem trung binh bang nhau" << endl;
    else cout << "\nHai sinh vien co diem trung binh khac nhau" << endl;
    return 0;
}
