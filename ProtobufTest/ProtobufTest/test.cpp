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
	//1、创建Person对象，并初始化
	Person p;
	p.set_id(1001);
	//申请一块内存，来存储名字
	p.add_name();
	p.set_name(0,"路飞");
	
	p.add_name();
	p.set_name(1, "路飞1");
	
	p.add_name();
	p.set_name(2, "路飞2");
	
	p.set_sex("man");
	p.set_age(17);
	//2、将Person对象序列化 -》 字符串
	string output;
	p.SerializeToString(&output);//序列化成字符串
	cout << "序列化后的数据：" << output << endl;


	//3、数据传输
	
	//4、接收数据并且解析(output) -》解码-》原始数据
	//4.1、创建Person对象
	Person pp;
	pp.ParseFromString(output);//解析数据来自于字符串
	
	//5、处理原始数据-》打印数据信息
	cout << "id:" << pp.id() << ", name:" 
		<< pp.name(0) <<"."
		<< pp.name(1) << "."
		<< pp.name(2) << "."
		<< ", sex:" << pp.sex() << ", age:" << pp.age() << endl;

	return 0;
}