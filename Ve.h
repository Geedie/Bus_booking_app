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

    string maVe;                  
    KhachHang thongTinKhachHang;  
    double giaVe;                 
    string trangThai;             
    ChuyenXe thongTinChuyenXe;    
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


    Ve(string maVe, ChuyenXe thongTinChuyenXe, KhachHang thongTinKhachHang, double giaVe, string trangThai)
        : maVe(maVe), thongTinChuyenXe(thongTinChuyenXe),
        thongTinKhachHang(thongTinKhachHang), giaVe(giaVe), trangThai(trangThai) {}


    string getMaVe() const { 
        return maVe; 
    }
    ChuyenXe getThongTinChuyenXe() const { 
        return thongTinChuyenXe; 
    }
    KhachHang getThongTinKhachHang() const { 
        return thongTinKhachHang; 
    }
    double getGiaVe() const { 
        return giaVe; 
    }
    string getTrangThai() const {
        return trangThai; 
    }


    void setThongTinChuyenXe(const ChuyenXe& thongTinChuyenXe) { 
        this->thongTinChuyenXe = thongTinChuyenXe; 
    }
    void setThongTinKhachHang(const KhachHang& thongTinKhachHang) { 
        this->thongTinKhachHang = thongTinKhachHang; 
    }
    void setGiaVe(double giaVe) { 
        this->giaVe = giaVe; 
    }
    void setTrangThai(const string& trangThai) { 
        this->trangThai = trangThai; 
    }

};


extern vector<Ve> danhSachVe;

void QLVX();

#endif
