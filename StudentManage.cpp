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
	cout << "�п�J�n�W�[���ǥͩm�W�B�Ǹ��B�ƾǦ��Z�B�^�妨�Z:";
	string name, id;
	int MathScore, EnglishScore;
	cin >> name >> id >> MathScore >> EnglishScore;
	Student stu(name, id, MathScore, EnglishScore);
	students.push_back(stu);
	cout << "�ǥ� " << name << " �w�K�[�C" << endl;
}


void StudentManage::FindStudent() {
	bool find = false;
	string name;
	cout << "�п�J�n�d�䪺�ǥͩm�W: ";
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
		cout << "�����Ӿǥ�!" << endl;
	}

}

void StudentManage::ModifyStudent() {
	bool find = false;
	string name, id;
	int MathScore, EnglishScore;

	cout << "�п�J�n�ק諸�ǥͩm�W: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			cout << "�п�J�n�ק諸�ǥͩm�W�B�Ǹ��B�ƾǦ��Z�B�^�妨�Z:";
			cin >> name >> id >> MathScore >> EnglishScore;
			students[i].setName(name);
			students[i].setID(id);
			students[i].setMath(MathScore);
			students[i].setEnglish(EnglishScore);
			cout << "�ǥ�: " << students[i].getName() << "�w�ק�C" << endl;
			find = true;
		}
	}
	if (!find) {
		cout << "�t�ΨS���ݭn�ק諸�ǥ�!" << endl;
	}
}

void StudentManage::DeleteStudent() {
	bool find = false;
	string name;

	cout << "�п�J�n�R�����ǥͩm�W: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			students.erase(students.begin() + i);
			cout << "�ǥ� " << name << " �w�R���C" << endl;
			find = true;
		}
	}
	if (!find) {
		cout << "�t�ΨS���ݭn�R�����ǥ�!" << endl;
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
	cout << "|" << setw(8) << "�m�W" << setw(6);
	cout << "|" << setw(11) << "�Ǹ�" << setw(8);
	cout << "|" << setw(7) << "�ƾ�" << setw(4);
	cout << "|" << setw(7) << "�^��" << setw(4);
	cout << "|" << setw(7) << "�ƦW" << setw(4) << "|";
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
		file << "|" << setw(7) << "�m�W" << setw(6);
		file << "|" << setw(9) << "�Ǹ�" << setw(6);
		file << "|" << setw(7) << "�ƾ�" << setw(4);
		file << "|" << setw(7) << "�^��" << setw(4);
		file << "|" << setw(7) << "�ƦW" << setw(4) << "|";
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

		cout << "�w�O�s " << students.size() << " �W�ǥ͸�ơC" << endl;
		file.close();
	}
	else {
		cout << "�L�k�}�Ҥ��I" << endl;
	}
}
void StudentManage::Run() {
	cout << "-------------�w��Ө즨�Z�޲z�t��-----------------" << endl;
	while (true) {
		cout << "�п�ܧA�Q�n���ާ@:" << endl;
		cout << "1.�W�[�ǥ�:" << endl;
		cout << "2.�d�߾ǥ�:" << endl;
		cout << "3.�ק�ǥ�:" << endl;
		cout << "4.�R���ǥ�:" << endl;
		cout << "5.��ܾǥ�:" << endl;
		cout << "6.�h�X�t��:" << endl;
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



