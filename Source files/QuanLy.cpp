#include"ChuyenXe.h"
#include"Ve.h"
#include"Xe.h"
#include"BaoCaoThongKe.h"
//#include"DocTT.h"

void QLHT() {
	int n;
	 do{
		cout << "> quan-ly-he-thong" << endl;
		cout << "> Chon chuc nang :" << endl;
		cout << "> 1. Quan ly chuyen xe"<<endl;
		cout << "> 2. Quan ly xe" << endl;
		cout << "> 3. Quan ly ve"<<endl;
		cout << "> 4. Bao cao thong ke" << endl;
		cout << "> 5. Doc thong tin tu file" << endl;
		cout << "> 6. Quay lai" << endl;
		cout << "> Chon(1 - 6) :"<<endl;
		cin >> n;
		switch (n) {
		case 1: 
			QLCX();
			break;
		case 2:
			QLX();
			break;
		case 3:
			QLVX();
			break;
		case 4:
			MenuDoanhThu();
			break;
		case 5:
			//DocTT();
			break;
		case 6:
			break;
		default:
			cout << "> Loi nhap vao ! Vui long nhap lai" << endl;
			break;
		}
	 } while (n != 6);
}