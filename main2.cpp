#include <iostream>
#include <cstring>
#include <string>

#include "MyString.h"

int main() {
	using namespace std;

	MyString a, b;

	cout << "Enter the first MyString obj: ";
	cin >> a;

	cout << "Enter the second MyString obj: ";
	cin >> b;

	cout << "\na == " << a << "\nb == " << b << "\n";
	cout << "len a == " << a.length() << "\nlen b == " << b.length() << "\n";

	cout << "\na + b == " << (a + b) << "\n";
	cout << "a > b == " << (a > b) << "\n";
	cout << "a < b == " << (a < b) << "\n";
	cout << "a >= b == " << (a >= b) << "\n";
	cout << "a <= b == " << (a <= b) << "\n";
	cout << "a >= b == " << (a == b) << "\n";
	cout << "a != b == " << (a != b) << "\n";

	cout << "\nAfter a = b:\n";
	a = b;
	cout << "a == " << a << "\nb == " << b << "\n";
	cout << "len a == " << a.length() << "\nlen b == " << b.length() << "\n\n";

	system("pause");
	return 0;
}
