#ifndef Student_H
#define Student_H
#include<string>
class Student {
private:
	std::string Name;
	std::string ID;
	int Math;
	int English;
public:
	Student(std::string name, std::string id, int math, int english);
	void setName(std::string name);
	void setID(std::string id);
	void setMath(int math);
	void setEnglish(int english);
	std::string getName() const;
	std::string getID() const;
	double getMath() const;
	double getEnglish() const;
	double getSum() const;
	double getAverage() const;

};
#endif