#pragma once
#include<string>
#include<iostream>
using namespace std;
//��Ҫ���������
typedef struct
{
	string EmpInfo[9];
	float Salary[3];
	int Age[2];
	float cost[4];
}stu;

//��Ա��
class Employ
{
public:
	Employ();
	~Employ();
	void getSal(float, stu);
	float getALL();
protected:
	stu People;
	float ALL = 0;
	//���ʿ���      ...EmpInfo[0]
	//���֤��        ...EmpInfo[1]
	//����            ...EmpInfo[2]
	//�Ա�            ...EmpInfo[3]
	//����            ...EmpInfo[4]
	//����ְ��        ...EmpInfo[5]
	//����ְ�Ʊ��    ...EmpInfo[6]
	//��ͥ�绰����    ...EmpInfo[7]
	//�ֻ�����        ...EmpInfo[8]

	//��������       ...Salary[0]
	//ְ����       ...Salary[1]
	//���ֲ���       ...Salary[2]



	//����           ...Age[0]
	//����           ...Age[1]



	//ˮ��            ...Cost[0]
	//���            ...Cost[1]
	//����          ...Cost[2]
	//��·���ӷ�      ...Cost[3]
};
class Technology :
	public Employ
{
public:
	Technology(stu people, float hour);
};


class SalesManager :
	public Employ
{
public:
	SalesManager(stu people);
};



class Manager :public Employ
{
public:
	Manager(stu people);
};



class Sales :
	public Employ
{
public:
	Sales(stu people, float sum);
private:
	double sum;
};
