#include "StudentManage.h"

StudentManage::StudentManage(string fname) {
	filename = fname;
	ifstream fin(filename);
	if (fin.is_open()) {
		string name, id;
		int math, english;
		while (fin >> name >> id >> math >> english) {
			Student s(name, id, math, english);
			students.push_back(s);
		}
		fin.close();
	}
}

//void StudentManage::UpdateFile() {
//	ofstream fout(filename);
//	if (fout.is_open()) {
//		for (int i = 0; i < students.size(); i++) {
//			fout << students[i].getName() << " "
//				<< students[i].getID() << " "
//				<< students[i].getMath() << " "
//				<< students[i].getEnglish() << endl;
//		}
//		fout.close();
//	}
//}

void StudentManage::AddStudent() {
	cout << "請輸入學生姓名、座號、數學成績、英文成績:";
	std::string name, id;
	int MathScore, EnglishScore;
	cin >> name >> id >> MathScore >> EnglishScore;
	Student stu(name, id, MathScore, EnglishScore);
	students.push_back(stu);
	cout << "學生 " << name << " 已添加。" << endl;
	//UpdateFile();
}


void StudentManage::FindStudent() {
	bool find = false;
	string name;
	cout << "請輸入你要查詢的學生姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			cout << students[i].getName() << " ";
			cout << students[i].getID() << " ";
			cout << students[i].getMath() << " ";
			cout << students[i].getEnglish() << endl;
			find = true;
			break;
		}
	}
	if (!find) {
		cout << "系統未找到該學生!" << endl;
	}

}

void StudentManage::ModifyStudent() {
	string name;
	int modify = false;
	cout << "請輸入你要修改的學生名字: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			string Moname, id;
			int MathScore, EnglishScore;
			cin >> Moname >> id >> MathScore >> EnglishScore;
			students[i].setName(Moname);
			students[i].setID(id);
			students[i].setMath(MathScore);
			students[i].setEnglish(EnglishScore);
			cout << "學生 " << students[i].getName() << " 已修改。" << endl;
			modify = true;

		}
	}
	if (!modify) {
		cout << "系統沒有需要修改的學生。" << endl;
	}
	//UpdateFile();

}

void StudentManage::DeleteStudent() {
	bool Delete = false;
	string name;
	cout << "請輸入你要刪除學生的姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			students.erase(students.begin() + i);
			cout << "學生 " << name << " 已刪除。" << endl;
			Delete = true;
			break;
		}
	}
	if (!Delete) {
		cout << "系統沒有需要刪除的學生。" << endl;
	}
	//UpdateFile();
}

void StudentManage::SortStudent() {
	for (int i = 0; i < students.size(); i++) {
		sort(students.begin(), students.end(), [](Student a, Student b) {return a.getSum() > b.getSum(); });
	}
	//UpdateFile();
}

void StudentManage::DisplayAllStudent() {
	for (int i = 0; i < 64; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|" << setw(10) << left << "姓名";
	cout << "|" << setw(18) << left << "學號";
	cout << "|" << setw(10) << left << "數學";
	cout << "|" << setw(10) << left << "英文";
	cout << "|" << setw(10) << left << "排名" << setw(4) << "|";
	cout << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << "|" << setw(10) << left << students[i].getName();
		cout << "|" << setw(18) << left << students[i].getID();
		cout << "|" << setw(10) << left << students[i].getMath();
		cout << "|" << setw(10) << left << students[i].getEnglish();
		cout << "|" << setw(10) << left << i + 1 << "|" << endl;
	}
	for (int i = 0; i < 64; i++) {
		cout << "-";
	}
	cout << endl;
}

void StudentManage::LoadData() {
	ifstream file(filename);
	if (file.is_open()) {
		students.clear(); // 先清空學生向量
		string name, id;
		int math, english;
		while (file >> name >> id >> math >> english) {
			Student s(name, id, math, english);
			students.push_back(s);
		}
		cout << "已載入 " << students.size() << " 名學生資料。" << endl;
		file.close();
	}
	else {
		cout << "無法開啟文件！" << endl;
	}
}

void StudentManage::SaveData() {
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < students.size(); i++) {
			file << students[i].getName() << " ";
			file << students[i].getID() << " ";
			file << students[i].getMath() << " ";
			file << students[i].getEnglish() << endl;
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
			//LoadData();
			SaveData();
			return;
			break;
		default:
			break;
		}
	}
}