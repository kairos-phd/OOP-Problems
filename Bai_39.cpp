#include <bits/stdc++.h>

using namespace std;

class CongSuat1
{
protected:
    string maKenh;
    double dienApRMS;
    double dongDienRMS;
    double heSoCongSuat;

public:
    CongSuat1()
    {
        maKenh = "";
        dienApRMS = 0;
        dongDienRMS = 0;
        heSoCongSuat = 0;
    }

    void nhap()
    {
        cout << "Nhap ma kenh: "; cin >> maKenh;
        cout << "Nhap dien ap RMS: "; cin >> dienApRMS;
        cout << "Nhap dong dien RMS: "; cin >> dongDienRMS;
        cout << "Nhap he so cong suat: "; cin >> heSoCongSuat;
    }

    void xuat()
    {
        cout << "ma kenh: " << maKenh << endl;
        cout << "dien ap RMS: " << dienApRMS << endl;
        cout << "dong dien RMS: " << dongDienRMS << endl;
        cout << "he so cong suat: " << heSoCongSuat << endl;
        cout << "Cong suat tac dung: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return dienApRMS * dongDienRMS * heSoCongSuat;
    }

    bool hopLe(){ return dienApRMS >= 0 && dongDienRMS >= 0 && heSoCongSuat >= 0 && heSoCongSuat <= 1; }

};

class CongSuat2 : public CongSuat1
{
public:
    CongSuat2 operator=(CongSuat2 a)
    {
        maKenh = a.maKenh;
        dienApRMS = a.dienApRMS;
        dongDienRMS = a.dongDienRMS;
        heSoCongSuat = a.heSoCongSuat;
        return *this;
    }

    bool operator>(CongSuat2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong kenh do toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CongSuat2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap kenh do thu " << i+1 << endl;
        ds[i].nhap();
    }
    double tong=0;
    for(int i=0;i<n;i++) if(ds[i].hopLe()) tong += ds[i].tinhGiaTri();
    cout << "\nTong gia tri cua cac kenh hop le: " << tong << endl;
    return 0;
}
