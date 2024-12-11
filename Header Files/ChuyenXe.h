#ifndef CHUYENXE_H
#define CHUYENXE_H
#pragma once

#include"Xe.h"

struct HanhTrinh {
    string diem;
    string thoiGian;
    int thoiGianDung;
};

class ChuyenXe : public Xe {
private:
    string maChuyenXe;       
    string diemDi;           
    string diemDen;          
    string ngayGioKhoiHanh;   
    double giaVeCoBan;        
    int soVeConLai;
    vector<HanhTrinh> hanhTrinh;


public:


    ChuyenXe(string maChuyenXe, string diemDi, string diemDen, string ngayGioKhoiHanh,
        double giaVeCoBan, int soVeConLai)
        : maChuyenXe(maChuyenXe), diemDi(diemDi), diemDen(diemDen),
        ngayGioKhoiHanh(ngayGioKhoiHanh), giaVeCoBan(giaVeCoBan),
        soVeConLai(soVeConLai) {}

    void inThongTin() override {
        cout << endl;
        cout << "Mã chuyến xe: " << maChuyenXe << endl;
        cout << "Điểm đi: " << diemDi << endl;
        cout << "Điểm đến: " << diemDen << endl;
        cout << "Thời gian khởi hành: " << ngayGioKhoiHanh << endl;
        cout << "Giá vé cơ bản: " << giaVeCoBan << endl;
        cout << "Số vé còn lại: " << soVeConLai << endl;
        Xe::inThongTin();
    }


    vector<HanhTrinh> getHanhTrinh() const {
        return hanhTrinh;
    }
    string getMaChuyenXe() const { return maChuyenXe; }
    string getDiemDi() const { return diemDi; }
    string getDiemDen() const { return diemDen; }
    string getNgayGioKhoiHanh() const { return ngayGioKhoiHanh; }
    double getGiaVeCoBan() const { return giaVeCoBan; }
    int getSoVeConLai() const { return soVeConLai; }

    void addHanhTrinh(const string& diem, const string& thoiGian, int thoiGianDung) {
        hanhTrinh.push_back({ diem, thoiGian, thoiGianDung });
    }
    void setDiemDi(const string& diemDi) { 
        this->diemDi = diemDi; 
    }
    void setDiemDen(const string& diemDen) { 
        this->diemDen = diemDen; 
    }
    void setNgayGioKhoiHanh(const string& ngayGioKhoiHanh) { 
        this->ngayGioKhoiHanh = ngayGioKhoiHanh; 
    }
    void setGiaVeCoBan(double giaVeCoBan) { 
        this->giaVeCoBan = giaVeCoBan; }
    void setSoVeConLai(int soVeConLai) { 
        this->soVeConLai = soVeConLai; 
    }

    ChuyenXe() = default;
};


void QLCX();

#endif