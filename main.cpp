#include "Student.h"
#include "StudentManage.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<windows.h>
using namespace std;


int main() {
	//�խI���¦r
	//system("color F0");
	StudentManage manager("students.txt");
	manager.Run();
	return 0;


}