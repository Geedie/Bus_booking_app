#pragma once

#include <string>
#include<iostream>
using namespace std;

class User {
private:
    string hoTen;
    string soDienThoai;
    string email;

public:
    User() {}
    User(string hoTen, string soDienThoai, string email)
        : hoTen(hoTen), soDienThoai(soDienThoai), email(email) {}

    virtual ~User() {}

    string getHoTen() const {
        return hoTen; 
    }
    string getSoDienThoai() const { 
        return soDienThoai; 
    }
    string getEmail() const { 
        return email; 
    }

    void setTT(const string soDT) {
        this->soDienThoai = soDT;
        cout << "Vui lòng nhập vào họ tên (vd: Huynh Van A): ";
        getline(cin, hoTen);
        cout << "Nhập vào email (vd: huynhvana@gmail.com): ";
        getline(cin, email);
        cin.ignore();   
    }

    void setHoTen(const string& hoTen) { 
        this->hoTen = hoTen; 
    }
    void setSoDienThoai(const string& soDienThoai) {
        this->soDienThoai = soDienThoai; 
    }
    void setEmail(const string& email) { 
        this->email = email; 
    }

    void displayDetails() const {
        cout << "> Ho Ten: " << hoTen << endl;
        cout << "> SDT: " << soDienThoai << endl;
        cout << "> Email: " << email << endl;
    }
};