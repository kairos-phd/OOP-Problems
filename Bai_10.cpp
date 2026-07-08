#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
private:
    int gio;
    int phut;
    int giay;

public:
    Time()
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

        chuanHoa();
    }

    void chuanHoa()
    {
        phut = phut + giay / 60;
        giay = giay % 60;

        gio = gio + phut / 60;
        phut = phut % 60;

        gio = gio % 24;
    }

    Time operator ++ ()
    {
        giay++;

        chuanHoa();

        return *this;
    }

    void xuat()
    {
        cout << setfill('0') << setw(2) << gio << ":"
             << setfill('0') << setw(2) << phut << ":"
             << setfill('0') << setw(2) << giay << endl;
    }
};

int main()
{
    Time t;

    cout << "Nhap thoi gian:" << endl;
    t.nhap();

    cout << "\nThoi gian ban dau: ";
    t.xuat();

    ++t;

    cout << "Sau khi tang 1 giay: ";
    t.xuat();

    return 0;
}
