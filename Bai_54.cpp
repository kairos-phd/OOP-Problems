#include <iostream>

using namespace std;

class time1
{
protected:
    int gio;
    int phut;
    int giay;

public:
    time1()
    {
        gio = 0;
        phut = 0;
        giay = 0;
    }

    void nhap()
    {
        cout << "Nhap gio: ";
        cin >> gio;

        cout << "Nhap phut: ";
        cin >> phut;

        cout << "Nhap giay: ";
        cin >> giay;
    }

    void xuat()
    {
        cout << gio << " gio "
             << phut << " phut "
             << giay << " giay";
    }
};

class time2 : public time1
{
private:
    int ngay;

public:
    time2() : time1()
    {
        ngay = 0;
    }

    void nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay;

        time1::nhap();

        chuanHoa();
    }

    void xuat()
    {
        cout << ngay << " ngay ";
        time1::xuat();
    }

    void chuanHoa()
    {
        phut = phut + giay / 60;
        giay = giay % 60;

        gio = gio + phut / 60;
        phut = phut % 60;

        ngay = ngay + gio / 24;
        gio = gio % 24;
    }

    time2 operator + (time2 b)
    {
        time2 kq;

        kq.ngay = ngay + b.ngay;
        kq.gio = gio + b.gio;
        kq.phut = phut + b.phut;
        kq.giay = giay + b.giay;

        kq.chuanHoa();

        return kq;
    }
};

int main()
{
    time2 n, m, kq;

    cout << "Nhap thoi gian n:" << endl;
    n.nhap();

    cout << "\nNhap thoi gian m:" << endl;
    m.nhap();

    kq = n + m;

    cout << "\nKet qua n + m = ";
    kq.xuat();

    return 0;
}
