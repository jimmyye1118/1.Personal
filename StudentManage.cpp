#include "StudentManage.h"
StudentManage::StudentManage(string fname) {
	filename = fname;
	fstream file(filename, ios::in);
	if (file.is_open()) {
		string line, wh, eline;
		getline(file, line);
		getline(file, wh);
		char s;
		string name, id;
		int math, english, rank;
		int sum;
		while (file >> s >> name >> s >> id >> s >> math >> s >> english >> s >> sum >> s >> rank >> s) {
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
	for (int i = 0; i < 72; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|" << setw(10) << left << " 姓名 ";
	cout << "|" << setw(16) << left << "學號";
	cout << "|" << setw(10) << left << "數學";
	cout << "|" << setw(10) << left << "英文";
	cout << "|" << setw(10) << left << "總分";
	cout << "|" << setw(10) << left << "排名" << setw(4) << "|";
	cout << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << "|" << setw(10) << left << students[i].getName();
		cout << "|" << setw(16) << left << students[i].getID();
		cout << "|" << setw(10) << left << students[i].getMath();
		cout << "|" << setw(10) << left << students[i].getEnglish();
		cout << "|" << setw(10) << left << students[i].getSum();
		cout << "|" << setw(10) << left << i + 1 << "|" << endl;
	}
	for (int i = 0; i < 72; i++) {
		cout << "-";
	}
	cout << endl;
}
void StudentManage::SaveData() {
	fstream file(filename, ios::out);
	if (file.is_open()) {
		for (int i = 0; i < 72; i++) {
			file << "-";
		}
		file << endl;
		file << "|" << setw(11) << left << "姓名";
		file << "|" << setw(16) << left << "學號";
		file << "|" << setw(10) << left << "數學";
		file << "|" << setw(10) << left << "英文";
		file << "|" << setw(10) << left << "總分";
		file << "|" << setw(10) << left << "排名" << setw(4) << "|";
		file << endl;
		for (int i = 0; i < students.size(); i++) {
			file << "|" << setw(10) << left << students[i].getName();
			file << "|" << setw(16) << left << students[i].getID();
			file << "|" << setw(10) << left << students[i].getMath();
			file << "|" << setw(10) << left << students[i].getEnglish();
			file << "|" << setw(10) << left << students[i].getSum();
			file << "|" << setw(10) << left << i + 1 << "|" << endl;
		}
		for (int i = 0; i < 72; i++) {
			file << "-";
		}
		file << endl;

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



