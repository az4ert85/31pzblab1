#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>

#include "StudentProgress.h"

void add_student(std::vector<StudentProgress>& arr) {
	std::string fname, lname, fthname, grp;
	int mmark, sdmark, emark;
	bool done;

	do {
		std::cout << "First name: ";
		std::cin >> fname;
		std::cout << "Last name: ";
		std::cin >> lname;
		std::cout << "Father name: ";
		std::cin >> fthname;
		std::cout << "Group : ";
		std::cin >> grp;
		std::cout << "Math mark : ";
		std::cin >> mmark;
		std::cout << "Software development mark : ";
		std::cin >> sdmark;
		std::cout << "English language mark : ";
		std::cin >> emark;

		done = true;
		for (auto& i : fname)
			if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
				std::cout << "\nWrong first name entered. Try again!\n\n";
				done = false;
			}

		for (auto& i : lname)
			if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
				std::cout << "\nWrong last name entered. Try again!\n\n";
				done = false;
			}

		for (auto& i : fthname)
			if (isdigit(i) || i < 'A' || i > 'z' || i > 'Z' && i < 'a') {
				std::cout << "Wrong father name entered. Try again!\n\n";
				done = false;
			}

		for (auto& i : grp)
			if (!isdigit(i) && !(i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i == '_')) {
				std::cout << "\nWrong group entered. Try again!\n\n";
				done = false;
			}

		if (mmark < 0 || mmark > 100) {
			std::cout << "\nWrong math mark input. Try again!\n\n";
			done = false;
		}

		if (sdmark < 0 || sdmark > 100) {
			std::cout << "\nWrong software development mark input. Try again!\n\n";
			done = false;
		}

		if (emark < 0 || emark > 100) {
			std::cout << "\nWrong English language mark input. Try again!\n\n";
			done = false;
		}
	} while (!done);

	arr.push_back({ fname, lname, fthname, grp, mmark, sdmark, emark });
}

void del_student(std::vector<StudentProgress>& arr) {
	int num;

	std::cout << "Enter the num: ";
	std::cin >> num;

	if (num < 1 || num > arr.size()) {
		std::cout << "\nWrong input!\n";
		return;
	}

	arr.erase(arr.begin() + num - 1);
}

void enter_students_info(std::vector<StudentProgress>& arr) {
	int count;
	do {
		std::cout << "Enter a count of students: ";
		std::cin >> count;
		if (count < 0)
			std::cout << "Wrong input! Try again.\n";
	} while (count < 0);

	for (int i = 0; i < count; i++) {
		std::cout << "\n--- Student #" << i + 1 << " -\n";
		add_student(arr);
	}
}

void find_student(const std::vector<StudentProgress>& arr) {
	char key;
	bool valid_pressed = false;

	std::cout << "Press the appropriate key to choose a parameter to find:\n";
	std::cout << "\tFirst name : 1\n\tLast name: 2\n\tFather name : 3\n\tGroup : 4\n";
	std::cout << "\tMath mark : 5\n\tSoftware development mark : 6\n\tEnglish language mark : 7\n";

	std::string str_tmp;
	int int_tmp;

	int found = 0;
	while (!valid_pressed) {
		switch (key = _getch()) {
		case '1':
			std::cout << "\nYou pressed 1\n\n";
			std::cout << "Enter a first name to find: ";
			std::cin >> str_tmp;
			for (auto& i : arr) {
				if (i.get_first_name() == str_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '2':
			std::cout << "\nYou pressed 2\n\n";
			std::cout << "Enter a last name to find: ";
			std::cin >> str_tmp;
			for (auto& i : arr) {
				if (i.get_last_name() == str_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '3':
			std::cout << "\nYou pressed 3\n\n";
			std::cout << "Enter a father name to find: ";
			std::cin >> str_tmp;
			for (auto& i : arr) {
				if (i.get_father_name() == str_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '4':
			std::cout << "\nYou pressed 4\n\n";
			std::cout << "Enter a group to find: ";
			std::cin >> str_tmp;
			for (auto& i : arr) {
				if (i.get_group() == str_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '5':
			std::cout << "\nYou pressed 5\n\n";
			std::cout << "Enter a math mark to find: ";
			std::cin >> int_tmp;
			for (auto& i : arr) {
				if (i.get_math_mark() == int_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '6':
			std::cout << "\nYou pressed 6\n\n";
			std::cout << "Enter a software development mark to find: ";
			std::cin >> int_tmp;
			for (auto& i : arr) {
				if (i.get_sw_dev_mark() == int_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		case '7':
			std::cout << "\nYou pressed 7\n\n";
			std::cout << "Enter an English language mark to find: ";
			std::cin >> int_tmp;
			for (auto& i : arr) {
				if (i.get_english_mark() == int_tmp) {
					i.print_student_info(found + 1);
					found++;
				}
			}
			valid_pressed = true;
			break;
		}
	}

	if (!found)
		std::cout << "\nNothing is found!\n";
}

void sort_students(const std::vector<StudentProgress>& arr) {
	std::vector<StudentProgress> copy = arr;
	char key;
	bool sorted = false;

	std::cout << "Press the appropriate key to choose a sorting parameter:\n";
	std::cout << "\tFirst name : 1\n\tLast name: 2\n\tFather name : 3\n\tGroup : 4\n";
	std::cout << "\tMath mark : 5\n\tSoftware development mark : 6\n\tEnglish language mark : 7\n";

	while (!sorted) {
		switch (key = _getch()) {
		case '1':
			std::cout << "\nYou pressed 1\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_first_name() < b.get_first_name(); });
			sorted = true;
			break;
		case '2':
			std::cout << "\nYou pressed 2\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_last_name() < b.get_last_name(); });
			sorted = true;
			break;
		case '3':
			std::cout << "\nYou pressed 3\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_father_name() < b.get_father_name(); });
			sorted = true;
			break;
		case '4':
			std::cout << "\nYou pressed 4\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_group() < b.get_group(); });
			sorted = true;
			break;
		case '5':
			std::cout << "\nYou pressed 5\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_math_mark() < b.get_math_mark(); });
			sorted = true;
			break;
		case '6':
			std::cout << "\nYou pressed 6\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_sw_dev_mark() < b.get_sw_dev_mark(); });
			sorted = true;
			break;
		case '7':
			std::cout << "\nYou pressed 6\n\n";
			std::sort(copy.begin(), copy.end(),
				[](const StudentProgress& a, const StudentProgress& b)
				{ return a.get_english_mark() < b.get_english_mark(); });
			sorted = true;
			break;
		}
	}

	int copy_size = copy.size();
	for (int i = 0; i < copy_size; i++)
		copy[i].print_student_info(i + 1);
}

void change_student_info(std::vector<StudentProgress>& arr) {
	int num;

	std::cout << "Enter the num: ";
	std::cin >> num;

	if (num < 1 || num > arr.size() - 1) {
		std::cout << "Wrong input!\n";
		system("pause");
		return;
	}

	std::vector<StudentProgress> tmp;
	std::cout << "Enter the new information:\n\n";
	add_student(tmp);

	arr[num - 1] = tmp[0];
}

void print_all_students(const std::vector<StudentProgress>& arr) {
	std::cout << "All students list:\n\n";

	int n = 1;
	for (auto& i : arr) {
		std::cout << "--- Student #" << n++ << "\n";
		std::cout << "First name: " << i.get_first_name() << "\n";
		std::cout << "Last name: " << i.get_last_name() << "\n";
		std::cout << "Father name: " << i.get_father_name() << "\n";
		std::cout << "Group : " << i.get_group() << "\n";
		std::cout << "Math mark : " << i.get_math_mark() << "\n";
		std::cout << "Software development mark : " << i.get_sw_dev_mark() << "\n";
		std::cout << "English language mark : " << i.get_english_mark() << "\n\n";
	}
}

void user_interface() {
	using namespace std;

	vector<StudentProgress> arr;
	bool notExit = true;
	char keyHit;

	while (notExit) {
		cout << "Hello dear user!\n\n";
		cout << "Available commands list (press the appropriate number):\n";
		cout << "1) Enter students list\n";
		cout << "2) Add one student\n";
		cout << "3) Delete a student\n";
		cout << "4) Change student data\n";
		cout << "5) Print all students data\n";
		cout << "6) Find students using a parameter\n";
		cout << "7) Print sorted students list\n";
		cout << "9) Exit the program\n\n";

		keyHit = _getch();

		if (keyHit == '1') {
			system("cls");
			enter_students_info(arr);
			std::cout << "\n";
			system("pause");
		}
		else if (keyHit == '2') {
			system("cls");
			add_student(arr);
			std::cout << "\n";
			system("pause");
		}
		else if (keyHit == '3') {
			system("cls");
			del_student(arr);
			std::cout << "\n";
			system("pause");
		}
		else if (keyHit == '4') {
			system("cls");
			change_student_info(arr);
			std::cout << "\n";
			system("pause");
		}
		else if (keyHit == '5') {
			system("cls");
			print_all_students(arr);
			system("pause");
		}
		else if (keyHit == '6') {
			system("cls");
			find_student(arr);
			system("pause");
		}
		else if (keyHit == '7') {
			system("cls");
			sort_students(arr);
			system("pause");
		}
		else if (keyHit == '9') {
			system("cls");
			cout << "Thank you for using my program!\n\n";
			system("pause");
			notExit = false;
		}
		system("cls");
	}
}

int main() {
	user_interface();
	return 0;
}