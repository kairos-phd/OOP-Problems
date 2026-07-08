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
        if (phanNguyen != 0)
        {
            cout << phanNguyen << " ";
        }

        PHANSO::xuat();
    }

    int doiThanhTuSo()
    {
        return phanNguyen * mau + tu;
    }

    HONSO operator + (HONSO b)
    {
        HONSO kq;

        int tu1 = doiThanhTuSo();
        int tu2 = b.doiThanhTuSo();

        kq.phanNguyen = 0;
        kq.tu = tu1 * b.mau + tu2 * mau;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }

    HONSO operator * (HONSO b)
    {
        HONSO kq;

        int tu1 = doiThanhTuSo();
        int tu2 = b.doiThanhTuSo();

        kq.phanNguyen = 0;
        kq.tu = tu1 * tu2;
        kq.mau = mau * b.mau;

        kq.rutGon();

        return kq;
    }
};

int main()
{
    HONSO a, b, c;

    cout << "Nhap hon so a:" << endl;
    a.nhap();

    cout << "\nNhap hon so b:" << endl;
    b.nhap();

    c = (a + b) * a;

    cout << "\nKet qua c = (a + b) * a = ";
    c.xuat();

    return 0;
}
