#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "../include/student.h"

void save_students(const std::string& filename, const std::vector<Student>& students) {
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "File failed to open" << std::endl;
		return;
	}

	for (const Student& student : students) {
		file << student.get_name() << ',' << student.get_age() << ',' << student.get_grade() << '\n';
	}
	file.close();
}

void load_students(const std::string& filename, std::vector<Student>& students, const std::string& iname) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "File failed to open" << std::endl;
		return;
	}

	std::string line;

	while (std::getline(file, line)) {
		std::stringstream sline(line);

		std::string name;
		int age;
		char grade;

		std::getline(sline, name, ',');
		if (iname == "*" || iname == name) {
			sline >> age;
			sline.ignore();
			sline >> grade;
		}
		else
			continue;

		Student student;

		student.set_name(name);
		student.set_age(age);
		student.set_grade(grade);

		students.push_back(student);
	}
	file.close();
}

void remove(const std::string& filename, const std::string& iname) {
	std::vector<std::string> students;

	std::ifstream file_in(filename);
	if (!file_in.is_open()) {
		std::cerr << "File failed to open" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file_in, line)) {
		std::stringstream sline(line);

		std::string name;

		std::getline(sline, name, ',');
		if (name != iname) {
			students.push_back(line);
		}
	}
	file_in.close();

	std::ofstream file_out(filename);
	if (!file_out.is_open()) {
		std::cerr << "File failed to open" << std::endl;
		return;
	}

	for (const std::string& student : students) {
		file_out << student << '\n';
	}
	file_out.close();
}
