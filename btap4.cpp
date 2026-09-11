#include<bits/stdc++.h>
using namespace std;
class sophuc{
private:
	float thuc;
	float ao;
public:
	sophuc(){
		thuc = 0;
		ao = 0;
	}
	sophuc(float thuc, float ao){
		this->thuc = thuc;
		this->ao = ao;
	}
	~sophuc(){};
	friend istream& operator >> (istream& in, sophuc &a);
	friend ostream& operator << (ostream& out, const sophuc &a);
	friend sophuc operator + (const sophuc &a,const sophuc &b);
	friend sophuc operator - (const sophuc &a,const sophuc &b);
	friend sophuc operator * (const sophuc &a,const sophuc &b);
	friend sophuc operator / (const sophuc &a,const sophuc &b);
};
istream& operator >> (istream& in, sophuc &a){
	cout << "nhap phan thuc : ";
	in >> a.thuc;
	cout << "nhap phan ao : ";
	in >> a.ao;
	return in;
}
ostream& operator << (ostream& out, const sophuc &a){
	if(a.ao < 0)out << a.thuc << a.ao << "*i" << endl; 
	if(a.ao > 0)out << a.thuc << "+" << a.ao << "*i" << endl; 
	return out;
}
sophuc operator + (const sophuc &a,const sophuc &b){
	return sophuc(a.thuc + b.thuc , a.ao + b.ao);
}
sophuc operator - (const sophuc &a,const sophuc &b){
	return sophuc(a.thuc - b.thuc, a.ao - b.ao); 
}
sophuc operator * (const sophuc &a,const sophuc &b){
	return sophuc(a.thuc * b.thuc - a.ao * b.ao, a.thuc * b.ao + a.ao * b.thuc); 
}
sophuc operator / (const sophuc &a,const sophuc &b){
	return sophuc((a.thuc * b.thuc + a.ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao), (a.thuc * b.ao - a.ao * b.thuc) / (b.thuc * b.thuc + b.ao * b.ao)); 
}
int main(){
	sophuc a, b;
	cin >> a;
	cin >> b;
	cout << a + b <<endl;
	cout << a - b <<endl;
	cout << a * b <<endl;
	cout << a / b <<endl;
	return 0;
}
