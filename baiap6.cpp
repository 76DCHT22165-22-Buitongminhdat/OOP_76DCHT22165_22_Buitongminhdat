#include <bits\stdc++.h>
using namespace std;

class SINHVIEN {
private:
    string hoten;
    int namsinh;
    double diem[5];

public:
    
    SINHVIEN() : hoten(""), namsinh(0) {
        for (int i = 0; i < 5; i++) {
            diem[i] = 0.0; 
        }
    }

    void nhap() {
        cin.ignore(); 
        cout << "nhap ho va ten : ";
        getline(cin, hoten);
        
        cout << "nhap nam sinh : ";
        cin >> namsinh;
        
        for (int i = 0; i < 5; i++) {
            cout << "nhap diem thu " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    double tb() const {
        double tong = 0.0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5; 
    }

    void xuat() const {
        cout << "Ho va ten: "<<hoten <<"||"<< "Nam sinh: " << namsinh << "||" << "Diem TB: " << fixed << setprecision(2) << tb() << endl;
    }

    void check() const {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5.0) {
                if (cnt == 0) {
                    cout << hoten << "||" << namsinh << "|| thi lai" << endl;
                    cout << "Cac mon thi lai: "<<endl;
                    cnt = 1;
                }
                cout << "mon " << i + 1 << " "; 
            }
            if(cnt == 1) cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "nhap so luong sv : ";
    cin >> n;
    SINHVIEN* ds = new SINHVIEN[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    cout << "\n=== KET QUA ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
    cout << "Danh sach thi lai :"<< endl;
	for (int i = 0; i < n; i++){
        ds[i].check();
    }
    delete[] ds;
    return 0;
}
