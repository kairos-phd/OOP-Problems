#include <bits/stdc++.h>

using namespace std;

class ADC1
{
protected:
    int kenhADC;
    int giaTriADC;
    int doPhanGiaiBit;
    double dienApThamChieu;

public:
    ADC1()
    {
        kenhADC = 0;
        giaTriADC = 0;
        doPhanGiaiBit = 0;
        dienApThamChieu = 0;
    }

    void nhap()
    {
        cout << "Nhap kenh ADC: "; cin >> kenhADC;
        cout << "Nhap gia tri ADC: "; cin >> giaTriADC;
        cout << "Nhap do phan giai bit: "; cin >> doPhanGiaiBit;
        cout << "Nhap dien ap tham chieu: "; cin >> dienApThamChieu;
    }

    void xuat()
    {
        cout << "kenh ADC: " << kenhADC << endl;
        cout << "gia tri ADC: " << giaTriADC << endl;
        cout << "do phan giai bit: " << doPhanGiaiBit << endl;
        cout << "dien ap tham chieu: " << dienApThamChieu << endl;
        cout << "Dien ap quy doi: " << tinhGiaTri() << endl;
    }

    double tinhGiaTri()
    {
        double maxADC = pow(2, doPhanGiaiBit) - 1; if(maxADC <= 0) return 0; return giaTriADC * dienApThamChieu / maxADC;
    }

};

class ADC2 : public ADC1
{
public:
    ADC2 operator=(ADC2 a)
    {
        kenhADC = a.kenhADC;
        giaTriADC = a.giaTriADC;
        doPhanGiaiBit = a.doPhanGiaiBit;
        dienApThamChieu = a.dienApThamChieu;
        return *this;
    }

    bool operator>(ADC2 a)
    {
        return tinhGiaTri() > a.tinhGiaTri();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong tin hieu ADC toi da 10: "; cin >> n;
    if(n <= 0 || n > 10)
    {
        cout << "So luong khong hop le" << endl;
        return 0;
    }
    ADC2 ds[10];
    for(int i=0;i<n;i++)
    {
        cout << "\nNhap tin hieu ADC thu " << i+1 << endl;
        ds[i].nhap();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ds[j] > ds[i]){ ADC2 tam=ds[i]; ds[i]=ds[j]; ds[j]=tam; }
    cout << "\nDanh sach giam dan" << endl;
    for(int i=0;i<n;i++){ cout << "\ntin hieu ADC thu " << i+1 << endl; ds[i].xuat(); }
    return 0;
}
