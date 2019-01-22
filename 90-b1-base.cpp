/*1751151 计1 郭思远*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include "E:/JJ作业/JJ作业/90-b1/common/cmd_console_tools.h"
#include<windows.h>
#include"90-b1.h"
using namespace std;
void xiaochu(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal)
{
	int i, j, k, num = 0;
	k = a[czh][czl];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (cz[i][j] == '*')
			{
				a[i][j] = 0;
				num++;
			}
		}
	shuchu(a, cz, 0, h, l, 2);
	jifen(num, k, goal, 0, 1);
}