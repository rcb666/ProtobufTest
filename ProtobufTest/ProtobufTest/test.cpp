#include <stdio.h>
#include <iostream>
#include "Person.pb.h"
using namespace std;

/*
message Person{
	int32 id = 1;
	string name = 2;
	string sex = 3;
	int32 age = 4;
}
*/
int main() {
	//1������Person���󣬲���ʼ��
	Person p;
	p.set_id(1001);
	//����һ���ڴ棬���洢����
	p.add_name();
	p.set_name(0,"·��");
	
	p.add_name();
	p.set_name(1, "·��1");
	
	p.add_name();
	p.set_name(2, "·��2");
	
	p.set_sex("man");
	p.set_age(17);
	//2����Person�������л� -�� �ַ���
	string output;
	p.SerializeToString(&output);//���л����ַ���
	cout << "���л�������ݣ�" << output << endl;


	//3�����ݴ���
	
	//4���������ݲ��ҽ���(output) -������-��ԭʼ����
	//4.1������Person����
	Person pp;
	pp.ParseFromString(output);//���������������ַ���
	
	//5������ԭʼ����-����ӡ������Ϣ
	cout << "id:" << pp.id() << ", name:" 
		<< pp.name(0) <<"."
		<< pp.name(1) << "."
		<< pp.name(2) << "."
		<< ", sex:" << pp.sex() << ", age:" << pp.age() << endl;

	return 0;
}