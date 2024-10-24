#include <iostream>
#include <string>
#include <vector>
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

void add_students() {
	int count;

	std::cout << "Enter number of students to enter: " << std::endl;
	std::cin >> count;
	std::cout << std::endl;

	std::vector<Student> students(count);

	for (int i = 0; i < count; i++) {
		std::string name;
		int age;
		char grade;

		std::cout << "Enter the name of student " << i + 1 << ':' << std::endl;
		std::getline(std::cin >> std::ws, name);
		std::cout << std::endl;
		students[i].set_name(name);

		std::cout << "Enter the age of student " << i + 1 << ':' << std::endl;
		std::cin >> age;
		std::cout << std::endl;
		students[i].set_age(age);

		std::cout << "Enter the grade of student " << i + 1 << ':' << std::endl;
		std::cin >> grade;

		while (grade < 'A' || grade > 'F' || grade == 'E') {
			std::cout << "Please Enter a valid grade: " << std::endl;
			std::cin >> grade;
			std::cout << std::endl;
		}

		std::cout << std::endl;
		students[i].set_grade(grade);
	}

	save_students(filename, students);

	for (const Student& student : students) {
		std::cout << "Student: " << student.get_name()
			<< ", Age: " << student.get_age()
			<< ", Grade: " << student.get_grade() << std::endl;
	}
}

void rmv_student() {
	std::string name;
	std::cout << "Enter the name of the student to remove: " << std::endl;
	std::getline(std::cin >> std::ws, name);

	remove(filename, name);
}

void list_students() {
	std::string name;
	std::cout << "Enter the name of the student (Enter '*' for all students): " << std::endl;
	std::getline(std::cin >> std::ws, name);
	std::cout << std::endl;

	std::vector<Student> students;

	load_students(filename, students, name);

	char sort_flag;
	std::cout << "Would you like to sort the students by grade? (y or n): " << std::endl;
	std::cin >> sort_flag;

	if (sort_flag == 'y' || sort_flag == 'Y') {
		sort_students(students);
	}


	for (const Student& student : students) {
		std::cout << "Student: " << student.get_name()
			<< ", Age: " << student.get_age()
			<< ", Grade: " << student.get_grade() << std::endl;
	}
}