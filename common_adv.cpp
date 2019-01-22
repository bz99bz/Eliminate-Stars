/*1751151 计1 郭思远*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include"E:/JJ作业/JJ作业/90-b1/common/cmd_console_tools.h"
#include<windows.h>
using namespace std;
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd, int hn, int ln);//查找函数
void jifen(int num, int k, int goal, int cd, int flag);//计分
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l, int flag)
{
	int value;
	char value2;
	char  a[4] = { 0 };
	if (min_value == 'a')
	{
		while (1)
		{
			cout << "                                                  " << endl;
			cout << prompt;
			cin >> a;
			if (a[0] >= 'a'&&a[0] <= 'h')
				a[0] = a[0] - 32;
			if (a[0] >= 'A'&&a[0] <= h - 1 + 'A'&&a[1] >= '0'&&a[1] <= l - 1 + '0')
			{
				*p1 = a[0] - 'A';
				*p2 = a[1] - '0';
				break;
			}
			else
				cout << "输入错误，请重新输入.";
		}
		return 0;
	}
	if (min_value == 0)
	{
		while (1)
		{
			cout << prompt << "(" << min_value << "-" << max_value << "):";
			cin >> value;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail(), '\n');
				continue;
			}
			if (value >= min_value&&value <= max_value)
				break;
		}
		return value;
	}
	if (min_value == 5 || min_value == 8)
	{
		while (1)
		{
			if (!flag)
			{
				if (max_value == 8)
					gotoxy(0, 0);
				if (max_value == 10)
					gotoxy(0, 1);
				if (max_value == 20)
					gotoxy(0, 2);
				cout << "                                                                                  " << endl;
				if (max_value == 8)
					gotoxy(0, 0);
				if (max_value == 10)
					gotoxy(0, 1);
				if (max_value == 20)
					gotoxy(0, 2);
			}
			cout << prompt << "(" << min_value << "-" << max_value << "):";
			cin >> value;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail(), '\n');
				continue;
			}
			if (value >= min_value&&value <= max_value)
				break;
			else
				cout << "                       输入错误" << endl;
		}
		return value;
	}
	if (min_value == 'N')
		while (1)
		{
			cin >> value2;
			if (value2 == 'y' || value2 == 'Y' || value2 == 'n' || value2 == 'N' || value2 == 'q' || value2 == 'Q')
				break;
		}
	return value2;
}
void CSH(int(*a)[10], int h, int l, int flag)
{
	int i, j;
	if (flag)
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				*(*(a + i) + j) = rand() % 5 + 1;
			}
	}
	else
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				*(*(a + i) + j) = rand() % 3 + 1;
			}
	}
	cout << endl;
}
void get_end(char *pe, char *pn, char *pd)
{
	int m, n, i;
	getxy(m, n);
	gotoxy(m, n);
	char a[10] = { 0 };
	while (1)
	{
		cin >> a;
		if (a[0] >= 'a'&&a[0] <= 'z'&&a[1] >= 'a'&&a[1] <= 'z'&&a[2] >= 'a'&&a[2] <= 'z')
		{
			a[0] = a[0] - 32;
			a[1] = a[1] - 32;
			a[2] = a[2] - 32;
		}
		if (a[0] == 'E'&&a[1] == 'N'&&a[2] == 'D')
		{
			*pe = a[0];
			*pn = a[1];
			*pd = a[2];
			break;
		}
		else
		{
			gotoxy(m, n + 1);
			cout << "输入错误";
		}
		for (i = 0; i < 10; i++)
			a[i] = 0;
	}
}
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag, int star, int cd)//菜单D的鼠标和键盘移动都还有问题！！！在move里改！！！
{
	int hn, ln;
	if (cd == 9 || cd == 'E')
	{
		hn = 8;
		ln = 4;
	}
	if (cd == 'F' || cd == 'D'||cd=='G')
	{
		hn = 6;
		ln = 3;
	}
	if (a[(y - 2) / ln][(x - 2) / hn] == 0&&cd!=9)
	{
		if (flag)
		{
			*p1 = (x - 2) / hn *hn + 2;
			*p2 = (y - 2) / ln* ln + 2;
			setcolor(COLOR_HWHITE, COLOR_HWHITE);
			gotoxy((x - 2) / hn * hn + 2, (y - 2) / ln* ln + 2);
			cout << "╔═╗";
			gotoxy((x - 2) / hn * hn + 2, (y - 2) / ln * ln + 3);
			cout << "║★║";
			gotoxy((x - 2) / hn * hn + 2, (y - 2) / ln* ln + 4);
			cout << "╚═╝";
			gotoxy(0, h * ln + 3);
		}
		else
		{
			
				*p1 = x;
				*p2 = y;
				setcolor(COLOR_HWHITE, COLOR_HWHITE);
				gotoxy(x, y);
				cout << "╔═╗";
				gotoxy(x, y + 1);
				cout << "║★║";
				gotoxy(x, y + 2);
				cout << "╚═╝";
				gotoxy(0, h * 4 + 3);
			
		}
	}
	else
	{
		if (flag)
		{
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
			{
				*p1 = (x - 2) / 6 * 6 + 2;
				*p2 = (y - 2) / 3 * 3 + 2;
			}
			else
			{
				*p1 = (x - 2) / 8 * 8 + 2;
				*p2 = (y - 2) / 4 * 4 + 2;
			}
			if (star)
			{
				if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
					setcolor(a[(y - 2) / 3][(x - 2) / 6] + 8, COLOR_WHITE);
				else
					setcolor(a[(y - 2) / 4][(x - 2) / 8] + 8, COLOR_WHITE);
			}
			else
				setcolor(COLOR_HYELLOW, COLOR_BLUE);
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				gotoxy((x - 2) / 6 * 6 + 2, (y - 2) / 3 * 3 + 2);
			else
				gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 2);
			cout << "╔═╗";
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				gotoxy((x - 2) / 6 * 6 + 2, (y - 2) / 3 * 3 + 3);
			else
				gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 3);
			if (star)
				cout << "║★║";
			else
				cout << "║ " << a[(y - 2) / 4][(x - 2) / 8] << "║";
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				gotoxy((x - 2) / 6 * 6 + 2, (y - 2) / 3 * 3 + 4);
			else
				gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 4);
			cout << "╚═╝";
			gotoxy(0, h * 4 + 3);
		}
		else
		{
			*p1 = x;
			*p2 = y;
			if (star)
			{
				if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
					setcolor(a[(y - 2) / 3][(x - 2) / 6] + 8, COLOR_WHITE);
				else
					setcolor(a[(y - 2) / 4][(x - 2) / 8] + 8, COLOR_WHITE);
			}
			else
				setcolor(COLOR_HYELLOW, COLOR_BLUE);
			gotoxy(x, y);
			cout << "╔═╗";
			gotoxy(x, y + 1);
			if (star)
				cout << "║★║";
			else
				cout << "║ " << a[(y - 2) / 4][(x - 2) / 8] << "║";
			gotoxy(x, y + 2);
			cout << "╚═╝";
			gotoxy(0, h * 4 + 3);
		}
	}
}

void hf_colour(int a[][10], int m, int n, int star,int cd)
{
	int hn, ln;
	if (cd == 9 || cd == 'E')
	{
		hn = 8;
		ln = 4;
	}
	if (cd == 'F' || cd == 'D'||cd=='G')
	{
		hn = 6;
		ln = 3;
	}
	if (m != 0&& a[(n - 2) / ln][(m - 2) / hn] != 0)
	{
		int c = a[(n - 2) / 4][(m - 2) / 8];
		if (star)
		{
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				setcolor(a[(n - 2) / 3][(m - 2) / 6] + 8, COLOR_BLACK);
			else
				setcolor(a[(n- 2) / 4][(m - 2) / 8] + 8, COLOR_BLACK);
		}
		else
			setcolor(c, COLOR_BLACK);
		gotoxy(m, n);
		cout << "╔═╗";
		gotoxy(m, n + 1);
		if (star)
			cout << "║★║";
		else
			cout << "║ " << a[(n - 2) / 4][(m - 2) / 8] << "║";
		gotoxy(m, n + 2);
		cout << "╚═╝";
	}
	if (a[(n - 2) / ln][(m - 2) / hn] == 0)
	{
		if ((n - 2) / ln != 0 || (m - 2) / hn != 0)
		{
			setcolor(COLOR_HWHITE, COLOR_HWHITE);
			gotoxy(m, n);
			cout << "╔═╗";
			gotoxy(m, n + 1);
			cout << "║★║";
			gotoxy(m, n + 2);
			cout << "╚═╝";
		}
		else
		{
			m = 2, n = 2;
			setcolor(COLOR_HWHITE, COLOR_HWHITE);
			gotoxy(m, n);
			cout << "╔═╗";
			gotoxy(m, n + 1);
			cout << "║★║";
			gotoxy(m, n + 2);
			cout << "╚═╝";
		}
	}
}
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl,int flag,int hn,int ln)//czh,czl是当前光标位置。
{
	int k, i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
	k = CZ(a, bz, cz, h, l, (czl - 2) / ln, (czh - 2) / hn, 8,hn,ln);
	if (k == 0)
		return 0;
	if (k)
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					if (flag)
					{
						if ((i == (czl - 2) / ln) && (j == (czh - 2) / hn))
							setcolor(a[(czl - 2) / ln][(czh - 2) / hn] + 8, COLOR_HWHITE);
						else
							setcolor(a[(czl - 2) / ln][(czh - 2) / hn] + 8, COLOR_WHITE);
					}
					else
					{
						if ((i == (czl - 2) / ln) && (j == (czh - 2) / hn))
							setcolor(COLOR_HYELLOW, COLOR_HRED);
						else
							setcolor(COLOR_HYELLOW, COLOR_BLACK);
					}
					gotoxy(hn * j + 2, ln * i + 2);
					cout << "╔═╗";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					if (flag)
						cout << "║★║";
					else
						cout << "║ " << a[i][j] << "║";
					gotoxy(hn * j + 2, ln * i + 2 + 2);
					cout << "╚═╝";
				}
			}
		setcolor(COLOR_BLACK, COLOR_WHITE);
		gotoxy(0, h * ln + 3);
		cout << "箭头键移动并取消当前选择，回车键合成                  " << endl;
	}
	return 1;
}
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int star,int hn,int ln,int cd)
{
	int k, i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
	k = CZ(a, bz, cz, h, l, (czl - 2) / ln, (czh - 2) / hn, cd,hn,ln);
	if (k)
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					if (star)
						setcolor(a[i][j] + 8, COLOR_BLACK);
					else
						setcolor(a[i][j], COLOR_BLACK);
					gotoxy(hn * j + 2, ln * i + 2);
					cout << "╔═╗";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					if (star)
						cout << "║★║";
					else
						cout << "║ " << a[i][j] << "║";
					gotoxy(hn* j + 2, ln * i + 2 + 2);
					cout << "╚═╝";
				}
			}
	}
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
}
char get_char(char *prompt, char min_value, char max_value)
{
	char value;
	while (1)
	{
		cout << "                                                  " << endl;
		cout << prompt;
		cin >> value;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			continue;
		}
		if (value >= 'a'&&value <= 'g')
			value = value - 32;
		if (value >= min_value&&value <= max_value)
			break;
	}
	return value;
}
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal,int flag,int hn,int ln)
{
	int i, j, k, num = 0;
	k = a[(czl - 2) / ln][(czh - 2) / hn];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (cz[i][j] == '*')
			{
				setcolor(COLOR_HWHITE, COLOR_HWHITE);
				gotoxy(hn * j + 2, ln * i + 2);
				cout << "╔═╗";
				gotoxy(hn * j + 2, ln * i + 2 + 1);
				cout << "║ " << a[i][j] << "║";
				gotoxy(hn * j + 2, ln * i + 2 + 2);
				cout << "╚═╝";
				num++;
				bz[i][j] = 1;
				a[i][j] = 0;
			}
		}
	if (flag == 0)
	{
		a[(czl - 2) / ln][(czh - 2) / hn] = k + 1;
		setcolor(k + 1, COLOR_BLACK);
		gotoxy(czh, czl);
		cout << "╔═╗";
		gotoxy(czh, czl + 1);
		cout << "║ " << a[(czl - 2) / ln][(czh - 2) / hn] << "║";
		gotoxy(czh, czl + 2);
		cout << "╚═╝";
		bz[(czl - 2) / ln][(czh - 2) / hn] = 0;
	}
	setcolor(COLOR_BLACK, COLOR_WHITE);
	jifen(num, k, goal, 8, 1);
	gotoxy(0, h * ln + 3);
	cout << "合成完成，回车键下落0                         " << endl;
}
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl,int flag,int hn,int ln)
{
	int i, j, kg = 0, m, n,ling=0,mark=0,k=0,t;
	for (j = 0; j < l; j++)
	{
		for (i = h - 1; i >= 0; i--)
		{
			if (bz[i][j] == 1 && kg == 0)
			{
				kg = 1;
				m = i;
				n = j;
			}
			if (kg == 1)
			{
				if (bz[i][j] == 0&&a[i][j]!=0)
				{
					setcolor(COLOR_HWHITE, COLOR_HWHITE);
					gotoxy(hn * j + 2, ln * i + 2);
					cout << "╔═╗";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					cout << "║  ║";
					gotoxy(hn * j + 2, ln * i + 2 + 2);
					cout << "╚═╝";
					if (flag)
						setcolor(a[i][j] + 8, COLOR_BLACK);
					else
						setcolor(a[i][j], COLOR_BLACK);
					gotoxy(hn* n + 2, ln * m + 2);
					cout << "╔═╗";
					gotoxy(hn* n + 2, ln* m + 2 + 1);
					if(flag)
						cout << "║★║";
					else
					    cout << "║ " << a[i][j] << "║";
					gotoxy(hn* n + 2, ln* m + 2 + 2);
					cout << "╚═╝";
					bz[m][n] = 0;
					bz[i][j] = 1;
					a[m][n] = a[i][j];
					a[i][j] = 0;
					kg = 0;
					i = h - 1;
					Sleep(500);
					continue;
				}
			}
		}
		kg = 0;
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
					for (k = j; k < l - 1; k++)
						for (t = 0; t < h; t++)
						{
							if (a[t][k + 1] != 0)
							{
								m = t;
								n = k;
								setcolor(a[t][k + 1] + 8, COLOR_BLACK);
								gotoxy(hn* n + 2, ln * m + 2);
								cout << "╔═╗";
								gotoxy(hn* n + 2, ln* m + 2 + 1);
								cout << "║★║";
								gotoxy(hn* n + 2, ln* m + 2 + 2);
								cout << "╚═╝";
								m = t;
								n = k+1;
								setcolor(COLOR_HWHITE, COLOR_HWHITE);
								gotoxy(hn* n + 2, ln * m + 2);
								cout << "╔═╗";
								gotoxy(hn* n + 2, ln* m + 2 + 1);
								cout << "║★║";
								gotoxy(hn* n + 2, ln* m + 2 + 2);
								cout << "╚═╝";
								a[t][k] = a[t][k + 1];
								a[t][k + 1] = 0;
							}
						}
					for (t = 0; t < h; t++)
						a[t][l - 1] = 0;
				}
			}
	}
}
void jifen(int num, int k, int goal, int cd, int flag)
{
	static int sum = 0;
	int bc;
	if (flag)
		bc = num*num * 5;
	else
		bc = k*num * 3;
	sum = sum + bc;
	if (cd == 8)
		gotoxy(0, 0);
	if (flag)
		cout << "本次得分：" << bc << " " << "总得分：" << sum << endl;
	else
		cout << "本次得分：" << bc << " " << "总得分：" << sum << " " << "合成目标：" << goal << endl;
	cout << endl;
}
