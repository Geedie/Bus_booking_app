#pragma once
#include "Xe.h"

vector<Xe> danhSachXe;

void themXe() {
    string bienSo, loaiXe;
    int soChoNgoi;
    map<string, double> tienIch;

    cout << "> Nhap bien so xe: ";
    cin >> bienSo;
    cout << "> Nhap loai xe (ghe ngoi/giuong nam): ";
    cin >> loaiXe;
    cout << "> Nhap so cho ngoi: ";
    cin >> soChoNgoi;

    int soTienIch;
    cout << "> Nhap so luong tien ich: ";
    cin >> soTienIch;
    for (int i = 0; i < soTienIch; ++i) {
        string tenTienIch;
        double giaTienIch;
        cout << "> Nhap ten tien ich " << i + 1 << ": ";
        cin >> tenTienIch;
        cout << "> Nhap gia tien ich " << i + 1 << ": ";
        cin >> giaTienIch;
        tienIch[tenTienIch] = giaTienIch;
    }

    Xe xe(bienSo, loaiXe, soChoNgoi, tienIch);
    danhSachXe.push_back(xe);

    cout << "> Them xe thanh cong!" << endl;
}

void suaXe() {
    string bienSo;
    cout << "> Nhap bien so xe can chinh sua: ";
    cin >> bienSo;

    for (auto& xe : danhSachXe) {
        if (xe.getBienSo() == bienSo) {
            cout << "> Chinh sua thong tin xe (de trong neu khong muon thay doi):" << endl;

            cout << "> Loai xe hien tai (" << xe.getLoaiXe() << "): ";
            string loaiXe;
            cin.ignore();
            getline(cin, loaiXe);
            if (!loaiXe.empty()) xe.setLoaiXe(loaiXe);

            cout << "> So cho ngoi hien tai (" << xe.getSoChoNgoi() << "): ";
            int soChoNgoi;
            cin >> soChoNgoi;
            if (soChoNgoi > 0) xe.setSoChoNgoi(soChoNgoi);

            cout << "> Cap nhat danh sach tien ich (xoa tien ich cu):" << endl;
            map<string, double> tienIch;
            int soTienIch;
            cout << "> Nhap so luong tien ich moi: ";
            cin >> soTienIch;
            for (int i = 0; i < soTienIch; ++i) {
                string tenTienIch;
                double giaTienIch;
                cout << "> Nhap ten tien ich " << i + 1 << ": ";
                cin >> tenTienIch;
                cout << "> Nhap gia tien ich " << i + 1 << ": ";
                cin >> giaTienIch;
                tienIch[tenTienIch] = giaTienIch;
            }
            xe.setTienIch(tienIch);

            cout << "> Chinh sua thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay xe voi bien so " << bienSo << endl;
}

void xoaXe() {
    string bienSo;
    cout << "> Nhap bien so xe can xoa: ";
    cin >> bienSo;

    for (auto it = danhSachXe.begin(); it != danhSachXe.end(); ++it) {
        if (it->getBienSo() == bienSo) {
            danhSachXe.erase(it);
            cout << "> Xoa xe thanh cong!" << endl;
            return;
        }
    }
    cout << "> Khong tim thay xe voi bien so " << bienSo << endl;
}

void QLX() {
    int choice;
    do {
        cout << endl << "> Quan ly xe:" << endl;
        cout << "> 1. Them xe moi" << endl;
        cout << "> 2. Chinh sua thong tin xe" << endl;
        cout << "> 3. Xoa xe" << endl;
        cout << "> 0. Thoat" << endl;
        cout << "> Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            themXe();
            break;
        case 2:
            suaXe();
            break;
        case 3:
            xoaXe();
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