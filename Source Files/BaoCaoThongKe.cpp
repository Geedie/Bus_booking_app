#include <iostream>
#include "BaoCaoThongKe.h"

DoanhThu* doanhThu = DoanhThu::getInstance();

void MenuDoanhThu() {
    int n;

    do {
        cout << endl;
        cout << "> --- Menu Quan ly Doanh Thu ---" << endl;
        cout << "> 1. Thong ke doanh thu theo ngay" << endl;
        cout << "> 2. Thong ke doanh thu theo thang" << endl;
        cout << "> 3. Thong ke doanh thu theo nam" << endl;
        cout << "> 4. Thong ke doanh thu theo chuyen xe" << endl;
        cout << "> 5. Thong ke so luong ve ban ra theo ngay" << endl;
        cout << "> 6. Thong ke so luong ve ban ra theo thang" << endl;
        cout << "> 7. Thong ke so luong ve ban ra theo nam" << endl;
        cout << "> 8. Thong ke so luong khach hang da su dung he thong" << endl;
        cout << "> 0. Thoat" << endl;
        cout << "> Lua chon cua ban: ";
        cin >> n;

        switch (n) {
        case 1: {
            string ngay;
            cout << "> Nhap ngay can thong ke (YYYY-MM-DD): ";
            cin >> ngay;
            double doanhThuNgay = doanhThu->DoanhThuTG(ngay);
            cout << "> Doanh thu ngay " << ngay << ": " << doanhThuNgay << " VNĐ" << endl;
            break;
        }
        case 2: {
            string thang;
            cout << "> Nhap thang can thong ke (YYYY-MM): ";
            cin >> thang;
            double doanhThuThang = doanhThu->DoanhThuTG(thang);
            cout << "> Doanh thu thang " << thang << ": " << doanhThuThang << " VNĐ" << endl;
            break;
        }
        case 3: {
            string nam;
            cout << "> Nhap nam can thong ke (YYYY): ";
            cin >> nam;
            double doanhThuNam = doanhThu->DoanhThuTG(nam);
            cout << "> Doanh thu nam " << nam << ": " << doanhThuNam << " VNĐ" << endl;
            break;
        }
        case 4: {
            string maChuyenXe;
            cout << "> Nhap ma chuyen xe can thong ke: ";
            cin >> maChuyenXe;
            double doanhThuChuyenXe = doanhThu->DoanhThuCX(maChuyenXe);
            cout << "> Doanh thu chuyen xe " << maChuyenXe << ": " << doanhThuChuyenXe << " VNĐ" << endl;
            break;
        }
        case 5: {
            string ngay;
            cout << "> Nhap ngay can thong ke (YYYY-MM-DD): ";
            cin >> ngay;
            double soLuongVeNgay = doanhThu->SoLuongVeTG(ngay);
            cout << "> So luong ve ban ra ngay " << ngay << ": " << soLuongVeNgay << endl;
            break;
        }
        case 6: {
            string thang;
            cout << "> Nhap thang can thong ke (YYYY-MM): ";
            cin >> thang;
            double soLuongVeThang = doanhThu->SoLuongVeTG(thang);
            cout << "> So luong ve ban ra thang " << thang << ": " << soLuongVeThang << endl;
            break;
        }
        case 7: {
            string nam;
            cout << "> Nhap nam can thong ke (YYYY): ";
            cin >> nam;
            double soLuongVeNam = doanhThu->SoLuongVeTG(nam);
            cout << "> So luong ve ban ra nam " << nam << ": " << soLuongVeNam << endl;
            break;
        }
        case 8: {
            cout << "> So luong khach hang da va dang su dung he thong la: " << doanhThu->SoLuongKhachHang() << endl;
            break;
        }
        case 0:
            cout << "> Thoat chuong trinh." << endl;
            break;
        default:
            cout << "> Lua chon khong hop le. Vui long nhap lai." << endl;
            break;
        }
    } while (n != 0);
}