#include "Student.h"
#include "StudentManage.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<windows.h>
using namespace std;


int main() {
	//¥Õ­I´º¶Â¦r
	//system("color F0");
	StudentManage manager("students.txt");
	manager.Run();
	return 0;


}