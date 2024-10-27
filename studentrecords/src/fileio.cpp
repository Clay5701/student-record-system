#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "../include/student.h"

const std::string filename = "../studentrecords/data/students.csv";

void get_students(std::vector<Student>& students) {
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
		sline >> age;
		sline.ignore();
		sline >> grade;

		Student student;
		student.set_name(name);
		student.set_age(age);
		student.set_grade(grade);

		students.push_back(student);
	}
	file.close();
}

void save_students(const std::vector<Student>& students) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "File failed to open" << std::endl;
		return;
	}

	for (const Student& student : students) {
		file << student.get_name() << ',' << student.get_age() << ',' << student.get_grade() << '\n';
	}
	file.close();
}