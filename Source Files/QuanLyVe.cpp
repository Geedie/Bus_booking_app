#include "Ve.h"

vector<Ve> danhSachVe;

void xemDanhSachVe() {
    cout << "> Danh sach tat ca cac ve:" << endl;
    for (const auto& ve : danhSachVe) {
        cout << "> Ma ve: " << ve.getMaVe() << endl;
        cout << "> Thong tin chuyen xe:" << endl;
        cout << ">   Ma chuyen xe: " << ve.getThongTinChuyenXe().getMaChuyenXe() << endl;
        cout << ">   Diem di: " << ve.getThongTinChuyenXe().getDiemDi() << endl;
        cout << ">   Diem den: " << ve.getThongTinChuyenXe().getDiemDen() << endl;
        cout << "> Thong tin khach hang:" << endl;
        cout << ">   Ho ten: " << ve.getThongTinKhachHang().getHoTen() << endl;
        cout << ">   So dien thoai: " << ve.getThongTinKhachHang().getSoDienThoai() << endl;
        cout << ">   Email: " << ve.getThongTinKhachHang().getEmail() << endl;
        cout << "> Gia ve: " << ve.getGiaVe() << endl;
        cout << "> Trang thai: " << ve.getTrangThai() << endl;
        cout << "> -------------------------" << endl;
    }
}

void suaVe() {
    string maVe;
    cout << "> Nhap ma ve can chinh sua: ";
    cin >> maVe;

    for (auto& ve : danhSachVe) {
        if (ve.getMaVe() == maVe) {
            cout << "> Chinh sua thong tin ve:" << endl;

            string diemDi, diemDen;
            cout << ">   Diem di moi (de trong neu khong thay doi): ";
            cin.ignore();
            getline(cin, diemDi);
            if (!diemDi.empty()) ve.getThongTinChuyenXe().setDiemDi(diemDi);

            cout << ">   Diem den moi (de trong neu khong thay doi): ";
            getline(cin, diemDen);
            if (!diemDen.empty()) ve.getThongTinChuyenXe().setDiemDen(diemDen);

            string hoTen, soDienThoai, email;
            cout << "> Ho ten khach hang hien tai: " << ve.getThongTinKhachHang().getHoTen() << endl;
            cout << ">   Ho ten moi (de trong neu khong thay doi): ";
            getline(cin, hoTen);
            if (!hoTen.empty()) ve.getThongTinKhachHang().setHoTen(hoTen);

            cout << ">   So dien thoai moi (de trong neu khong thay doi): ";
            getline(cin, soDienThoai);
            if (!soDienThoai.empty()) ve.getThongTinKhachHang().setSoDienThoai(soDienThoai);

            cout << ">   Email moi (de trong neu khong thay doi): ";
            getline(cin, email);
            if (!email.empty()) ve.getThongTinKhachHang().setEmail(email);

            string trangThai;
            cout << "> Trang thai hien tai: " << ve.getTrangThai() << endl;
            cout << ">   Trang thai moi (de trong neu khong thay doi): ";
            getline(cin, trangThai);
            if (!trangThai.empty()) ve.setTrangThai(trangThai);

            cout << "> Chinh sua thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay ve voi ma " << maVe << endl;
}

void huyVe() {
    string maVe;
    cout << "> Nhap ma ve can huy: ";
    cin >> maVe;

    for (auto it = danhSachVe.begin(); it != danhSachVe.end(); ++it) {
        if (it->getMaVe() == maVe) {
            danhSachVe.erase(it);
            cout << "> Huy ve thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay ve voi ma " << maVe << endl;
}

void QLVX() {
    int choice;
    do {
        cout << "> Quan ly ve:" << endl;
        cout << "> 1. Xem danh sach tat ca cac ve" << endl;
        cout << "> 2. Chinh sua thong tin ve" << endl;
        cout << "> 3. Huy ve" << endl;
        cout << "> 0. Thoat" << endl;
        cout << "> Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            xemDanhSachVe();
            break;
        case 2:
            suaVe();
            break;
        case 3:
            huyVe();
            break;
        case 0:
            cout << "> Thoat chuong trinh." << endl;
            break;
        default:
            cout << "> Lua chon khong hop le." << endl;
        }
    } while (choice != 0);
}