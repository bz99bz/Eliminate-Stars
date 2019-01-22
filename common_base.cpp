/*1751151 计1 郭思远*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include"E:/JJ作业/JJ作业/90-b1/common/cmd_console_tools.h"
#include<windows.h>
using namespace std;
void CSH(int(*a)[10], int h, int l, int flag);//初始化数组
void gotoxy(const int X, const int Y);
void setcolor(const int bg_color, const int fg_color);
void hebing(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal);//合并
void down(int a[][10], char cz[][10], int h, int l, int flag);//下落
int Max(int a[][10], int h, int l);//寻找最大值
void New(int a[][10], int bz[][10], int h, int l, int cd);//填充新值
int judge(int a[][10], int h, int l, int goal);//判断目标是否到达
void kuang(int a[][10], int h, int l, int cd);//框
void nbsz(int a[][10], int h, int l, int cd, int flag);//内部数组
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd);//移动
void getxy(int &x, int &y);//取坐标值
void getcolor(int &bg_color, int &fg_color);//取色
void hf_colour(int a[][10], int m, int n, int star,int cd);
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int flag, int hn, int ln);
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal, int flag, int hn, int ln);//图形合并
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl, int flag, int hn, int ln);//零下落
void tc(int a[][10], int bz[][10], int h, int l);//图形填充
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int star, int hn, int ln, int cd);//不连返回
int CD(int flag);//菜单
void get_end(char *pe, char *pn, char *pd);//读end;
char get_char(char *prompt, char min_value, char max_value);
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l, int flag);
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag, int star, int cd);
int CD(int flag)
{
	int cd;
	setconsoleborder(80, 30, 0, 0);
	cout << "--------------------------------------------" << endl;
	if (flag)
	{
		cout << "A.命令行找出可消除项并标识" << endl;
		cout << "B.命令行完成一次消除（分步骤显示)" << endl;
		cout << "C.命令行完成一关（分步骤显示)" << endl;
		cout << "D.伪图形界面下用鼠标选择一个色块（无分隔线)" << endl;
		cout << "E.伪图形界面下用鼠标选择一个色块（有分隔线）" << endl;
		cout << "F.伪图形界面完成一次消除（分步骤）" << endl;
		cout << "G.伪图形界面完整版" << endl;
		cout << "Q.退出" << endl;
	}
	else
	{
		cout << "1.命令行找出可合成项并标识（非递归）" << endl;
		cout << "2.命令行找出可合成项并标识（递归）" << endl;
		cout << "3.命令行完成一次合成（分步骤显示）" << endl;
		cout << "4.命令行完整版（分步骤显示）" << endl;
		cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
		cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
		cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
		cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
		cout << "9.伪图形界面完整版" << endl;
		cout << "0、退出" << endl;
	}
	cout << "--------------------------------------------" << endl;
	if (flag)
		cd = get_char("[请选择]:", 'A', 'G');
	else
		cd = get_int("请选择[0-9]", 0, 9, 0, 0, 0, 0, 0, 1);
	return cd;
}
void shuchu(int(*a)[10], char(*cz)[10], int bz[][10], int h, int l, int k)//0:当前数组，1：查找数组，2：颜色，3：零，4：填充
{

	if (k == 0)
	{
		cout << "当前数组：" << endl;
	}
	if (k == 2)
	{
		cout << "当前数组(不同色标识)：" << endl;
	}
	if (k == 1)
	{
		cout << "查找结果数组：" << endl;
	}
	if (k == 3)
	{
		cout << "除0后的数组(不同色标识)" << endl;
	}
	if (k == 4)
	{
		cout << "新值填充后的数组(不同色标识)：" << endl;
	}
	int i, j;
	cout << "  |";
	for (j = 0; j < l; j++)
		cout << "  " << j;
	cout << endl;
	cout << "--+";
	for (j = 1; j <= l; j++)
		cout << "---";
	cout << "-" << endl;
	if (k == 0)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
				cout << "  " << *(*(a + i) + j);
			cout << endl;
		}
	}
	if (k == 1)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
				cout << "  " << *(*(cz + i) + j);
			cout << endl;
		}
	}
	if (k == 2)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	if (k == 3)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (a[i][j] == 0)
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	if (k == 4)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (bz[i][j] == 1)
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;
}
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd,int hn,int ln)//查找函数
{
	int i, j, mb;
	mb = a[czh][czl];
	if (((*(*(a + czh - 1) + czl)) != mb&& *(*(a + czh + 1) + czl) != mb && (*(*(a + czh) + czl - 1) != mb) && (*(*(a + czh) + czl + 1) != mb)) || mb == 0)
	{
		if (cd != 8 && mb != 0&&cd!='F'&&cd!=9&&cd!='G')
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		if (cd == 8 && mb != 0)
		{
			setcolor(COLOR_BLACK, COLOR_WHITE);
			gotoxy(0, h * ln + 3);
			cout << "周围无相同值，箭头键移动，回车键选择" << endl;
		}
		if (mb == 0&&cd!='F'&&cd != 'G')
			cout << "输入的矩阵坐标位置为0（非法位置），请重新输入" << endl;
		return 0;
	}
	else
	{
		bz[czh][czl] = 1;
		cz[czh][czl] = '*';
		if (a[czh - 1][czl] == mb && (czh - 1) >= 0)
			cz[czh - 1][czl] = '*';
		if (a[czh + 1][czl] == mb && (czh + 1) < h)
			cz[czh + 1][czl] = '*';
		if (a[czh][czl + 1] == mb && (czl + 1) < l)
			cz[czh][czl + 1] = '*';
		if (a[czh][czl - 1] == mb && (czl - 1) >= 0)
			cz[czh][czl - 1] = '*';
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*'&&bz[i][j] == 0)
				{
					bz[i][j] = 1;
					if (a[i - 1][j] == mb && (i - 1) >= 0)
						cz[i - 1][j] = '*';
					if (a[i + 1][j] == mb && (i + 1) < h)
						cz[i + 1][j] = '*';
					if (a[i][j + 1] == mb && (j + 1) < l)
						cz[i][j + 1] = '*';
					if (a[i][j - 1] == mb && (j - 1) >= 0)
						cz[i][j - 1] = '*';
					i = 0;
					j = 0;
					continue;
				}
			}

		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] != '*')
					cz[i][j] = '0';
			}
		return 1;
	}
}
void down(int a[][10], char cz[][10], int h, int l, int flag)
{
	int ling = 0, mark;
	int i, j, step = h - 1;
	for (j = 0; j < l; j++)
	{
		step = h - 1;
		for (i = h - 1; i >= 0; i--)
			if (a[i][j] != 0)
			{
				a[step][j] = a[i][j];
				step--;
			}
		while (step >= 0)
		{
			a[step][j] = 0;
			step--;
		}
	}
	if (flag)
	{
		for (j = 0; j < l; j++)
		{
			ling = 0;
			for (i = 0; i < h; i++)
				if (a[i][j] == 0)
				{
					ling++;
				}
			if (ling == l)
			{
				mark = j;
				break;
			}
		}
		if (ling == l)
		{
			for (j = mark; j < l - 1; j++)
				for (i = 0; i < h; i++)
					a[i][j] = a[i][j + 1];
			for (i = 0; i < h; i++)
				a[i][l - 1] = 0;
		}
	}
	shuchu(a, cz, 0, h, l, 3);
}
int fail(int a[][10], int bz[][10], int h, int l, int flag)
{
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			bz[i][j] = 0;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if ((i - 1) >= 0 && (i + 1) < h && (j - 1) >= 0 && (j + 1) < l)//中间
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j - 1] != a[i][j])
							if (a[i][j + 1] != a[i][j])
								bz[i][j] = 1;
			if (j == 0 && i != 0 && i != h - 1)//四边
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (i == 0 && j != 0 && j != l - 1)
				if (a[i + 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (j == l - 1 && i != 0 && i != h - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j - 1] != a[i][j])
							bz[i][j] = 1;
			if (i == h - 1 && j != 0 && j != l - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (i == 0 && j == 0)//四角
				if (a[i][j + 1] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						bz[i][j] = 1;
			if (i == 0 && j == l - 1)
				if (a[i + 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						bz[i][j] = 1;
			if (i == h - 1 && j == 0)
				if (a[i][j + 1] != a[i][j])
					if (a[i - 1][j] != a[i][j])
						bz[i][j] = 1;
			if (i == h - 1 && j == l - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						bz[i][j] = 1;
		}
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (flag)
			{
				if (a[i][j] != 0)
					if (bz[i][j] != 1)
						return 0;
			}
			else
			{
				if (bz[i][j] != 1)
					return 0;
			}
		}
	return 1;
}
void kuang(int a[][10], int h, int l, int cd)
{
	if (cd == 5 || cd == 'D'||cd=='F'||cd=='G')
	{
		setconsoleborder(35 + 6 * (l - 5), 22 + 3 * (h - 5), 0, 0);
		cout << "屏幕当前设置为" << 22 + 3 * (h - 5) << "行" << 35 + 6 * (l - 5) << "列" << endl;
		int i, j, k;
		setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "╔";
		for (j = 0; j < l; j++)
		{
			cout << "═══";
			Sleep(100);
		}
		cout << "╗" << endl;
		for (i = 0; i < h; i++)
		{
			for (k = 0; k < 3; k++)
			{
				cout << "║";
				for (j = 0; j < l; j++)
					cout << "      ";
				cout << "║" << endl;
				Sleep(100);
			}
		}
		cout << "╚";
		for (j = 0; j < l; j++)
		{
			cout << "═══";
			Sleep(100);
		}
		cout << "╝" << endl;

		setcolor(COLOR_BLACK, COLOR_WHITE);
	}
	else
	{
		setconsoleborder(43 + 8 * (l - 5), 26 + 4 * (h - 5), 0, 0);
		cout << "屏幕当前设置为" << 26 + 4 * (h - 5) << "行" << 43 + 8 * (l - 5) << "列" << endl;
		int i, j, k;
		setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "╔";
		for (j = 0; j < l - 1; j++)
			cout << "═══╤";
		cout << "═══";
		cout << "╗" << endl;
		Sleep(100);
		for (i = 0; i < h - 1; i++)
		{
			for (k = 0; k < 3; k++)
			{
				cout << "║";
				for (j = 0; j < l - 1; j++)
					cout << "      │";
				cout << "      ║" << endl;
				Sleep(100);
			}
			cout << "╟";
			for (j = 0; j < l - 1; j++)
				cout << "───┼";
			cout << "───╢" << endl;
		}
		for (k = 0; k < 3; k++)
		{
			cout << "║";
			for (j = 0; j < l - 1; j++)
				cout << "      │";
			cout << "      ║" << endl;
			Sleep(100);
		}
		cout << "╚";
		for (j = 0; j < l - 1; j++)
		{
			cout << "═══╧";
			Sleep(100);
		}
		cout << "═══";
		cout << "╝" << endl;
	}
}
void nbsz(int a[][10], int h, int l, int cd, int flag)//内部数组
{
	const int BASE_X = 2, BASE_Y = 2;
	int n = 0, m = 0;
	gotoxy(BASE_X, BASE_Y);
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			if (a[i][j] == 1)
			{
				if (flag)
					setcolor(9, COLOR_BLACK);
				else
					setcolor(1, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				if (flag)
					cout << "║★║";
				else
					cout << "║ " << a[i][j] << "║";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";

			}
			if (a[i][j] == 2)
			{
				if (flag)
					setcolor(10, COLOR_BLACK);
				else
					setcolor(2, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				if (flag)
					cout << "║★║";
				else
					cout << "║ " << a[i][j] << "║";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";
			}
			if (a[i][j] == 3)
			{
				if (flag)
					setcolor(11, COLOR_BLACK);
				else
					setcolor(3, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				if (flag)
					cout << "║★║";
				else
					cout << "║ " << a[i][j] << "║";
				if (cd == 5 || cd == 'D')
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6 || cd == 'E')
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";
			}
			if (flag)
			{
				if (a[i][j] == 4)
				{
					if (flag)
						setcolor(12, COLOR_BLACK);
					else
						setcolor(4, COLOR_BLACK);
					cout << "╔═╗";
					if (cd == 5 || cd == 'D')
						gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
					if (cd == 6 || cd == 'E')
						gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
					cout << "║★║";
					if (cd == 5 || cd == 'D')
						gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
					if (cd == 6 || cd == 'E')
						gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
					cout << "╚═╝";
				}
				if (a[i][j] == 5)
				{
					if (flag)
						setcolor(13, COLOR_BLACK);
					else
						setcolor(4, COLOR_BLACK);
					cout << "╔═╗";
					if (cd == 5 || cd == 'D')
						gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
					if (cd == 6 || cd == 'E')
						gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
					cout << "║★║";
					if (cd == 5 || cd == 'D')
						gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
					if (cd == 6 || cd == 'E')
						gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
					cout << "╚═╝";
				}
			}

			if (cd != 8)
				Sleep(100);
			n++;
			if (cd == 5 || cd == 'D')
				gotoxy(BASE_X + 6 * n, BASE_Y + m * 3);
			if (cd == 6 || cd == 'E')
				gotoxy(BASE_X + 8 * n, BASE_Y + m * 4);
		}
		n = 0;
		m++;
		if (cd == 5 || cd == 'D')
			gotoxy(BASE_X + n * 6, BASE_Y + m * 3);
		if (cd == 6 || cd == 'E')
			gotoxy(BASE_X + n * 8, BASE_Y + m * 4);
	}
	if (cd == 5 || cd == 'D')
		gotoxy(BASE_X + n * 6, BASE_Y + m * 3 + 3);
	if (cd == 6 || cd == 'E')
		gotoxy(BASE_X + n * 6, BASE_Y + m * 3 + 6);
	setcolor(COLOR_BLACK, COLOR_WHITE);
}
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd)
{
	int star = 0;
	if (cd == 'D' || cd == 'E' || cd == 'F' || cd == 'G')
		star = 1;
	gotoxy(0, h * 4 + 2);
	if (cd == 7)
		cout << "箭头键移动，回车键选择并结束" << endl;
	if (cd == 8)
		cout << "箭头键移动，回车键选择" << endl;
	int t = 0, s = 0, i = 2, j = 2, w = 0, kg = 1;
	const int BASE_X = 2, BASE_Y = 2;
	int x = BASE_X, y = BASE_Y, n = 0, m = 0,z;
	int hh, ll,hn,ln;
	if (star)
	{
		hn = 6;
		ln = 3;
	}
	else
	{
		hn = 8;
		ln = 4;
	}
	for (z = 0; z < h - 1; z++)
	{
		if (sz[(BASE_Y + z * ln - 2) / ln ][(BASE_X - 2) / hn] != 0)
		{
			i = BASE_X;
			j = BASE_Y + z * ln;
			x = BASE_X;
			y = BASE_Y + z * ln;
			m = 0;
			n = z;
			break;
		}
	}
	gotoxy(i, j);
	int a, b;
	int ret, maction;
	int X = 0, Y = 0;
	int flag = 0, feifa = 1, bl = 1, get_x = 0, get_y = 0, qr = 0, ju = 0, open = 0, close = 0;
	enable_mouse();
	setcursor(CURSOR_INVISIBLE);
	while (1)
	{
		
		if (star)
		{
			hn = 6;
			ln = 3;
		}
		else
		{
			hn = 8;
			ln = 4;
		}
		if (open)
		{
			setcolor(COLOR_BLACK, COLOR_WHITE);
			if (cd == 'D')
			{
				gotoxy(0, h * 3 + 4);
				cout << "                                                                         " << endl;
				gotoxy(0, h * 3 + 4);
				cout << "选中了" << (char)('A' + (Y - 2) / 3) << "行" << (X - 2) / 6 << "列" << endl;
			}
			if(cd=='E')
			{
				gotoxy(0, h * 4 + 2);
				cout << "                                                                         " << endl;
				gotoxy(0, h * 4 + 2);
				cout << "选中了" << (char)('A' + (Y - 2) / 4) << "行" << (X - 2) / 8 << "列" << endl;
			}
			break;
		}
		if (bl)
		{
			hf_colour(sz, t, s, star, cd);
			colour(sz, h, l, &t, &s, i, j, flag, star, cd);
		}
		ret = read_keyboard_and_mouse(X, Y, maction, a, b);
		if (ret == CCT_KEYBOARD_EVENT)
		{
			feifa = 1;
			for (hh = 0; hh < h; hh++)
				for (ll = 0; ll < l; ll++)
				{
					bz[hh][ll] = 0;
					cz[hh][ll] = 0;
				}
			if (a == 13)
			{
				if (cd == 7 || cd == 'D' || cd == 'E')
					break;
				w = lian(sz, cz, bz, h, l, i, j, star,hn,ln);
				a = 0;
				a = _getch();
				if (a == 13 && w == 1)
					break;
				if (a == 224)
				{
					b = _getch();
					bulian(sz, cz, bz, h, l, i, j, star,hn,ln,cd);
					a = 0;
					continue;
				}
			}
			else
			{
				if (a == 224 && b == 72)//向上
				{
					int kg_up = 0;
					if (cd == 'D'||cd=='F'||cd=='G')
					{
						if (y >= BASE_Y+ 3 && y <= BASE_Y + (h - 1) * 3)
						{
							if(sz[(y - 2) / 3 - 1][(x - 2) / 6] == 0)
							{
									kg_up = 1;
									n = h - 1;
									x = BASE_X + 6 * m;
									y = BASE_Y + (h - 1) * 3;
							}
							if (sz[(y - 2) / 3 - 1][(x - 2) / 6] != 0&&kg_up==0)
							{
								n--;
								x = BASE_X + 6 * m;
								y = BASE_Y + 3 * n;
							}
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (y == BASE_Y)
						{
							n = h - 1;
							x = BASE_X + 6 * m;
							y = BASE_Y + (h - 1) * 3;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
					else
					{
						if (y >= BASE_Y + 4 && y <= BASE_Y + (h - 1) * 4)
						{
							n--;
							x = BASE_X + 8 * m;
							y = BASE_Y + 4 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (y == BASE_Y)
						{
							n = h - 1;
							x = BASE_X + 8 * m;
							y = BASE_Y + (h - 1) * 4;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
				}
				else if (a == 224 && b == 75)//左
				{
					int kg_left = 0;
					if (cd == 'D'||cd=='F'||cd=='G')
					{
						if (x >= BASE_X + 6 && x <= BASE_X + (l - 1) * 6)
						{
							while (sz[(y - 2) / 3][(x - 2) / 6-1] == 0)
							{
								m--;
								x = BASE_X + 6 * m;
								y = BASE_Y + 3 * n;
								if (x == BASE_X)
								{
									kg_left = 1;
									x = BASE_X + (l - 1) * 6;
									y = BASE_Y + 3 * n;
									m = l - 1;
								}
								
							}
							if(sz[(y - 2) / 3][(x - 2) / 6 - 1] != 0&& kg_left==0)
							{
								m--;
								x = BASE_X + 6 * m;
								y = BASE_Y + 3 * n;
							}
								gotoxy(x, y);
								getxy(i, j);
								continue;
						}
						if (x == BASE_X)
						{
							m = l - 1;
							x = BASE_X + (l - 1) * 6;
							y = BASE_Y + 3 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
					else
					{
						if (x >= BASE_X + 8 && x <= BASE_X + (l - 1) * 8)
						{
							m--;
							x = BASE_X + 8 * m;
							y = BASE_Y + 4 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (x == BASE_X)
						{
							m = l - 1;
							x = BASE_X + (l - 1) * 8;
							y = BASE_Y + 4 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
				}
				else if (a == 224 && b == 77)//右
				{
					int kg_right = 0;
					if (cd == 'D'||cd=='F'||cd=='G')
					{
						if (x >= BASE_X && x <= BASE_X + (l - 2) * 6)
						{
							while (sz[(y - 2) / 3][(x - 2) / 6 + 1] == 0)
							{
								m++;
								x = BASE_X + 6 * m;
								y = BASE_Y + 3 * n;
								if (x == BASE_X + (l - 1) * 6)
								{
									kg_right = 1;
									m = 0;
									x = BASE_X + 6 * m;
									y = BASE_Y + 3 * n;
								}
								
							}
							if (sz[(y - 2) / 3][(x - 2) / 6 + 1] != 0&& kg_right==0)
							{
								m++;
								x = BASE_X + 6 * m;
								y = BASE_Y + 3 * n;
							}
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (x == BASE_X + (l - 1) * 6)
						{
							m = 0;
							x = BASE_X + 6 * m;
							y = BASE_Y + 3 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
					else
					{
						if (x >= BASE_X && x <= BASE_X + (l - 2) * 8)
						{
							m++;
							x = BASE_X + 8 * m;
							y = BASE_Y + 4 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (x == BASE_X + (l - 1) * 8)
						{
							m = 0;
							x = BASE_X;
							y = BASE_Y + 4 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
				}
				else if (a == 224 && b == 80)
				{
					int kg_down = 0;
					if (cd == 'D'||cd=='F' || cd == 'G')
					{
						if (y >= BASE_Y&&y <= BASE_Y + (h - 2) * 3)
						{
							n++;
							x = BASE_X + 6 * m;
							y = BASE_Y + 3 * n;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (y == BASE_Y + (h - 1) * 3)
						{
							n = 0;
							x = BASE_X + 6 * m;
							y = BASE_Y;
							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
					else
					{
						if (y >= BASE_Y&&y <= BASE_Y + (h - 2) * 4)
						{
							n++;

							x = BASE_X + 8 * m;
							y = BASE_Y + 4 * n;

							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
						if (y == BASE_Y + (h - 1) * 4)
						{
							n = 0;

							x = BASE_X + 8 * m;
							y = BASE_Y;

							gotoxy(x, y);
							getxy(i, j);
							continue;
						}
					}
				}
			}
		}
		else if (ret == CCT_MOUSE_EVENT)
		{
			if (star == 0)
			{
				ju = judge(sz, h, l, goal);
				if (ju)
				{
					gotoxy(0, h * 4 + 2);
					setcolor(COLOR_HYELLOW, COLOR_HRED);
					cout << "已经合成到" << goal << endl;
					setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "按回车键继续向更高目标进发..." << endl;
					while (1)
					{
						ret = read_keyboard_and_mouse(X, Y, maction, a, b);
						if (a == 13 || maction == MOUSE_LEFT_BUTTON_CLICK)
							break;
					}
					goal++;
				}
			}
			flag = 1;
			switch (maction)
			{
				case MOUSE_ONLY_MOVED:
					if (cd == 9)
					{
						if (!bl &&( X <= (i - 2) / 8 * 8 + 2 || X >= (i - 2) / 8 * 8 + 8 || Y <= (j - 2) / 4 * 4 + 1 || Y >= (j - 2) / 4 * 4 + 5))
						{
							bulian(sz, cz, bz, h, l, i, j, star, 8, 4,cd);
							bl = 1;
							qr = 0;
							w = 0;
						}
					}
					if (cd == 'D' || cd == 'F' || cd == 'G')
					{
						if (!bl && (X <= (i - 2) * 6 / 6+1|| X >= (i - 2) / 6* 6+7|| Y <= (j - 2) / 3* 3+1|| Y >= (j - 2) / 3* 3 +5 ))
						{
							bulian(sz, cz, bz, h, l, i, j, star,6,3,cd);
							bl = 1;
							qr = 0;
							w = 0;
						}
					}
					if (cd == 'D' || cd == 'F' || cd == 'G')
					{
						setcolor(COLOR_BLACK, COLOR_WHITE);
						gotoxy(0, h * 3 + 4);
						cout << "                                                   ";
						gotoxy(0, h * 3 + 4);
						if ((((Y - 2) / 3) <= h - 1) && (((X - 2) / 6) <= l - 1) && Y > 0)
						{
							cout << "[当前鼠标]" << (char)('A' + (Y - 2) / 3) << "行" << (X - 2) / 6 << "列" << endl;
							if (bl)
							{
								i = X;
								j = Y;
							}
							feifa = 1;
						}
						else
						{
							cout << "[当前鼠标]位置非法";
							feifa = 0;
						}
					}
					else
					{
						setcolor(COLOR_BLACK, COLOR_WHITE);
						gotoxy(0, h * 4 + 2);
						cout << "                                                   ";
						gotoxy(0, h * 4 + 2);
						if ((((Y - 2) / 4) <= h - 1) && (((X - 2) / 8) <= l - 1) && Y > 0)
						{
							cout << "[当前鼠标]" << (char)('A' + (Y - 2) / 4) << "行" << (X - 2) / 8 << "列" << endl;
							if (bl)
							{
								i = X;
								j = Y;
							}
							feifa = 1;
						}
						else
						{
							cout << "[当前鼠标]位置非法";
							feifa = 0;
						}
					}
					break;
				case MOUSE_LEFT_BUTTON_CLICK:
				{
					if (star)
					{
						hn = 6;
						ln = 3;
					}
					else
					{
						hn = 8;
						ln = 4;
					}
					if (cd == 'D' || cd == 'E')
					{
						open = 1;
						break;
					}
					if (qr&&w)
					{
						for (hh = 0; hh < h; hh++)
							for (ll = 0; ll < l; ll++)
								bz[hh][ll] = 0;
						i = (X - 2) / hn * hn + 2;
						j = (Y - 2) / ln * ln + 2;
						tx_hb(sz, cz, bz, h, l, i, j, goal, star,hn,ln);
						tx_down(sz, bz, cz, h, l, i, j, star,hn,ln);
						if (!star)
							tc(sz, bz, h, l);
						qr = 0;
						w = 0;
						if (cd == 'F'||cd=='G')
						{
							open = 1;
							break;
						}
					}
					else
					{
						if (cd == 'D' || cd == 'F' || cd == 'G')
						{
							i = (X - 2) / 6 * 6 + 2;
							j = (Y - 2) / 3 * 3 + 2;
						}
						else
						{
							i = (X - 2) / 8 * 8 + 2;
							j = (Y - 2) / 4 * 4 + 2;
						}
						w = lian(sz, cz, bz, h, l, i, j, star,hn,ln);
						bl = 0;
						qr = 1;
						setcolor(COLOR_BLACK, COLOR_WHITE);
						gotoxy(0, h * ln + 3);
						cout << "箭头键/鼠标移动取消当前选择，回车键、单击左键确认";
					}
					break;
				}
			}
			get_x = i, get_y = j;
		}
	}
	if(open!=1)
		if (cd == 8 || cd == 9 || cd == 'F' || cd == 'G')
		{
			if (star)
			{
				hn = 6;
				ln = 3;
			}
			else
			{
				hn = 8;
				ln = 4;
			}
			for (hh = 0; hh < h; hh++)
				for (ll = 0; ll < l; ll++)
					bz[hh][ll] = 0;
			tx_hb(sz, cz, bz, h, l, i, j, goal, star,hn,ln);
			int gsy;
			if (cd == 8||cd=='F')
			{
				while (1)
				{
					gsy = _getch();
					if (gsy == 13)
						break;
				}
			}
			tx_down(sz, bz, cz, h, l, i, j, star,hn,ln);
	        gsy = 0;
			if (cd == 8)
				while (1)
				{
					gsy = _getch();
					if (gsy == 13)
						break;
				}
			tc(sz, bz, h, l);
		}
		gotoxy(0, h * 4 + 3);
		setcolor(COLOR_BLACK, COLOR_WHITE);
}




