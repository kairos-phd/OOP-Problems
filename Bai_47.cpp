#include <bits/stdc++.h>

using namespace std;

class canhbao1
{
protected:
    string maCanhBao;
    string loaiCanhBao;

public:
    canhbao1()
    {
        maCanhBao = "";
        loaiCanhBao = "";
    }

    void nhap()
    {
        cout << "Nhap ma canh bao: "; cin >> maCanhBao;
        cout << "Nhap loai canh bao: "; cin >> loaiCanhBao;
    }

    void xuat()
    {
        cout << "ma canh bao: " << maCanhBao << endl;
        cout << "loai canh bao: " << loaiCanhBao << endl;
    }
};

class canhbao2 : public canhbao1
{
private:
    int mucDoUuTien;
    string trangThai;

public:
    canhbao2() : canhbao1()
    {
        mucDoUuTien = 0;
        trangThai = "";
    }

    void nhap()
    {
        canhbao1::nhap();
        cout << "Nhap muc do uu tien: "; cin >> mucDoUuTien;
        cout << "Nhap trang thai: "; cin >> trangThai;
    }

    void xuat()
    {
        canhbao1::xuat();
        cout << "muc do uu tien: " << mucDoUuTien << endl;
        cout << "trang thai: " << trangThai << endl;
    }

    bool chuaXuLy(){ return trangThai=="chua_xu_ly" || trangThai=="chuaxuly" || trangThai=="ChuaXuLy"; }
    bool operator>(canhbao2 a){ return mucDoUuTien > a.mucDoUuTien; }

};

int main()
{
    int n;
    cout << "Nhap so luong canh bao: "; cin >> n;
    if(n <= 0)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    canhbao2 *ds = new canhbao2[n];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap canh bao thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[j] > ds[i]){ canhbao2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    bool co=false; cout << "\nDanh sach canh bao chua xu ly theo muc uu tien giam dan" << endl;
    for(int i=0;i<n;i++) if(ds[i].chuaXuLy()){ co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co canh bao chua xu ly" << endl;

    delete[] ds;
    return 0;
}
