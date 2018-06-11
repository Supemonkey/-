#include"Collechea.h"
//储存数据
typedef struct
{
	string num = "0";//编号
	string name = "0";
	string sex = "0";
	int age = 0;
	string Posi = "0";//职位
	float Sala = 0;
	int rank = 0;
	int log = 0;
}Storage;
//所有函数
void getCursor(int x, int y);
void Backup(stu No1[], Storage sto[]);
void Menu(stu[], Storage[]);
void Choose(stu[], Storage[]);
void Sortrank(stu No1[], Storage Sto[]);
void taxCont(Storage Sto[]);
void Print(stu No1[], Storage sto[]);
void Create(stu No1[], Storage Sto[]);
void Together(stu No1[], Storage Sto[]);
void Sortrank2(stu No1[], Storage Sto[]);
