#include <iostream>
#include <string>

using namespace std;

class LedDon
{
private:
    string maLed;
    string mauSac;
    double dienApKich;

public:
    LedDon()
    {
        maLed = "";
        mauSac = "";
        dienApKich = 0;
    }

    void nhap()
    {
        cout << "Nhap ma led: ";
        cin >> maLed;

        cout << "Nhap mau sac: ";
        cin >> mauSac;

        cout << "Nhap dien ap kich: ";
        cin >> dienApKich;
    }

    void xuat()
    {
        cout << "Ma led: " << maLed << endl;
        cout << "Mau sac: " << mauSac << endl;
        cout << "Dien ap kich: " << dienApKich << endl;
    }

    string getMauSac()
    {
        return mauSac;
    }
};

class ThanhLedChay
{
private:
    LedDon ds[8];

public:
    void nhap()
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "\nNhap thong tin led thu " << i + 1 << endl;
            ds[i].nhap();
        }
    }

    void xuat()
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "\nLed thu " << i + 1 << endl;
            ds[i].xuat();
        }
    }

    bool coLedDo()
    {
        for (int i = 0; i < 8; i++)
        {
            if (ds[i].getMauSac() == "Do" || ds[i].getMauSac() == "do" || ds[i].getMauSac() == "Đỏ")
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    ThanhLedChay thanhLed;

    cout << "Nhap thong tin thanh LED chay:" << endl;
    thanhLed.nhap();

    cout << "\nThong tin thanh LED chay:" << endl;
    thanhLed.xuat();

    if (thanhLed.coLedDo())
    {
        cout << "\nThanh LED co chua bong den mau Do" << endl;
    }
    else
    {
        cout << "\nThanh LED khong chua bong den mau Do" << endl;
    }

    return 0;
}
