#include"TimVaHienThiCX.h"

class ChuyenXeDisplay {
public:
    virtual void display(const ChuyenXe& chuyenXe) const = 0;
    virtual ~ChuyenXeDisplay() = default;
};

class BasicDisplay : public ChuyenXeDisplay {
public:
    void display(const ChuyenXe& chuyenXe) const override {
        cout << "> xem-chi-tiet "<<chuyenXe.getMaChuyenXe() << endl;
        cout << "> Thong tin chi tiet chuyen xe " << chuyenXe.getMaChuyenXe()<<":" << endl;
        cout << "> Thong tin co ban : " << endl;
        cout << "   Ma chuyen xe: " << chuyenXe.getMaChuyenXe() << endl;
    }
};

class DetailedDisplay : public ChuyenXeDisplay {
public:
    void display(const ChuyenXe& chuyenXe) const override {
        cout << "> xem-chi-tiet " << chuyenXe.getMaChuyenXe() << endl;
        cout << "> Thong tin chi tiet chuyen xe " << chuyenXe.getMaChuyenXe() << ":" << endl;
        cout << "> Thong tin co ban: " << endl;
        cout << "   Ma chuyen xe: " << chuyenXe.getMaChuyenXe() << endl;
        cout << "   Diem di: " << chuyenXe.getDiemDi() << endl;
        cout << "   Diem den: " << chuyenXe.getDiemDen() << endl;
        cout << "   Ngay gio khoi hanh: " << chuyenXe.getNgayGioKhoiHanh() << endl;
        //cout << "   Ngay gio du kien den: " << /*chuyenXe.getNgayGioDuKienDen()*/ << endl;
        cout << "   Gia ve co ban: " << chuyenXe.getGiaVeCoBan() << " VND" << endl;
        cout << "   So ve con lai: " << chuyenXe.getSoVeConLai() << endl;

        cout << "> Thong tin ve xe: " << endl;
        cout << "   Loai xe: " << chuyenXe.getLoaiXe() << endl; 
        cout << "   Bien so xe: " << chuyenXe.getBienSo() << endl; 
        cout << "   So cho: " << chuyenXe.getSoChoNgoi() << endl; 
        cout << "   Tien ich: ";
        for (const auto& ti : chuyenXe.getTienIch()) { 
            cout << ti.first << " (" << ti.second << " VND) ";
        }
        cout << endl;

        cout << "> Thong tin khac: " << endl;
        cout << "   Hanh trinh di chuyen: " << endl;
        for (const auto& stop : chuyenXe.getHanhTrinh()) {
            cout << "   - " << stop.diem << ": " << stop.thoiGian << " (dung " << stop.thoiGianDung << " phut)" << endl;
        }

        cout << "   Quy dinh hanh ly: Moi hanh khach duoc mang toi da 20kg hanh ly." << endl;
        cout << "   Chinh sach huy ve: Huy ve truoc 24h khoi hanh: Hoan 50% gia." << endl;
        cout << "> Thong tin lien he nha xe: " << "0834825528" << endl; 
    }
};