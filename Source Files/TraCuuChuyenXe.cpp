#include"TraCuuChuyenXe.h"


class TraCuuCX {
public:
    virtual bool apply(const ChuyenXe& chuyenXe) const = 0;
    virtual ~TraCuuCX() = default;
};


class DiemDiFilter : public TraCuuCX {
private:
    string diemDi;
public:
    explicit DiemDiFilter(const string& diemDi) : diemDi(diemDi) {}

    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getDiemDi() == diemDi;
    }
};
class DiemDenFilter : public TraCuuCX {
private:
    string diemDen;
public:
    explicit DiemDenFilter(const string& diemDen) : diemDen(diemDen) {}

    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getDiemDen() == diemDen;
    }
};
class LoaiXeFilter : public TraCuuCX {
private:
    string loaiXe;
public:
    explicit LoaiXeFilter(const string& loaiXe) : loaiXe(loaiXe) {}

    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getLoaiXe() == loaiXe;
    }
};
class NgayKhoiHanhFilter : public TraCuuCX {
private:
    string ngayKhoiHanh;
public:
    explicit NgayKhoiHanhFilter(const string& ngayKhoiHanh) : ngayKhoiHanh(ngayKhoiHanh) {}

    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getNgayGioKhoiHanh() == ngayKhoiHanh;
    }
};
class GiaVeCoBanFilter : public TraCuuCX {
private:
    double GiaVeCoban;
public:
    explicit GiaVeCoBanFilter(double giaVe) : GiaVeCoban(giaVe) {}
    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getGiaVeCoBan() == GiaVeCoban;
    }
};
class TienIchFilter : public TraCuuCX {
private:
    map<string, double> tienIch;
public:
    explicit TienIchFilter(map<string, double> tienIch) : tienIch(tienIch) {}
    bool apply(const ChuyenXe& chuyenXe) const override {
        return chuyenXe.getTienIch() == tienIch;
    }
};

class ChuyenXeFilter {
private:
    TraCuuCX* traCuuCX = nullptr;

public:
    void setTraCuuCX(TraCuuCX* newTraCuuCX) {
        traCuuCX = newTraCuuCX;
    }

    vector<ChuyenXe> filter(const string& ttChuyenXe) const {
        vector<ChuyenXe> results;

        ifstream file(ttChuyenXe);
        if (!file.is_open()) {
            cerr << "Không thể mở file: " << ttChuyenXe << endl;
            return results;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);

            string maChuyenXe, diemDi, diemDen, ngayGioKhoiHanh, loaiXe;
            double giaVeCoBan;
            int soVeConLai;

            string bienSo;
            int soChoNgoi;
            map<string, double> tienIch;

            if (!(iss >> maChuyenXe >> diemDi >> diemDen >> ngayGioKhoiHanh >> giaVeCoBan >> soVeConLai >> bienSo >> loaiXe >> soChoNgoi)) {
                cerr << "Dữ liệu không hợp lệ: " << line << endl;
                continue;
            }

            string tenTienIch;
            double giaTienIch;
            while (iss >> tenTienIch >> giaTienIch) {
                tienIch[tenTienIch] = giaTienIch;
            }

            Xe xe(bienSo, loaiXe, soChoNgoi, tienIch);

            ChuyenXe chuyenXe(maChuyenXe, diemDi, diemDen, ngayGioKhoiHanh, giaVeCoBan, soVeConLai);
            chuyenXe.setBienSo(bienSo);
            chuyenXe.setLoaiXe(loaiXe);
            chuyenXe.setSoChoNgoi(soChoNgoi);
            chuyenXe.setTienIch(tienIch);

            if (traCuuCX && traCuuCX->apply(chuyenXe)) {
                results.push_back(chuyenXe);
            }
        }

        file.close();
        return results;
    }
};



void mainFilter(string diemDi,string diemDen, string ngayKhoiHanh, double KhoangGia, string loaiXe, map<string,double> tienIch) {
    ChuyenXeFilter filter;

    DiemDiFilter diemDiFilter(diemDi);
    DiemDenFilter diemDenFilter(diemDen);
    LoaiXeFilter loaiXeFilter(loaiXe);
    NgayKhoiHanhFilter NgayGioKhoiHanh(ngayKhoiHanh);
    GiaVeCoBanFilter giaVeCoBanFilter(KhoangGia);
    TienIchFilter tienIchFilter(tienIch);

    filter.setTraCuuCX(&diemDiFilter);
    filter.setTraCuuCX(&diemDenFilter);
    filter.setTraCuuCX(&loaiXeFilter);
    filter.setTraCuuCX(&NgayGioKhoiHanh);
    filter.setTraCuuCX(&giaVeCoBanFilter);
    filter.setTraCuuCX(&tienIchFilter);



    auto results = filter.filter("ttChuyenXe.txt");

    cout << "> Ket qua tim kiem:" << endl;
    cout << "| Ma chuyen | Gio khoi hanh | Loai xe | Gia ve | Ve con lai | " << endl;
    cout << "|-----------|---------------|---------|--------|------------| " << endl;

    for (const auto& chuyenXe : results) {
        cout << "| " << chuyenXe.getMaChuyenXe() << "  | " << chuyenXe.getNgayGioKhoiHanh() << " | "
            << chuyenXe.getLoaiXe() << " | " << chuyenXe.getGiaVeCoBan() << " | " << chuyenXe.getSoVeConLai() << " | " << endl;
    }

    cout << "|-----------|---------------|---------|--------|------------| " << endl;

}
