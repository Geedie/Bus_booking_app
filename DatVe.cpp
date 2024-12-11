#include"DatVe.h"

class DatVe {
public:
    string maChuyenXe;
    int soVe;
    KhachHang thongTinHanhKhach;
    vector<int> choNgoi;
    vector<string> tienIch;
    double giaVeCuoi;

    DatVe(const string& maXe, int soVe)
        : maChuyenXe(maXe), soVe(soVe), giaVeCuoi(0) {}
};

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class ProcessDatVeCommand : public Command {
private:
    unique_ptr<DatVe> datVe;
    ChuyenXe chuyenXe;

public:
    ProcessDatVeCommand(unique_ptr<DatVe> b) : datVe(move(b)) {}

    void execute() override {
        cout << "> Dat ve " << datVe->maChuyenXe << endl;

        cout << "> Nhap so ve: " << datVe->soVe << endl;

        cout << "> Thong tin hanh khach: " << endl;
        cout << "> Ho Ten: " << datVe->thongTinHanhKhach.getHoTen() << endl;
        cout << "> So dien thoai: " << datVe->thongTinHanhKhach.getSoDienThoai() << endl;
        cout << "> Email: " << datVe->thongTinHanhKhach.getEmail() << endl;
        cout << "Chon cho ngoi (Hien thi so cho ngoi): " << endl;
        for (const auto& seat : datVe->choNgoi) {
            cout << " - Cho ngoi: " << seat << endl;
        }
        cout << endl;
        cout << "> Chon tien ich: " << endl;
        for (const auto& extra : datVe->tienIch) {
            cout << " - " << extra << endl;
        }

        datVe->giaVeCuoi = tinhtoanGiaVe();
        cout << "> Tong gia ve: " << datVe->giaVeCuoi << " VND" << endl;

        luuVeVaoDuLieu(*this->datVe);
    }

    bool checkChoNgoi() {
        return true;
    }

    double tinhtoanGiaVe() {
        return datVe->soVe * chuyenXe.getGiaVeCoBan();
    }

    void luuVeVaoDuLieu(const DatVe& datVe) {
        ofstream file("ttVe.txt", ios::app);
        if (file.is_open()) {
            file << datVe.maChuyenXe << endl;
            file << datVe.soVe << endl;
            file << datVe.thongTinHanhKhach.getHoTen() << " - " << datVe.thongTinHanhKhach.getSoDienThoai() << endl;
            for (const auto& seat : datVe.choNgoi) {
                file << seat << " ";
            }
            file << endl;
            for (const auto& extra : datVe.tienIch) {
                file << extra << " ";
            }
            file << endl;
            file << datVe.giaVeCuoi<< endl;
            file << endl;

            file.close();
        }
        else {
            return;
        }
    }
};

class DatVeSystem {
private:
    vector<shared_ptr<Command>> commands;

public:
    void addCommand(shared_ptr<Command> command) {
        commands.push_back(command);
    }

    void processCommands() {
        for (const auto& command : commands) {
            command->execute();
        }
        commands.clear();
    }
};

void mainDatVe(string maCX, vector<string> tienIch, KhachHang khachHang, vector<int> choNgoi) {
    DatVeSystem datVeSystem;
    auto datVe = make_unique<DatVe>(maCX, choNgoi.size());
    datVe->thongTinHanhKhach = khachHang;
    datVe->choNgoi = choNgoi;
    datVe->tienIch = tienIch;

    datVeSystem.addCommand(make_shared<ProcessDatVeCommand>(move(datVe)));

    datVeSystem.processCommands();
}
