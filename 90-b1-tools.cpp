/*1751151 计1 郭思远*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include "E:/JJ作业/JJ作业/90-b1/common/cmd_console_tools.h"
#include<windows.h>
#include"90-b1.h"
using namespace std;
int sy_count(int a[][10], int h, int l)
{
	int i, j, num = 0;
	for (i = 0; i<h; i++)
		for (j = 0; j < l; j++)
		{
			if (a[i][j] != 0)
				num++;
		}
	return num;
}