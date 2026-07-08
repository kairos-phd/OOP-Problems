#include <bits/stdc++.h>

using namespace std;

class CamBien1
{
protected:
    string maCamBien;
    string tenCamBien;
    double giaTriDo;
    double nguongCanhBao;

public:
    CamBien1()
    {
        maCamBien = "";
        tenCamBien = "";
        giaTriDo = 0;
        nguongCanhBao = 0;
    }

    void nhap()
    {
        cout << "Nhap ma cam bien: "; cin >> maCamBien;
        cout << "Nhap ten cam bien: "; cin >> tenCamBien;
        cout << "Nhap gia tri do: "; cin >> giaTriDo;
        cout << "Nhap nguong canh bao: "; cin >> nguongCanhBao;
    }

    void xuat()
    {
        cout << "ma cam bien: " << maCamBien << endl;
        cout << "ten cam bien: " << tenCamBien << endl;
        cout << "gia tri do: " << giaTriDo << endl;
        cout << "nguong canh bao: " << nguongCanhBao << endl;
        cout << "Gia tri so sanh: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        return giaTriDo;
    }

    bool kiemTra(){ return giaTriDo >= nguongCanhBao; }

};

class CamBien2 : public CamBien1
{
public:
    CamBien2 operator=(CamBien2 a)
    {
        maCamBien = a.maCamBien;
        tenCamBien = a.tenCamBien;
        giaTriDo = a.giaTriDo;
        nguongCanhBao = a.nguongCanhBao;
        return *this;
    }

    bool operator>(CamBien2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong cam bien toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    CamBien2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap cam bien thu " << i+1 << endl;
        ds[i].nhap();
    }
    bool co=false;
    cout << "\nDanh sach canh bao:" << endl;
    for(int i=0;i<n;i++) if(ds[i].kiemTra()) { co=true; ds[i].xuat(); }
    if(!co) cout << "Khong co doi tuong nao" << endl;
    return 0;
}
