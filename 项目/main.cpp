#define _CRT_SECURE_NO_WARNINGS
#include"Collechea.h"
#include<Windows.h>
#include"Hear.h"
#include"Function.h"
using namespace std;
//主菜单
void Menu(stu No1[], Storage sto[])
{
	FILE *p;
	 p =fopen("菜单.txt", "r");
	char ch;
	ch = getc(p);
	while (ch != EOF) {
		cout << ch;
		ch = getc(p);
	}
	fclose(p);
	cout << endl;
	getCursor(44, 21);
	cout << "请选择：";
	int m;
	cin >> m;
	system("cls");
	switch (m) {
	case 1:
		Create(No1, sto); break;
	case 2:
		Together(No1, sto); break;
	case 3:
		Print(No1, sto); break;
	case 4:
		Backup(No1, sto); break;
	case 5:break;
	default:
		cout << "没有此项选择，系统默认退出";
	}
}


//选项
void Choose(stu No1[], Storage sto[])
{
	int num;
	FILE *p;
	p=fopen("选项.txt", "r");
	char ch;


	ch = getc(p);
	while (ch != EOF) {
		cout << ch;
		ch = getc(p);
	}
	fclose(p);
	cout << endl;
	getCursor(44, 14);
	cout << "请选择：";
	cin >> num;

	system("cls");
	if (num == 1) {
		system("cls");
		Menu(No1, sto);
	}


	else if (num == 2)  exit(0);

	else {

		cout << "没有此选项,系统默认退出程序";
	}
	
}
//得到光标的位置
void getCursor(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

int main()
{
	stu No1[MAX];
	Storage sto[MAX];
	//Sortrank2(No1, sto);
	Menu(No1, sto);

	system("pause");
	return 0;
}