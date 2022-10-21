#include"ThuVien_Phan1__DoAn.h"
void main()
{
	ListPeople danh_sach;
	initialize(danh_sach);
	char file_name[50] ;
	People nguoi;
	char chon;
	do {
		//menu lựa chọn
		cout << "\n _________________________________________________________________________________________";
		cout << "\n|_____________|               CHUONG TRINH QUAN LY NHAN KHAU C++           |______________|";
		cout << "\n|_____________|____________________________________________________________|______________|";
		cout << "\n|-----TINH---->     a. Nhap Danh sach Nhan Khau.                           <-----TINH-----|";
		cout << "\n|-----THANH--->     b. Them vao vi tri bat ki trong Danh sach Nhan Khau.   <----THANH-----|";
		cout << "\n|-----PHUONG-->     c. Tim kiem  mot  Nguoi trong Danh sach Nhan khau      <----PHUONG----|";
		cout << "\n|-----TH05---->     d. Xoa mot Nguoi trong Danh sach Nhan Khau .           <-----TH05-----|";
		cout << "\n|-----TH05---->     e. Sap xep danh sach Nhan Khau.                        <-----TH05-----|";
		cout << "\n|-----TH05---->     f. Doc Danh sach NHAN KHAU tu file.                    <-----TH05-----|";
		cout << "\n|-----TH05---->     g. Ghi Danh sach NHAN KHAU tu file.                    <-----TH05-----|";
		cout << "\n|-----TH05---->     h. Hien thi Danh sach Nhan Khau.                       <-----TH05-----|";
		cout << "\n|-----TH05---->     y. Thoat.                                              <-----TH05-----|";
		cout << "\n|__________________________________________STU____________________________________________|";
		cout << "\n\t>> Ban chon muc nao : ";
		cin >> chon;
		switch (chon)
		{
			case 'a':
			{
				cout << "\n _______________________________________________________________";
				cout << "\n|                    a. Nhap Danh sach Nhan Khau.               |";
				cout << "\n|_______________________________________________________________|";
				nhap_danh_sach_nguoi(danh_sach);
				xuat_danh_sach_nguoi(danh_sach);
				break;
			}
			case 'b':
			{
				cout << "\n _______________________________________________________________";
				cout << "\n|       b. Them vao vi tri bat ki trong Danh sach Nhan Khau.    |";
				cout << "\n|_______________________________________________________________|";
				int vi_tri;
				cout << "\nNhap vi tri can them: ";
				cin >> vi_tri;// vị trí cần chèn
				cout << "\nNhap thong tin mot nguoi.\n ";
				nhap_thong_tin_mot_nguoi(nguoi);
				them_nguoi(danh_sach, vi_tri, nguoi);
				xuat_danh_sach_nguoi(danh_sach);
				break;
			}
			case 'c':
			{
				if (danh_sach.so_nguoi > 0)
				{
					char chon;
					do {
						cout << "\n _______________________________________________________________";
						cout << "\n|    c. Tim kiem  mot  Nguoi trong Danh sach Nhan khau          |";
						cout << "\n|_______________________________________________________________|";
						cout << "\n|    1. Tim kiem  mot Nguoi trong Danh sach theo: CMND.         |";
						cout << "\n|    2. Tim kiem  mot Nguoi trong Danh sach theo: Ten.          |";
						cout << "\n|    3. Tim kiem  mot Nguoi trong Danh sach theo: so dien thoai |";
						cout << "\n|    4. Tro ve menu truoc                                       |";
						cout << "\n|_______________________________________________________________|";
						cout << "\n\t>> Ban chon muc nao : ";
						cin >> chon;
						switch (chon)
						{
						case '1':
						{
							int temp;
							cout << "\nNhap so CMND can tim: ";
							cin >> temp;
							int i = tim_kiem_tuan_tu_cmnd(danh_sach, temp);
							if (i < 0)
								cout << "\nKhong tim thay!";
							else
							{
								cout << "\nTim Thay!";
								cout << "\nSo CMND" << setw(10) << "Ten" << setw(25) << "ngay sinh" << setw(20) << "Dia chi" << setw(20) << "So dien thoai";
								xuat_thong_tin_mot_nguoi(danh_sach.data[i]);
							}
							break;
						}
						case '2':
						{
							char temp[30];
							cout << "\nNhap Ten can tim: ";
							cin.ignore();
							cin.getline(temp, 30);
							cout << "\nSo CMND" << setw(10) << "Ten" << setw(25) << "ngay sinh" << setw(20) << "Dia chi" << setw(20) << "So dien thoai";
							tim_kiem_tuan_tu_ten(danh_sach, temp);
							break;
						}
						case '3':
						{
							int temp;
							cout << "\nNhap so dien thoai can tim: ";
							cin >> temp;
							int i = tim_kiem_tuan_tu_dien_thoai(danh_sach, temp);
							if (i < 0)
								cout << "\nKhong tim thay!";
							else
							{
								cout << "\nTim Thay!";
								cout << "\nSo CMND" << setw(10) << "Ten" << setw(25) << "ngay sinh" << setw(20) << "Dia chi" << setw(20) << "So dien thoai";
								xuat_thong_tin_mot_nguoi(danh_sach.data[i]);

							}
							break;
						}
						case '4':
							break;
						default:
							cout << "\n\tBan da chon sai, vui long chon lai.";
							break;
						}
					} while (chon != '4');
				}
				else
					cout << "\nDanh sach NHAN KHAU rong!!!";
				 break;
			}
			case 'd':
			{
				if (danh_sach.so_nguoi > 0)
				{
					int temp;
					char chon;
					do {
						cout << "\n ________________________________________________________________";
						cout << "\n|------|       d. Xoa mot Nguoi trong Danh Sach         |-------|";
						cout << "\n|_______________________________________________________________|";
						cout << "\n|                 1. Xoa mot Nguoi khi biet CMND.               |";
						cout << "\n|                 2. Xoa mot nguoi khi biet so dien thoai       |";
						cout << "\n|                 3. tro ve menu truoc.                         |";
						cout << "\n|_______________________________________________________________|";
						cout << "\n\t>> Ban chon muc nao : ";
						cin >> chon;
						switch (chon)
						{
						case '1':
						{
							cout << "\nNhap so CMND can xoa: ";
							cin >> temp;
							xoa_nguoi_CMND(danh_sach, temp);
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '2':
						{
							cout << "\nNhap so dien thoai can xoa: ";
							cin >> temp;
							xoa_nguoi_dien_thoai(danh_sach, temp);
							xuat_danh_sach_nguoi(danh_sach);
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
				else
					cout << "\nDanh sach NHAN KHAU rong!!!";
				break;
			}
			case 'e':
			{
				if (danh_sach.so_nguoi > 0)
				{
					char chon;
					do {
						cout << "\n _______________________________________________________________";
						cout << "\n|                       e. Sap xep danh sach                    |";
						cout << "\n|_______________________________________________________________|";
						cout << "\n|                   1. Tang theo tieu chi: so CMND.             |";
						cout << "\n|                   2. Tang theo tieu chi: Ten.                 |";
						cout << "\n|                   3. Tang theo tieu chi: so dien thoai.       |";
						cout << "\n|                   4. Giam theo tieu chi: so CMND.             |";
						cout << "\n|                   5. Giam theo tieu chi: Ten.                 |";
						cout << "\n|                   6. Giam theo tieu chi: so dien thoai.       |";
						cout << "\n|                   7. tro ve menu truoc.                       |";
						cout << "\n|_______________________________________________________________|";
						cout << "\n\t>> Ban chon muc nao : ";
						cin >> chon;
						switch (chon)
						{
						case '1':
						{
							sap_xep_tang_CMND(danh_sach);
							cout << "\n1. Tang theo tieu chi : so CMND.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '2':
						{
							sap_xep_tang_ten(danh_sach);
							cout << "\n2. Tang theo tieu chi: Ten.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '3':
						{
							sap_xep_tang_dien_thoai(danh_sach);
							cout << "\n3. Tang theo tieu chi: so dien thoai.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '4':
						{
							sap_xep_giam_CMND(danh_sach);
							cout << "\n4. Giam theo tieu chi: so CMND.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '5':
						{
							sap_xep_giam_ten(danh_sach);
							cout << "\n5. Giam theo tieu chi: Ten.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case '6':
						{
							sap_xep_giam_dien_thoai(danh_sach);
							cout << "\n6. Giam theo tieu chi: so dien thoai.";
							xuat_danh_sach_nguoi(danh_sach);
							break;
						}
						case'7':
							break;
						default:
							cout << "\n\tBan da chon sai, vui long chon lai.";
							break;
						}
					} while (chon != '7');
				}
				else
					cout << "\nDanh sach NHAN KHAU rong!!!";				
				break;
			}
			case 'f':
			{
				strcpy_s(file_name, "nhankhau.dat");
				doc_nhan_khau_file(danh_sach, file_name);
				xuat_danh_sach_nguoi(danh_sach);
				break;
			}
			case 'g':
			{
				if (danh_sach.so_nguoi > 0)
				{
					strcpy_s(file_name, "nhankhau.dat");
					ghi_nhan_khau_file(danh_sach, file_name);
				}
				else
					cout << "\nDanh sach NHAN KHAU rong khong ghi duoc!!!";
				break;

			}
			case 'h':
			{
				cout << "\n _______________________________________________________________";
				cout << "\n|                      DANH SACH NHAN KHAU                      |";
				cout << "\n|_______________________________________________________________|";
				xuat_danh_sach_nguoi(danh_sach);
				break;
			}
			case 'y':
				break;
			default:
				cout<<"\n\tBan da chon sai, vui long chon lai.";
				break;
		}
	}while ((chon!='y')&&(chon!='Y'));
	system("pause");
}