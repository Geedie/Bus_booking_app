#include <fstream>
#include "ChuyenXe.h"
#pragma once

vector<ChuyenXe> danhSachChuyenXe;

string taoMaChuyenXe() {
    return "CX" + to_string(danhSachChuyenXe.size() + 1);
}

void themChuyenXe() {
    string diemDi, diemDen, ngayGioKhoiHanh, bienSo, loaiXe;
    double giaVeCoBan;
    int soChoNgoi;
    map<string, double> tienIch;

    cout << "> Nhap diem di: ";
    cin >> diemDi;
    cout << "> Nhap diem den: ";
    cin >> diemDen;
    cout << "> Nhap ngay gio khoi hanh: ";
    cin >> ngayGioKhoiHanh;
    cout << "> Nhap gia ve co ban: ";
    cin >> giaVeCoBan;
    cout << "> Nhap bien so xe: ";
    cin >> bienSo;
    cout << "> Nhap loai xe: ";
    cin >> loaiXe;
    cout << "> Nhap so cho ngoi: ";
    cin >> soChoNgoi;

    int soTienIch;
    cout << "> Nhap so luong tien ich: ";
    cin >> soTienIch;

    for (int i = 0; i < soTienIch; ++i) {
        string tenTienIch;
        double giaTienIch;
        cout << "> Nhap tien ich " << i + 1 << ": ";
        cin >> tenTienIch;
        cout << "> Nhap gia tien ich " << i + 1 << ": ";
        cin >> giaTienIch;
        tienIch[tenTienIch] = giaTienIch;
    }

    Xe xe(bienSo, loaiXe, soChoNgoi, tienIch);
    string maChuyenXe = taoMaChuyenXe();
    ChuyenXe chuyenXe(maChuyenXe, diemDi, diemDen, ngayGioKhoiHanh, giaVeCoBan, soChoNgoi);
    danhSachChuyenXe.push_back(chuyenXe);

    cout << "> Them chuyen xe thanh cong voi ma: " << maChuyenXe << endl;
}

void suaChuyenXe() {
    string maChuyenXe;
    cout << "> Nhap ma chuyen xe can chinh sua: ";
    cin >> maChuyenXe;

    for (auto& chuyenXe : danhSachChuyenXe) {
        if (chuyenXe.getMaChuyenXe() == maChuyenXe) {
            cout << "> Chinh sua thong tin chuyen xe (de trong neu khong muon thay doi):" << endl;

            cout << "> Diem di hien tai (" << chuyenXe.getDiemDi() << "): ";
            string diemDi;
            cin.ignore();
            getline(cin, diemDi);
            if (!diemDi.empty()) chuyenXe.setDiemDi(diemDi);

            cout << "> Diem den hien tai (" << chuyenXe.getDiemDen() << "): ";
            string diemDen;
            getline(cin, diemDen);
            if (!diemDen.empty()) chuyenXe.setDiemDen(diemDen);

            cout << "> Ngay gio khoi hanh hien tai (" << chuyenXe.getNgayGioKhoiHanh() << "): ";
            string ngayGioKhoiHanh;
            getline(cin, ngayGioKhoiHanh);
            if (!ngayGioKhoiHanh.empty()) chuyenXe.setNgayGioKhoiHanh(ngayGioKhoiHanh);

            cout << "> Gia ve co ban hien tai (" << chuyenXe.getGiaVeCoBan() << "): ";
            double giaVeCoBan;
            cin >> giaVeCoBan;
            if (giaVeCoBan > 0) chuyenXe.setGiaVeCoBan(giaVeCoBan);

            cout << "> Chinh sua thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay chuyen xe voi ma " << maChuyenXe << endl;
}

void xoaChuyenXe() {
    string maChuyenXe;
    cout << "> Nhap ma chuyen xe can xoa: ";
    cin >> maChuyenXe;

    for (auto it = danhSachChuyenXe.begin(); it != danhSachChuyenXe.end(); ++it) {
        if (it->getMaChuyenXe() == maChuyenXe) {
            danhSachChuyenXe.erase(it);
            cout << "> Xoa chuyen xe thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay chuyen xe voi ma " << maChuyenXe << endl;
}

void QLCX() {
    int choice;
    do {
        cout << endl << "> Quan ly chuyen xe:" << endl;
        cout << "> 1. Them chuyen xe moi" << endl;
        cout << "> 2. Chinh sua thong tin chuyen xe" << endl;
        cout << "> 3. Xoa chuyen xe" << endl;
        cout << "> 0. Thoat" << endl;
        cout << "> Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            themChuyenXe();
            break;
        case 2:
            suaChuyenXe();
            break;
        case 3:
            xoaChuyenXe();
            break;
        case 0:
            cout << "> Thoat chuong trinh." << endl;
            break;
        default:
            cout << "> Lua chon khong hop le." << endl;
        }
    } while (choice != 0);

    return;
}