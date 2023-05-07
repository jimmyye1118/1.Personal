#include "Student.h"
using namespace std;
Student::Student(std::string name, std::string id, int math, int english)
	:Name(name), ID(id), Math(math), English(english) {}

void Student::setName(std::string name) {
	Name = name;
}

void Student::setID(std::string id) {
	ID = id;
}

void Student::setMath(int math) {
	Math = math;
}

void Student::setEnglish(int english) {
	English = english;
}

std::string Student::getName() const {
	return Name;
}

std::string Student::getID() const {
	return ID;
}

double Student::getMath() const {
	return Math;
}

double Student::getEnglish() const {
	return English;
}

double Student::getSum() const {
	return (Math + English);
}

double Student::getAverage() const {
	return (Math + English) / 2.0;
}


