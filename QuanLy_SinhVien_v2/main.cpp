#include"lopHoc.h"
int main() {
	sinhVien sv;
	lopHoc lh;
	lh.nhap();
	cout << "\nDanh Sach Lop:";
	lh.xuat();
	lopHoc temp;
	cout << "\nNhap Vao Lua Chon:";
	cout << "\nIn Ra Danh Sach Sinh Vien Gioi:";
		temp = lh.timDsSinhVienGioi();
		temp.xuat();
	cout << "\nIn Ra Danh Sach Sinh Vien Kha:2";
		temp = lh.timDsSinhVienKha();
		temp.xuat();
	cout << "\nIn Ra Danh Sach Sinh Vien Trung Binh:3";
		temp = lh.timDsSinhVienTrungBinh();
		temp.xuat();
	cout << "\nIn Ra Danh Sach Sinh Vien Yeu:4";
		temp = lh.timDsSinhVienYeu2();
		temp.xuat();
	cout << "\nSap Xep Sinh Vien Tang Dan Theo DTB:5";
		temp = lh.sapxepTheoDiemTrungBinh();
		temp.xuat();
	cout << "\nSap Xep Sinh Vien Tang Dan Theo Ten:6";
		temp = lh.sapXepTheoTen();
		temp.xuat();
	cout << "\nTim Sinh Vien Theo MSSV:7";
	bool tam = lh.timTheoMSSV(sv);
		if (tam == true)
		{
			cout << "\nTim Thay:";
			sv.xuat();
		}
		else
		{
			cout << "\nTim khong Thay:";
		}
	cout << "\nTim Sinh Vien Theo Ten:8";
		temp = lh.timTheoTen();
		temp.xuat();
	return 0;
}