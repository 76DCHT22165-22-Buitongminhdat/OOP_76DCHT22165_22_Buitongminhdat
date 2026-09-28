#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//class SP1
class SP1{
protected:
	float thuc;
	float ao;
public:
	SP1(){
		thuc = 0;
		ao = 0;
	}
	SP1(float thuc, float ao){
		this->thuc = thuc;
		this->ao = ao;	
	}
	//nhap
	void nhap(){
		cout << "nhap phan thuc : ";
		cin >> thuc;
		cout << "nhap phan ao : ";
		cin >> ao;
	}
	
	//xuat
	void xuat() const{
		if(ao >= 0) cout << thuc << " + " << ao << "i" << endl;
		else cout << thuc << ao << "i" << endl;
	}
	
	float module() const{
		return sqrt(thuc*thuc + ao*ao);
	}
};
//SP2 ke thua SP1
class SP2 : public SP1{
public:
	SP2() : SP1() {}
	SP2(float thuc, float ao) : SP1(thuc, ao){}
	
	//phep gan
	SP2& operator = (const SP2& sp){
		if(this != &sp){
			this->thuc = sp.thuc;
			this->ao = sp.ao;
		}
		return *this;
	}
	
	//toan tu >
	bool operator > (const SP2& sp) const{
		return this-> module() > sp.module();
	}
};

int main(){
	int n;
	cin >> n;
	while(n <= 0 || n > 10){
		cout << "nhap lai : ";
		cin >> n;
	}
	SP2 ds[10];
	
	for(int i = 0; i < n; i++){
		ds[i].nhap();
	}
	for(int i = 0; i < n - 1 ; i++){
		for(int j = i + 1; j < n; j++){
			if(!(ds[i] > ds[j])){
				SP2 temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		ds[i].xuat();
	}
	return 0;
}
