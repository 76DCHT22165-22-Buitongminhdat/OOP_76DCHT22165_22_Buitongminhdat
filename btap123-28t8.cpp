#include<iostream>
using namespace std;

class MaTran{
	private:
		int n, m;
		int a[100][100];
	public:
		MaTran(){
			n = 0;
			m = 0;
		}
		void nhap(){
			cout <<"nhap so hang : ";
			cin >> n;
			cout <<"nhap so cot : ";
			cin >> m;
			
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					cout<<"a["<<i<<"]["<<j<<"] = ";
					cin >> a[i][j];
				}
			}
		}
		void xuat(){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					cout <<a[i][j]<< "\t";
				}
				cout<<endl;
			}
		}
		friend MaTran congmatran(MaTran m1, MaTran m2);
};
MaTran congmatran(MaTran m1, MaTran m2){
	MaTran  kq;
	kq.n = m1.n;
	kq.m = m1.m;
		
	
	for(int i = 0; i<m1.n; i++){
		for(int j = 0; j<m1.m; j++){
			kq.a[i][j] = m1.a[i][j] + m2.a[i][j];
		}
	}
	return kq;
}

int main(){
	MaTran m1, m2, mtong;
	cout<<"nhap ma tran 1\n";
	m1.nhap();
	cout<<"nhap ma tran 2\n";
	m2.nhap();
	mtong = congmatran(m1, m2);
	cout<<" ma tran 1\n";
	m1.xuat();
	cout<<" ma tran 2\n";
	m2.xuat();
	cout<<" tong 2 mtran\n";
	mtong.xuat();
	return 0;
}
