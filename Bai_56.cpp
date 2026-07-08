#include <bits/stdc++.h>

using namespace std;

class RELAY1
{
protected:
    string maRelay;
    string loaiRelay;
    double thoiGianTacDong;

public:
    RELAY1()
    {
        maRelay = "";
        loaiRelay = "";
        thoiGianTacDong = 0;
    }
    void nhap()
    {
        cout << "Nhap ma relay: "; cin >> maRelay;
        cout << "Nhap loai relay: "; cin >> loaiRelay;
        cout << "Nhap thoi gian tac dong: "; cin >> thoiGianTacDong;
    }
    void xuat()
    {
        cout << "ma relay: " << maRelay << endl;
        cout << "loai relay: " << loaiRelay << endl;
        cout << "thoi gian tac dong: " << thoiGianTacDong << endl;
    }
};

class RELAY2 : public RELAY1
{
private:
    double dongDienTacDong;

public:
    RELAY2() : RELAY1()
    {
        dongDienTacDong = 0;
    }
    void nhap()
    {
        RELAY1::nhap();
        cout << "Nhap dong dien tac dong: "; cin >> dongDienTacDong;
    }
    void xuat()
    {
        RELAY1::xuat();
        cout << "dong dien tac dong: " << dongDienTacDong << endl;
    }

    bool operator<(RELAY2 a){ return dongDienTacDong < a.dongDienTacDong; }

};

int main()
{
    int n;
    cout << "Nhap so luong RELAY: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    RELAY2 *ds = new RELAY2[n];
    for(int i=0;i<n;i++){ cout << "\nNhap RELAY thu " << i+1 << endl; ds[i].nhap(); }
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(ds[i] < ds[j]){ RELAY2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach RELAY giam dan theo dong dien tac dong" << endl;
    for(int i=0;i<n;i++){ cout << "\nRELAY thu " << i+1 << endl; ds[i].xuat(); }

    delete[] ds;
    return 0;
}
