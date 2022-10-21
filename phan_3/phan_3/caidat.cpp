#include"thuvien.h"
//=============== Tao nut Nguoi ===================
NodeNguoi createrNode_Nguoi(Nguoi x)
{
	NodeNguoi p;
	p = new Node;
	p->next = NULL;
	p->info = x;
	return p;
}
//================Tao nut Ho khau ================
NodeHoKhau createrNode_HoKhau(HoKhau x)
{
	NodeHoKhau p;
	p = new NodeHK;
	p->next = NULL;
	p->info = x;
	p->info.ds_nguoi = NULL;
	for (int i = 0; i < p->info.so_nhankhau; i++)
	{
		cout << "\n=========Thanh vien thu:" << i + 1 << endl;;
		nhap_thong_tin_nguoi(p->info.ds_nguoi);
	}
	return p;
}
//=============== ham kiem tra cmnd co bi trung hay khong
bool kiemTraTrung_cmnd(NodeNguoi& list, int check)
{
	NodeNguoi p = list;
	while (p != NULL)
	{
		if (p->info.cmnd == check)
			return true;// thoat
		p = p->next;
	}
	return false;
}
//============== ham kiem tra ma ho khau co bi trung hay khong
bool kiemTraTrung_id_hokhau(NodeHoKhau& list, int check)
{
	NodeHoKhau p = list;
	while (p != NULL)
	{
		if (p->info.id_hokhau == check)
			return true;// thoat
		p = p->next;
	}
	return false;
}
//=============Ham kiem tra ngay thang nam
int laNamNhuan(DateOfBirth x)
{
	if (x.nam_sinh % 400 == 0) return 1;
	else
	{
		if ((x.nam_sinh % 100 != 0) && (x.nam_sinh % 4 == 0)) return 1;
	}
	cout << x.nam_sinh << "khong phai la nam nhuan!\n";
	return 0;

}
int kiemtraNgayThangNam(DateOfBirth x)
{
	if (x.ngay_sinh <= 0) return 0;
	else
	{
		if (x.thang_sinh == 2 && x.ngay_sinh > 28 && !laNamNhuan(x)) return 0;
		else
		{
			if (x.thang_sinh == 2 && x.ngay_sinh > 29 && laNamNhuan(x))return 0;
			else
			{
				if ((x.thang_sinh == 1 || x.thang_sinh == 3 || x.thang_sinh == 5 || x.thang_sinh == 7 || x.thang_sinh == 8 || x.thang_sinh == 10 || x.thang_sinh == 12) && x.ngay_sinh > 31) return 0;
				else
				{
					if ((x.thang_sinh == 4 || x.thang_sinh == 6 || x.thang_sinh == 9 || x.thang_sinh == 11) && x.ngay_sinh > 30) return 0;
				}
			}
		}
	}
	return 1;
}
//============== Nhập thông tin của một người 
void nhap_thong_tin_nguoi(NodeNguoi& list)
{

	Nguoi x;
	NodeNguoi p = NULL;
	cout << "Nhap so CMND:  ";
	cin >> x.cmnd;
	while (kiemTraTrung_cmnd(list, x.cmnd))
	{
		cout << " CMND nguoi bi trung cmnd. Yeu cau nhap lai!  ";
		cin >> x.cmnd;
	}
	cout << "Nhap ten: ";
	cin.ignore();
	cin.getline(x.ten, 30);
	do {
		cout << "Nhap ngay thang nam Sinh: ";
		cin >> x.sinh_nhat.ngay_sinh >> x.sinh_nhat.thang_sinh >> x.sinh_nhat.nam_sinh;
		if (kiemtraNgayThangNam(x.sinh_nhat) == 0) cout << "\nBan da nhap sai!";
	} while (kiemtraNgayThangNam(x.sinh_nhat) == 0);
	cin.ignore();
	cout << "Nhap dia chi thuong tru: ";
	cin.getline(x.dia_chi, 60);
	do {
		cout << "Nhap so dien thoai di dong: ";
		cin >> x.so_dienthoai;
		if (x.so_dienthoai > 999999999 || x.so_dienthoai < 100000000)
			cout << "So dien thoai gom 10 so .Yeu cau nhap lai!\n";
	} while (x.so_dienthoai > 999999999 || x.so_dienthoai < 100000000);// so dien thoai toi da 10 so
	p = createrNode_Nguoi(x);
	if (list == NULL)// kiem tra danh sach rong
	{
		list = p;// chinh lai con tro
	}
	else
	{
		NodeNguoi q = list;
		while (q->next != NULL)//tim node cuoi cung
			q = q->next;
		q->next = p;
	}

}
//=================== xuat danh sach  nguoi
void xuat_danh_sach_nguoi(NodeNguoi list)
{
	cout << "\nCMND" << setw(20) << "TEN" << setw(25) << "SINH NHAT" << setw(20) << "DIA CHI" << setw(20) << "SO DIEN THOAI";
	while (list != NULL)
	{
		cout << "\n" << list->info.cmnd << setw(20) << list->info.ten << setw(10) << list->info.sinh_nhat.ngay_sinh << "/" << list->info.sinh_nhat.thang_sinh << "/" << list->info.sinh_nhat.nam_sinh << setw(20) << list->info.dia_chi << setw(20) << "0" << list->info.so_dienthoai;
		list = list->next;

	}
}
//============== Nhập thong tin ho khau
void nhap_thong_tin_HoKhau(NodeHoKhau& list)
{
	NodeHoKhau p;
	do {
		HoKhau x;
		cout << "\nNhap ma ho khau (Thoat -99) : ";
		cin >> x.id_hokhau;
		while (kiemTraTrung_id_hokhau(list, x.id_hokhau))
		{
			cout << " Ma ho khau bi trung. Yeu cau nhap lai! ";
			cin >> x.id_hokhau;
		}
		if (x.id_hokhau == -99)
			break;
		cout << "Nhap ten chu ho: ";
		cin.ignore();
		cin.getline(x.ten_chuho, 30);
		cout << "Nhap dia chi ho khau: ";
		cin.getline(x.dia_chi, 60);
		cin.ignore(0);
		do
		{
			cout << "Nhap so dien thoai ban: ";
			cin >> x.so_dienthoaiban;
			if (x.so_dienthoaiban > 9999999999 || x.so_dienthoaiban < 1000000000)
				cout << "So dien thoai gom 11 so.Yeu cau nhap lai!\n";
		} while (x.so_dienthoaiban > 9999999999 || x.so_dienthoaiban < 1000000000);// so dien thoai ban toi da 11 so
		do
		{
			cout << "Nhap so luong nhan khau: ";
			cin >> x.so_nhankhau;
		} while (x.so_nhankhau < 0);
		p = createrNode_HoKhau(x);
		if (list == NULL)// kiem tra danh sach rong
		{
			list = p;// chinh lai con tro
		}
		else
		{
			NodeHoKhau q = list;
			while (q->next != NULL)//tim node cuoi cung
				q = q->next;
			q->next = p;
		}
	} while (1);
}
// xuat thong tin mot ho khau
void xuat_hoKhau(HoKhau hokhau)
{
	cout << "\nMA HO KHAU" << setw(20) << "TEN CHU HO" << setw(25) << "SO SO NHAN KHAU" << setw(20) << "DIA CHI" << setw(20) << "SO DIEN THOAI BAN";
	cout << "\n" << hokhau.id_hokhau << setw(20) << hokhau.ten_chuho << setw(15) << hokhau.so_nhankhau << setw(30) << hokhau.dia_chi << setw(10) << "0" << hokhau.so_dienthoaiban;
	cout << "\n\n-------------------------Thong tin thanh vien trong ho khau-------------------------";
	xuat_danh_sach_nguoi(hokhau.ds_nguoi);
}
//================== xuat danh sach ho khau
void xuat_danh_sach_HoKhau(NodeHoKhau list)
{
	cout << "\n______________________________________________________________________________________________________________________\n";
	while (list != NULL)
	{
		xuat_hoKhau(list->info);
		list = list->next;
		cout << "\n______________________________________________________________________________________________________________________\n";
	}
}
//================b. Them ho khau vao vi tri bat ki. 
// Đếm số phần tử trong danh sách 
int SizeOfList(NodeHoKhau x)
{
	NodeHoKhau p = x;
	int size = 0;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}
void them_hoKhau_viTri_batKi(NodeHoKhau& list_hk, int vitri)
{
	int i = 0;
	if (vitri < 0 || vitri>SizeOfList(list_hk))
	{
		cout << "\n Vi tri nhap khong hop le !";
	}
	else
	{
		NodeHoKhau p;
		HoKhau x;
		cout << "\nNhap ma ho khau: ";
		cin >> x.id_hokhau;
		while (kiemTraTrung_id_hokhau(list_hk, x.id_hokhau))
		{
			cout << " Ma ho khau bi trung. Yeu cau nhap lai! ";
			cin >> x.id_hokhau;
		}
		cout << "Nhap ten chu ho: ";
		cin.ignore();
		cin.getline(x.ten_chuho, 30);
		cout << "Nhap dia chi ho khau: ";
		cin.getline(x.dia_chi, 60);
		cin.ignore(0);
		do
		{
			cout << "Nhap so dien thoai ban: ";
			cin >> x.so_dienthoaiban;
			if (x.so_dienthoaiban > 9999999999 || x.so_dienthoaiban < 1000000000)
				cout << "So dien thoai gom 11 so.Yeu cau nhap lai!\n";
		} while (x.so_dienthoaiban > 9999999999 || x.so_dienthoaiban < 1000000000);// so dien thoai ban toi da 11 so
		do
		{
			cout << "Nhap so luong nhan khau: ";
			cin >> x.so_nhankhau;
		} while (x.so_nhankhau < 0);
		p = createrNode_HoKhau(x);
		if (vitri == 0)// them dau danh sach
		{
			p->next = list_hk;// sua lai lien ket
			list_hk = p;// thay doi con tro
		}
		else// them sau node q
		{
			NodeHoKhau q = list_hk;

			while (i < vitri - 1)// tim node truoc vi tri can chen
			{
				i++;
				q = q->next;
			}
			if (q != NULL)
			{
				p->next = q->next;
				q->next = p;
			}
		}
	}
}
//============ c. Xoa mot ho khau khi biet ten chu ho hoac dia chi.
void xoa_hoKhau_tenChuHo(NodeHoKhau& list_hk, HoKhau hokhau)
{
	NodeHoKhau p, before;
	if (strcmp(list_hk->info.ten_chuho, hokhau.ten_chuho) == 0 )// xoa dau
	{
		p = list_hk;
		list_hk = p->next;
		delete p;
	}
	else// xoa sau node
	{
		p = list_hk;
		before = list_hk;
		while (p != NULL && strcmp(p->info.ten_chuho, hokhau.ten_chuho) != 0)
		{
			before = p;
			p = p->next;
		}
		if (p != NULL)
		{
			before->next = p->next;
			delete p;
		}
		else
			cout << "\nKhong tim thay gia tri can tim!!!";
	}
}
void xoa_hoKhau_diachi(NodeHoKhau& list_hk, HoKhau hokhau)
{
	NodeHoKhau p, before;
	if (strcmp(list_hk->info.dia_chi, hokhau.dia_chi) == 0)// xoa dau
	{
		p = list_hk;
		list_hk = p->next;
		delete p;
	}
	else  // xoa sau node
	{
		p = list_hk;
		before = list_hk;
		while (p != NULL && strcmp(p->info.dia_chi, hokhau.dia_chi) != 0)
		{
			before = p;
			p = p->next;
		}
		if (p != NULL)
		{
			before->next = p->next;
			delete p;
		}
		else
			cout << "\nKhong tim thay gia tri can tim!!!";
	}
}
//============ d. Cho phep tim ho khau khi biet ten chu ho hoac dian thoai.
void timKiem_hoKhau_tenChuHo_hoac_dienThoai(NodeHoKhau list, HoKhau hokhau)
{
	int i = 0;
	NodeHoKhau p = list;
	while (p != NULL)
	{
		if (strcmp(p->info.ten_chuho, hokhau.ten_chuho) == 0 || p->info.so_dienthoaiban == hokhau.so_dienthoaiban)
		{
			i = 1;
			cout << "\n______________________________________________________________________________________________________________________\n";
			xuat_hoKhau(p->info);
			cout << "\n______________________________________________________________________________________________________________________\n";
		}
		p = p->next;
	}
	if (i == 0)
		cout << "\nKhong tim thay Ho Khau!!!";
}
//======== e. Them mot nguoi vao ho khau khi biet ma ho khau.
void themNguoi_hoKhau_id_hoKhau(NodeHoKhau& list_hk, HoKhau hokhau)
{
	NodeHoKhau p = list_hk;
	while (p != NULL)
	{
		if (p->info.id_hokhau == hokhau.id_hokhau)
		{
			cout << "\n=========Nhap thanh vien can them:" << endl;;
			nhap_thong_tin_nguoi(p->info.ds_nguoi);
			p->info.so_nhankhau++;
			xuat_hoKhau(p->info);
		}
		p = p->next;
	}
}