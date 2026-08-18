#include <iostream>
#include <string>
using namespace std;

struct nhanvien {
	string manv;
	string tennv;
	double luongcoban;
	double heso;
};
int main(){
	int n;
	cout <<"nhap so luong nhan vien : ";
	cin >> n;
	
	nhanvien *ds = new nhanvien[n];
	delete[] ds;
	return 0;
}
