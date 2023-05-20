#include "Student.h"
#include "StudentManage.h"
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	StudentManage manager("students.txt");
	manager.Run();
	return 0;

}