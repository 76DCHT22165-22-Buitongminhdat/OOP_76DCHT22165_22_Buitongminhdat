#include <bits\stdc++.h>
using namespace std;

class SINHVIEN {
private:
    string hoten;
    int namsinh;
    float diem[4];

public:
    SINHVIEN() : hoten(""), namsinh(0) {
        for (int i = 0; i < 4; i++) {
            diem[i] = 0.0;
        }
    }

    float tb() const {
        float tong = 0.0;
        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }
        return tong / 4;
    }

    friend istream& operator>>(istream& in, SINHVIEN &sv) {
        cout << "nhap ho va ten : ";
        getline(in, sv.hoten);
        cout << "nhap nam sinh : ";
        in >> sv.namsinh;
        for (int i = 0; i < 4; i++) {
            cout << "nhap diem thu " << i + 1 << ": ";
            in >> sv.diem[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream &out, const SINHVIEN &sv) {
        out << "Ho va ten: " << sv.hoten << " || Nam sinh: " << sv.namsinh << " || Diem TB: " << fixed << setprecision(2) << sv.tb();
        return out;
    }

    friend bool laTotNghiep(const SINHVIEN &sv) {
        for(int i = 0; i < 4; i++) {
            if(sv.diem[i] < 5.0) return false;
        }
        if(sv.tb() >= 7.0) return false;
        return true;
    }
};

int main() {
    int n;
    cout << "nhap so luong sv : ";
    cin >> n;
    
    SINHVIEN* ds = new SINHVIEN[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        cin.ignore();
        cin >> ds[i];
    }
    
    cout << "\n=== KET QUA KHACH QUAN TONG HOP ===\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i] << endl;
    }
    
    cout << "\nDANH SACH SINH VIEN DU DK TOT NGHIEP :\n";
    int tn = 0;
    for (int i = 0; i < n; i++) {
        if (laTotNghiep(ds[i])) {
            cout << ds[i] << "\n";
            tn++;
        }
    }
    if (tn == 0) cout << " (Khong co sinh vien nao thoa man)\n";
    
    cout << "\nDANH SACH SINH VIEN KHONG DU DK TOT NGHIEP:\n";
    int tr = 0;
    for (int i = 0; i < n; i++) {
        if (!laTotNghiep(ds[i])) {
            cout << ds[i] << "\n";
            tr++;
        }
    }
    if (tr == 0) cout << " (Khong co sinh vien nao)\n";
    
    delete[] ds;
    return 0;
}
