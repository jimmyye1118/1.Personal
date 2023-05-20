#ifndef StudentManage_H
#define StudentManage_H
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<iostream>
using namespace std;
#include "Student.h"
class StudentManage {
private:
	vector <Student> students;
	string filename;
public:
	StudentManage(string fname);
	void AddStudent();
	void FindStudent();
	void ModifyStudent();
	void DeleteStudent();
	void SortStudent();
	void DisplayAllStudent();
	void SaveData();
	void Run();

};
#endif
