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
	cout <<"+ Vui long nhap ma so nhan vien : ";
	cin >> nv.manv;
	cin.ignore();
	cout <<"+ Vui long nhap ho va ten :  ";
	getline(cin, nv.tennv);
	cout <<"+ Vui long nhap muc luong co ban (kVND): ";
	cin >> nv.luongcoban;
	cout <<"+ Vui long nhap he so luong : ";
	cin >> nv.heso;
}

void xuat(int stt, NV nv){
	cout << stt 
		<< "\t" << nv.manv 
		<< "\t\t" << nv.tennv 
		<< "\t\t"<< nv.luongcoban 
		<< "\t\t"<< nv.heso << endl;
}
int main(){
	int n;
	cout <<"-----------------------------------------------"<<endl;	
	cout <<"    CHUONG TRING QUAN LY THONG TIN NHAN VIEN"<<endl;
	cout <<"-----------------------------------------------"<<endl;
	cout <<"Chao ban! Xin vui long nhap so luong nhan vien : ";
	cin  >> n;
	cout <<"-----------------------------------------------"<<endl;
	NV *ds = new NV[n];
	
	for(int i = 0; i < n; i++ ){
		cout <<"[->] Nhap thong tin cho nhan vien thu "<<i+1<<endl;
		nhap(ds[i]);
		cout <<"-----------------------------------------------"<<endl;
	}
	cout << "\n---DANH SACH NHAN VIEN---" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
    cout << "STT\tMa NV\t\tHo va Ten\t\tLuong CB\tHe so" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for(int i = 0; i < n; i++) {
        xuat(i+1, ds[i]); 
    }
	delete[] ds;
	return 0;
}
