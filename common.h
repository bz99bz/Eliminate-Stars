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
void hf_colour(int a[][10], int m, int n, int star, int cd);
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
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd, int hn, int ln);//查找函数
void jifen(int num, int k, int goal, int cd, int flag);//计分
#pragma once
