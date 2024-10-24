#include <iostream>
#include <string>
#include "../include/student.h"
#include "../include/fileio.h"
#include "../include/operations.h"

int main() {
	bool loopcon = true;
	int selection;

	std::cout << "************STUDENT RECORD SYSTEM************" << std::endl;
	while(loopcon) {
		std::cout << "1. Add students" << std::endl;
		std::cout << "2. Remove student" << std::endl;
		std::cout << "3. List students" << std::endl;
		std::cout << "4. Close application" << std::endl;
		std::cout << "Enter a selection: " << std::endl;
		std::cin >> selection;
		std::cout << std::endl;

		switch (selection) {
		case 1:
			add_students();
			std::cout << std::endl;
			break;

		case 2:
			rmv_student();
			std::cout << std::endl;
			break;

		case 3:
			list_students();
			std::cout << std::endl;
			break;

		case 4:
			char confirm;
			std::cout << "Are you sure you want to quit? (y or n): " << std::endl;
			std::cin >> confirm;

			if (confirm == 'y' || confirm == 'Y') {
				loopcon = false;
			}
			break;
		}
	}
}