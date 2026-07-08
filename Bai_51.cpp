#include <bits/stdc++.h>
using namespace std;
class PHANSO{protected:int tuSo,mauSo;public:PHANSO(){tuSo=0;mauSo=1;}void nhap(){cout<<"Nhap tu so: ";cin>>tuSo;cout<<"Nhap mau so: ";cin>>mauSo;if(mauSo==0)mauSo=1;}void xuat(){cout<<tuSo<<"/"<<mauSo;}};
class HONSO:public PHANSO{private:int phanNguyen;double giaTri(){return phanNguyen+(double)tuSo/mauSo;}public:HONSO():PHANSO(){phanNguyen=0;}void nhap(){cout<<"Nhap phan nguyen: ";cin>>phanNguyen;PHANSO::nhap();}void xuat(){cout<<phanNguyen<<" ";PHANSO::xuat();cout<<endl;}HONSO operator++(){phanNguyen++;return *this;}bool operator>(HONSO a){return giaTri()>a.giaTri();}};
int main(){HONSO a,b;cout<<"Nhap hon so a"<<endl;a.nhap();cout<<"\nNhap hon so b"<<endl;b.nhap();++b;cout<<"\nHon so b sau khi tang 1 phan nguyen: ";b.xuat();if(a>b)cout<<"a lon hon b sau khi tang"<<endl;else cout<<"a khong lon hon b sau khi tang"<<endl;return 0;}
