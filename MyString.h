#pragma once

#include <iostream>

class MyString {
private:
	int len;
	char* str;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;
	~MyString();

	MyString& operator=(const MyString& other);

	bool operator>(const MyString& other) const;
	bool operator<(const MyString& other) const;
	bool operator>=(const MyString& other) const;
	bool operator<=(const MyString& other) const;
	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;

	friend MyString operator+(const MyString& a, const MyString& b);
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);

	int length() const;
};
