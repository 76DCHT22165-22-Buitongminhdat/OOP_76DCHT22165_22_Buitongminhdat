#include <iostream>
#include <string>

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNV);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh : ";
        getline(cin, ngaySinh);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    void xuat() const {
        cout << "Ma NV: " << maNV 
			 << " | Ho ten: " << hoTen 
			 << " | Ngay sinh: " << ngaySinh 
			 << " | Dia chi: " << diaChi << endl;
    }
};

int main() {
    int n = 10;
    NhanVien* dsNhanVien = new NhanVien[n];

    cout << "=== NHAP DANH SACH " << n << " NHAN VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---" << endl;
        dsNhanVien[i].nhap();
    }

    cout << "=== DANH SACH THONG TIN " << n << " NHAN VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        dsNhanVien[i].xuat();
    }

    delete[] dsNhanVien;
    return 0;
}
