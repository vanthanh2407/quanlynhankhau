#include"thuvien.h"
// khoi tao danh sach lien ket don
// Ham tao node nhan khau
Nodeptr tao_node_people(People nguoi)
{
	Nodeptr p = new Node;
	p->data = nguoi;
	p->link = NULL;
	return p;
}

void initialize_list(ListPeople& list)
{
	list = NULL;

}
// ham them nguoi vao cuoi danh sach
void them_cuoi(ListPeople& list, People nguoi)
{
	Nodeptr p;
	p = tao_node_people(nguoi);
	if (list == NULL)// kiem tra danh sach rong
	{
		list = p;// chinh lai con tro
	}
	else
	{
		Nodeptr q = list;
		while (q->link != NULL)//tim node cuoi cung
			q = q->link;
		q->link = p;
	}
}
// Nhập thông tin của một người 
void nhap_thong_tin_mot_nguoi(ListPeople& list, People& nguoi)
{
	cout << "Nhap so CMND:  ";
	cin >> nguoi.id;
	while (kiemTra_trung_id(list, nguoi.id))
	{
		cout << "\n CMND nguoi bi trung";
		cout << "\nNhap lai CMND nguoi : ";
		cin >> nguoi.id;
	}
	cout << "Nhap ten: ";
	cin.ignore();
	cin.getline(nguoi.name, 30);
	cout << "Nhap ngay thang nam sinh: \n";
	do {
		cout << "Nhap ngay sinh: ";
		cin >> nguoi.date_birth;
	} while (nguoi.date_birth > 31 || nguoi.date_birth < 1);// ngay sinh nam trong doan tu 1->31
	do {
		cout << "Nhap thang sinh: ";
		cin >> nguoi.month_birth;
	} while (nguoi.month_birth > 12 || nguoi.month_birth < 1);// thang sinh nam trong doan tu 1->12
	do {
		cout << "Nhap nam sinh: ";
		cin >> nguoi.year_birth;
	} while (nguoi.year_birth > 2020 || nguoi.year_birth < 1600);// nam sinh nam trong doan tu 1600->2020
	cin.ignore();
	cout << "Nhap dia chi thuong tru: ";
	cin.getline(nguoi.address, 50);
	cout << "Nhap so dien thoai: ";
	cin >> nguoi.phone_number;
}
// ham kiem tra cmnd co bi trung hay khong
bool kiemTra_trung_id(ListPeople& list, int check_id)
{
	Nodeptr p = list;
	while (p != NULL)
	{
		if (p->data.id == check_id)
			return true;// thoat
		p = p->link;
	}
	return false;
}

// a.nhap danh sach nhan khau
void nhap_danh_sach_nguoi(ListPeople& list)
{
	initialize_list(list);
	People nguoi;
	char chon;
	do
	{
		cout << "\n_______________________________________________________________________________________________\n\n";
		nhap_thong_tin_mot_nguoi(list, nguoi);
		them_cuoi(list, nguoi);
		cout << "\t>>Tiep tuc (chon n) ? Thoat (chon y) Ban chon: ";
		cin >> chon;

	} while (chon != 'y');

}

// Xuất thông tin của một người
void xuat_thong_tin_mot_nguoi(People nguoi)
{
	cout << "\n" << nguoi.id << setw(15) << nguoi.name << setw(10) << nguoi.date_birth << "/" << nguoi.month_birth << "/" << nguoi.year_birth << setw(20) << nguoi.address << setw(20) << nguoi.phone_number;
}

// xuat danh sach nhan khau
void xuat_danh_sach_nguoi(ListPeople list)
{
	if (list == NULL)
		cout << "\nDanh sach rong";
	else
	{
		cout << "\n_______________________________________________________________________________________________\n";
		cout << "\nSo CMND" << setw(10) << "Ten" << setw(25) << "ngay sinh" << setw(20) << "Dia chi" << setw(20) << "So dien thoai";
		while (list != NULL)
		{
			xuat_thong_tin_mot_nguoi(list->data);
			list = list->link;
		}
		cout << "\n_______________________________________________________________________________________________\n";
	}
}

// Đếm số phần tử trong danh sách 
int SizeOfList(ListPeople list)
{
	Nodeptr p = list;
	int size = 0;
	while (p != NULL)
	{
		p = p->link;
		size++;
	}
	return size;
}
//b. Thêm vào vị trí bất kì trong danh sách
void them_nguoi(ListPeople& list, int vi_tri, People nguoi)
{
	Nodeptr p = tao_node_people(nguoi);
	int i = 0;
	if (vi_tri < 0 || vi_tri>SizeOfList(list))
	{
		cout << "\n Vi tri nhap khong hop le !";
	}
	else if (vi_tri == 0)// them dau danh sach
	{
		p->link = list;// sua lai lien ket
		list = p;// thay doi con tro
	}
	else if (vi_tri == SizeOfList(list))// them cuoi danh sach
	{
		them_cuoi(list, nguoi);
	}
	else// them sau node
	{
		Nodeptr q = list;

		while (i < vi_tri - 1)// tim node truoc vi tri can chen
		{
			i++;
			q = q->link;
		}
		if (q != NULL)
		{
			p->link = q->link;
			q->link = p;
		}
	}
}
//c.1 Tím kiếm theo CMND
Nodeptr tim_kiem_tuan_tu_cmnd(ListPeople list, People nguoi)
{
	Nodeptr p = list;
	while (p != NULL)
	{
		if (p->data.id == nguoi.id)
			return p;
		p = p->link;
	}
	return NULL;
}

//c.2 Tìm kiếm tuần tự Người theo tên
void tim_kiem_tuan_tu_ten(ListPeople list, People nguoi)
{
	int i = 0;
	Nodeptr p = list;
	while (p != NULL)
	{
		if (strcmp(p->data.name, nguoi.name) == 0)
		{
			i = 1;
			xuat_thong_tin_mot_nguoi(p->data);
		}
		p = p->link;
	}
	if (i == 0)
		cout << "\nTim khong thay !!";
	else
		cout << "\nTim thay!!!";
}

//c.3 tìm kiem  tuần tự theo số điện thoại
Nodeptr  tim_kiem_tuan_tu_dien_thoai(ListPeople list, People nguoi)
{
	Nodeptr p = list;
	while (p != NULL)
	{
		if (p->data.phone_number == nguoi.phone_number)
			return p;
		p = p->link;
	}
	return NULL;
}

//d.1 Cho phép xóa 1 người khi biết số CMND 
void xoa_nguoi_cmnd(ListPeople& list, People nguoi)
{
	Nodeptr p, before;
	if (list->data.id == nguoi.id)// xoa dau
	{
		p = list;
		list = p->link;
		delete p;
	}
	else// xoa sau node
	{
		p = list;
		before = list;
		while (p != NULL && (p->data.id != nguoi.id))
		{
			before = p;
			p = p->link;
		}
		if (p != NULL)
		{
			before->link = p->link;
			delete p;
		}
		else
			cout << "\nKhong tim thay cmnd " << nguoi.id;
	}
}
//d.2 Cho phép xóa 1 người khi biết số điện thoại.
void xoa_nguoi_dien_thoai(ListPeople& list, People nguoi)
{
	Nodeptr p, before;
	if (list->data.id == nguoi.phone_number)// xoa dau
	{
		p = list;
		list = p->link;
		delete p;
	}
	else// xoa sau node
	{

		p = list;
		before = list;
		while (p != NULL && (p->data.phone_number != nguoi.phone_number))
		{
			before = p;
			p = p->link;
		}
		if (p != NULL)
		{
			before->link = p->link;
			delete p;
		}
		else
			cout << "\nKhong tim thay so dien thoai " << nguoi.phone_number;
	}
}
//e.1Cho phép sắp xếp tăng  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_tang_cmnd(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (p->data.id > q->data.id) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}

}
//e.2Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  tên
void sap_xep_tang_ten(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (strcmp(p->data.name, q->data.name) > 0)// nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}
//e.3Cho phép sắp xếp tăng danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_tang_dien_thoai(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (p->data.phone_number > q->data.phone_number) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}
//e.4Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí : số CMND
void sap_xep_giam_cmnd(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (p->data.id < q->data.id) // nếu giá trị trước < giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}
//e.5Cho phép sắp xếp giam danh sách những người này theo  tiêu chí  :  tên
void sap_xep_giam_ten(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (strcmp(p->data.name, q->data.name) < 0)// nếu giá trị trước < giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}
//e.6Cho phép sắp xếp giam  danh sách những người này theo  tiêu chí  :  số điện thoại.
void sap_xep_giam_dien_thoai(ListPeople& list)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		for (Nodeptr q = p->link; q != NULL; q = q->link)
		{
			if (p->data.phone_number < q->data.phone_number) // nếu giá trị trước < giá trị sau thì hoán đổi hai vị trí
			{
				People tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}
//g.Ghi Danh sach NHAN KHAU tu file.
void ghi_nhan_khau_file(ListPeople list, char* file_name)
{
	FILE* file = fopen(file_name, "wb");// mo file de ghi du lieu
	if (file == NULL)
		cout << "\nKhong mo duoc file de ghi!!!";
	else
	{
		for (Nodeptr p = list; p != NULL; p = p->link)
		{
			fwrite(&p->data, sizeof(People), 1, file);
		}

		cout << "\n//Ghi Danh sach NHAN KHAU tu file thanh cong.";
		fclose(file);// dong file.

	}
}
// xoa node cuoi danh sach
void xoa_cuoi(ListPeople& list)
{
	Nodeptr p, before;
	p = list;
	before = list;
	if (p->link == NULL)
	{
		delete p;
		list = NULL;
	}
	else
	{
		while (p->link != NULL)
		{
			before = p;
			p = p->link;
		}
		if (p->link == NULL)
		{
			delete p;
			before->link = NULL;
		}
	}
}
//f.Doc Danh sach NHAN KHAU tu file.
void doc_nhan_khau_file(ListPeople& list, char* file_name)
{

	FILE* file = fopen(file_name, "rb");// mo file de doc du lieu
	if (file == NULL)
		cout << "\nKhong mo duoc file de doc du lieu!!!";
	else
	{
		while (!feof(file))//kiểm tra end-of-file indicator
		{
			People nguoi;
			fread(&nguoi, sizeof(People), 1, file);
			them_cuoi(list, nguoi);
		}
		xoa_cuoi(list);//nếu ko có thì chương trình đọc 2 lần phần tử cuoi cung
		cout << "\nDoc Danh sach NHAN KHAU tu file thanh cong.";
		fclose(file);// dong file.
	}
}