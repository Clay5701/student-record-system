#pragma once
#include <string>
#include <vector>
#include "../include/student.h"

void save_students(const std::string& filename, const std::vector<Student>& students);
void load_students(const std::string& filename, std::vector<Student>& students, const std::string& iname);
void remove(const std::string& filename, const std::string& iname);