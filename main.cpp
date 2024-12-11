#include"QuanLy.h"
#include"QuanLyTK.h"
#include"DatVe.h"
#include"LoginnSignUp.cpp"
#include"ThanhToan.h"
#include"TimVaHienThiCX.h"
#include"TraCuuChuyenXe.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


Login* Login::instance = nullptr;
SignUp* SignUp::instance = nullptr;
Ve* Ve::instance = nullptr;

int main() {
    int choice;

    do {
        cout << "> ========= MENU ==========" << endl;
        cout << "> 1. Quan ly he thong (QLHT)" << endl;
        cout << "> 2. Quan ly tai khoan (QLTK)" << endl;
        cout << "> 3. Quan ly ve xe (QLVX)" << endl;
        cout << "> 4. Quan ly chuyen xe (QLX)" << endl;
        cout << "> 5. Quan ly ve (QLV)" << endl;
        cout << "> 6. Quan ly chuyen xe (QLCX)" << endl;
        cout << "> 7. Menu doanh thu (MenuDoanhThu)" << endl;
        cout << "> 8. Dat ve (mainDatVe)" << endl;
        cout << "> 9. Thanh toan (mainThanhToan)" << endl;
        cout << "> 10. Loc thong tin chuyen xe (mainFilter)" << endl;
        cout << "> 0. Thoat" << endl;
        cout << "> ==========================" << endl;
        cout << "> Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            QLHT();
            break;
        case 2: {
            vector<User> danhSachNguoiDung; 
            QLTK(danhSachNguoiDung);
            break;
        }
        case 3:
            QLVX();
            break;
        case 4:
            QLX();
            break;
        case 5:
            QLVX();
            break;
        case 6:
            QLCX();
            break;
        case 7:
            //MenuDoanhThu();
            break;
        case 8: {
            string maCX = "CX123";
            vector<string> tienIch = { "Wi-Fi", "Do an" };
            KhachHang khachHang; 
            vector<int> choNgoi = { 1, 2, 3 };
            mainDatVe(maCX, tienIch, khachHang, choNgoi);
            break;
        }
        case 9: {
            Ve* ve = Ve::getInstance();
            mainThanhToan(*ve);
            break;
        }
        case 10: {
            string diemDi = "Ha Noi";
            string diemDen = "Da Nang";
            string ngayKhoiHanh = "2024-12-25";
            double khoangGia = 500000;
            string loaiXe = "Limousine";
            map<string, double> tienIch = { {"Wi-Fi", 10.0}, {"Do an", 20.0} };
            mainFilter(diemDi, diemDen, ngayKhoiHanh, khoangGia, loaiXe, tienIch);
            break;
        }
        case 0:
            cout << "> Thoat chuong trinh." << endl;
            break;
        default:
            cout << "> Lua chon khong hop le, vui long thu lai." << endl;
        }
    } while (choice != 0);

    return 0;
}
