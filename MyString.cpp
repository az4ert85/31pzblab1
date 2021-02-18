#include <iostream>
#include <string>

#include "MyString.h"

MyString::MyString() : str(nullptr), len(0) {}

MyString::MyString(const char* str) {
	this->len = strlen(str);
	this->str = new char[this->len];

	for (int i = 0; str[i] != '\0'; i++)
		this->str[i] = str[i];
}

MyString::MyString(const MyString& other) {
	this->len = other.len;
	this->str = new char[this->len];

	for (int i = 0; i < this->len; i++)
		this->str[i] = other.str[i];
}

MyString::MyString(MyString&& other) noexcept {
	//std::cout << "CP CONS\n";
	this->len = other.len;
	this->str = other.str;
	other.str = nullptr;
}

MyString::~MyString() { delete[] this->str; }

int MyString::length() const {
	return this->len;
}

MyString& MyString::operator=(const MyString& other) {
	if (this == &other)
		return *this;

	delete[] this->str;
	this->str = new char[other.len];

	this->len = other.len;

	for (int i = 0; i < this->len; i++)
		this->str[i] = other.str[i];

	return *this;
}

MyString operator+(const MyString& a, const MyString& b) {
	MyString res;
	res.len = a.len + b.len;
	res.str = new char[res.len];

	for (int i = 0; i < a.len; i++)
		res.str[i] = a.str[i];
	for (int i = 0; i < b.len; i++)
		res.str[a.len + i] = b.str[i];

	return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& object) {
	for (int i = 0; i < object.len; i++)
		os << object.str[i];

	return os;
}

std::istream& operator>>(std::istream& is, MyString& object) {
	char* buff = new char[2500];
	is.getline(buff, 2500);
	object = MyString{ buff };
	delete[] buff;

	return is;
}

bool MyString::operator>(const MyString& other) const {
	if (this->len > other.len)
		return true;
	else if (this->len < other.len)
		return false;

	for (int i = 0; i < this->len; i++) {
		if (this->str[i] > other.str[i])
			return true;
		else if (this->str[i] < other.str[i])
			return false;
	}

	return false;
}

bool MyString::operator<(const MyString& other) const {
	if (this->len < other.len)
		return true;
	else if (this->len > other.len)
		return false;

	for (int i = 0; i < this->len; i++) {
		if (this->str[i] < other.str[i])
			return true;
		else if (this->str[i] > other.str[i])
			return false;
	}

	return false;
}

bool MyString::operator>=(const MyString& other) const {
	if (this->len > other.len)
		return true;
	else if (this->len < other.len)
		return false;

	for (int i = 0; i < this->len; i++) {
		if (this->str[i] > other.str[i])
			return true;
		else if (this->str[i] < other.str[i])
			return false;
	}

	return true;
}

bool MyString::operator<=(const MyString& other) const {
	if (this->len < other.len)
		return true;
	else if (this->len > other.len)
		return false;

	for (int i = 0; i < this->len; i++) {
		if (this->str[i] < other.str[i])
			return true;
		else if (this->str[i] > other.str[i])
			return false;
	}

	return true;
}

bool MyString::operator==(const MyString& other) const {
	if (this->len < other.len)
		return false;
	else if (this->len > other.len)
		return false;

	for (int i = 0; i < this->len; i++) {
		if (this->str[i] < other.str[i])
			return false;
		else if (this->str[i] > other.str[i])
			return false;
	}

	return true;
}

bool MyString::operator!=(const MyString& other) const {
	return !(*this == other);
}
