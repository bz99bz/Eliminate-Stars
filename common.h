void CSH(int(*a)[10], int h, int l, int flag);//��ʼ������
void gotoxy(const int X, const int Y);
void setcolor(const int bg_color, const int fg_color);
void hebing(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal);//�ϲ�
void down(int a[][10], char cz[][10], int h, int l, int flag);//����
int Max(int a[][10], int h, int l);//Ѱ�����ֵ
void New(int a[][10], int bz[][10], int h, int l, int cd);//�����ֵ
int judge(int a[][10], int h, int l, int goal);//�ж�Ŀ���Ƿ񵽴�
void kuang(int a[][10], int h, int l, int cd);//��
void nbsz(int a[][10], int h, int l, int cd, int flag);//�ڲ�����
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd);//�ƶ�
void getxy(int &x, int &y);//ȡ����ֵ
void getcolor(int &bg_color, int &fg_color);//ȡɫ
void hf_colour(int a[][10], int m, int n, int star, int cd);
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int flag, int hn, int ln);
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal, int flag, int hn, int ln);//ͼ�κϲ�
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl, int flag, int hn, int ln);//������
void tc(int a[][10], int bz[][10], int h, int l);//ͼ�����
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int star, int hn, int ln, int cd);//��������
int CD(int flag);//�˵�
void get_end(char *pe, char *pn, char *pd);//��end;
char get_char(char *prompt, char min_value, char max_value);
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l, int flag);
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag, int star, int cd);
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd, int hn, int ln);//���Һ���
void jifen(int num, int k, int goal, int cd, int flag);//�Ʒ�
#pragma once
