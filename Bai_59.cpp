#include <bits/stdc++.h>

using namespace std;

class LED1
{
protected:
    string maLed;
    string mauLed;
    double dongHoatDong;

public:
    LED1()
    {
        maLed = "";
        mauLed = "";
        dongHoatDong = 0;
    }
    void nhap()
    {
        cout << "Nhap ma led: "; cin >> maLed;
        cout << "Nhap mau led: "; cin >> mauLed;
        cout << "Nhap dong hoat dong: "; cin >> dongHoatDong;
    }
    void xuat()
    {
        cout << "ma led: " << maLed << endl;
        cout << "mau led: " << mauLed << endl;
        cout << "dong hoat dong: " << dongHoatDong << endl;
    }
};

class LED2 : public LED1
{
private:
    double congSuatTieuThu;

public:
    LED2() : LED1()
    {
        congSuatTieuThu = 0;
    }
    void nhap()
    {
        LED1::nhap();
        cout << "Nhap cong suat tieu thu: "; cin >> congSuatTieuThu;
    }
    void xuat()
    {
        LED1::xuat();
        cout << "cong suat tieu thu: " << congSuatTieuThu << endl;
    }

    bool operator<(LED2 a){ return congSuatTieuThu < a.congSuatTieuThu; }

};

int main()
{
    int n;
    cout << "Nhap so luong LED: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    LED2 *ds = new LED2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap LED thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i] < ds[j]){ LED2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach LED giam dan theo cong suat tieu thu" << endl;
    for(int i=0;i<n;i++){ cout << "\nLED thu " << i+1 << endl; ds[i].xuat(); }

    delete[] ds;
    return 0;
}
