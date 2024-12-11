#include"ThanhToan.h"



class ThanhToan {
public:
    virtual void thanhToan(double giaVe) = 0;
    virtual void displayInstructions() = 0;
};

class ThanhToanThe : public ThanhToan {
public:
    void thanhToan(double giaVe) override {
        cout << "> Dang xu ly thanh toan bang the tin dung" << endl;
    }

    void displayInstructions() override {
        cout << "> Nhap thong tin the (so the, ngay het han, ma CVV)." << endl;
    }
};
class ThanhToanNH : public ThanhToan {
public:
    void thanhToan(double giaVe) override {
        cout << "> Dang xu ly thanh toan bang chuyen khoan ngan hang..." << endl;
    }

    void displayInstructions() override {
        cout << "> Thong tin tai khoan ngan hang: [Thong tin tai khoan]." << endl;
    }
};
class ThanhToanBankingOnline : public ThanhToan {
public:
    void thanhToan(double giaVe) override {
        cout << "> Dang xu ly thanh toan bang vi dien tu..." << endl;
    }

    void displayInstructions() override {
        cout << "> Quet ma QR de thanh toan." << endl;
    }
};
class ThanhToanTrucTiep : public ThanhToan {
public:
    void thanhToan(double giaVe) override {
        cout << "> Dang xu ly thanh toan bang tien mat..." << endl;
    }

    void displayInstructions() override {
        cout << "> Thanh toan tien mat khi nhan ve." << endl;
    }
};

void QTThanhToan(ThanhToan* thanhToan, double giaVe) {
    thanhToan->displayInstructions();
    thanhToan->thanhToan(giaVe);
}

void mainThanhToan(Ve& ve) {

    int choice;
    cout << "> Chon phuong thuc thanh toan:" << endl;
    cout << "> 1. Thanh toan bang the tin dung" << endl;
    cout << "> 2. Thanh toan bang chuyen khoan ngan hang" << endl;
    cout << "> 3. Thanh toan bang vi dien tu" << endl;
    cout << "> 4. Thanh toan truc tiep" << endl;
    cout << "> Lua chon cua ban: ";
    cin >> choice;

    ThanhToan* thanhToan = nullptr;

    switch (choice) {
    case 1:
        thanhToan = new ThanhToanThe();
        break;
    case 2:
        thanhToan = new ThanhToanNH();
        break;
    case 3:
        thanhToan = new ThanhToanBankingOnline();
        break;
    case 4:
        thanhToan = new ThanhToanTrucTiep();
        break;
    default:
        cout << "> Lua chon khong hop le." << endl;
        return;
    }

    QTThanhToan(thanhToan, ve.getGiaVe());
    ve.setTrangThai("DaThanhToan");
    delete thanhToan; 
}