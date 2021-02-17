#pragma once

#include <string>
#include <vector>

class StudentProgress {
private:
	std::string first_name;
	std::string last_name;
	std::string father_name;
	std::string group;
	int math_mark; //mathematics
	int sw_dev_mark; //softrware development
	int english_mark; //English language
protected:
	void set_first_name(const std::string& first_name);
	void set_last_name(const std::string& last_name);
	void set_father_name(const std::string& father_name);
	void set_group(const std::string& group);
	void set_math_mark(const int& math_mark);
	void set_sw_dev_mark(const int& sw_dev_mark);
	void set_english_mark(const int& english_mark);
public:
	StudentProgress(const std::string& first_name = "",
					const std::string& last_name = "",
					const std::string& father_name = "",
					const std::string& group = "",
					const int& math_mark = 0,
					const int& sw_dev_mark = 0,
					const int& english_mark = 0);
	StudentProgress(const StudentProgress& other);
	~StudentProgress() = default;

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_father_name() const;
	std::string get_group() const;
	int get_math_mark() const;
	int get_sw_dev_mark() const;
	int get_english_mark() const;

	void print_student_info(const int& num = 0) const;
};