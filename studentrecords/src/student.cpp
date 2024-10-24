#include <string>
#include "../include/student.h"

void Student::set_name(const std::string& name) {
	m_name = name;
}
std::string Student::get_name() const {
	return m_name;
}

void Student::set_age(int age) {
	m_age = age;
}
int Student::get_age() const {
	return m_age;
}

void Student::set_grade(char ch) {
	m_grade = ch;
}
char Student::get_grade() const {
	return m_grade;
}
