#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../include/student.h"
#include "../include/fileio.h"

const std::string filename = "../studentrecords/data/students.csv";

void sort_students(std::vector<Student>& students) {
	int n = students.size();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (students[j].get_grade() > students[j + 1].get_grade())
				std::swap(students[j], students[j + 1]);
		}
	}
}

void add_students(std::vector<Student>& students) {
	int count;

	std::cout << "Enter number of students to enter: " << std::endl;
	std::cin >> count;

	while (std::cin.fail() || count <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		std::cout << "Please enter a valid number of students: " << std::endl;
		std::cin >> count;
	}

	std::cout << std::endl;

	for (int i = 0; i < count; i++) {
		std::string name;
		int age;
		char grade;

		Student student;

		std::cout << "Enter the name of student " << i + 1 << ':' << std::endl;
		std::getline(std::cin >> std::ws, name);
		std::cout << std::endl;
		student.set_name(name);

		std::cout << "Enter the age of student " << i + 1 << ':' << std::endl;
		std::cin >> age;
		std::cout << std::endl;
		student.set_age(age);

		std::cout << "Enter the grade of student " << i + 1 << ':' << std::endl;
		std::cin >> grade;

		while (grade < 'A' || grade > 'F' || grade == 'E') {
			std::cout << "Please Enter a valid grade: " << std::endl;
			std::cin >> grade;
			std::cout << std::endl;
		}

		std::cout << std::endl;
		student.set_grade(grade);

		students.push_back(student);
	}

	std::cout << "Student(s) were successfully added." << std::endl;
}

void rmv_student(std::vector<Student>& students) {
	std::string name;
	std::cout << "Enter the name of the student to remove: " << std::endl;
	std::getline(std::cin >> std::ws, name);

	auto student = students.begin();
	while (student != students.end()) {
		if (student->get_name() == name) {
			student = students.erase(student);
		}
		else {
			student++;
		}
	}
}

void list_students(std::vector<Student>& students) {
	std::string name;
	std::cout << "Enter the name of the student (Enter '*' for all students): " << std::endl;
	std::getline(std::cin >> std::ws, name);
	std::cout << std::endl;

	char sort_flag;
	std::cout << "Would you like to sort the students by grade? (y or n): " << std::endl;
	std::cin >> sort_flag;
	std::cout << std::endl;

	if (sort_flag == 'y' || sort_flag == 'Y') {
		sort_students(students);
	}


	for (Student& student : students) {
		if (name == "*" || student.get_name() == name) {
			std::cout << "Student: " << student.get_name()
				<< ", Age: " << student.get_age()
				<< ", Grade: " << student.get_grade() << std::endl;
		}
		else continue;
	}
}