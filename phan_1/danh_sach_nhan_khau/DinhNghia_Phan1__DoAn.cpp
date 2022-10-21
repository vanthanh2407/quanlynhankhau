#include"ThuVien_Phan1__DoAn.h"
/* Định nghĩa các hàm sẽ xây dựng*/

// Nhập thông tin của một người
void nhap_thong_tin_mot_nguoi(People& nguoi)
{
		cout << "Nhap so CMND: ";
		cin >> nguoi.so_cmnd;
	cout << "Nhap ten: ";
	cin.ignore();
	cin.getline(nguoi.ten, 30);
	cout << "Nhap ngay thang nam sinh: \n";
	do {
		cout << "Nhap ngay sinh: ";
		cin >> nguoi.ngay_sinh;
	} while (nguoi.ngay_sinh>31||nguoi.ngay_sinh<1);// ngay sinh nam trong doan tu 1->31
	do {
		cout << "Nhap thang sinh: ";
		cin >> nguoi.thang_sinh;
	} while (nguoi.thang_sinh >12 ||nguoi.thang_sinh<1);// thang sinh nam trong doan tu 1->12
	do {
		cout << "Nhap nam sinh: ";
		cin >> nguoi.nam_sinh;
	} while (nguoi.nam_sinh >2020|| nguoi.nam_sinh<1600);// nam sinh nam trong doan tu 1600->2020
	cin.ignore();
	cout << "Nhap dia chi thuong tru: ";
	cin.getline(nguoi.dia_chi, 50);
	cout << "Nhap so dien thoai: ";
	cin >> nguoi.dien_thoai;
}
// dat so phan tu trong danh sach bang 0
void initialize(ListPeople& danh_sach)
{
	danh_sach.so_nguoi = 0;
}
// Xuất thông tin của một người
void xuat_thong_tin_mot_nguoi(People nguoi)
{
	cout << "\n" << nguoi.so_cmnd << setw(15) << nguoi.ten << setw(10) << nguoi.ngay_sinh << "/" << nguoi.thang_sinh << "/" << nguoi.nam_sinh << setw(20) << nguoi.dia_chi << setw(20) << nguoi.dien_thoai;
}

//a.	Cho phép nhập vào một danh sách người
void nhap_danh_sach_nguoi(ListPeople& danh_sach)
{	
	do {
		cout << "\nNhap so luong Nguoi cua Danh sach: ";
		cin >> danh_sach.so_nguoi;
	} while (danh_sach.so_nguoi <= 0 || danh_sach.so_nguoi > MAX);
	cout << "\nNhap thong tin cho tung nhan khau trong danh sach. ";
	cout << "\n_______________________________________________________________________________________________\n";
	for (int i = 0; i < danh_sach.so_nguoi; i++)
	{
		cout << "\nThong tin Nguoi  thu: " << i + 1 << endl;
		nhap_thong_tin_mot_nguoi(danh_sach.data[i]);		
		cout << "_______________________________________________________________________________________________\n";
	}
}

// Xuất Danh sach nguoi
void xuat_danh_sach_nguoi(ListPeople danh_sach)
{
	cout << "\n________________________________________________________________________________________________";
	cout << "\nSo CMND" << setw(10) << "Ten" << setw(25) << "ngay sinh" << setw(20) << "Dia chi" << setw(20) << "So dien thoai";
	for (int i = 0; i < danh_sach.so_nguoi; i++)
	{
		xuat_thong_tin_mot_nguoi(danh_sach.data[i]);
	}
	cout << "\n________________________________________________________________________________________________";
}
//b. Thêm vào vị trí bất kì trong danh sách
void them_nguoi(ListPeople& danh_sach, int vi_tri, People nguoi)
{
	if (vi_tri<0 || vi_tri>danh_sach.so_nguoi)
		cout << "\nVi tri khong hop le !";
	else
	{
		for (int i = danh_sach.so_nguoi - 1; i >= vi_tri; i--)
			danh_sach.data[i + 1] = danh_sach.data[i];
		danh_sach.data[vi_tri] = nguoi;
		danh_sach.so_nguoi++;
		cout << "\nBan da them thanh cong!";
	}
}

//c.1 Tìm kiếm tuần tự theo CMND
int tim_kiem_tuan_tu_cmnd(ListPeople danh_sach, int tim_so_cmnd)
{
	int i = 0;
	while (i < danh_sach.so_nguoi && danh_sach.data[i].so_cmnd != tim_so_cmnd)
		i++;
	if (i == danh_sach.so_nguoi)
		return -1;// khong tim thay
	return i;
}

//c.2 Tìm kiếm tuần tự Người theo tên
void tim_kiem_tuan_tu_ten(ListPeople danh_sach, char* tim_ten)
{
	int found=0;
	for (int i = 0; i < danh_sach.so_nguoi; i++)
		if (strcmp(danh_sach.data[i].ten, tim_ten) == 0)
		{
			found++;
			xuat_thong_tin_mot_nguoi(danh_sach.data[i]);
		}
	if (found == 0)
		cout << "\nKhong tim thay!";
	else
		cout << "\nTim Thay!";

}

//c.3 tìm kiem  tuần tự theo số điện thoại
int tim_kiem_tuan_tu_dien_thoai(ListPeople danh_sach,int tim_dien_thoai)
{
	int i = 0;
	while (i < danh_sach.so_nguoi && danh_sach.data[i].dien_thoai!= tim_dien_thoai)
		i++;
	if (i == danh_sach.so_nguoi)
		return -1;// khong tim thay
	return i;
}


//d.1 Cho phép xóa 1 người khi biết số CMND 
void xoa_nguoi_CMND(ListPeople &danh_sach, int xoa_so_cmnd)
{
	int found = 0;// kiem tra gia tri co to tai
	for (int i = 0; i < danh_sach.so_nguoi; i++)
		if (danh_sach.data[i].so_cmnd == xoa_so_cmnd)
		{
			found = 1;
			for (int j = i; j < danh_sach.so_nguoi - 1; j++)
				danh_sach.data[j] = danh_sach.data[j + 1];
			danh_sach.so_nguoi--;
		}
	if (found == 0) {
		cout<<"\n NHAN KHAU co CMND "<<xoa_so_cmnd<<" khong ton tai.";
	}
	else {
		cout << "\n Xoa thanh cong!!!";
	}
}

//d.2 Cho phép xóa 1 người khi biết số điện thoại.
void xoa_nguoi_dien_thoai(ListPeople &danh_sach, int  xoa_dien_thoai)
{
	int found = 0;// kiem tra gia tri co to tai
	for (int i = 0; i < danh_sach.so_nguoi; i++)
		if (danh_sach.data[i].dien_thoai == xoa_dien_thoai)
		{
			for (int j = i; j < danh_sach.so_nguoi - 1; j++)
				danh_sach.data[j] = danh_sach.data[j + 1];
			danh_sach.so_nguoi--;
		}
	if (found == 0) {
		cout << "\n NHAN KHAU co so dien thoai " << xoa_dien_thoai << " khong ton tai.";
	}
	else {
			cout << "\n Xoa thanh cong!!!";
	}
		
}

//e.1Cho phép sắp xếp tăng  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_tang_CMND(ListPeople &danh_sach) {
	for(int i=0;i<danh_sach.so_nguoi-1;i++)
		for (int j = i+1; j < danh_sach.so_nguoi; j++)
			if (danh_sach.data[j].so_cmnd < danh_sach.data[i].so_cmnd)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i]=danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
 }

//e.2Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  tên
void sap_xep_tang_ten(ListPeople &danh_sach) {
	for (int i = 0; i < danh_sach.so_nguoi - 1; i++)
		for (int j = i + 1; j < danh_sach.so_nguoi; j++)
			if (strcmp(danh_sach.data[j].ten , danh_sach.data[i].ten)<0)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i] = danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
}

//e.3Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_tang_dien_thoai(ListPeople &danh_sach) {
	for (int i = 0; i < danh_sach.so_nguoi - 1; i++)
		for (int j = i + 1; j < danh_sach.so_nguoi; j++)
			if (danh_sach.data[j].dien_thoai < danh_sach.data[i].dien_thoai)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i] = danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
}

//e.4Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_giam_CMND(ListPeople &danh_sach) {
	for (int i = 0; i < danh_sach.so_nguoi - 1; i++)
		for (int j = i + 1; j < danh_sach.so_nguoi; j++)
			if (danh_sach.data[j].so_cmnd > danh_sach.data[i].so_cmnd)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i] = danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
}

//e.5Cho phép sắp xếp giam danh sách những người này theo  tiêu chí  :  tên
void sap_xep_giam_ten(ListPeople &danh_sach) {
	for (int i = 0; i < danh_sach.so_nguoi - 1; i++)
		for (int j = i + 1; j < danh_sach.so_nguoi; j++)
			if (strcmp(danh_sach.data[j].ten, danh_sach.data[i].ten) > 0)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i] = danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
}
//e.6Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_giam_dien_thoai(ListPeople &danh_sach) {
	for (int i = 0; i < danh_sach.so_nguoi - 1; i++)
		for (int j = i + 1; j < danh_sach.so_nguoi; j++)
			if (danh_sach.data[j].dien_thoai > danh_sach.data[i].dien_thoai)
			{
				People temp = danh_sach.data[i];
				danh_sach.data[i] = danh_sach.data[j];
				danh_sach.data[j] = temp;
			}
}


//g.Ghi Danh sach NHAN KHAU tu file.
void ghi_nhan_khau_file(ListPeople  danh_sach, char* file_name)
{
	FILE* file = fopen(file_name, "wb");// mo file de ghi diu loieu
	if (file == NULL)
		cout << "\nKhong mo duoc file de ghi!!!";
	else
	{
		// ghi so luong nguoi
		fwrite(&danh_sach.so_nguoi, sizeof(int), 1, file);
		fwrite(&danh_sach.data, sizeof(People), danh_sach.so_nguoi,file);
		cout << "\n//Ghi Danh sach NHAN KHAU tu file thanh cong.";
		fclose(file);// dong file.

	}
}
//f.Doc Danh sach NHAN KHAU tu file.
void doc_nhan_khau_file(ListPeople &danh_sach, char* file_name)
{
	FILE* file = fopen(file_name, "rb");// mo file de doc du lieu
	if (file == NULL)
		cout << "\nKhong mo duoc file de doc du lieu!!!";
	else
	{
		// doc so luong nguoi
		fread(&danh_sach.so_nguoi, sizeof(int), 1, file);
		fread(&danh_sach.data, sizeof(People), danh_sach.so_nguoi, file);
		cout << "\nDoc Danh sach NHAN KHAU tu file thanh cong.";
		fclose(file);// dong file.
	}
 }

