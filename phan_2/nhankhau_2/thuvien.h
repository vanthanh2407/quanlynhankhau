#define _CRT_SECURE_NO_WARNINGS
#include<iostream> //chứa hàm xuất nhập cout và cin
#include<iomanip>//Định nghĩa nhiều phép điều chỉnh mà nó lấy vào một đối số.
#include <string.h> //chứa các hàm về chuỗi
#include <fstream>//Định nghĩa các lớp hỗ trợ các phép toán cho dòng xuất nhập trên các chuỗi chứa trong các tập tin bên ngoài
using namespace std;

// thong tin mot nguoi
struct  People
{
	int id;
	char name[30];
	int date_birth;
	int month_birth;
	int year_birth;
	char address[60];
	int phone_number;
};
// danh sach lien ket don
struct Node
{
	People data;
	Node* link;
};
typedef  Node* Nodeptr;
typedef   Nodeptr  ListPeople;
// Ham tao node nhan khau
Nodeptr tao_node_people(People nguoi);
// khoi tao danh sach lien ket don
void initialize_list(ListPeople& list);
// ham them nguoi vao cuoi danh sach
void them_cuoi(ListPeople& list, People nguoi);
// ham kiem tra cmnd co bi trung hay khong
bool kiemTra_trung_id(ListPeople& list, int check_id);
// Nhập thông tin của một người
void nhap_thong_tin_mot_nguoi(ListPeople& list, People& nguoi);
// a.nhap danh sach nhan khau
void nhap_danh_sach_nguoi(ListPeople& list);
// Xuất thông tin của một người
void xuat_thong_tin_mot_nguoi(People nguoi);
// xuat danh sach nhan khau
void xuat_danh_sach_nguoi(ListPeople list);
// Đếm số phần tử trong danh sách 
int SizeOfList(ListPeople list);
//b. Thêm vào vị trí bất kì trong danh sách
void them_nguoi(ListPeople& list, int vi_tri, People nguoi);
//c.1 Tím kiếm theo CMND
Nodeptr tim_kiem_tuan_tu_cmnd(ListPeople list, People nguoi);
//c.2 Tìm kiếm tuần tự Người theo tên
void tim_kiem_tuan_tu_ten(ListPeople list, People nguoi);
//c.3 tìm kiem  tuần tự theo số điện thoại
Nodeptr tim_kiem_tuan_tu_dien_thoai(ListPeople list, People nguoi);
//d.1 Cho phép xóa 1 người khi biết số CMND 
void xoa_nguoi_cmnd(ListPeople& list, People nguoi);
//d.2 Cho phép xóa 1 người khi biết số điện thoại.
void xoa_nguoi_dien_thoai(ListPeople& list, People nguoi);
//e.1Cho phép sắp xếp tăng  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_tang_cmnd(ListPeople& list);
//e.2Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  tên
void sap_xep_tang_ten(ListPeople& list);
//e.3Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_tang_dien_thoai(ListPeople& list);
//e.4Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_giam_cmnd(ListPeople& list);
//e.5Cho phép sắp xếp giam danh sách những người này theo  tiêu chí  :  tên
void sap_xep_giam_ten(ListPeople& list);
//e.6Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_giam_dien_thoai(ListPeople& list);
///f.Doc Danh sach NHAN KHAU tu file.
void doc_nhan_khau_file(ListPeople& list, char* file_name);
// xoa node cuoi danh sach
void xoa_cuoi(ListPeople& list);
//g.Ghi Danh sach NHAN KHAU tu file.
void ghi_nhan_khau_file(ListPeople list, char* file_name);
