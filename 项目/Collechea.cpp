#include"Collechea.h"
using namespace std;

Employ::Employ()
{
}

Employ::~Employ()
{

}

void Employ::getSal(float P, stu S)
{
	float sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += S.Salary[i];
	}
	for (int i = 0; i < 4; i++) {
		sum = sum - S.cost[i];
	}
	this->ALL = P + sum;

}

float Employ::getALL()
{
	return ALL;
}


//������Ա
Technology::Technology(stu people, float hour)
{
	this->People = people;
	this->ALL = 100 * hour;
	getSal(ALL, people);
	Employ::~Employ();
}


//���۾���
SalesManager::SalesManager(stu people)
{
	this->ALL = 0;
	this->People = people;
	getSal(ALL, people);
	Employ::~Employ();
}


//����
Manager::Manager(stu people)
{
	this->People = people;
	this->ALL = 8000;
	getSal(ALL, people);
	Employ::~Employ();
}


//����
Sales::Sales(stu people, float sum)
{
	this->ALL = sum * 0.04;
	this->People = people;
	getSal(ALL, people);
	Employ::~Employ();
}

