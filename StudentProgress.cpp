#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <Windows.h>
#include <conio.h>
#include <algorithm>

#include "StudentProgress.h"


StudentProgress::StudentProgress(const std::string& first_name,
								 const std::string& last_name,
								 const std::string& father_name,
								 const std::string& group,
								 const int& math_mark,
								 const int& sw_dev_mark,
							   	 const int& english_mark) {
	for(auto& i : first_name)
		if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
			std::cerr << "\nFATAL ERROR: Wrong first name is given to the constructor!\n";
			system("pause");
			exit(-1);
		}

	for (auto& i : last_name)
		if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
			std::cerr << "\nFATAL ERROR: Wrong last name is given to the constructor!\n";
			system("pause");
			exit(-1);
		}

	for (auto& i : father_name)
		if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
			std::cerr << "\FATAL ERROR: Wrong father name is given to the constructor!\n";
			system("pause");
			exit(-1);
		}

	for (auto& i : group) {
		if (!isdigit(i) && !(i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i == '_')) {
			std::cerr << "\FATAL ERROR: Wrong math mark is given to the constructor!\n";
			system("pause");
			exit(-1);
		}
	}

	if (math_mark < 0 || math_mark > 100) {
		std::cerr << "\FATAL ERROR: Wrong math mark is given to the constructor!\n";
		system("pause");
		exit(-1);
	}

	if (sw_dev_mark < 0 || sw_dev_mark > 100) {
		std::cerr << "\FATAL ERROR: Wrong software development mark is given to the constructor!\n";
		system("pause");
		exit(-1);
	}

	if (english_mark < 0 || english_mark > 100) {
		std::cerr << "\FATAL ERROR: Wrong English language mark is given to the constructor!\n";
		system("pause");
		exit(-1);
	}

	this->first_name = first_name;
	this->last_name = last_name;
	this->father_name = father_name;
	this->group = group;
	this->math_mark = math_mark;
	this->sw_dev_mark = sw_dev_mark;
	this->english_mark = english_mark;
}

StudentProgress::StudentProgress(const StudentProgress& other) {
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->father_name = other.father_name;
	this->group = other.group;
	this->math_mark = other.math_mark;
	this->sw_dev_mark = other.sw_dev_mark;
	this->english_mark = other.english_mark;
}

std::string StudentProgress::get_first_name() const {
	return this->first_name;
}

std::string StudentProgress::get_last_name() const {
	return this->last_name;
}

std::string StudentProgress::get_father_name() const {
	return this->father_name;
}

std::string StudentProgress::get_group() const {
	return this->group;
}

int StudentProgress::get_math_mark() const {
	return this->math_mark;
}

int StudentProgress::get_sw_dev_mark() const {
	return this->sw_dev_mark;
}

int StudentProgress::get_english_mark() const {
	return this->english_mark;
}

void StudentProgress::set_first_name(const std::string& first_name) {
	this->father_name = first_name;
}

void StudentProgress::set_last_name(const std::string& last_name) {
	this->last_name = last_name;
}

void StudentProgress::set_father_name(const std::string& father_name) {
	this->father_name = father_name;
}

void StudentProgress::set_group(const std::string& group) {
	this->group = group;
}

void StudentProgress::set_math_mark(const int& math_mark) {
	this->math_mark = math_mark;
}

void StudentProgress::set_sw_dev_mark(const int& sw_dev_mark) {
	this->sw_dev_mark = sw_dev_mark;
}

void StudentProgress::set_english_mark(const int& english_mark) {
	this->english_mark = english_mark;
}

void StudentProgress::print_student_info(const int& num) const {
	if (num)
		std::cout << "--- Student #" << num << " -\n";
	std::cout << "First name: " << this->first_name << "\n";
	std::cout << "Last name: " << this->last_name << "\n";
	std::cout << "Father name: " << this->father_name << "\n";
	std::cout << "Group: " << this->group << "\n";
	std::cout << "Math mark: " << this->math_mark << "\n";
	std::cout << "Software development mark: " << this->sw_dev_mark << "\n";
	std::cout << "English language mark: " << this->english_mark << "\n\n";
}