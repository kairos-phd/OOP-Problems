#include <bits/stdc++.h>

using namespace std;

class sach1
{
protected:
    string maSach;
    string tenSach;

public:
    sach1()
    {
        maSach = "";
        tenSach = "";
    }

    void nhap()
    {
        cout << "Nhap ma sach: "; cin >> maSach;
        cout << "Nhap ten sach: "; cin >> tenSach;
    }

    void xuat()
    {
        cout << "ma sach: " << maSach << endl;
        cout << "ten sach: " << tenSach << endl;
    }
};

class sach2 : public sach1
{
private:
    int soTrang;
    int namXuatBan;

public:
    sach2() : sach1()
    {
        soTrang = 0;
        namXuatBan = 0;
    }

    void nhap()
    {
        sach1::nhap();
        cout << "Nhap so trang: "; cin >> soTrang;
        cout << "Nhap nam xuat ban: "; cin >> namXuatBan;
    }

    void xuat()
    {
        sach1::xuat();
        cout << "so trang: " << soTrang << endl;
        cout << "nam xuat ban: " << namXuatBan << endl;
    }

    string phanLoai(){ if(soTrang < 100) return "Loai mong"; if(soTrang <= 200) return "Loai TB"; return "Loai day"; }
    int getNamXuatBan(){ return namXuatBan; }

};

int main()
{
    int n; cout << "Nhap so luong quyen sach (n > 5): "; cin >> n;
    if(n <= 5){ cout << "So luong khong hop le" << endl; return 0; }
    sach2 *ds = new sach2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap quyen sach thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i].getNamXuatBan() > ds[j].getNamXuatBan()){ sach2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nThong tin 3 quyen sach cu nhat:" << endl;
    for(int i=0;i<3;i++){ cout << "\nQuyen sach thu " << i+1 << endl; ds[i].xuat(); cout << "Phan loai: " << ds[i].phanLoai() << endl; }
    delete[] ds; return 0;
}
