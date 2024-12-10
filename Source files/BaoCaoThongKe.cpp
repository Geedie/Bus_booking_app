#include <iostream>
#include "BaoCaoThongKe.h" 


DoanhThu* doanhThu = DoanhThu::getInstance();

void MenuDoanhThu() {
    int n;

    do {
        cout << endl;
        cout << "--- Menu Quản lý Doanh Thu ---" << endl;
        cout << "1. Thống kê doanh thu theo ngày" << endl;
        cout << "2. Thống kê doanh thu theo tháng" << endl;
        cout << "3. Thống kê doanh thu theo năm" << endl;
        cout << "4. Thống kê doanh thu theo chuyến xe" << endl;
        cout << "5. Thống kê số lượng vé bán ra theo ngày" << endl;
        cout << "6. Thống kê số lượng vé bán ra theo tháng" << endl;
        cout << "7. Thống kê số lượng vé bán ra theo năm" << endl;
        cout << "8. Thống kê số lượng khách hàng đã sử dụng hệ thống" << endl;
        cout << "0. Thoát" << endl;;
        cout << "Lựa chọn của bạn: ";
        cin >> n;

        switch (n) {
        case 1: {
            string ngay;
            cout << "Nhập ngày cần thống kê (YYYY-MM-DD): ";
            cin >> ngay;
            double doanhThuNgay = doanhThu->DoanhThuTG(ngay);
            cout << "Doanh thu ngày " << ngay << ": " << doanhThuNgay << " VNĐ" << endl;
            break;
        }
        case 2: {
            string thang;
            cout << "Nhập tháng cần thống kê (YYYY-MM): ";
            cin >> thang;
            double doanhThuThang = doanhThu->DoanhThuTG(thang);
            cout << "Doanh thu tháng " << thang << ": " << doanhThuThang << " VNĐ" << endl;
            break;
        }
        case 3: {
            string nam;
            cout << "Nhập năm cần thống kê (YYYY): ";
            cin >> nam;
            double doanhThuNam = doanhThu->DoanhThuTG(nam);
            cout << "Doanh thu năm " << nam << ": " << doanhThuNam << " VNĐ" << endl;
            break;
        }
        case 4: {
            string maChuyenXe;
            cout << "Nhập mã chuyến xe cần thống kê: ";
            cin >> maChuyenXe;
            double doanhThuChuyenXe = doanhThu->DoanhThuCX(maChuyenXe);
            cout << "Doanh thu chuyến xe " << maChuyenXe << ": " << doanhThuChuyenXe << " VNĐ" << endl;
            break;
        }
        case 5: {
            string ngay;
            cout << "Nhập ngày cần thống kê (YYYY-MM-DD): ";
            cin >> ngay;
            double soLuongVeNgay = doanhThu->SoLuongVeTG(ngay);
            cout << "Doanh thu ngày " << ngay << ": " << soLuongVeNgay << " VNĐ" << endl;
            break;
        }
        case 6: {
            string thang;
            cout << "Nhập tháng cần thống kê (YYYY-MM): ";
            cin >> thang;
            double soLuongVeThang = doanhThu->SoLuongVeTG(thang);
            cout << "Doanh thu tháng " << thang << ": " << soLuongVeThang << " VNĐ" << endl;
            break;           
        }
        case 7: {
            string nam;
            cout << "Nhập năm cần thống kê (YYYY): ";
            cin >> nam;
            double soLuongVeNam = doanhThu->SoLuongVeTG(nam);
            cout << "Doanh thu năm " << nam << ": " << soLuongVeNam << " VNĐ" << endl;
            break;           
        }
        case 8: {
            cout << "Số lượng khách hàng đã và đang sử dụng hệ thống là: " << doanhThu->SoLuongKhachHang() << endl;
            break;
        }
        case 0:
            cout << "Thoát chương trình." << endl;
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại." << endl;
            break;
        }
    } while (n != 0);
}


