#pragma once
#ifndef VE_H
#define VE_H

#include "KhachHang.h"
#include "ChuyenXe.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Ve {
private:

    static Ve* instance;

    string maVe;                  // Mã vé (duy nhất)
    KhachHang thongTinKhachHang;  // Thông tin khách hàng
    double giaVe;                 // Giá vé
    string trangThai;             // Trạng thái vé (Đã đặt, Đã thanh toán, Đã hủy)
    ChuyenXe thongTinChuyenXe;    // Thông tin chuyến xe
    Ve(){}

public:

    static Ve* getInstance() {
        if (!instance) {
            instance = new Ve;

        }
        return instance;
    }

    static void deleteInstance() {
        if (instance) {
            delete instance;
            instance = nullptr;

        }
    }

    // Constructor
    Ve(string maVe, ChuyenXe thongTinChuyenXe, KhachHang thongTinKhachHang, double giaVe, string trangThai)
        : maVe(maVe), thongTinChuyenXe(thongTinChuyenXe),
        thongTinKhachHang(thongTinKhachHang), giaVe(giaVe), trangThai(trangThai) {}

    // Getter
    string getMaVe() const { return maVe; }
    ChuyenXe getThongTinChuyenXe() const { return thongTinChuyenXe; }
    KhachHang getThongTinKhachHang() const { return thongTinKhachHang; }
    double getGiaVe() const { return giaVe; }
    string getTrangThai() const { return trangThai; }

    // Setter
    void setThongTinChuyenXe(const ChuyenXe& thongTinChuyenXe) { this->thongTinChuyenXe = thongTinChuyenXe; }
    void setThongTinKhachHang(const KhachHang& thongTinKhachHang) { this->thongTinKhachHang = thongTinKhachHang; }
    void setGiaVe(double giaVe) { this->giaVe = giaVe; }
    void setTrangThai(const string& trangThai) { this->trangThai = trangThai; }

};


extern vector<Ve> danhSachVe;

void QLVX();

#endif
