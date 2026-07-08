#include <iostream>
#include <cstdlib>

using namespace std;

int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

class PHANSO
{
protected:
    int tu;
    int mau;

public:
    PHANSO()
    {
        tu = 0;
        mau = 1;
    }

    void nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tu;

        do
        {
            cout << "Nhap mau so: ";
            cin >> mau;

            if (mau == 0)
            {
                cout << "Mau so phai khac 0. Nhap lai!" << endl;
            }
        }
        while (mau == 0);
    }

    void xuat()
    {
        cout << tu << "/" << mau;
    }

    void rutGon()
    {
        int u = ucln(tu, mau);

        tu = tu / u;
        mau = mau / u;

        if (mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
    }
};

class HONSO : public PHANSO
{
private:
    int phanNguyen;

public:
    HONSO()
    {
        phanNguyen = 0;
        tu = 0;
        mau = 1;
    }

    void nhap()
    {
        cout << "Nhap phan nguyen: ";
        cin >> phanNguyen;

        PHANSO::nhap();
    }

    void xuat()
    {
        cout << phanNguyen << " ";
        PHANSO::xuat();
    }

    int doiThanhTuSo()
    {
        return phanNguyen * mau + tu;
    }

    HONSO operator ++ ()
    {
        phanNguyen++;
        return *this;
    }

    bool operator > (HONSO b)
    {
        int tu1 = doiThanhTuSo();
        int tu2 = b.doiThanhTuSo();

        return tu1 * b.mau > tu2 * mau;
    }
};

int main()
{
    HONSO a, b;

    cout << "Nhap hon so a:" << endl;
    a.nhap();

    cout << "\nNhap hon so b:" << endl;
    b.nhap();

    ++b;

    cout << "\nSau khi tang b len 1 phan nguyen, b = ";
    b.xuat();

    cout << endl;

    if (a > b)
    {
        cout << "a lon hon b sau khi tang" << endl;
    }
    else
    {
        cout << "a khong lon hon b sau khi tang" << endl;
    }

    return 0;
}
