#include <bits/stdc++.h>

using namespace std;

class DoNong1
{
protected:
    string maThietBi;
    double nhietDoDoDuoc;
    double nguongThap;
    double nguongCao;

public:
    DoNong1()
    {
        maThietBi = "";
        nhietDoDoDuoc = 0;
        nguongThap = 0;
        nguongCao = 0;
    }

    void nhap()
    {
        cout << "Nhap ma thiet bi: "; cin >> maThietBi;
        cout << "Nhap nhiet do do duoc: "; cin >> nhietDoDoDuoc;
        cout << "Nhap nguong thap: "; cin >> nguongThap;
        cout << "Nhap nguong cao: "; cin >> nguongCao;
    }

    void xuat()
    {
        cout << "ma thiet bi: " << maThietBi << endl;
        cout << "nhiet do do duoc: " << nhietDoDoDuoc << endl;
        cout << "nguong thap: " << nguongThap << endl;
        cout << "nguong cao: " << nguongCao << endl;
        cout << "Nhiet do do duoc: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return nhietDoDoDuoc;
    }

    bool kiemTra(){ return nhietDoDoDuoc < nguongThap || nhietDoDoDuoc > nguongCao; }

};

class DoNong2 : public DoNong1
{
public:
    DoNong2 operator=(DoNong2 a)
    {
        maThietBi = a.maThietBi;
        nhietDoDoDuoc = a.nhietDoDoDuoc;
        nguongThap = a.nguongThap;
        nguongCao = a.nguongCao;
        return *this;
    }

    bool operator>(DoNong2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong thiet bi do toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    DoNong2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap thiet bi do thu " << i+1 << endl;
        ds[i].nhap();
    }
    bool co=false;
    cout << "\nDanh sach canh bao:" << endl;
    for(int i=0;i<n;i++) if(ds[i].kiemTra()) { co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co doi tuong nao" << endl;
    return 0;
}
