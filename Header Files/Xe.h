
#ifndef XE_H
#define XE_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Xe {
private:
    string bienSo;
    string loaiXe;
    int soChoNgoi;
    map<string, double> tienIch;

public:
    Xe() {}

    Xe(string bienSo, string loaiXe, int soChoNgoi, map<string, double> tienIch)
        : bienSo(bienSo), loaiXe(loaiXe), soChoNgoi(soChoNgoi), tienIch(tienIch) {}
    virtual ~ Xe(){}

    virtual void inThongTin() {
        cout << endl;
        cout << "Biển số Xe: " << bienSo << endl;
        cout << "Loại xe: " << loaiXe << endl;
        cout << "Số chỗ ngồi: " << soChoNgoi << endl;
        cout << "Các tiện ích: " <<  endl;
        for (auto it = tienIch.begin(); it != tienIch.end(); ++it) {
            cout <<  it->second << ": " << it->first << endl;
        }

    }

    string getBienSo() const { 
        return bienSo; 
    }
    string getLoaiXe() const { 
        return loaiXe; 
    }
    int getSoChoNgoi() const { 
        return soChoNgoi; 
    }
    map<string, double> getTienIch() const { 
        return tienIch; 
    }

    void setBienSo(const string& bienSo) { 
        this->bienSo = bienSo; 
    }
    void setLoaiXe(const string& loaiXe) { 
        this->loaiXe = loaiXe; 
    }
    void setSoChoNgoi(int soChoNgoi) { 
        this->soChoNgoi = soChoNgoi;
    }
    void setTienIch(const map<string, double>& tienIch) { 
        this->tienIch = tienIch; 
    }
};

void QLX();

#endif