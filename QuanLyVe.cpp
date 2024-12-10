#include "Ve.h"


vector<Ve> danhSachVe;

// Xem danh sách tất cả các vé
void xemDanhSachVe() {
    cout << "\nDanh sách tất cả các vé:\n";
    for (const auto& ve : danhSachVe) {
        cout << "Mã vé: " << ve.getMaVe() << "\n";
        cout << "Thông tin chuyến xe:\n";
        cout << "  Mã chuyến xe: " << ve.getThongTinChuyenXe().getMaChuyenXe() << "\n";
        cout << "  Điểm đi: " << ve.getThongTinChuyenXe().getDiemDi() << "\n";
        cout << "  Điểm đến: " << ve.getThongTinChuyenXe().getDiemDen() << "\n";
        cout << "Thông tin khách hàng:\n";
        cout << "  Họ tên: " << ve.getThongTinKhachHang().getHoTen() << "\n";
        cout << "  Số điện thoại: " << ve.getThongTinKhachHang().getSoDienThoai() << "\n";
        cout << "  Email: " << ve.getThongTinKhachHang().getEmail() << "\n";
        cout << "Giá vé: " << ve.getGiaVe() << "\n";
        cout << "Trạng thái: " << ve.getTrangThai() << "\n";
        cout << "-------------------------\n";
    }
}

// Chỉnh sửa thông tin vé
void suaVe() {
    string maVe;
    cout << "Nhập mã vé cần chỉnh sửa: ";
    cin >> maVe;

    for (auto& ve : danhSachVe) {
        if (ve.getMaVe() == maVe) {
            cout << "Chỉnh sửa thông tin vé:\n";

            // Chỉnh sửa thông tin chuyến xe
            string diemDi, diemDen;
            cout << "  Điểm đi mới (để trống nếu không thay đổi): ";
            cin.ignore();
            getline(cin, diemDi);
            if (!diemDi.empty()) ve.getThongTinChuyenXe().setDiemDi(diemDi);

            cout << "  Điểm đến mới (để trống nếu không thay đổi): ";
            getline(cin, diemDen);
            if (!diemDen.empty()) ve.getThongTinChuyenXe().setDiemDen(diemDen);

            // Chỉnh sửa thông tin khách hàng
            string hoTen, soDienThoai, email;
            cout << "Họ tên khách hàng hiện tại: " << ve.getThongTinKhachHang().getHoTen() << "\n";
            cout << "  Họ tên mới (để trống nếu không thay đổi): ";
            getline(cin, hoTen);
            if (!hoTen.empty()) ve.getThongTinKhachHang().setHoTen(hoTen);

            cout << "  Số điện thoại mới (để trống nếu không thay đổi): ";
            getline(cin, soDienThoai);
            if (!soDienThoai.empty()) ve.getThongTinKhachHang().setSoDienThoai(soDienThoai);

            cout << "  Email mới (để trống nếu không thay đổi): ";
            getline(cin, email);
            if (!email.empty()) ve.getThongTinKhachHang().setEmail(email);

            // Chỉnh sửa trạng thái vé
            string trangThai;
            cout << "Trạng thái hiện tại: " << ve.getTrangThai() << "\n";
            cout << "  Trạng thái mới (để trống nếu không thay đổi): ";
            getline(cin, trangThai);
            if (!trangThai.empty()) ve.setTrangThai(trangThai);

            cout << "Chỉnh sửa thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy vé với mã " << maVe << endl;
}

// Hủy vé
void huyVe() {
    string maVe;
    cout << "Nhập mã vé cần hủy: ";
    cin >> maVe;

    for (auto it = danhSachVe.begin(); it != danhSachVe.end(); ++it) {
        if (it->getMaVe() == maVe) {
            danhSachVe.erase(it);
            cout << "Hủy vé thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy vé với mã " << maVe << endl;
}

// Quản lý vé
void QLVX() {
    int choice;
    do {
        cout << "\nQuản lý vé:\n";
        cout << "1. Xem danh sách tất cả các vé\n";
        cout << "2. Chỉnh sửa thông tin vé\n";
        cout << "3. Hủy vé\n";
        cout << "0. Thoát\n";
        cout << "Lựa chọn: ";
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
            cout << "Thoát chương trình.\n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}
