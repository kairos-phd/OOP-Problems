#include <bits/stdc++.h>

using namespace std;

class DIEM2
{
protected:
    double tungDo;
    double hoanhDo;

public:
    DIEM2()
    {
        tungDo = 0;
        hoanhDo = 0;
    }
    void nhap()
    {
        cout << "Nhap tung do: "; cin >> tungDo;
        cout << "Nhap hoanh do: "; cin >> hoanhDo;
    }
    void xuat()
    {
        cout << "tung do: " << tungDo << endl;
        cout << "hoanh do: " << hoanhDo << endl;
    }
};

class DIEM3 : public DIEM2
{
private:
    double caoDo;

public:
    DIEM3() : DIEM2()
    {
        caoDo = 0;
    }
    void nhap()
    {
        DIEM2::nhap();
        cout << "Nhap cao do: "; cin >> caoDo;
    }
    void xuat()
    {
        DIEM2::xuat();
        cout << "cao do: " << caoDo << endl;
    }

    double tinhKhoangCach(){ return sqrt(tungDo*tungDo + hoanhDo*hoanhDo + caoDo*caoDo); }

};

int main()
{
    int n;
    cout << "Nhap so luong DIEM: "; cin >> n;
    if(n <= 0){ cout << "So luong khong hop le" << endl; return 0; }
    DIEM3 *ds = new DIEM3[n];
    for(int i=0;i<n;i++){ cout << "\nNhap DIEM thu " << i+1 << endl; ds[i].nhap(); }
    int vt=0; for(int i=1;i<n;i++) if(ds[i].tinhKhoangCach() > ds[vt].tinhKhoangCach()) vt=i;
    cout << "\nDIEM xa goc toa do nhat:" << endl; ds[vt].xuat(); cout << "Khoang cach: " << ds[vt].tinhKhoangCach() << endl;

    delete[] ds;
    return 0;
}
