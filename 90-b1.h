int CD(int flag);//菜单
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l, int flag);
char get_char(char *prompt, char min_value, char max_value);
void CSH(int(*a)[10], int h, int l, int flag);
void shuchu(int(*a)[10], char(*cz)[10], int bz[][10], int h, int l, int k);//0:当前数组，1：查找数组，2：颜色，3：零，4：填充
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd, int hn, int ln);//查找函数
void get_end(char *pe, char *pn, char *pd);
void gotoxy(const int X, const int Y);
void jifen(int num, int k, int goal, int cd, int flag);
void xiaochu(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal);
void down(int a[][10], char cz[][10], int h, int l, int flag);
int sy_count(int a[][10], int h, int l);//记录剩余的个数
void kuang(int a[][10], int h, int l, int cd);
int fail(int a[][10], int bz[][10], int h, int l, int flag);
void nbsz(int a[][10], int h, int l, int cd, int flag);//内部数组
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd);//移动
void tc(int a[][10], int bz[][10], int h, int l);//图形填充
#pragma once
