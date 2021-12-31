#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
#include <conio.h>
using namespace std;
class sinhVien
{
private:
	string Mssv;
	string hoTen;
	float diemToan;
	float diemVan;
public:
	sinhVien() {
		this->Mssv = "";
		this->hoTen = "";
		this->diemToan = 0;
		this->diemVan = 0;
	}
	sinhVien(string mssv, string hoten, float diemtoan, float diemvan) {
		this->Mssv = mssv;
		this->hoTen = hoten;
		this->diemToan = diemtoan;
		this->diemVan = diemvan;
	}
	~sinhVien() {
		return;
	}
	void setHocTen(string hocten) {
		this->hoTen = hocten;
	}
	void setMssv(string mssv) {
		this->Mssv = mssv;
	}
	void setDiemToan(float diemtoan) {
		this->diemToan = diemtoan;
	}
	void setDiemVan(float diemvan) {
		this->diemVan = diemvan;
	}
	string getMssv() {
		return this->Mssv;
	}
	string getHocTen() {
		return this->hoTen;
	}
	float getDiemToan() {
		return this->diemToan;
	}
	float getDiemVan() {
		return this->diemVan;
	}
	void nhap() {
		cout << "\nNhap Vao MSSV:";
		cin.ignore(1);
		getline(cin, this->Mssv);
		cout << "\nNhap Vao Hoc Ten:";
		getline(cin, this->hoTen);
		cout << "\nNhap Vao Diem Toan:";
		cin >> this->diemToan;
		cout << "\nNhap Vao Diem Van:";
		cin >> this->diemVan;
	}
	float tinhDiemTrungBinh() {
		return (this->diemToan + this->diemVan) / 2;
	}
	string xepLoai() {
		if (this->tinhDiemTrungBinh() < 5)
		{
			return "Yeu";
		}
		else if (this->tinhDiemTrungBinh() < 7) {
			return "Trung Binh";
		}
		else if (this->tinhDiemTrungBinh() < 8.5)
		{
			return "Kha";
		}else
		{
			return "Gioi";
		}
	}
	string tachTen() {
		string ten = "";
		int vitri = -1;
		int soKyTu = 0;
		vitri = this->hoTen.find_last_of(" ");
		soKyTu = this->hoTen.length() - vitri;
		ten = this->hoTen.substr(vitri+1, soKyTu);
		return ten;
	}
	void xuat() {
		cout << "\nKet Qua Hoc Tap:";
		cout << "\nChuc Muong Sinh Vien:" << this->hoTen;
		cout << "\nMSSV:" << this->Mssv;
		cout << "\nDat Duoc Diem Trung Binh Mon:" << this->tinhDiemTrungBinh();
		cout << "\nDuoc Xep Loai:" << this->xepLoai();
	}
};

