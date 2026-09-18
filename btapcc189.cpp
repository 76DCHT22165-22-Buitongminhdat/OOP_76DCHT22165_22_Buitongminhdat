#include<bits/stdc++.h>
using namespace std;

class nguoi{
protected:
	string hoten;
	int namsinh;
public:
	void nhap(){
		cout << "nhap ho va ten :";
		getline(cin, hoten);
		cout << "nhap nam sinh : ";
		cin >> namsinh;
		cin.ignore();	
	}
	void xuat() const{
		cout << "Ho ten : " << hoten << " " << "Nam sinh : " << namsinh << " ";
	}
	string getht() const{
		return hoten;
	}	 
};
class sinhvien : public nguoi{
private:
	string msv;
	float dtb;
public:
	void nhap(){
		nguoi :: nhap();
		cout << "nhap ma sinh vien : ";
		getline(cin, msv);
		cout << "nhap diem trung binh : ";
		cin >> dtb;
		cin.ignore();
	}
	void xuat() const{
		nguoi :: xuat();
		cout << "Ma sinh vien : " << msv << " " << "Diem trung binh : " << fixed << setprecision(2) << dtb << "\n";
	}
	string getmsv() const{
		return msv;
	}
};
int main(){
	int n;
	cout <<"nhap so luong sinh vien : ";
	cin >> n;
	cin.ignore();
	vector<sinhvien> ds(n);
	for(int i = 0; i < n; i++){
		ds[i].nhap();
	}
	for(auto it : ds){
		it.xuat();
	}
	string s;
	cout << "nhap ho ten hoac msv de tim kiem : ";
	getline(cin, s);
	bool ok = 0;
	for(int i = 0; i < n; i++){
		if(s == ds[i].getht() || s == ds[i].getmsv()){
			ds[i].xuat();
			ok = 1;
		}
	}
	if(!ok) cout << "ko tim thay !!!" << "\n";
	return 0;
}
