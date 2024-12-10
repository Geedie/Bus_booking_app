#ifndef KHACHHANG_H
#define KHACHHANG_H
#pragma once
#include"User.h"


class KhachHang : public User {
public:
    KhachHang(){}
    KhachHang(const KhachHang& khachHang) {
        *this = khachHang;
    }
};

#endif
