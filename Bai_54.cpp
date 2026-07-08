#include <bits/stdc++.h>
using namespace std;
class time1{protected:int gio,phut,giay;public:time1(){gio=0;phut=0;giay=0;}void nhap(){cout<<"Nhap gio: ";cin>>gio;cout<<"Nhap phut: ";cin>>phut;cout<<"Nhap giay: ";cin>>giay;}void chuanHoa(){phut+=giay/60;giay%=60;gio+=phut/60;phut%=60;}void xuat(){cout<<gio<<" gio "<<phut<<" phut "<<giay<<" giay";}};
class time2:public time1{private:int ngay;public:time2():time1(){ngay=0;}void nhap(){cout<<"Nhap ngay: ";cin>>ngay;time1::nhap();chuanHoaNgay();}void chuanHoaNgay(){chuanHoa();ngay+=gio/24;gio%=24;}void xuat(){cout<<ngay<<" ngay ";time1::xuat();cout<<endl;}time2 operator+(time2 a){time2 kq;kq.ngay=ngay+a.ngay;kq.gio=gio+a.gio;kq.phut=phut+a.phut;kq.giay=giay+a.giay;kq.chuanHoaNgay();return kq;}};
int main(){time2 n,m,kq;cout<<"Nhap thoi gian n"<<endl;n.nhap();cout<<"\nNhap thoi gian m"<<endl;m.nhap();kq=n+m;cout<<"\nKet qua n + m: ";kq.xuat();return 0;}
