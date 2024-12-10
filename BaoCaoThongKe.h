#ifndef QUANLY_H 
#define QUANLY_H
#pragma once
#include <sstream>
#include <iomanip>
#include <ctime>
#include<set>
#include "Ve.h"

using namespace std;

class DoanhThu {
private:
    static double TongDoanhThu;
    static DoanhThu* instance;
    static vector<Ve> danhSachVe;  

public:
    static DoanhThu* getInstance() {
        if (!instance) {
            instance = new DoanhThu;
        }
        return instance;
    }

    static DoanhThu* deleteInstance() {
        if (instance) {
            delete instance;
            instance = nullptr;
        }
        return instance;
    }
    //Thống kê Doanh Thu
    double DoanhThuTG(const string& thoigian) {
        double doanhThu = 0.0;
        tm timeStruct = {};
        istringstream ss(thoigian);
        ss >> get_time(&timeStruct, "%Y-%m-%d");

        if (ss.fail()) {
            cerr << "Invalid date format\n";
            return 0.0;
        }

        for (const auto& ve : danhSachVe) {
            tm chuyenXeTime = {};
            istringstream chuyenXeStream(ve.getThongTinChuyenXe().getNgayGioKhoiHanh());
            chuyenXeStream >> get_time(&chuyenXeTime, "%Y-%m-%d %H:%M:%S");

            if (chuyenXeStream.fail()) {
                cerr << "Invalid time format in chuyến xe\n";
                continue;
            }

            if (timeStruct.tm_year == chuyenXeTime.tm_year &&
                timeStruct.tm_mon == chuyenXeTime.tm_mon &&
                timeStruct.tm_mday == chuyenXeTime.tm_mday) {
                doanhThu += ve.getGiaVe();
            }
        }
        return doanhThu;
    }
    double DoanhThuCX(const string& MaChuyenXe) {
        double DoanhThuCX = 0.0;
        for (const auto& ve : danhSachVe) {
            if (ve.getThongTinChuyenXe().getMaChuyenXe() == MaChuyenXe) {
                DoanhThuCX += ve.getGiaVe();
            }
        }
        return DoanhThuCX;
    }

    //Thống kê số lượng vé bán ra
    int SoLuongVeTG(const string& thoigian) {
        int soLuongVe = 0;
        tm timeStruct = {};
        istringstream ss(thoigian);
        ss >> get_time(&timeStruct, "%Y-%m-%d");

        if (ss.fail()) {
            cerr << "Invalid date format" << endl;
            return 0;
        }

        for (const auto& ve : danhSachVe) {
            tm chuyenXeTime = {};
            istringstream chuyenXeStream(ve.getThongTinChuyenXe().getNgayGioKhoiHanh());
            chuyenXeStream >> std::get_time(&chuyenXeTime, "%Y-%m-%d %H:%M:%S");

            if (chuyenXeStream.fail()) {
                cerr << "Invalid time format in chuyến xe" << endl;
                continue;
            }

            if (timeStruct.tm_year == chuyenXeTime.tm_year &&
                timeStruct.tm_mon == chuyenXeTime.tm_mon &&
                timeStruct.tm_mday == chuyenXeTime.tm_mday) {
                soLuongVe++;
            }
        }
        return soLuongVe;
    }
    int SoLuongVeCX(const string& MaChuyenXe) {
        int soLuongVeCX = 0;
        for (const auto& ve : danhSachVe) {
            if (ve.getThongTinChuyenXe().getMaChuyenXe() == MaChuyenXe) {
                soLuongVeCX++;
            }
        }
        return soLuongVeCX;
    }

    //Thống kê số lượng khách hàng
    int SoLuongKhachHang() {
        set<string> danhSachKhachHang;  //  mỗi khách hàng đều khác biệt
        for (const auto& ve : danhSachVe) {
            danhSachKhachHang.insert(ve.getThongTinKhachHang().getSoDienThoai());  // Giả sử số điện thoại là duy nhất để nhận diện khách hàng
        }
        return danhSachKhachHang.size();
    }
};

void MenuDoanhThu();



#endif
