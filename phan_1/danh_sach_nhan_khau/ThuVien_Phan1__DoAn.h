#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
using namespace std;
//Thông tin của 1 người(Nhân khẩu)
struct  People
{
	int so_cmnd ;
	char ten [30];
	int ngay_sinh;
	int thang_sinh;
	int nam_sinh;
	char dia_chi [50];
	int dien_thoai;
};
const int MAX= 100;// số lượng nguời tối đa
// Danh sach Nguoi
struct ListPeople
{
	int so_nguoi;// số lượng nguời
	People data[MAX];
};
// dat so phan tu trong danh sach bang 0
void initialize(ListPeople &danh_sach);
// Nhập thông tin của một người
void nhap_thong_tin_mot_nguoi(People &nguoi);
// Xuất thông tin của một người
void xuat_thong_tin_mot_nguoi(People nguoi);
// Xuất Danh sach nguoi
void xuat_danh_sach_nguoi(ListPeople danh_sach);
//a. Cho phép nhập vào 1 Danh sách người.
void nhap_danh_sach_nguoi(ListPeople&danh_sach);
//b. Thêm vào vị trí bất kì trong danh sách
void them_nguoi(ListPeople &danh_sach, int vi_tri, People nguoi);
//c.1 Tím kiếm theo CMND
int tim_kiem_tuan_tu_cmnd(ListPeople danh_sach,int tim_so_cmnd);
//c.2 Tìm kiếm tuần tự Người theo tên
void tim_kiem_tuan_tu_ten(ListPeople danh_sach, char* tim_ten);
//c.3 tìm kiem  tuần tự theo số điện thoại
int tim_kiem_tuan_tu_dien_thoai(ListPeople danh_sach, int tim_dien_thoai);
//d.1 Cho phép xóa 1 người khi biết số CMND 
void xoa_nguoi_CMND(ListPeople&danh_sach, int xoa_so_cmnd);
//d.2 Cho phép xóa 1 người khi biết số điện thoại.
void xoa_nguoi_dien_thoai(ListPeople&danh_sach, int xoa_dien_thoai);
//e.1Cho phép sắp xếp tăng  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_tang_CMND(ListPeople&danh_sach);
//e.2Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  tên
void sap_xep_tang_ten(ListPeople&danh_sach);
//e.3Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_tang_dien_thoai(ListPeople&danh_sach);
//e.4Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_giam_CMND(ListPeople&danh_sach);
//e.5Cho phép sắp xếp giam danh sách những người này theo  tiêu chí  :  tên
void sap_xep_giam_ten(ListPeople &danh_sach);
//e.6Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_giam_dien_thoai(ListPeople & danh_sach);
///f.Doc Danh sach NHAN KHAU tu file.
void doc_nhan_khau_file(ListPeople & danh_sach, char* file_name);
//g.Ghi Danh sach NHAN KHAU tu file.
void ghi_nhan_khau_file(ListPeople danh_sach, char* file_name);
