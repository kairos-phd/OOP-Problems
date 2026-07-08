#include <bits/stdc++.h>

using namespace std;

class Tram1
{
protected:
    string maTram;
    double congSuatPhat;
    double banKinhPhuSong;
    int soThueBao;

public:
    Tram1()
    {
        maTram = "";
        congSuatPhat = 0;
        banKinhPhuSong = 0;
        soThueBao = 0;
    }

    void nhap()
    {
        cout << "Nhap ma tram: "; cin >> maTram;
        cout << "Nhap cong suat phat: "; cin >> congSuatPhat;
        cout << "Nhap ban kinh phu song: "; cin >> banKinhPhuSong;
        cout << "Nhap so thue bao: "; cin >> soThueBao;
    }

    void xuat()
    {
        cout << "ma tram: " << maTram << endl;
        cout << "cong suat phat: " << congSuatPhat << endl;
        cout << "ban kinh phu song: " << banKinhPhuSong << endl;
        cout << "so thue bao: " << soThueBao << endl;
        cout << "Mat do thue bao: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        if(banKinhPhuSong == 0) return 0; return soThueBao / (3.14 * banKinhPhuSong * banKinhPhuSong);
    }

};

class Tram2 : public Tram1
{
public:
    Tram2 operator=(Tram2 a)
    {
        maTram = a.maTram;
        congSuatPhat = a.congSuatPhat;
        banKinhPhuSong = a.banKinhPhuSong;
        soThueBao = a.soThueBao;
        return *this;
    }

    bool operator<(Tram2 a)
    {
        return tinhGiaTri() < a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong tram thu phat toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    Tram2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap tram thu phat thu " << i+1 << endl;
        ds[i].nhap();
    }
    double tong=0; for(int i=0;i<n;i++) tong += ds[i].tinhGiaTri();
    double tb=tong/n;
    cout << "\nGia tri trung binh: " << tb << endl;
    cout << "Cac tram thu phat co gia tri lon hon trung binh:" << endl;
    for(int i=0;i<n;i++) if(ds[i].tinhGiaTri() > tb){ cout << "\ntram thu phat thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
