#define _CRT_SECURE_NO_WARNINGS
#include"Collechea.h"
#include<Windows.h>
#include"Hear.h"
#include"Function.h"
using namespace std;
//���˵�
void Menu(stu No1[], Storage sto[])
{
	FILE *p;
	 p =fopen("�˵�.txt", "r");
	char ch;
	ch = getc(p);
	while (ch != EOF) {
		cout << ch;
		ch = getc(p);
	}
	fclose(p);
	cout << endl;
	getCursor(44, 21);
	cout << "��ѡ��";
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
		cout << "û�д���ѡ��ϵͳĬ���˳�";
	}
}


//ѡ��
void Choose(stu No1[], Storage sto[])
{
	int num;
	FILE *p;
	p=fopen("ѡ��.txt", "r");
	char ch;


	ch = getc(p);
	while (ch != EOF) {
		cout << ch;
		ch = getc(p);
	}
	fclose(p);
	cout << endl;
	getCursor(44, 14);
	cout << "��ѡ��";
	cin >> num;

	system("cls");
	if (num == 1) {
		system("cls");
		Menu(No1, sto);
	}


	else if (num == 2)  exit(0);

	else {

		cout << "û�д�ѡ��,ϵͳĬ���˳�����";
	}
	
}
//�õ�����λ��
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