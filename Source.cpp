#include "Matrix.h"
#include <iostream>

void menu() {
	std::cout << "\nEnter character for to do something:\n"
		<< "+ to add matrices\n" 
		<< "/ to divide matrices\n"
		<< "% to divide matrix by number\n" 
		<< "t to transpose matrix\n"
		<< "* to multiply matrices\n" 
		<< "d to find determinant of matrix\n"
		<< "m to find minor for element of matrix\n" 
		<< "a return matrix of algebras additions\n"
		<< "e to exit\n";
}

int main() {
	int n1, m1, n2, m2;
	std::cout << "Enter size of first matrix (nxm):\n";
	std::cin >> n1 >> m1;
	Matrix mat1(n1, m1);

	std::cout << "Enter size of second matrix (nxm):\n";
	std::cin >> n2 >> m2;
	Matrix mat2(n2, m2);
	
	
	char flag = 's';
	while (flag != 'e') {
		std::cin.ignore();
		system("cls");
		
		std::cout << "First matrix: \n";
		mat1.Print();

		std::cout << "Second matrix: \n";
		mat2.Print();

		menu();
		std::cin >> flag; 
		switch (flag)
		{
		case '+': {
			std::cout << "Sum of this matrices is:\n";
			Matrix* result=new Matrix(mat1 + mat2);
			result->Print();
			delete result;
		}break;
		case '/': {
			std::cout << "Result of dividing these matrices is:\n";
			Matrix* result = new Matrix(mat1 / mat2);
			result->Print();
			delete result;
		}break;
		case '%': {
			int num;
			std::cout << "Choose matrix 1 or 2: "; std::cin >> num;
			if (num != 1 && num != 2) {
				std::cout << "Incorect input\n";
			}
			else {
				double divider;
				std::cout << "Enter divider: "; std::cin >> divider;
				std::cout << "Result of dividing matrix " << num << " by " << divider << " is:\n";
				Matrix result;
				if (num == 1) result = mat1 / divider;
				else result = mat2 / divider;
				result.Print();
			}
		}break;	
		case 't': {
			int num;
			std::cout << "Choose matrix 1 or 2: "; std::cin >> num;
			if (num != 1 && num != 2) {
				std::cout << "Incorect input\n";
			}
			else {
				Matrix result;
				std::cout << "Result of transposing matrix " << num << " is:\n";
				if (num == 1) result = mat1;
				else  result = mat2;
				result.Trans().Print();
			}
		}break; 
		case '*': {
			std::cout << "Product of this matrices is:\n";
			Matrix result = mat1 * mat2;
			result.Print();
		}break; 
		case 'd': {
			int num;
			std::cout << "Choose matrix 1 or 2: "; std::cin >> num;
			if (num != 1 && num != 2) {
				std::cout << "Incorect input\n";
			}
			else {
				std::cout << "Determinant of matrix " << num << " is: ";
				if (num == 1) std::cout << mat1.det() << '\n';
				else std::cout << mat2.det() << '\n';
			}
		}break; 
		case 'm': {
			int num;
			std::cout << "Choose matrix 1 or 2: "; std::cin >> num;
			if (num != 1 && num != 2) {
				std::cout << "Incorect input\n";
			}
			else {
				int i, j;
				std::cout << "Enter index (i, j) of element: ";
				std::cin >> i >> j;
				if(num == 1){
					if ((i < 0 || i > n1) || (j < 0 || j > m1)) {
						std::cout << "Incorect input\n";
					}
					else {
						std::cout << "Minor element["<< i <<"]["<< j <<"] of matrix " << num << " is: " << mat1.minor(i, j) << '\n';
						
					}
				}
				else {
					if ((i < 0 || i > n2) || (j < 0 || j > m2)) {
						std::cout << "Incorect input\n";
					}
					else {
						std::cout << "Minor element[" << i << "][" << j << "] of matrix " << num << " is: " << mat2.minor(i, j) << '\n';
					}
				}
			}
		}break; 
		case 'a': {
			int num;
			std::cout << "Choose matrix 1 or 2: "; std::cin >> num;
			if (num != 1 && num != 2) {
				std::cout << "Incorect input\n";
			}
			else {
				std::cout << "Matrix of algebras additions for matrix " << num << " is:\n";
				if (num == 1) mat1.algadditions().Print();
				else mat2.algadditions().Print();
			}
		}break;
		default: 
			break;
		}
		system("pause");
	}

	return 0;
}