#ifndef StudentManage_H
#define StudentManage_H
#include<iostream>
#include <fstream>
using namespace std;
#include<vector>
#include<algorithm>
#include<iomanip>
#include <fstream>
#include "Student.h"
class StudentManage {
private:
	vector <Student> students;
	string filename;
	//void UpdateFile();
public:
	StudentManage(string fname);
	void AddStudent();
	void FindStudent();
	void ModifyStudent();
	void DeleteStudent();
	void SortStudent();
	void LoadData();
	void SaveData();
	void DisplayAllStudent();
	void Run();

};
#endif
