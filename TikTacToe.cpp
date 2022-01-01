#include <iostream>
#include <fstream>	// nhap xuat file
#include <windows.h>	//set console's size
#include <conio.h>	// system
#include <string>

using namespace std;

void menu();

// toa do
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// co dinh console
void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//mau
void SetColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

// doi size console
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

//nhap ky tu bat ky
char doi_nhap(char lenh)	// doi nguoi dung go phim
{
	lenh = _getch();
	return lenh;
}

// bang huong dan trong ban co
void huong_dan()
{
	SetColor(14);
	for (int i = 0; i <= 40; i++)	// huong dan
	{
		gotoxy(85, 0 + i);
		if (i == 0)	//dong dau
		{
			cout << char(201);
			for (int j = 1; j <= 8; j++)
			{
				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(187) << endl;
		}
		else if (i == 40)	//dong cuoi
		{
			cout << char(200);
			for (int j = 1; j <= 8; j++)
			{
				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(188) << endl;
		}
		else //dong thuong
		{
			cout << char(186);
			gotoxy(104, 0 + i);
			cout << char(186) << endl;
		}
	}

	gotoxy(90, 3);
	cout << "BANG DIEM";
	gotoxy(88, 6);
	SetColor(12);
	cout << "P1";
	SetColor(14);
	gotoxy(93, 6);
	cout << "V.S";
	SetColor(10);
	gotoxy(100, 6);
	cout << "P2";
	gotoxy(94, 8);
	cout << ":";
	SetColor(13);
	gotoxy(91, 15);
	cout << "TOI LUOT";

	SetColor(14);
	gotoxy(88, 24);
	cout << "CACH DI CHUYEN";
	gotoxy(91, 26);
	cout << "^: LEN";
	gotoxy(91, 28);
	cout << "v: XUONG";
	gotoxy(91, 30);
	cout << "<: TRAI";
	gotoxy(91, 32);
	cout << ">: PHAI";
	gotoxy(89, 34);
	cout << "ENTER: DANH CO";
	gotoxy(89, 36);
	cout << "TAB: VE MENU";
	gotoxy(89, 38);
	cout << "ESC: THOAT GAME";

	SetColor(12);
	gotoxy(91, 19);
	cout << "---X---";
}

//gioi thieu trong menu
void gioi_thieu()
{
	system("cls");
	SetColor(14);
	for (int i = 0; i <= 14; i++)
	{
		gotoxy(35, 15 + i);
		if (i == 0)	//dong dau
		{
			cout << char(201);
			for (int j = 1; j <= 21; j++)
			{

				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(187) << endl;
		}
		else if (i == 14)	//dong cuoi
		{
			cout << char(200);
			for (int j = 1; j <= 21; j++)
			{

				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(188) << endl;
		}
		else //dong thuong
		{
			cout << char(186);
			gotoxy(80, 15 + i);
			cout << char(186) << endl;
		}
	}

	SetColor(13);
	gotoxy(47, 17);
	cout << "GIOI THIEU CHUONG TRINH";
	SetColor(15);
	gotoxy(40, 20);
	cout << "HO VA TEN: PHAM HOANG NHAT THANH";
	gotoxy(40, 22);
	cout << "MSSV: 2051012108";
	gotoxy(40, 24);
	cout << "DAY LA DO AN CARO GIUA KY 1 NAM 1";

	gotoxy(68, 27);
	cout << "QUAY LAI";
	SetColor(13);
	gotoxy(77, 27);
	cout << "<";

	char lenh = ' ';
	lenh = doi_nhap(lenh);			//doi nhap tu ban phim
	system("cls");
}

//thoat game
void bye()
{
	system("cls");
	SetColor(14);
	gotoxy(25, 20);
	cout << "CAM ON CAC BAN DA THAM GIA TRO CHOI. HEN GAP LAI CAC BAN";

	SetColor(13);
	gotoxy(45, 22);
	for (int i = 1; i < 15; i++)
		cout << "*";
	cout << "*" << endl;
	Sleep(2000);
	exit(0);
}

//ve ban co
void ban_co(int n)
{
	system("cls");
	SetColor(15);
	int x = 0, y = 2;

	for (int i = 0; i <= n; i++)
	{
		if (i == 0)	//dong dau
		{
			cout << char(218);
			for (int j = 1; j < n; j++)
			{
				cout << char(196) << char(196) << char(196) << char(194);
			}
			cout << char(196) << char(196) << char(196) << char(191) << endl;
		}
		else if (i == n)	//dong cuoi
		{
			gotoxy(x, y);
			cout << char(192);
			for (int j = 1; j < n; j++)
			{
				gotoxy(x + 1, y);
				cout << char(196) << char(196) << char(196) << char(193);
				x += 4;
			}
			gotoxy(x + 1, y);
			cout << char(196) << char(196) << char(196) << char(217) << endl;
		}
		else //dong thuong
		{
			gotoxy(x, y);
			cout << char(195);
			for (int j = 1; j < n; j++)
			{
				gotoxy(x + 1, y);
				cout << char(196) << char(196) << char(196) << char(197);
				x += 4;
			}
			gotoxy(x + 1, y);
			cout << char(196) << char(196) << char(196) << char(180) << endl;
			y += 2;
			x = 0;
		}
	}

	x = 0;
	y = 1;
	for (int i = 0; i < n; i++)	// them cot
	{
		for (int j = 0; j <= n; j++)
		{
			gotoxy(x, y);
			cout << char(179);
			x += 4;
		}
		x = 0;
		y += 2;
	}

	huong_dan();
}

//kiem tra va danh dau o
bool check(int x, int y, int arr[100][100], int luot)
{
	if (char(arr[y][x]) > 0) return false;	// check o da danh
	else
	{
		if (luot % 2 == 0) arr[y][x] = 2;	// X = 2;
		else arr[y][x] = 1;	// O = 1;
		return true;
	}
}

//dieu kien thang
int checkWin(int n, int x, int y, int arr[100][100], int luot)
{
	if (luot >= 9)
	{
		if (arr[y][x] == 2)	// Check win X
		{
			int dem = 1;
			int t = 1;
			bool chanA = false, chanB = false;

			// Check Ngang
			while (arr[y][x + t * 4] > 0)	//Check phai
			{
				if (arr[y][x + t * 4] == 1)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if (x > n * 4 - 2) break;
			}

			t = 1;
			while (arr[y][x - t * 4] > 0)	//Check trai
			{
				if (arr[y][x - t * 4] == 1)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if (x < 2) break;
			}
			if (chanA && chanB && dem == 5) return 1;
			if (dem == 5) return 2;
			dem = 1, t = 1, chanA = false, chanB = false;

			// Check Doc
			while (arr[y + t * 2][x] > 0)	//Check xuong
			{
				if (arr[y + t * 2][x] == 1)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if ((y - t * 2) > n * 2 - 1) break;
			}

			t = 1;
			while (arr[y - t * 2][x] > 0)	//Check len
			{
				if (arr[y - t * 2][x] == 1)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if ((y - t * 2) < 1) break;
			}
			if (chanA && chanB && dem == 5) return 1;
			if (dem == 5) return 2;
			dem = 1, t = 1, chanA = false, chanB = false;

			// Check Cheo Chinh
			while (arr[y + t * 2][x + t * 4] > 0)	//Check xuong
			{
				if (arr[y + t * 2][x + t * 4] == 1)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if (((y + t * 2) > n * 2 - 1) || ((x + t * 4)) > n * 4 - 2) break;
			}

			t = 1;
			while (arr[y - t * 2][x - t * 4] > 0)	//Check len
			{
				if (arr[y - t * 2][x - t * 4] == 1)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if (((y - t * 2) < 1) || ((x - t * 4)) < 2) break;
			}
			if (chanA && chanB && dem == 5) return 1;
			if (dem == 5) return 2;
			dem = 1, t = 1, chanA = false, chanB = false;

			// Check Cheo Phu
			while (arr[y + t * 2][x - t * 4] > 0)	//Check cheo xuong
			{
				if (arr[y + t * 2][x - t * 4] == 1)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if (((y + t * 2) > n * 2 - 1) || ((x - t * 4)) > n * 4 - 2) break;
			}

			t = 1;
			while (arr[y - t * 2][x + t * 4] > 0)	//Check cheo len
			{
				if (arr[y - t * 2][x + t * 4] == 1)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if (((y - t * 2) < 1) || ((x + t * 4)) < 2) break;
			}
			if (chanA && chanB && dem == 5) return 1;
			if (dem == 5) return 2;
		}


		else // Check O
		{
			int dem = 1;
			int t = 1;
			bool chanA = false, chanB = false;

			// Check Ngang
			while (arr[y][x + t * 4] > 0)	//Check phai
			{
				if (arr[y][x + t * 4] == 2)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if ((x + t * 4) > n * 4 - 2) break;	// check ria
			}

			t = 1;
			while (arr[y][x - t * 4] > 0)	//Check trai
			{
				if (arr[y][x - t * 4] == 2)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if ((x - t * 4) < 2) break;
			}
			if (chanA && chanB && dem == 5) return 2;
			if (dem == 5) return 1;
			dem = 1, t = 1, chanA = false, chanB = false;


			// Check Doc
			while (arr[y + t * 2][x] > 0)	//Check xuong
			{
				if (arr[y + t * 2][x] == 2)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if ((y + t * 2) > n * 2 - 1) break;
			}

			t = 1;
			while (arr[y - t * 2][x] > 0)	//Check len
			{
				if (arr[y - t * 2][x] == 2)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if ((y - t * 2) < 1) break;
			}
			if (chanA && chanB && dem == 5) return 2;
			if (dem == 5) return 1;
			dem = 1, t = 1, chanA = false, chanB = false;

			// Check Cheo Chinh
			while (arr[y + t * 2][x + t * 4] > 0)	//Check cheo xuong
			{
				if (arr[y + t * 2][x + t * 4] == 2)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if (((y + t * 2) > n * 2 - 1) || ((x + t * 4)) > n * 4 - 2) break;
			}

			t = 1;
			while (arr[y - t * 2][x - t * 4] > 0)	//Check cheo len
			{
				if (arr[y - t * 2][x - t * 4] == 2)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if (((y - t * 2) < 1) || ((x - t * 4)) < 2) break;
			}
			if (chanA && chanB && dem == 5) return 2;
			if (dem == 5) return 1;
			dem = 1, t = 1, chanA = false, chanB = false;

			// Check Cheo Phu
			while (arr[y + t * 2][x - t * 4] > 0)	//Check cheo xuong
			{
				if (arr[y + t * 2][x - t * 4] == 2)
				{
					chanB = true;
					break;
				}
				else dem++;
				t++;
				if (((y + t * 2) > n * 2 - 1) || ((x - t * 4)) > n * 4 - 2) break;
			}

			t = 1;
			while (arr[y - t * 2][x + t * 4] > 0)	//Check cheo len
			{
				if (arr[y - t * 2][x + t * 4] == 2)
				{
					chanA = true;
					break;
				}
				else dem++;
				t++;
				if (((y - t * 2) < 1) || ((x + t * 4)) < 2) break;
			}
			if (chanA && chanB && dem == 5) return 2;
			if (dem == 5) return 1;
		}
	}
	return 0;
}

//cong diem va vinh danh
void win(int n, int x, int y, int arr[100][100], int luot, int &diemP1, int &diemP2)
{
	if (checkWin(n, x, y, arr, luot) == 2)
	{
		SetColor(12);
		gotoxy(40, 42);
		cout << "<< NGUOI CHIEN THANG: PLAYER 1 >>";
		diemP1++;
	}
	else
	{
		SetColor(10);
		gotoxy(40, 42);
		cout << "<< NGUOI CHIEN THANG: PLAYER 2 >>";
		diemP2++;
	}

	SetColor(13);
	gotoxy(20, 45);
	cout << "T: CHOI TIEP";
	gotoxy(73, 45);
	cout << "L: LUU DIEM";
}

//danh X hay O
void danh_co(int n, int x, int y, int arr[100][100], int &luot)
{
	if (check(x, y, arr, luot))
	{
		if (luot % 2 == 0)	// danh X
		{
			SetColor(12);
			cout << "X";

			SetColor(10);
			gotoxy(91, 19);
			cout << "---O---";
			gotoxy(x, y);
		}
		else 	// danh O
		{
			SetColor(10);
			cout << "O";

			SetColor(12);
			gotoxy(91, 19);
			cout << "---X---";
			gotoxy(x, y);
		}
		luot++;
	}
}

//xu ly cac hoat dong khi choi
void choi(int n, bool &tiep, int &diemP1, int &diemP2)
{
	int x = 2, y = 1;
	bool lap = true;
	int luot = 0;
	int arr[100][100];
	string data;
	fstream file;

	SetColor(12);
	gotoxy(88, 8);
	cout << diemP1;
	SetColor(14);

	SetColor(10);
	gotoxy(100, 8);
	cout << diemP2;

	SetColor(15);
	gotoxy(x, y);
	while (lap)
	{
		char lenh = ' ';
		lenh = doi_nhap(lenh);
		switch (lenh)
		{
		case 72:	// len
			if (y >= 1)
			{
				y -= 2;
				if (y < 1) y = n * 2 - 1;
				gotoxy(x, y);
			}
			break;

		case 80:	// xuong
			if (y <= n * 2 - 1)
			{
				y += 2;
				if (y > n * 2 - 1) y = 1;
				gotoxy(x, y);
			}
			break;

		case 77:	// phai
			if (x <= n * 4 - 2)
			{
				x += 4;
				if (x > n * 4 - 2) x = 2;
				gotoxy(x, y);
			}
			break;

		case 75:	// trai
			if (x >= 2)
			{
				x -= 4;
				if (x < 2) x = n * 4 - 2;
				gotoxy(x, y);
			}
			break;

		case 27:	// thoat
			bye();
			break;

		case 9:	// quay lai
			menu();
			break;

		case 13:	// danh
			danh_co(n, x, y, arr, luot);
			if (checkWin(n, x, y, arr, luot) > 0)
			{
				win(n, x, y, arr, luot, diemP1, diemP2);
				lap = false;

				char lenh1 = ' ';
				lenh1 = _getch();
				switch (lenh1)
				{
				case 116: case 84:	// choi tiep
					tiep = true;
					break;

				case 108: case 76:	// luu
					gotoxy(40, 47);
					cout << "TEN FILE LUU: ";
					getline(cin, data);
					data += ".txt";
					file.open(data, ios::out);
					file << n << endl;
					file << diemP1 << endl;
					file << diemP2 << endl;
					file.close();
					break;

				case 27:	// thoat
					bye();
					break;

				case 9:	// quay lai
					menu();
					break;

				default: break;
				}
			}
			break;
		}
	}
}

void veMenu()
{
	system("cls");
	SetColor(14);
	gotoxy(48, 11);
	cout << "C A R O";
	gotoxy(44, 13);
	cout << "PLAYER vs PLAYER";
	for (int i = 0; i <= 14; i++)
	{
		gotoxy(39, 15 + i);
		if (i == 0)	//dong dau
		{
			cout << char(201);
			for (int j = 1; j <= 12; j++)
			{

				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(187) << endl;
		}
		else if (i == 14)	//dong cuoi
		{
			cout << char(200);
			for (int j = 1; j <= 12; j++)
			{

				cout << char(205) << char(205);
			}
			cout << char(205) << char(205) << char(188) << endl;
		}
		else //dong thuong
		{
			cout << char(186);
			gotoxy(66, 15 + i);
			cout << char(186) << endl;
		}
	}

	int x = 44, y = 18;

	gotoxy(x, y);
	cout << "BAN CO: 20 x 20" << endl;
	gotoxy(x, y + 2);
	cout << "BAN CO: 15 x 15" << endl;
	gotoxy(x, y + 4);
	cout << "GIOI THIEU" << endl;
	gotoxy(x, y + 6);
	cout << "LOAD DIEM" << endl;
	gotoxy(x, y + 8);
	cout << "THOAT" << endl;

	x = 75;
	gotoxy(x, y - 1);
	cout << "HUONG DAN" << endl;
	gotoxy(x, y + 2);
	cout << "^: LEN" << endl;
	gotoxy(x, y + 4);
	cout << "v: XUONG" << endl;
	gotoxy(x, y + 6);
	cout << "ENTER: CHON" << endl;

	x = 62;
	gotoxy(x, y);
	SetColor(13);
	cout << "<";
	SetColor(15);

}

void conti(int n, bool tiep, int diemP1, int diemP2)
{
	while (tiep)
	{
		ban_co(n);
		choi(n, tiep, diemP1, diemP2);
	}
}

void load(int &n, bool tiep, int diemP1, int diemP2, string &data)
{
	fstream file;
	system("cls");
	gotoxy(40, 20);
	cout << "TEN FILE LUU: ";
	getline(cin, data);
	data += ".txt";

	file.open(data, ios::in);

	if (!file)
	{
		system("cls");
		gotoxy(40, 20);
		cout << "FILE NAY KHONG TON TAI!";
		Sleep(2000);
		menu();
	}
	else
	{
		file >> n;
		file >> diemP1;
		file >> diemP2;

		conti(n, tiep, diemP1, diemP2);
	}

	file.close();
}

void move(int &x, int &y, char lenh)
{
	gotoxy(x, y);		// xoa (ghi de)
	cout << " ";

	if (y >= 18 && lenh == 72)
	{
		if (y <= 18) y = 28;
		gotoxy(x, y - 2);
		SetColor(13);
		cout << "<";
		SetColor(15);
		y -= 2;
	}

	if (y <= 26 && lenh == 80)
	{
		if (y >= 26) y = 16;
		gotoxy(x, y + 2);
		SetColor(13);
		cout << "<";
		SetColor(15);
		y += 2;
	}
}

void menu()
{
	veMenu();

	int x = 62, y = 18;
	bool lap = true, tiep = true;
	int n, diemP1 = 0, diemP2 = 0;
	string data;

	while (lap)
	{
		char lenh = ' ';
		lenh = doi_nhap(lenh);			//doi nhap tu ban phim

		switch (lenh)
		{
		case 72:	// len
			move(x, y, lenh);
			break;

		case 80:	// xuong
			move(x, y, lenh);
			break;

		case 13:		// chon
			switch (y)
			{
			case 18: // size 20
				n = 20;
				conti(n, tiep, diemP1, diemP2);
				lap = false;
				break;

			case 20: // size 15
				n = 15;
				conti(n, tiep, diemP1, diemP2);
				lap = false;
				break;

			case 22: // gioi thieu
				gioi_thieu();
				menu();
				lap = false;
				break;

			case 24: // Load
				load(n, tiep, diemP1, diemP2, data);
				lap = false;
				break;

			case 26: // Thoat
				bye();
				break;
			}
			break;
		}
	}
}

int main()
{
	fixConsoleWindow();	// co dinh console
	SetWindow(105, 50); // console's size
	menu();
	return 0;
}