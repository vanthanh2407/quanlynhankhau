#include"thuvien.h"
void main()
{
	NodeHoKhau list_hk = NULL;
	char chon;
	do {
		//menu lựa chọn
		cout << "\n ___________________________________________________________________________________________________";
		cout << "\n|_____________|                      CHUONG TRINH QUAN LY HO KHAU C++                |______________|";
		cout << "\n|_____________|______________________________________________________________________|______________|";
		cout << "\n|-----TINH---->      a. Nhap Danh sach Ho Khau.                                      <-----TINH-----|";
		cout << "\n|-----THANH--->      b. Them ho khau vao vi tri bat ki.                              <----THANH-----|";
		cout << "\n|-----PHUONG-->      c. Xoa mot ho khau khi biet ten chu ho hoac dia chi.            <----PHUONG----|";
		cout << "\n|-----TH05---->      d. Cho phep tim ho khau khi biet ten chu ho hoac dien thoai.    <-----TH05-----|";
		cout << "\n|-----TH05---->      e. Them mot nguoi vao ho khau khi biet ma ho khau.              <-----TH05-----|";
		cout << "\n|-----TH05---->      f. Danh sach HO KHAU.                                           <-----TH05-----|";
		cout << "\n|-----TH05---->      y. Thoat.                                                       <-----TH05-----|";
		cout << "\n|__________________________________________________STU______________________________________________|";
		cout << "\n\t>> Ban chon muc nao : ";
		cin >> chon;
		switch (chon)
		{
		case'a':
		{
			nhap_thong_tin_HoKhau(list_hk);
			xuat_danh_sach_HoKhau(list_hk);
			break;
		}
		case'b':
		{
			int vitri;
			cout << "\n______________________________________________________________________________________________________________________\n";
			cout << "\nNhap vi tri can them: ";
			cin >> vitri;
			them_hoKhau_viTri_batKi(list_hk, vitri);
			cout << "\n______________________________________________________________________________________________________________________\n";
			xuat_danh_sach_HoKhau(list_hk);
			break;
		}
		case'c':
		{
			if (list_hk == NULL)
				cout << "\nDanh sach rong !!!";
			else
			{

				char chon;
				do {
					cout << "\n ________________________________________________________________";
					cout << "\n|------|      d. Xoa mot HO KHAU trong Danh Sach        |-------|";
					cout << "\n|_______________________________________________________________|";
					cout << "\n|                 1. Xoa mot ho khau khi biet ten chu ho.       |";
					cout << "\n|                 2. Xoa mot ho khau khi dia chi.               |";
					cout << "\n|                 3. tro ve menu truoc.                         |";
					cout << "\n|_______________________________________________________________|";
					cout << "\n\t>> Ban chon muc nao : ";
					cin >> chon;
					switch (chon)
					{
					case '1':
					{
						HoKhau hokhau;
						cout << "\nNhap ten chu ho can xoa: ";
						cin.ignore();
						cin.getline(hokhau.ten_chuho, 30);
						xoa_hoKhau_tenChuHo(list_hk, hokhau);
						xuat_danh_sach_HoKhau(list_hk);
						break;
					}
					case '2':
					{
						HoKhau hokhau;
						cout << "\nNhap dia chi can xoa: ";
						cin.ignore();
						cin.getline(hokhau.dia_chi, 60);
						xoa_hoKhau_diachi(list_hk, hokhau);
						xuat_danh_sach_HoKhau(list_hk);
						break;
					}
					case'3':
						break;
					default:
						cout << "\n\tBan da chon sai, vui long chon lai.";
						break;
					}
				} while (chon != '3');
			}
			break;
		}
		case'd':
		{
			if (list_hk == NULL)
				cout << "\nDanh sach rong !!!";
			else
			{

				char chon;
				do {
					cout << "\n ________________________________________________________________";
					cout << "\n|------|     d. Tim kiem mot HO KHAU trong danh sach    |-------|";
					cout << "\n|_______________________________________________________________|";
					cout << "\n|        1. Tim kiem mot ho khau khi biet ten chu ho.           |";
					cout << "\n|        2. Tim kiem mot ho khau khi biet dien thoai chu ho.    |";
					cout << "\n|        3. tro ve menu truoc.                                  |";
					cout << "\n|_______________________________________________________________|";
					cout << "\n\t>> Ban chon muc nao : ";
					cin >> chon;
					switch (chon)
					{
					case '1':
					{
						HoKhau hokhau;
						cout << "\nNhap ten chu ho can tim: ";
						cin.ignore();
						cin.getline(hokhau.ten_chuho, 30);
						timKiem_hoKhau_tenChuHo_hoac_dienThoai(list_hk, hokhau);
						break;
					}
					case '2':
					{
						HoKhau hokhau;
						cout << "\nNhap so dien thoai chu ho can tim : ";
						cin >> hokhau.so_dienthoaiban;
						timKiem_hoKhau_tenChuHo_hoac_dienThoai(list_hk, hokhau);
						break;
					}
					case'3':
						break;
					default:
						cout << "\n\tBan da chon sai, vui long chon lai.";
						break;
					}
				} while (chon != '3');
			}
			break;
		}
		case'e':
		{
			if (list_hk == NULL)
				cout << "\nDanh sach rong !!!";
			else
			{
				HoKhau hokhau;
				Nguoi nguoi;
				cout << "\n______________________________________________________________________________________________________________________\n";
				cout << "\nNhap ma ho khau de them nguoi: ";
				cin >> hokhau.id_hokhau;
				themNguoi_hoKhau_id_hoKhau(list_hk, hokhau);
				cout << "\n______________________________________________________________________________________________________________________\n";
			}
			break;
		}
		case'f':
		{
			xuat_danh_sach_HoKhau(list_hk);
			break;
		}
		case 'y':
			break;
		default:
			cout << "\n\tBan da chon sai, vui long chon lai.";
			break;
		}
	} while ((chon != 'y') && (chon != 'Y'));
}