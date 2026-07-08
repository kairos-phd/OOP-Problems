#include <bits/stdc++.h>

using namespace std;

class MBA1
{
protected:
    string maMay;
    double congSuatDinhMuc;

public:
    MBA1()
    {
        maMay = "";
        congSuatDinhMuc = 0;
    }
    void nhap()
    {
        cout << "Nhap ma may: "; cin >> maMay;
        cout << "Nhap cong suat dinh muc: "; cin >> congSuatDinhMuc;
    }
    void xuat()
    {
        cout << "ma may: " << maMay << endl;
        cout << "cong suat dinh muc: " << congSuatDinhMuc << endl;
    }
};

class MBA2 : public MBA1
{
private:
    double dienApVao;
    double dienApRa;

public:
    MBA2() : MBA1()
    {
        dienApVao = 0;
        dienApRa = 0;
    }
    void nhap()
    {
        MBA1::nhap();
        cout << "Nhap dien ap vao: "; cin >> dienApVao;
        cout << "Nhap dien ap ra: "; cin >> dienApRa;
    }
    void xuat()
    {
        MBA1::xuat();
        cout << "dien ap vao: " << dienApVao << endl;
        cout << "dien ap ra: " << dienApRa << endl;
    }

    double tinhTiSoBienAp(){ if(dienApVao==0) return 0; return dienApRa/dienApVao; }
    bool operator<(MBA2 a){ return tinhTiSoBienAp() < a.tinhTiSoBienAp(); }

};

int main()
{
    int n;
    cout << "Nhap so luong MBA: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    MBA2 *ds = new MBA2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap MBA thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i] < ds[j]){ MBA2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach MBA giam dan theo ti so bien ap" << endl;
    for(int i=0;i<n;i++){ cout << "\nMBA thu " << i+1 << endl; ds[i].xuat(); cout << "Ti so bien ap: " << ds[i].tinhTiSoBienAp() << endl; }

    delete[] ds;
    return 0;
}
