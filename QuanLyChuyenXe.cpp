#include"ChuyenXe.h"
#pragma once



// Danh sách các chuyến xe
vector<ChuyenXe> danhSachChuyenXe;

// Hàm tạo mã chuyến xe tự động
string taoMaChuyenXe() {
    return "CX" + to_string(danhSachChuyenXe.size() + 1); //CX<STT>
}

// Thêm chuyến xe mới
void themChuyenXe() {
    string diemDi, diemDen, ngayGioKhoiHanh, bienSo, loaiXe;
    double giaVeCoBan;
    int soChoNgoi;
    map<string, double> tienIch;

    cout << "Nhập điểm đi: ";
    cin >> diemDi;
    cout << "Nhập điểm đến: ";
    cin >> diemDen;
    cout << "Nhập ngày giờ khởi hành: ";
    cin >> ngayGioKhoiHanh;
    cout << "Nhập giá vé cơ bản: ";
    cin >> giaVeCoBan;
    cout << "Nhập biển số xe: ";
    cin >> bienSo;
    cout << "Nhập loại xe: ";
    cin >> loaiXe;
    cout << "Nhập số chỗ ngồi: ";
    cin >> soChoNgoi;

    int soTienIch;
    cout << "Nhập số lượng tiện ích: ";
    cin >> soTienIch;

    for (int i = 0; i < soTienIch; ++i) {
        string tenTienIch;
        double giaTienIch;
        cout << "Nhập tiện ích " << i + 1 << ": ";
        cin >> tenTienIch;
        cout << "Nhập giá tiện ích " << i + 1 << ": ";
        cin >> giaTienIch;
        tienIch[tenTienIch] = giaTienIch;
    }

    Xe xe(bienSo, loaiXe, soChoNgoi, tienIch);
    string maChuyenXe = taoMaChuyenXe();
    ChuyenXe chuyenXe(maChuyenXe, diemDi, diemDen, ngayGioKhoiHanh, giaVeCoBan, soChoNgoi);
    danhSachChuyenXe.push_back(chuyenXe);

    cout << "Thêm chuyến xe thành công với mã: " << maChuyenXe << endl;
}

// Chỉnh sửa thông tin chuyến xe
void suaChuyenXe() {
    string maChuyenXe;
    cout << "Nhập mã chuyến xe cần chỉnh sửa: ";
    cin >> maChuyenXe;

    for (auto& chuyenXe : danhSachChuyenXe) {
        if (chuyenXe.getMaChuyenXe() == maChuyenXe) {
            cout << "Chỉnh sửa thông tin chuyến xe (để trống nếu không muốn thay đổi):\n";

            cout << "Điểm đi hiện tại (" << chuyenXe.getDiemDi() << "): ";
            string diemDi;
            cin.ignore();
            getline(cin, diemDi);
            if (!diemDi.empty()) chuyenXe.setDiemDi(diemDi);

            cout << "Điểm đến hiện tại (" << chuyenXe.getDiemDen() << "): ";
            string diemDen;
            getline(cin, diemDen);
            if (!diemDen.empty()) chuyenXe.setDiemDen(diemDen);

            cout << "Ngày giờ khởi hành hiện tại (" << chuyenXe.getNgayGioKhoiHanh() << "): ";
            string ngayGioKhoiHanh;
            getline(cin, ngayGioKhoiHanh);
            if (!ngayGioKhoiHanh.empty()) chuyenXe.setNgayGioKhoiHanh(ngayGioKhoiHanh);

            cout << "Giá vé cơ bản hiện tại (" << chuyenXe.getGiaVeCoBan() << "): ";
            double giaVeCoBan;
            cin >> giaVeCoBan;
            if (giaVeCoBan > 0) chuyenXe.setGiaVeCoBan(giaVeCoBan);

            cout << "Chỉnh sửa thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy chuyến xe với mã " << maChuyenXe << endl;
}

// Xóa chuyến xe
void xoaChuyenXe() {
    string maChuyenXe;
    cout << "Nhập mã chuyến xe cần xóa: ";
    cin >> maChuyenXe;

    for (auto it = danhSachChuyenXe.begin(); it != danhSachChuyenXe.end(); ++it) {
        if (it->getMaChuyenXe() == maChuyenXe) {
            danhSachChuyenXe.erase(it);
            cout << "Xóa chuyến xe thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy chuyến xe với mã " << maChuyenXe << endl;
}

// Hàm chính
void QLCX () {
    int choice;
    do {
        cout << endl << "Quản lý chuyến xe: " << endl;
        cout << "1. Thêm chuyến xe mới" << endl;
        cout << "2. Chỉnh sửa thông tin chuyến xe" << endl;
        cout << "3. Xóa chuyến xe" << endl;
        cout << "0. Thoát" << endl;
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice) {
        case 1:
            themChuyenXe();
            break;
        case 2:
            suaChuyenXe();
            break;
        case 3:
            xoaChuyenXe();
            break;
        case 0:
            cout << "Thoát chương trình." << endl;
            break;
        default:
            cout << "Lựa chọn không hợp lệ." << endl;
        }
    } while (choice != 0);

    return;
}
