/*1751151 ��1 ��˼Զ*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include"E:/JJ��ҵ/JJ��ҵ/90-b1/common/cmd_console_tools.h"
#include<windows.h>
using namespace std;
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd, int hn, int ln);//���Һ���
void jifen(int num, int k, int goal, int cd, int flag);//�Ʒ�
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
				cout << "�����������������.";
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
				cout << "                       �������" << endl;
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
			cout << "�������";
		}
		for (i = 0; i < 10; i++)
			a[i] = 0;
	}
}
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag, int star, int cd)//�˵�D�����ͼ����ƶ����������⣡������move��ģ�����
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
			cout << "�X�T�[";
			gotoxy((x - 2) / hn * hn + 2, (y - 2) / ln * ln + 3);
			cout << "�U��U";
			gotoxy((x - 2) / hn * hn + 2, (y - 2) / ln* ln + 4);
			cout << "�^�T�a";
			gotoxy(0, h * ln + 3);
		}
		else
		{
			
				*p1 = x;
				*p2 = y;
				setcolor(COLOR_HWHITE, COLOR_HWHITE);
				gotoxy(x, y);
				cout << "�X�T�[";
				gotoxy(x, y + 1);
				cout << "�U��U";
				gotoxy(x, y + 2);
				cout << "�^�T�a";
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
			cout << "�X�T�[";
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				gotoxy((x - 2) / 6 * 6 + 2, (y - 2) / 3 * 3 + 3);
			else
				gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 3);
			if (star)
				cout << "�U��U";
			else
				cout << "�U " << a[(y - 2) / 4][(x - 2) / 8] << "�U";
			if (cd == 5 || cd == 'D' || cd == 'F'||cd=='G')
				gotoxy((x - 2) / 6 * 6 + 2, (y - 2) / 3 * 3 + 4);
			else
				gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 4);
			cout << "�^�T�a";
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
			cout << "�X�T�[";
			gotoxy(x, y + 1);
			if (star)
				cout << "�U��U";
			else
				cout << "�U " << a[(y - 2) / 4][(x - 2) / 8] << "�U";
			gotoxy(x, y + 2);
			cout << "�^�T�a";
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
		cout << "�X�T�[";
		gotoxy(m, n + 1);
		if (star)
			cout << "�U��U";
		else
			cout << "�U " << a[(n - 2) / 4][(m - 2) / 8] << "�U";
		gotoxy(m, n + 2);
		cout << "�^�T�a";
	}
	if (a[(n - 2) / ln][(m - 2) / hn] == 0)
	{
		if ((n - 2) / ln != 0 || (m - 2) / hn != 0)
		{
			setcolor(COLOR_HWHITE, COLOR_HWHITE);
			gotoxy(m, n);
			cout << "�X�T�[";
			gotoxy(m, n + 1);
			cout << "�U��U";
			gotoxy(m, n + 2);
			cout << "�^�T�a";
		}
		else
		{
			m = 2, n = 2;
			setcolor(COLOR_HWHITE, COLOR_HWHITE);
			gotoxy(m, n);
			cout << "�X�T�[";
			gotoxy(m, n + 1);
			cout << "�U��U";
			gotoxy(m, n + 2);
			cout << "�^�T�a";
		}
	}
}
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl,int flag,int hn,int ln)//czh,czl�ǵ�ǰ���λ�á�
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
					cout << "�X�T�[";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					if (flag)
						cout << "�U��U";
					else
						cout << "�U " << a[i][j] << "�U";
					gotoxy(hn * j + 2, ln * i + 2 + 2);
					cout << "�^�T�a";
				}
			}
		setcolor(COLOR_BLACK, COLOR_WHITE);
		gotoxy(0, h * ln + 3);
		cout << "��ͷ���ƶ���ȡ����ǰѡ�񣬻س����ϳ�                  " << endl;
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
					cout << "�X�T�[";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					if (star)
						cout << "�U��U";
					else
						cout << "�U " << a[i][j] << "�U";
					gotoxy(hn* j + 2, ln * i + 2 + 2);
					cout << "�^�T�a";
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
				cout << "�X�T�[";
				gotoxy(hn * j + 2, ln * i + 2 + 1);
				cout << "�U " << a[i][j] << "�U";
				gotoxy(hn * j + 2, ln * i + 2 + 2);
				cout << "�^�T�a";
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
		cout << "�X�T�[";
		gotoxy(czh, czl + 1);
		cout << "�U " << a[(czl - 2) / ln][(czh - 2) / hn] << "�U";
		gotoxy(czh, czl + 2);
		cout << "�^�T�a";
		bz[(czl - 2) / ln][(czh - 2) / hn] = 0;
	}
	setcolor(COLOR_BLACK, COLOR_WHITE);
	jifen(num, k, goal, 8, 1);
	gotoxy(0, h * ln + 3);
	cout << "�ϳ���ɣ��س�������0                         " << endl;
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
					cout << "�X�T�[";
					gotoxy(hn * j + 2, ln * i + 2 + 1);
					cout << "�U  �U";
					gotoxy(hn * j + 2, ln * i + 2 + 2);
					cout << "�^�T�a";
					if (flag)
						setcolor(a[i][j] + 8, COLOR_BLACK);
					else
						setcolor(a[i][j], COLOR_BLACK);
					gotoxy(hn* n + 2, ln * m + 2);
					cout << "�X�T�[";
					gotoxy(hn* n + 2, ln* m + 2 + 1);
					if(flag)
						cout << "�U��U";
					else
					    cout << "�U " << a[i][j] << "�U";
					gotoxy(hn* n + 2, ln* m + 2 + 2);
					cout << "�^�T�a";
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
								cout << "�X�T�[";
								gotoxy(hn* n + 2, ln* m + 2 + 1);
								cout << "�U��U";
								gotoxy(hn* n + 2, ln* m + 2 + 2);
								cout << "�^�T�a";
								m = t;
								n = k+1;
								setcolor(COLOR_HWHITE, COLOR_HWHITE);
								gotoxy(hn* n + 2, ln * m + 2);
								cout << "�X�T�[";
								gotoxy(hn* n + 2, ln* m + 2 + 1);
								cout << "�U��U";
								gotoxy(hn* n + 2, ln* m + 2 + 2);
								cout << "�^�T�a";
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
		cout << "���ε÷֣�" << bc << " " << "�ܵ÷֣�" << sum << endl;
	else
		cout << "���ε÷֣�" << bc << " " << "�ܵ÷֣�" << sum << " " << "�ϳ�Ŀ�꣺" << goal << endl;
	cout << endl;
}
