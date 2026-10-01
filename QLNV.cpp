#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// 1. Lop Nguoi
class Nguoi {
protected:
    string hoten;
    int namsinh;
public:
    Nguoi(string hoten = "", int namsinh = 0) : hoten(hoten), namsinh(namsinh) {}
    
    virtual void xuat() const {
        cout << "Ho ten : " << hoten << " | Nam sinh : " << namsinh;
    }
    virtual ~Nguoi() {}
};

// 2. Lop truu tuong Nhanvien (ke thua lop Nguoi)
class Nhanvien : virtual public Nguoi {
protected:
    string mnv;
    double lcb;
public:
    Nhanvien(string hoten = "", int namsinh = 0, string mnv = "", double lcb = 0.0)
        : Nguoi(hoten, namsinh), mnv(mnv), lcb(lcb) {}
    
    void xuat() const override {
        Nguoi::xuat();
        cout << " | Ma NV : " << mnv << " | Luong co ban : " << fixed << setprecision(0) << lcb;
    }
    
    virtual double tinhluong() const = 0;
};

// 3. Lop Quanly (ke thua lop Nguoi)
class Quanly : virtual public Nguoi {
protected:
    double phucapquanly;
public:
    Quanly(string hoten = "", int namsinh = 0, double phucapquanly = 0.0)
        : Nguoi(hoten, namsinh), phucapquanly(phucapquanly) {}
    
    void xuat() const override {
        Nguoi::xuat();
        cout << " | Phu cap QL : " << fixed << setprecision(0) << phucapquanly;
    }
};

// 4. Lop Nhanvienvanphong (ke thua lop Nhanvien) 
class Nhanvienvanphong : public Nhanvien {
private:
    int so_ngaylamviec;
public:
    Nhanvienvanphong(string hoten = "", int namsinh = 0, string mnv = "", double lcb = 0.0, int so_ngaylamviec = 0)
        : Nguoi(hoten, namsinh), Nhanvien(hoten, namsinh, mnv, lcb), so_ngaylamviec(so_ngaylamviec) {}
    
    // Đổi kiểu trả về thành double
    double tinhluong() const override {
        return lcb + so_ngaylamviec * 200000.0;
    }
    
    void xuat() const override {
        Nhanvien::xuat();
        cout << " | So ngay lam viec : " << so_ngaylamviec
             << " | Tong luong : " << fixed << setprecision(0) << tinhluong() << endl;
    }    
};

// 5. Lop Nhanvienkinhdoanh (ke thua lop Nhanvien)
class Nhanvienkinhdoanh : public Nhanvien {
private:
    double doanhso;
public:
    Nhanvienkinhdoanh(string hoten = "", int namsinh = 0, string mnv = "", double lcb = 0.0, double doanhso = 0.0)
        : Nguoi(hoten, namsinh), Nhanvien(hoten, namsinh, mnv, lcb), doanhso(doanhso) {}
    
    double tinhluong() const override {
        return lcb + doanhso * 0.1;
    }
    
    void xuat() const override {
        Nhanvien::xuat();
        cout << " | Doanh so ban hang : " << fixed << setprecision(0) << doanhso 
             << " | Tong luong : " << tinhluong() << endl; 
    }    
};

// 6. Lop Truongphong (ke thua lop NV va QLy)
class Truongphong : public Nhanvien, public Quanly {
private:
    int sonamkinhnghiem;
public:
    Truongphong(string hoten = "", int namsinh = 0, string mnv = "", double lcb = 0.0, double phucapquanly = 0.0, int sonamkinhnghiem = 0)
        : Nguoi(hoten, namsinh),
          Nhanvien(hoten, namsinh, mnv, lcb),
          Quanly(hoten, namsinh, phucapquanly),
          sonamkinhnghiem(sonamkinhnghiem) {}
    
    double tinhluong() const override {
        return lcb + phucapquanly + sonamkinhnghiem * 500000.0;
    }
    
    void xuat() const override {
        Nhanvien::xuat();
        cout << " | Phu cap QL : " << fixed << setprecision(0) << phucapquanly
             << " | So nam kinh nghiem : " << sonamkinhnghiem
             << " | Tong luong : " << tinhluong() << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien : ";
    cin >> n;
    Nhanvien **ds = new Nhanvien*[n];
    
    for(int i = 0; i < n; i++) {
        cout << "\n- Nhap thong tin cho nhan vien thu " << i + 1 << endl;
        int loai;
        cout << "1.NV van phong || 2.NV kinh doanh || 3. Truong phong : ";
        cin >> loai;
        while(loai < 1 || loai > 3) {
            cout << "Vui long nhap lai !!!: ";
            cin >> loai;
        }
        cin.ignore();
        
        string hoten, mnv;
        int namsinh;
        double lcb;
        
        cout << "- Nhap ho ten : ";   getline(cin, hoten);
        cout << "- Nhap MNV : ";      getline(cin, mnv);
        cout << "- Nhap nam sinh : ";  cin >> namsinh;
        cout << "- Nhap luong co ban : "; cin >> lcb;
        
        // 1. Van phong
        if(loai == 1) {
            int so_ngaylamviec;
            cout << "- Nhap so ngay lam : "; cin >> so_ngaylamviec;
            ds[i] = new Nhanvienvanphong(hoten, namsinh, mnv, lcb, so_ngaylamviec);
        }
        // 2. Kinh doanh
        else if(loai == 2) {
            double doanhso;
            cout << "- Nhap doanh so : "; cin >> doanhso;
            ds[i] = new Nhanvienkinhdoanh(hoten, namsinh, mnv, lcb, doanhso);
        }
        // 3. Truong phong
        else if(loai == 3) {
            double phucapquanly;
            int sonamkinhnghiem;
            cout << "- Nhap phu cap QL : "; cin >> phucapquanly;
            cout << "- Nhap so nam kinh nghiem : "; cin >> sonamkinhnghiem; 
            ds[i] = new Truongphong(hoten, namsinh, mnv, lcb, phucapquanly, sonamkinhnghiem);
        }
    }
    
    cout << "\n====================== DANH SACH NHAN VIEN ======================\n" << endl;
    for(int i = 0; i < n; i++) {
        ds[i]->xuat();
    }
        
    // Giai phong vung nho
    for(int i = 0; i < n; i++) {
        delete ds[i];
    }
    delete[] ds;
    return 0;
}
