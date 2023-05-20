#include "StudentManage.h"
StudentManage::StudentManage(string fname) {
	filename = fname;
	fstream file(filename, ios::in);
	if (file.is_open()) {
		string line, wh, eline;
		getline(file, line);
		getline(file, wh);
		string name, id;
		int math, english, rank;
		while (file >> name >> id >> math >> english >> rank) {
			Student s(name, id, math, english);
			students.push_back(s);
		}
		getline(file, eline);
		file.close();
	}
}
void StudentManage::AddStudent() {
	cout << "請輸入要增加的學生姓名、學號、數學成績、英文成績:";
	string name, id;
	int MathScore, EnglishScore;
	cin >> name >> id >> MathScore >> EnglishScore;
	Student stu(name, id, MathScore, EnglishScore);
	students.push_back(stu);
	cout << "學生 " << name << " 已添加。" << endl;
}


void StudentManage::FindStudent() {
	bool find = false;
	string name;
	cout << "請輸入要查找的學生姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			cout << students[i].getName() << " ";
			cout << students[i].getID() << " ";
			cout << students[i].getEnglish() << " ";
			cout << students[i].getMath() << endl;
			find = true;
			break;
		}
	}
	if (!find) {
		cout << "未找到該學生!" << endl;
	}

}

void StudentManage::ModifyStudent() {
	bool find = false;
	string name, id;
	int MathScore, EnglishScore;

	cout << "請輸入要修改的學生姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			cout << "請輸入要修改的學生姓名、學號、數學成績、英文成績:";
			cin >> name >> id >> MathScore >> EnglishScore;
			students[i].setName(name);
			students[i].setID(id);
			students[i].setMath(MathScore);
			students[i].setEnglish(EnglishScore);
			cout << "學生: " << students[i].getName() << "已修改。" << endl;
			find = true;
		}
	}
	if (!find) {
		cout << "系統沒有需要修改的學生!" << endl;
	}
}

void StudentManage::DeleteStudent() {
	bool find = false;
	string name;

	cout << "請輸入要刪除的學生姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			students.erase(students.begin() + i);
			cout << "學生 " << name << " 已刪除。" << endl;
			find = true;
		}
	}
	if (!find) {
		cout << "系統沒有需要刪除的學生!" << endl;
	}
}
void StudentManage::SortStudent() {
	sort(students.begin(), students.end(), [](Student a, Student b) {return a.getSum() > b.getSum(); });
}
void StudentManage::DisplayAllStudent() {
	for (int i = 0; i < 66; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|" << setw(8) << "姓名" << setw(6);
	cout << "|" << setw(11) << "學號" << setw(8);
	cout << "|" << setw(7) << "數學" << setw(4);
	cout << "|" << setw(7) << "英文" << setw(4);
	cout << "|" << setw(7) << "排名" << setw(4) << "|";
	cout << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << "|" << left << setw(13) << students[i].getName();
		cout << "|" << left << setw(18) << students[i].getID();
		cout << "|" << left << setw(10) << students[i].getEnglish();
		cout << "|" << left << setw(10) << students[i].getMath();
		cout << "|" << left << setw(10) << i + 1 << "|" << endl;
	}
	for (int i = 0; i < 66; i++) {
		cout << "-";
	}
	cout << endl;
}
void StudentManage::SaveData() {
	fstream file(filename, ios::out);
	if (file.is_open()) {
		for (int i = 0; i < 60; i++) {
			file << "-";
		}
		file << endl;
		file << "|" << setw(7) << "姓名" << setw(6);
		file << "|" << setw(9) << "學號" << setw(6);
		file << "|" << setw(7) << "數學" << setw(4);
		file << "|" << setw(7) << "英文" << setw(4);
		file << "|" << setw(7) << "排名" << setw(4) << "|";
		file << endl;
		for (int i = 0; i < students.size(); i++) {
			file << left << setw(14) << students[i].getName();
			file << left << setw(14) << students[i].getID() << " ";
			file << left << setw(10) << students[i].getMath() << " ";
			file << left << setw(10) << students[i].getEnglish() << " ";
			file << left << setw(10) << i + 1 << endl;
		}
		for (int i = 0; i < 60; i++) {
			file << "-";
		}

		cout << "已保存 " << students.size() << " 名學生資料。" << endl;
		file.close();
	}
	else {
		cout << "無法開啟文件！" << endl;
	}
}
void StudentManage::Run() {
	cout << "-------------歡迎來到成績管理系統-----------------" << endl;
	while (true) {
		cout << "請選擇你想要的操作:" << endl;
		cout << "1.增加學生:" << endl;
		cout << "2.查詢學生:" << endl;
		cout << "3.修改學生:" << endl;
		cout << "4.刪除學生:" << endl;
		cout << "5.顯示學生:" << endl;
		cout << "6.退出系統:" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			AddStudent();
			break;
		case 2:
			FindStudent();
			break;
		case 3:
			ModifyStudent();
			break;
		case 4:
			DeleteStudent();
			break;
		case 5:
			SortStudent();
			DisplayAllStudent();
			break;
		case 6:
			SaveData();
			return;
			break;
		default:
			break;
		}
	}
}



