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
		cout << "\nNhap Vao Si So Lop Hoc:";
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
	void xuat() {
		cout << "\nMa Lop Hoc:" << this->maLopHoc;
		cout << "\nTen Lop Hoc:" << this->tenLopHoc;
		cout << "\nSi So Lop:" << this->siSo;
		cout << "\nDanh Sach Sinh Vien:";
		for (int i = 0; i < this->siSo; i++)
		{
			cout << "\nSinh Vien Thu:" << i + 1;
			this->dsSinhVien[i].xuat();
		}
	}
	//tim diem trung binh
	float timDiemAVG() {
		float diemAVG = 0;
		for (int i = 0; i < this->siSo; i++)
		{
			diemAVG = diemAVG + this->dsSinhVien[i].tinhDiemTrungBinh();
		}
		return diemAVG / this->siSo;
	}
	//tim Diem trung binh lon nhat
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
	//tim Diem trung binh nho nhat
	float timDiemMIN() {
		float diemMIN = dsSinhVien[0].tinhDiemTrungBinh();
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].tinhDiemTrungBinh() < diemMIN) {
				diemMIN = this->dsSinhVien[i].tinhDiemTrungBinh();
			}
		}
		return diemMIN;
	}
	// tim Sinh vien theo mssv
	bool timTheoMSSV(sinhVien& sv) {
		string mssv;
		cout << "\nNhap Vao MSSV Muon Tim:";
		cin.ignore(1);
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
	//tim Sinh vien theo Ten
	lopHoc timTheoTen() {
		lopHoc kq;
		string ten;
		cout << "\nNhap Vao Ten Sinh Vien Muon Tim:";
		getline(cin, ten);
		for (int i = 0; i < this->siSo; i++)
		{
			if (ten.compare(this->dsSinhVien[i].tachTen()) == 0) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	// tim Danh Sach Sinh vien yeu
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
			if (this->dsSinhVien[i].xepLoai().compare("Yeu") == 0)
			{
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	//timDsSinhVienKha
	lopHoc timDsSinhVienKha() {
		lopHoc kq;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].xepLoai().compare("Kha") == 0) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	//tim danh sach sinh vien gioi
	lopHoc timDsSinhVienGioi() {
		lopHoc kq;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].xepLoai().compare("Gioi") == 0) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	//tim ds Sinh vien trung binh
	lopHoc timDsSinhVienTrungBinh() {
		lopHoc kq;
		for (int i = 0; i < this->siSo; i++)
		{
			if (this->dsSinhVien[i].xepLoai().compare("Trung Binh") == 0) {
				kq.dsSinhVien[kq.siSo++] = this->dsSinhVien[i];
			}
		}
		return kq;
	}
	//sap xep ds sinh vien tang dan theo diem trung binh
	lopHoc sapxepTheoDiemTrungBinh() {
		lopHoc kq = *this;
		for (int i = 0; i < kq.siSo -1; i++)
		{
			for (int j = i + 1; j < kq.siSo;j++) {
				if (kq.dsSinhVien[i].tinhDiemTrungBinh() > kq.dsSinhVien[i].tinhDiemTrungBinh())
				{
					swap(kq.dsSinhVien[i], kq.dsSinhVien[j]);
				}
			}
		}
		return kq;
	}
	//sap xep ds sinh vien tang dan theo ten
	lopHoc sapXepTheoTen() {
		lopHoc kq = *this;
		for (int i = 0; i < kq.siSo - 1; i++)
		{
			for (int j = i + 1; j < kq.siSo; j++) {
				if (kq.dsSinhVien[i].tachTen().compare(kq.dsSinhVien[j].tachTen()) >0)
				{
					swap(kq.dsSinhVien[i], kq.dsSinhVien[j]);
				}
			}
		}
		return kq;
	}
};

