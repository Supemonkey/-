#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <cstdlib>
#include<fstream>
#define MAX 5

//������Ϣ
void Create(stu No1[], Storage Sto[])
{
	Employ Emp;
	for (int i = 0; i < MAX; i++) {
		cout << "��" << i + 1 << "������Ϣ��" << endl;
		cout << "���������� ��> ���ʿ��� - ���֤�� - ���� - �Ա� - ���� - ����ְ�� - ����ְ�Ʊ�� - ��ͥ�绰���� - �ֻ�����" << endl;
		for (int j = 0; j < 9; j++)
			cin >> No1[i].EmpInfo[j];
		cout << "���������� ��> �������� - ְ���� - ���ֲ���" << endl;
		for (int j = 0; j < 3; j++)
			cin >> No1[i].Salary[j];
		cout << "���������룺����,���䣺" << endl;
		for (int j = 0; j < 2; j++)
			cin >> No1[i].Age[j];
		cout << "���������� ��> ˮ�� - ��� - ���� - ��·���ӷѣ�" << endl;
		for (int j = 0; j < 4; j++)
			cin >> No1[i].cost[j];
	}
	for (int i = 0; i < MAX; i++) {
		if (No1[i].EmpInfo[5] == "����") {
			Manager Mana(No1[i]);
			Sto[i].Sala = Mana.getALL();
		}
		else if (No1[i].EmpInfo[5] == "����Ա") {
			float hour = 0;
			cout << "����������������Ա��������ʱ�䣺";
			cin >> hour;
			Technology Tec(No1[i], hour);
			Sto[i].Sala = Tec.getALL();
		}
		else if (No1[i].EmpInfo[5] == "����Ա") {
			float sum = 0;
			cout << "��������������Ա�����۶";
			cin >> sum;
			Sales Sal(No1[i], sum);
			Sto[i].Sala = Sal.getALL();
		}
		else if (No1[i].EmpInfo[5] == "���۾���") {
			SalesManager SalMan(No1[i]);
			Sto[i].Sala = SalMan.getALL();
		}
		else {
			cout << "û�д����ˣ�ϵͳĬ�ϴ�������";
			system("pause");
			system("cls");
			Create(No1, Sto);
		}
		Sto[i].name = No1[i].EmpInfo[2];
		Sto[i].num = No1[i].EmpInfo[6];
		Sto[i].Posi = No1[i].EmpInfo[5];
		Sto[i].sex = No1[i].EmpInfo[3];
		Sto[i].age = No1[i].Age[0];
		Sto[i].rank = i + 1;
		Sto[i].log = 1;
	}
	taxCont(Sto);
	cout << "¼��ɹ�" << endl;
	system("pause");
	system("cls");
	Choose(No1, Sto);
}



//���۾����ʼ���
void SMcount(stu No1[], Storage Sto[])
{
	float All = 0;
	for (int i = 0; i <MAX; i++) {
		if (Sto[i].Posi == "����Ա")
			All += Sto[i].Sala;
	}
	for (int i = 0; i < MAX; i++) {
		if (Sto[i].Posi == "���۾���")
			Sto[i].Sala += All;
	}
	taxCont(Sto);
}
 
//˰�ļ���
void taxCont(Storage Sto[])
{
	for (int i = 0; i < MAX; i++) {
		if (Sto[i].Sala > 800 || Sto[i].Sala < 1400)
			Sto[i].Sala -= (Sto[i].Sala - 800)*0.05;
		if (Sto[i].Sala > 1400)
			Sto[i].Sala -= (Sto[i].Sala - 1400)*0.1;
		Sto[i].log = 1;
	}
}


void Together(stu No1[], Storage Sto[])
{
	
	SMcount(No1, Sto);

	taxCont(Sto);

	Sortrank2(No1, Sto);//�ļ�������

	Sortrank(No1, Sto);//�ļ�������

	
}
//ð������
//�ļ�������  ������  ���޸�

void Sortrank2(stu No1[], Storage Sto[])
{
	Storage temp[80];
	Storage mid;
	ifstream infile("test.txt",ios::in);
	infile.read((char *)&temp[0], sizeof(temp));
	infile.close();
	int s = 0;
	for (int i = 0; temp[i].log!=0; i++) {
		s++;
		for (int j = 0; j < temp[i].log != 0; j++) {
			if (temp[j].Sala > temp[j].Sala) {
				mid = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = mid;
			}
		}
	}
	ofstream outfile("test.txt", ios::out);
	for (int i = 0; i= s; i++) {
		temp[i].rank = i + 1;
		outfile.write((char *)&temp[i], sizeof(temp[i]));
	}
	outfile.close();
}
//�ļ�������

void Sortrank(stu No1[], Storage Sto[])
{
	Storage temp;
	int num=0;
	for (int i = MAX - 1; i >= 0; i--) {
		for (int j = 0; j > i; j++) {
			if (Sto[j].Sala < Sto[j + 1].Sala) {
				temp = Sto[j];
				Sto[j] = Sto[j + 1];
				Sto[j + 1] = temp;
			}	
		}
	}
	for (int i = 0; i < MAX; i++) {
		Sto[i].rank = i+1;
	}

	cout << "������ɡ���������" << endl;
	system("pause");
	system("cls");
	Choose(No1, Sto);
}
//�������ļ�
void Backup(stu No1[], Storage sto[])
{
	FILE *p;
	fopen_s(&p, "test.txt", "ab+");
	try {
		if (p==NULL || sto[0].log == 0) throw 0;
		for (int i = 0; i < MAX; i++) {
			sto[i].log = 2;
			fwrite(&sto[i], sizeof(Storage), 1, p);
		}
		cout << "���ݳɹ�" << endl;
		system("pause");
	}
	catch (int) {
		cout << "�����ļ�ʧ�� ���� ����Ϊ�ա�";
		system("pause");
	}
	fclose(p);
	system("cls");
	Choose(No1, sto);
}
//��ӡ����Ļ
void Print(stu No1[], Storage sto[])
{
	Storage F;
	FILE *p;
	int m = 0;//Ϊͳ���ļ��е�����
	fopen_s(&p, "test.txt", "rb");
	system("cls");
	if (sto[0].log == 1 ||p!=NULL)
		cout << "ְ����\t\t����\t\t�Ա�\t\t����\t\t��λ\t\t����\t\t����" << endl;
	else cout << "������..." << endl;
	if (p==NULL)  cout << "���ļ�ʧ��" << endl;
	else {
		while (!feof(p)) {
			int i=fread(&F, sizeof(Storage), 1, p);
			if (i > 0) {
				cout << F.num << "\t\t"<<F.sex<<"\t\t" << F.name << "\t\t" << F.age<< "\t\t"
					<< F.Posi << "\t\t" << F.Sala << "\t\t" << F.rank <<" "<< endl;
				m++;
			}	
		}
		fclose(p);
	}


	if (sto[0].log == 1) {
		for (int i = 0; i < MAX; i++) {
			cout << sto[i].num << "\t\t"<<sto[i].sex<<"\t\t" << sto[i].name << "\t\t" << sto[i].age
				<< "\t\t" << sto[i].Posi << "\t\t" << sto[i].Sala << "\t\t" << sto[i].rank+m << endl;
		}
	}
	system("pause");
	system("cls");
	Choose(No1, sto);
}


