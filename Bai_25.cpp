#include <bits/stdc++.h>

using namespace std;

class GoiTin1
{
protected:
    string maGoi;
    double kichThuocDuLieu;
    double kichThuocTieuDe;
    double thoiGianTruyen;

public:
    GoiTin1()
    {
        maGoi = "";
        kichThuocDuLieu = 0;
        kichThuocTieuDe = 0;
        thoiGianTruyen = 0;
    }

    void nhap()
    {
        cout << "Nhap ma goi: "; cin >> maGoi;
        cout << "Nhap kich thuoc du lieu: "; cin >> kichThuocDuLieu;
        cout << "Nhap kich thuoc tieu de: "; cin >> kichThuocTieuDe;
        cout << "Nhap thoi gian truyen: "; cin >> thoiGianTruyen;
    }

    void xuat()
    {
        cout << "ma goi: " << maGoi << endl;
        cout << "kich thuoc du lieu: " << kichThuocDuLieu << endl;
        cout << "kich thuoc tieu de: " << kichThuocTieuDe << endl;
        cout << "thoi gian truyen: " << thoiGianTruyen << endl;
        cout << "Thong luong du lieu huu ich: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        if(thoiGianTruyen == 0) return 0; return kichThuocDuLieu / thoiGianTruyen;
    }

};

class GoiTin2 : public GoiTin1
{
public:
    GoiTin2 operator=(GoiTin2 a)
    {
        maGoi = a.maGoi;
        kichThuocDuLieu = a.kichThuocDuLieu;
        kichThuocTieuDe = a.kichThuocTieuDe;
        thoiGianTruyen = a.thoiGianTruyen;
        return *this;
    }

    bool operator>(GoiTin2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong goi tin toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    GoiTin2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap goi tin thu " << i+1 << endl;
        ds[i].nhap();
    }
    double tong=0; for(int i=0;i<n;i++) tong += ds[i].tinhGiaTri();
    double tb=tong/n;
    cout << "\nGia tri trung binh: " << tb << endl;
    cout << "Cac goi tin co gia tri lon hon trung binh:" << endl;
    for(int i=0;i<n;i++) if(ds[i].tinhGiaTri() > tb){ cout << "\ngoi tin thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
