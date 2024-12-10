#pragma once
#include"Xe.h"



// Danh sách các xe
vector<Xe> danhSachXe;

void themXe() {
    string bienSo, loaiXe;
    int soChoNgoi;
    map<string, double> tienIch;

    cout << "Nhập biển số xe: ";
    cin >> bienSo;
    cout << "Nhập loại xe (ghế ngồi/giường nằm): ";
    cin >> loaiXe;
    cout << "Nhập số chỗ ngồi: ";
    cin >> soChoNgoi;

    int soTienIch;
    cout << "Nhập số lượng tiện ích: ";
    cin >> soTienIch;
    for (int i = 0; i < soTienIch; ++i) {
        string tenTienIch;
        double giaTienIch;
        cout << "Nhập tên tiện ích " << i + 1 << ": ";
        cin >> tenTienIch;
        cout << "Nhập giá tiện ích " << i + 1 << ": ";
        cin >> giaTienIch;
        tienIch[tenTienIch] = giaTienIch;
    }

    Xe xe(bienSo, loaiXe, soChoNgoi, tienIch);
    danhSachXe.push_back(xe);

    cout << "Thêm xe thành công!" << endl;
}

// Chỉnh sửa thông tin xe
void suaXe() {
    string bienSo;
    cout << "Nhập biển số xe cần chỉnh sửa: ";
    cin >> bienSo;

    for (auto& xe : danhSachXe) {
        if (xe.getBienSo() == bienSo) {
            cout << "Chỉnh sửa thông tin xe (để trống nếu không muốn thay đổi):\n";

            cout << "Loại xe hiện tại (" << xe.getLoaiXe() << "): ";
            string loaiXe;
            cin.ignore();
            getline(cin, loaiXe);
            if (!loaiXe.empty()) xe.setLoaiXe(loaiXe);

            cout << "Số chỗ ngồi hiện tại (" << xe.getSoChoNgoi() << "): ";
            int soChoNgoi;
            cin >> soChoNgoi;
            if (soChoNgoi > 0) xe.setSoChoNgoi(soChoNgoi);

            cout << "Cập nhật danh sách tiện ích (xóa tiện ích cũ):\n";
            map<string, double> tienIch;
            int soTienIch;
            cout << "Nhập số lượng tiện ích mới: ";
            cin >> soTienIch;
            for (int i = 0; i < soTienIch; ++i) {
                string tenTienIch;
                double giaTienIch;
                cout << "Nhập tên tiện ích " << i + 1 << ": ";
                cin >> tenTienIch;
                cout << "Nhập giá tiện ích " << i + 1 << ": ";
                cin >> giaTienIch;
                tienIch[tenTienIch] = giaTienIch;
            }
            xe.setTienIch(tienIch);

            cout << "Chỉnh sửa thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy xe với biển số " << bienSo << endl;
}

// Xóa xe
void xoaXe() {
    string bienSo;
    cout << "Nhập biển số xe cần xóa: ";
    cin >> bienSo;

    for (auto it = danhSachXe.begin(); it != danhSachXe.end(); ++it) {
        if (it->getBienSo() == bienSo) {
            danhSachXe.erase(it);
            cout << "Xóa xe thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy xe với biển số " << bienSo << endl;
}

// Hàm chính
void QLX() { //quan ly xe
    int choice;
    do {
        cout << endl << "Quản lý xe:" << endl;
        cout << "1. Thêm xe mới\n";
        cout << "2. Chỉnh sửa thông tin xe" << endl;
        cout << "3. Xóa xe" << endl;
        cout << "0. Thoát" << endl;
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice) {
        case 1:
            themXe();
            break;
        case 2:
            suaXe();
            break;
        case 3:
            xoaXe();
            break;
        case 0:
            cout << "Thoát chương trình.\n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);

    return;
}