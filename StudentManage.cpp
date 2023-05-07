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
	cout << "�п�J�ǥͩm�W�B�y���B�ƾǦ��Z�B�^�妨�Z:";
	std::string name, id;
	int MathScore, EnglishScore;
	cin >> name >> id >> MathScore >> EnglishScore;
	Student stu(name, id, MathScore, EnglishScore);
	students.push_back(stu);
	cout << "�ǥ� " << name << " �w�K�[�C" << endl;
	//UpdateFile();
}


void StudentManage::FindStudent() {
	bool find = false;
	string name;
	cout << "�п�J�A�n�d�ߪ��ǥͩm�W: ";
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
		cout << "�t�Υ����Ӿǥ�!" << endl;
	}

}

void StudentManage::ModifyStudent() {
	string name;
	int modify = false;
	cout << "�п�J�A�n�ק諸�ǥͦW�r: ";
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
			cout << "�ǥ� " << students[i].getName() << " �w�ק�C" << endl;
			modify = true;

		}
	}
	if (!modify) {
		cout << "�t�ΨS���ݭn�ק諸�ǥ͡C" << endl;
	}
	//UpdateFile();

}

void StudentManage::DeleteStudent() {
	bool Delete = false;
	string name;
	cout << "�п�J�A�n�R���ǥͪ��m�W: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getName() == name) {
			students.erase(students.begin() + i);
			cout << "�ǥ� " << name << " �w�R���C" << endl;
			Delete = true;
			break;
		}
	}
	if (!Delete) {
		cout << "�t�ΨS���ݭn�R�����ǥ͡C" << endl;
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
	cout << "|" << setw(10) << left << "�m�W";
	cout << "|" << setw(18) << left << "�Ǹ�";
	cout << "|" << setw(10) << left << "�ƾ�";
	cout << "|" << setw(10) << left << "�^��";
	cout << "|" << setw(10) << left << "�ƦW" << setw(4) << "|";
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
		students.clear(); // ���M�žǥͦV�q
		string name, id;
		int math, english;
		while (file >> name >> id >> math >> english) {
			Student s(name, id, math, english);
			students.push_back(s);
		}
		cout << "�w���J " << students.size() << " �W�ǥ͸�ơC" << endl;
		file.close();
	}
	else {
		cout << "�L�k�}�Ҥ��I" << endl;
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
			//LoadData();
			SaveData();
			return;
			break;
		default:
			break;
		}
	}
}