#include<bits\stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

class phanso{
private:
	int tu;
	int mau;
public:
	phanso(){
		tu = 0;
		mau = 1;
	}
	phanso(int tu, int mau){
		this->tu = tu;
		this->mau = mau;
		rutgon();
	}
	~phanso(){};
	void rutgon(){
		int l = gcd(tu,mau);
		tu /= l;
		mau /= l;
	}
	friend istream& operator >> (istream& in, phanso &p);
	friend ostream& operator << (ostream& out, const phanso &p);
	friend phanso operator + (const phanso &a, const phanso &b);
	friend phanso operator - (const phanso &a, const phanso &b);
	friend phanso operator * (const phanso &a, const phanso &b);
	friend phanso operator / (const phanso &a, const phanso &b);
};
istream& operator >> (istream& in, phanso &p){
	cout << "nhap tu so : ";
	in >> p.tu;
	cout << "nhap mau so : ";
	in >> p.mau;
	while(p.mau == 0){
		cout << "nhap mau so khac 0 !";
		in >> p.mau;
	}
	p.rutgon();
	return in;
}
ostream& operator << (ostream& out, const phanso &p){
	if(p.mau == 1) cout << p.tu <<endl;
	else if (p.tu < 0 && p.mau < 0) cout << abs(p.tu) << "/" << abs(p.mau) << endl;
	else if (p.tu > 0 && p.mau < 0) cout << (-1)*p.tu << "/" << abs(p.mau) << endl;
	else if (p.tu == p.mau) cout << "1" << endl;
	else cout << p.tu << "/" << p.mau << endl;
	return out; 
}
phanso operator + (const phanso &a, const phanso &b){
	return phanso(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
}
phanso operator - (const phanso &a, const phanso &b){
	return phanso(a.tu * b.mau - b.tu * a.mau, a.mau * b.mau);
}
phanso operator * (const phanso &a, const phanso &b){
	return phanso(a.tu * b.tu, a.mau * b.mau);
}
phanso operator / (const phanso &a, const phanso &b){
	return phanso(a.tu * b.mau , a.mau * b.tu);
}
int main(){
	phanso a, b;
	cout << "nhap phan so thu nhat : \n";
	cin >> a;
	cout << "nhap phan so thu hai : \n";
	cin >> b;
	cout << "tong 2 phan so : " << a + b << endl;
	cout << "hieu phan so : " << a - b << endl;
	cout << "tich 2 phan so : " << a * b << endl;
	cout << "thuong 2 phan so : " << a / b << endl;
	return 0;
}
