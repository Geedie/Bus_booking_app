#include"QuanLyTK.h"

using namespace std;

class Lenh {
public:
    virtual void ThucHien() = 0;
    virtual ~Lenh() {}
};

class LenhCapNhatNguoiDung : public Lenh {
private:
    User& NguoiDung;
    string TenMoi;
    string SoDienThoaiMoi;
    string EmailMoi;

public:
    LenhCapNhatNguoiDung(User& usr, const string& hoTen, const string& soDienThoai, const string& email)
        : NguoiDung(usr), TenMoi(hoTen), SoDienThoaiMoi(soDienThoai), EmailMoi(email) {}

    void ThucHien() override {
        NguoiDung.setHoTen(TenMoi);
        NguoiDung.setSoDienThoai(SoDienThoaiMoi);
        NguoiDung.setEmail(EmailMoi);
        cout << "> Thong tin nguoi dung da duoc cap nhat." << endl;
    }
};

class QuanLyLenh {
private:
    vector<Lenh*> DanhSachLenh;

public:
    void ThemLenh(Lenh* lenh) {
        DanhSachLenh.push_back(lenh);
    }

    void ThucHienTatCaLenh() {
        for (auto& lenh : DanhSachLenh) {
            lenh->ThucHien();
        }
    }

    ~QuanLyLenh() {
        for (auto cmd : DanhSachLenh) {
            delete cmd;
        }
    }
};

void TaiNguoiDung(const string& TenFile, vector<User>& NguoiDungs) {
    ifstream file(TenFile);
    string line;

    while (getline(file, line)) {
        string TenDangNhap, MatKhau;
        istringstream iss(line);
        iss >> TenDangNhap >> MatKhau;

        if (getline(file, line)) {
            string HoTen, SoDienThoai, Email;
            istringstream issChiTiet(line);
            issChiTiet >> HoTen >> SoDienThoai >> Email;
            NguoiDungs.emplace_back(HoTen, SoDienThoai, Email);
        }
    }
}

void QLTK(vector<User> DanhSachNguoiDung) {
    QuanLyLenh QuanLyLenh;

    TaiNguoiDung("ttKhachHang.txt", DanhSachNguoiDung);

    for (const auto& NguoiDung : DanhSachNguoiDung) {
        NguoiDung.displayDetails();
    }

    if (!DanhSachNguoiDung.empty()) {
        QuanLyLenh.ThemLenh(new LenhCapNhatNguoiDung(DanhSachNguoiDung[0],
            "Nguyen Van B", "0123456789", "nvb@example.com"));
        QuanLyLenh.ThucHienTatCaLenh();

        DanhSachNguoiDung[0].displayDetails();
    }
}