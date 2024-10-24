#pragma once
#include <string>

class Student {
private:
	std::string m_name;
	int m_age = 0;
	char m_grade;

public:
	void set_name(const std::string& name);
	std::string get_name() const;

	void set_age(int age);
	int get_age() const;

	void set_grade(char ch);
	char get_grade() const;
};
