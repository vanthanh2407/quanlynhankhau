#include<iostream>
#include<iomanip>
using namespace std;
//======= Thong tin nguoi ===============
struct DateOfBirth
{
	int ngay_sinh; // nagy sinh nguoi
	int thang_sinh; // thang sinh nguoi
	int nam_sinh; // nam sinh nguoi
};
struct  Nguoi
{
	long long cmnd; // chung minh nhan dan  mot nguoi
	char ten[30]; // ten nguoi
	DateOfBirth sinh_nhat;// ngay thang nam sinh
	char dia_chi[60]; // dia chi thuong tru  cua nguoi
	long long so_dienthoai; // so dien thoai lien lac
};
struct Node
{
	Nguoi info;
	Node* next;
};
typedef   Node* NodeNguoi;

//=========== Thong tin nhan khau=================
struct HoKhau
{
	long long id_hokhau; // ma ho khau
	char ten_chuho[30]; // ten chu ho
	char dia_chi[60]; // dia chi
	int so_nhankhau; // so so nhan khau
	long long so_dienthoaiban; // so dien thoai ban
	NodeNguoi ds_nguoi;  // danh sach nguoi 
};
struct NodeHK
{
	HoKhau info;
	NodeHK* next;
};
typedef   NodeHK* NodeHoKhau;

//================ kiem tra ngay thang nam
int kiemtraNgayThangNam(DateOfBirth x);
int laNamNhuan(DateOfBirth x);
//================ Tao Node Nguoi
NodeNguoi createrNode_Nguoi(Nguoi x);
//================ Tao nut Ho khau 
NodeHoKhau createrNode_HoKhau(HoKhau x);
//================  ham kiem tra cmnd co bi trung hay khong
bool kiemTraTrung_cmnd(NodeNguoi& list, int check);
// ham kiem tra ma ho khau co bi trung hay khong
bool kiemTraTrung_id_hokhau(NodeHoKhau& list, int check);
//================ Nhập thông tin của một người 
void nhap_thong_tin_nguoi(NodeNguoi& list);
//================  xuat danh sach  nguoi
void xuat_danh_sach_nguoi(NodeNguoi list);
//================ Nhập thong tin ho khau
void nhap_thong_tin_HoKhau(NodeHoKhau& list);
// xuat thong tin mot ho khau
void xuat_hoKhau(HoKhau hokhau);
//================ xuat danh sach nhan khau
void xuat_danh_sach_HoKhau(NodeHoKhau list);
//================b. Them ho khau vao vi tri bat ki. 
void them_hoKhau_viTri_batKi(NodeHoKhau& list_hk, int vitri);
// Đếm số phần tử trong danh sách 
int SizeOfList(NodeHoKhau x);
//============ c. Xoa mot ho khau khi biet ten chu ho hoac dia chi.
void xoa_hoKhau_tenChuHo(NodeHoKhau& list_hk, HoKhau hokhau);
void xoa_hoKhau_diachi(NodeHoKhau& list_hk, HoKhau hokhau);
//============ d. Cho phep tim ho khau khi biet ten chu ho hoac dian thoai.
void timKiem_hoKhau_tenChuHo_hoac_dienThoai(NodeHoKhau list, HoKhau hokhau);
//======== e. Them mot nguoi vao ho khau khi biet ma ho khau.
void themNguoi_hoKhau_id_hoKhau(NodeHoKhau& list_hk, HoKhau hokhau);