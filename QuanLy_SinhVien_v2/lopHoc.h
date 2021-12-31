#pragma once
#include"sinhVien.h"
class lopHoc
{
private:
	string tenLopHoc;
	string maLopHoc;
	int siSo;
	sinhVien dsSinhVien[100];
public:
	lopHoc() {
		this->maLopHoc = "";
		this->tenLopHoc = "";
		this->siSo = 0;
	}
	lopHoc(string malophoc, string tenlop, int siso) {
		this->maLopHoc = malophoc;
		this->tenLopHoc = tenlop;
		this->siSo = siso;
	}
	~lopHoc() {
		return;
	}
	bool checkMSSV(string mssv) {
		for (int i = 0; i < this->siSo; i++)
		{
			if (mssv.compare(this->dsSinhVien[i].getMssv()) == 0) {
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	void nhap() {
		cout << "\nNhap Vao Ma Lop Hoc:";
		getline(cin, this->maLopHoc);
		cout << "\nNhap Vao Ten Lop Hoc:";
		getline(cin, this->tenLopHoc);
		cout << "\nNhap Vao Si So Lop Hoc;";
		cin >> this->siSo;
		for (int i = 0; i < this->siSo; i++)
		{
			sinhVien sv;
			cout << "\nNhap Vao sinh Vien Thu [" << i+1 << "]";
			do
			{
				sv.nhap();
			} while (checkMSSV(sv.getMssv()));
			this->dsSinhVien[i] = sv;
		}
	}
	float timDiemAVG() {
		float diemAVG = 0;
		for (int i = 0; i < this->siSo; i++)
		{
			diemAVG = diemAVG + this->dsSinhVien[i].tinhDiemTrungBinh();
		}
		return diemAVG / this->siSo;
	}
	float timDiemMAX() {
		float diemMAX = 0;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].tinhDiemTrungBinh() > diemMAX) {
				diemMAX = this->dsSinhVien[i].tinhDiemTrungBinh();
			}
		}
		return diemMAX;
	}
	float timDiemMIN() {
		float diemMIN = 0;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].tinhDiemTrungBinh() < diemMIN) {
				diemMIN = this->dsSinhVien[i].tinhDiemTrungBinh();
			}
		}
		return diemMIN;
	}
	bool timTheoMSSV(sinhVien& sv) {
		string mssv;
		cout << "\nNhap Vao MSSV Muon Tim:";
		getline(cin, mssv);
		for (int i = 0; i < this->siSo; i++)
		{
			if (mssv.compare(this->dsSinhVien[i].getMssv()) == 0) {
				sv = this->dsSinhVien[i];
				return true;
			}
		}
		return false;
	}
	lopHoc timTheoTen() {
		lopHoc kq;
		string ten;
		cout << "\nNhap Vao Ten Sinh Vien Muon Tim:";
		for (int i = 0; i < this->siSo; i++)
		{
			if (ten.compare(this->dsSinhVien[i].tachTen()) == 0) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	lopHoc timDsSinhVienYeu() {
		lopHoc kq;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].tinhDiemTrungBinh() < 5) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	//tìm ds sinh viên yếu cách 2
	lopHoc timDsSinhVienYeu2() {
		lopHoc kq;
		for (int i = 0; i < this->siSo; i++)
		{

		}
	}
};

