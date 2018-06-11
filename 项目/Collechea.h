#pragma once
#include<string>
#include<iostream>
using namespace std;
//需要输入的数据
typedef struct
{
	string EmpInfo[9];
	float Salary[3];
	int Age[2];
	float cost[4];
}stu;

//雇员类
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
	//工资卡号      ...EmpInfo[0]
	//身份证号        ...EmpInfo[1]
	//姓名            ...EmpInfo[2]
	//性别            ...EmpInfo[3]
	//部门            ...EmpInfo[4]
	//技术职称        ...EmpInfo[5]
	//技术职称编号    ...EmpInfo[6]
	//家庭电话号码    ...EmpInfo[7]
	//手机号码        ...EmpInfo[8]

	//基本工资       ...Salary[0]
	//职务工资       ...Salary[1]
	//各种补助       ...Salary[2]



	//年龄           ...Age[0]
	//工龄           ...Age[1]



	//水费            ...Cost[0]
	//电费            ...Cost[1]
	//清洁费          ...Cost[2]
	//闭路电视费      ...Cost[3]
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
