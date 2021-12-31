#include"sinhVien.h"
int main() {
	sinhVien sv;
	sv.nhap();
	sv.xuat();
	string tachten = sv.tachTen();
	cout << "\nSau Khi Tach Ten:" << tachten;
	return 0;
}