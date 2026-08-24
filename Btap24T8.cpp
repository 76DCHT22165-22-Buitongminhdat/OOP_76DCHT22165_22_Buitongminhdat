#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    // Constructor không đối
    NhanVien() {
        maNV = "";
        hoTen = "";
        ngaySinh = "";
        diaChi = "";
    }

    // Constructor có đối
    NhanVien(string ma, string ten, string ns, string dc) {
        maNV = ma;
        hoTen = ten;
        ngaySinh = ns;
        diaChi = dc;
    }

    // Phương thức xuất thông tin theo dạng 1 dòng (để in dạng cột)
    void xuatHang() const {
        cout << left 
             << setw(15) << maNV 
             << setw(25) << hoTen 
             << setw(15) << ngaySinh 
             << setw(30) << diaChi << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); // Xoá bộ đệm sau khi nhập n

    // Cấp phát mảng động
    NhanVien* dsNhanVien = new NhanVien[n];

    // Nhập dữ liệu và dùng Constructor có đối để đưa vào mảng
    cout << "\n=== NHAP THONG TIN DANH SACH NHAN VIEN ===" << endl;
    for (int i = 0; i < n; i++) {
        string ma, ten, ns, dc;
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---" << endl;
        cout << "Nhap ma NV: ";
        getline(cin, ma);
        cout << "Nhap ho ten: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ns);
        cout << "Nhap dia chi: ";
        getline(cin, dc);

        // Khởi tạo đối tượng bằng Constructor có đối và gán vào mảng
        dsNhanVien[i] = NhanVien(ma, ten, ns, dc);
    }

    // Xuất dữ liệu nhân viên theo cột
    cout << "\n================================ DANH SACH NHAN VIEN ================================" << endl;
    cout << left 
         << setw(15) << "Ma NV" 
         << setw(25) << "Ho Ten" 
         << setw(15) << "Ngay Sinh" 
         << setw(30) << "Dia Chi" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < n; i++) {
        dsNhanVien[i].xuatHang();
    }

    // Giải phóng bộ nhớ
    delete[] dsNhanVien;
    dsNhanVien = nullptr;

    return 0;
}
