#pragma once
#include<fstream>
#include<vector>
#include"KhachHang.h"
#include"QuanLy.h"






extern vector<KhachHang> DsKhachHang;
extern vector<QuanLy> DsQuanLy;

using namespace std;

class Login {
private:
	static Login* instance;
	KhachHang* khachHang = nullptr;
	Login() {}
public:

	static Login* getInstance() {
		if (!instance) {
			instance = new Login;
		}
		return instance;
	}

	static void deleteInstance() {
		if (instance) {
			delete instance;
			instance = NULL;
		}

	}

	void login(string user, string password, bool type) {

		ifstream file;
		bool DangNhap = false;

		if (type) {

			file.open("AccountKH.txt", ios::in);

			if (file.is_open()) {

				string fileUser, filePassword;

				while (file >> fileUser >> filePassword) {
					if (fileUser == user && filePassword == password) {
						DangNhap = true;
						break;
					}
				}
			}
		}

		else {

			file.open("AccountQL.txt", ios::in);

			if (file.is_open()) {

				string fileUser, filePassword;

				while (file >> fileUser >> filePassword) {
					if (fileUser == user && filePassword == password) {
						DangNhap = true;
						break;
					}
				}

			}
		}

		if (DangNhap) {
			for (auto Khach : DsKhachHang) {
				if (Khach.getSoDienThoai() == user) {
					khachHang = &Khach;
					break;
				}
			}
		}


		file.close();
	}

};

class SignUp {
private:
	KhachHang* khachHang = new KhachHang;
	static SignUp* instance;
	SignUp(){}
public:

	static SignUp* getInstance() {
		if (!instance) {
			instance = new SignUp;
		}
		return instance;
	}

	static void deleteInstance() {
		if (instance) {
			delete instance;
			instance = NULL;
		}

	}

	void signup(string user, string password, bool type) {
		fstream file;
		file.open("AccountKH.txt", ios::out);
		if (file.is_open()) {
			string fileUser, filePassword;
			file.seekg(0, ios::end);
			if (file.eof()) {
				file << endl << user << " " << password;
				cout << "> Dang ki  thanh congh" << endl;
				khachHang->setTT(user);
				DsKhachHang.push_back(*khachHang);
			}
			else {
				cout << "Dang ki khong thanh cong";
				file.close();
				return;
			}
		}
		else {
			cout << "Dang ki khong thanh cong";
			file.close();
		}
		delete khachHang;
		file.close();
	}
};

