#include <bits/stdc++.h>

using namespace std;

class CanhBao1
{
protected:
    string maCanhBao;
    string loaiCanhBao;
    int mucUuTien;
    string thoiGianXuatHien;

public:
    CanhBao1()
    {
        maCanhBao = "";
        loaiCanhBao = "";
        mucUuTien = 0;
        thoiGianXuatHien = "";
    }

    void nhap()
    {
        cout << "Nhap ma canh bao: "; cin >> maCanhBao;
        cout << "Nhap loai canh bao: "; cin >> loaiCanhBao;
        cout << "Nhap muc uu tien: "; cin >> mucUuTien;
        cout << "Nhap thoi gian xuat hien: "; cin >> thoiGianXuatHien;
    }

    void xuat()
    {
        cout << "ma canh bao: " << maCanhBao << endl;
        cout << "loai canh bao: " << loaiCanhBao << endl;
        cout << "muc uu tien: " << mucUuTien << endl;
        cout << "thoi gian xuat hien: " << thoiGianXuatHien << endl;
        cout << "Muc uu tien: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return mucUuTien;
    }

};

class CanhBao2 : public CanhBao1
{
public:
    CanhBao2 operator=(CanhBao2 a)
    {
        maCanhBao = a.maCanhBao;
        loaiCanhBao = a.loaiCanhBao;
        mucUuTien = a.mucUuTien;
        thoiGianXuatHien = a.thoiGianXuatHien;
        return *this;
    }

    bool operator>(CanhBao2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong canh bao toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CanhBao2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap canh bao thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] > ds[i]){ CanhBao2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach giam dan" << endl;
    for(int i=0;i<n;i++){ cout << "\ncanh bao thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
