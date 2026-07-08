#include <bits/stdc++.h>
using namespace std;
class Time{private:int gio,phut,giay;public:Time(){gio=0;phut=0;giay=0;}void nhap(){cout<<"Nhap gio: ";cin>>gio;cout<<"Nhap phut: ";cin>>phut;cout<<"Nhap giay: ";cin>>giay;chuanHoa();}void chuanHoa(){int tong=gio*3600+phut*60+giay;tong=((tong%86400)+86400)%86400;gio=tong/3600;tong%=3600;phut=tong/60;giay=tong%60;}Time operator++(){giay++;chuanHoa();return *this;}Time operator--(){giay--;chuanHoa();return *this;}void xuat(){cout<<setfill('0')<<setw(2)<<gio<<":"<<setw(2)<<phut<<":"<<setw(2)<<giay<<setfill(' ')<<endl;}};
int main(){Time t;t.nhap();cout<<"Thoi gian sau khi chuan hoa: ";t.xuat();++t;cout<<"Sau khi tang 1 giay: ";t.xuat();--t;cout<<"Sau khi giam 1 giay: ";t.xuat();return 0;}
