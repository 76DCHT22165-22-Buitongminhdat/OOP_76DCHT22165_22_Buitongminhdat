#include <iostream>
#include <string>
using namespace std;
struct nhanvien {
	string manv;
	string tennv;
	double luongcoban;
	double heso;
};
typedef struct nhanvien NV;

void nhap(NV &nv){
	cout <<"nhap ma so nhan vien : ";
	cin >> nv.manv;
	cin.ignore();
	cout <<"nhap ho va ten :  ";
	getline(cin, nv.tennv);
	cout <<"nhap muc luong co ban : ";
	cin >> nv.luongcoban;
	cout <<"nhap he so luong : ";
	cin >> nv.heso;
}

void xuat(NV nv){
	cout <<"MaNV : " <<nv.manv
		 <<" | Ten : " <<nv.tennv
		 <<" | Luong co ban : " <<nv.luongcoban
		 <<" | He so : " <<nv.heso <<endl;
}
int main(){
	int n;
	cout <<"nhap so luong nhan vien : ";
	cin >> n;
	
	nhanvien *ds = new nhanvien[n];
	
	for(int i = 0; i < n; i++ ){
		cout <<"Nhap thong tin cho nhan vien thu "<<i+1<<": "<<endl;
		nhap(ds[i]);
	}
	cout <<"\n--- DANH SACH NHAN VIEN---"<<endl;
	for(int i = 0 ; i<n; i++){
		xuat(ds[i]);
	}
	delete[] ds;
	return 0;
}
