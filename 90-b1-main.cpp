/*1751151 ��1 ��˼Զ*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include "E:/JJ��ҵ/JJ��ҵ/90-b1/common/cmd_console_tools.h"
#include<windows.h>
#include"90-b1.h"
using namespace std;
int main()
{
	int cd;
	int flag = 1;
	cd = CD(flag);
	int h, l, czh, czl, i, j, goal = 0, sb;
	int sz[8][10] = { 0 }, bz[8][10] = { 0 };
	char cz[8][10] = { 0 }, xx;
	char pe, pn, pd;
	unsigned int k;
	k = (unsigned int)(time(0));
	srand(k);
	int num = 0;
	while (cd != 'Q')
	{
		system("cls");
		h = get_int("����������", 8, 10, 0, 0, 0, 0, 0, 1);
		l = get_int("����������", 8, 10, 0, 0, 0, 0, 0, 1);
		CSH(sz, h, l, flag);
		if (cd == 'A' || cd == 'B' || cd == 'C')
		{
			while (1)
			{
				sb = fail(sz, bz, h, l, 1);
				if (sb)
				{
					num = sy_count(sz, h, l);
					setcolor(COLOR_HYELLOW, COLOR_HRED);
					cout << "ʣ��" << num << "��������������ؽ�����" << endl;
					setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "��С�������������End����...";
					get_end(&pe, &pn, &pd);
					system("cls");
					cd = CD(flag);
					break;
				}
				shuchu(sz, 0, 0, h, l, 0);
				get_int("������ĸ+������ʽ[����c2]����������꣺", 'a', '9', &czh, &czl, 100, h, l, 1);
				cout << "����Ϊ" << (char)(czh + 'A') << "��" << czl << "��" << endl;
				i = CZ(sz, bz, cz, h, l, czh, czl, cd, 0, 0);
				while (i == 0)
				{
					get_int("������ĸ+������ʽ[����c2]����������꣺", 'a', '9', &czh, &czl, 100, h, l, 1);
					cout << "����Ϊ" << (char)(czh + 'A') << "��" << czl << "��" << endl;
					i = CZ(sz, bz, cz, h, l, czh, czl, cd, 0, 0);
				}
				cout << endl;
				shuchu(sz, cz, bz, h, l, 1);
				cout << endl;
				shuchu(sz, cz, bz, h, l, 2);
				if (cd == 'A')
					break;
				if (cd == 'B' || cd == 'C')
				{

					cout << "��ȷ���Ƿ��D7����Χ����ֵͬ����(Y/N/Q)��";
					xx = get_int(0, 'N', 'Y', 0, 0, 100, h, l, 1);
					if (xx == 'y' || xx == 'Y')
					{
						xiaochu(sz, cz, h, l, czh, czl, goal);
						cout << "���س������������������..." << endl;
						int gsy;
						gsy = _getch();
						down(sz, cz, h, l, 1);
						if (cd == 'B')
							break;
						if (cd == 'C')
						{
							cout << "�����������������س���������һ�ε�����..." << endl;
							gsy = _getch();
						}
					}
					if ((xx == 'n' || xx == 'N') && cd == 'B')
						break;
					if ((xx == 'n' || xx == 'N') && cd == 'C')
					{
						for (i = 0; i < h; i++)
							for (j = 0; j < l; j++)
							{
								cz[i][j] = 0;
								bz[i][j] = 0;
							}
						continue;
					}
					if (xx == 'q' || xx == 'Q')
						break;
				}
				for (i = 0; i < h; i++)
					for (j = 0; j < l; j++)
					{
						cz[i][j] = 0;
						bz[i][j] = 0;
					}
			}

		}
		if (cd == 'D')
		{
			kuang(sz, h, l, cd);
			nbsz(sz, h, l, 5, flag);
			move(sz, cz, bz, h, l, goal, cd);
			gotoxy(0, h * 3 + 4);
			cout << "��С�������������End����...";
			get_end(&pe, &pn, &pd);
			system("cls");
			cd = CD(flag);
			continue;
		}
		if (cd == 'E')
		{
			kuang(sz, h, l, cd);
			nbsz(sz, h, l, 6, flag);
			move(sz, cz, bz, h, l, goal, cd);
			cout << endl;
			cout << endl;
			cout << "��С�������������End����...";
			get_end(&pe, &pn, &pd);
			system("cls");
			cd = CD(flag);
			continue;
		}
		if (cd == 'F')
		{
			kuang(sz, h, l, cd);
			nbsz(sz, h, l, 5, flag);
			move(sz, cz, bz, h, l, goal, cd);
			cout << endl;
			cout << endl;
			gotoxy(0, h * 3 + 4);
			cout << "��С�������������End����...";
			get_end(&pe, &pn, &pd);
			system("cls");
			cd = CD(flag);
			continue;
		}
		if (cd == 'G')
		{
			int G_kg = 1;
			while (1)
			{
				if (G_kg)
				{
					CSH(sz, h, l, flag);
					kuang(sz, h, l, cd);
					nbsz(sz, h, l, 5, flag);
				}
				sb = fail(sz, bz, h, l, 1);

				if (sb)
				{
					num = sy_count(sz, h, l);
					setcolor(COLOR_HYELLOW, COLOR_HRED);
					gotoxy(0, h * 3 + 3);
					cout << "ʣ��" << num << "��������������ؽ�����";
					setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "���س���������һ��";
					int gsy;
					gsy = _getch();
					system("cls");
					G_kg = 1;
					continue;
				}
				else
					G_kg = 0;
				move(sz, cz, bz, h, l, goal, cd);
				for (i = 0; i < h; i++)
					for (j = 0; j < l; j++)
					{
						cz[i][j] = 0;
						bz[i][j] = 0;
					}

			}
			cout << endl;
			cout << endl;
			gotoxy(0, h * 3 + 4);
			cout << "��С�������������End����...";
			get_end(&pe, &pn, &pd);
			system("cls");
			cd = CD(flag);
		}
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				cz[i][j] = 0;
				bz[i][j] = 0;
			}

		if (cd == 'A' || cd == 'B' || (cd == 'C' && (xx == 'q' || xx == 'Q')))
		{
			setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << "��С�������������End����...";
			get_end(&pe, &pn, &pd);
			system("cls");
			cd = CD(flag);
			continue;
		}
	}
}
