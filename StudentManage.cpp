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
	for (int i = 0; i < 72; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|" << setw(10) << left << " �m�W ";
	cout << "|" << setw(16) << left << "�Ǹ�";
	cout << "|" << setw(10) << left << "�ƾ�";
	cout << "|" << setw(10) << left << "�^��";
	cout << "|" << setw(10) << left << "�`��";
	cout << "|" << setw(10) << left << "�ƦW" << setw(4) << "|";
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
		file << "|" << setw(11) << left << "�m�W";
		file << "|" << setw(16) << left << "�Ǹ�";
		file << "|" << setw(10) << left << "�ƾ�";
		file << "|" << setw(10) << left << "�^��";
		file << "|" << setw(10) << left << "�`��";
		file << "|" << setw(10) << left << "�ƦW" << setw(4) << "|";
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



