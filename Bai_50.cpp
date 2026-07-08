#include <bits/stdc++.h>
using namespace std;
int UCLN(int a,int b){a=abs(a);b=abs(b);while(b!=0){int r=a%b;a=b;b=r;}return a==0?1:a;}
class PHANSO{protected:int tuSo,mauSo;public:PHANSO(){tuSo=0;mauSo=1;}void nhap(){cout<<"Nhap tu so: ";cin>>tuSo;cout<<"Nhap mau so: ";cin>>mauSo;if(mauSo==0)mauSo=1;}void xuat(){cout<<tuSo<<"/"<<mauSo;}};
class HONSO:public PHANSO{private:int phanNguyen;int tuGia(){return phanNguyen*mauSo+tuSo;}void gan(int tu,int mau){if(mau==0)mau=1;int u=UCLN(tu,mau);tu/=u;mau/=u;phanNguyen=tu/mau;tuSo=tu%mau;mauSo=mau;}public:HONSO():PHANSO(){phanNguyen=0;}void nhap(){cout<<"Nhap phan nguyen: ";cin>>phanNguyen;PHANSO::nhap();}void xuat(){cout<<phanNguyen<<" ";PHANSO::xuat();cout<<endl;}HONSO operator+(HONSO a){HONSO kq;int tu=tuGia()*a.mauSo+a.tuGia()*mauSo;int mau=mauSo*a.mauSo;kq.gan(tu,mau);return kq;}HONSO operator*(HONSO a){HONSO kq;int tu=tuGia()*a.tuGia();int mau=mauSo*a.mauSo;kq.gan(tu,mau);return kq;}};
int main(){HONSO a,b,c;cout<<"Nhap hon so a"<<endl;a.nhap();cout<<"\nNhap hon so b"<<endl;b.nhap();c=(a+b)*a;cout<<"\nKet qua c = (a + b) * a: ";c.xuat();return 0;}
