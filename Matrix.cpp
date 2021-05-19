#include "Matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix()
{
	n = 0; m = 0;
}

Matrix::Matrix(int a, int b)
{
	set_size(a, b);
	set_matrix();
}

Matrix::Matrix(Matrix& mat)
{
	set_size(mat.n, mat.m);
	for (int i = 0; i < n; i++) {
		matrix.push_back(mat.matrix[i]);
	}
}

void Matrix::set_size(int a, int b) 
{
	this->n = a; 
	this->m = b;
}
void Matrix::set_matrix()
{
	double element;
	std::cout << "Enter your matrix " << n << "x" << m << " : \n";
	for (int i = 0; i < n; i++) {
		std::vector<double> vec;
		for (int j = 0; j < m; j++) {
			std::cin >> element;
			vec.push_back(element);
		}
		matrix.push_back(vec);
	}
}

void Matrix::Print()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << std::setw(5) <<round(matrix[i][j] * 100) / 100 << ' ';
		}
		std::cout << '\n';
	}
}

Matrix& operator+(const Matrix& mat1, const Matrix& mat2)
{
	Matrix* result = new Matrix();
	if (mat1.n == mat2.n && mat1.m == mat2.m) {
		result->set_size(mat1.n, mat2.m);
		for (int i = 0; i < result->n; i++) {
			std::vector<double> vec;
			for (int j = 0; j <result->m; j++) {
				vec.push_back(mat1.matrix[i][j] + mat2.matrix[i][j]);
			}
			result->matrix.push_back(vec);
		}
	}
	else std::cout << "\nYou can not add this two matrix with different sizes!\n";

	return *result;
}

Matrix& Matrix::operator/(Matrix& mat)
{
	Matrix* result = new Matrix();
	result->set_size(n, m);

	if (mat.det() == 0.0) {
		std::cout << "You can not divide this matrix - determin is zero\n";
	}
	else {//якщо det!=0  знаходимо обернену матрицю до матриці-дільника
		
		Matrix divider(mat.algadditions());//складаємо матрицю алгебраїчних доповнень (союзну) та протранспонувати її
		divider.Trans();
		divider = divider / mat.det();//ділимо союзну матрицю на детермінант
		*result = (*this) * divider; //виконуємо множення матриць
	}

	return *result;
}

Matrix& Matrix::Trans()
{
	double temp;
	int k = (m <= n) ? m : n;

	//для квадратної матриці чи частини прямокутної 
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	if (n > m) {//коли рядків більше ніж стовпців
		for (int i = m; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matrix[j].push_back(matrix[i][j]);
			}
		}
		matrix.erase(matrix.begin()+m, matrix.end());//видаляє рядки транспоновані в стовпці
		int tmp = n; n = m; m = tmp;//змінює розміри матриці
	}
	else if (n < m) {//коли стовпців більше ніж рядків
		for (int i = n; i < m; i++) {
			std::vector<double> vec;
			for (int j = 0; j < n; j++) {
				vec.push_back(matrix[j][i]);
			}
			matrix.push_back(vec);
		}
		for (int i = 0; i < n; i++) {
			matrix[i].erase(matrix[i].begin() + n, matrix[i].end());//видаляє стовпці транспоновані в рядки
		}
		int tmp = n; n = m; m = tmp;//змінює розміри матриці
	}

	return *this;
}   


Matrix& Matrix::algadditions()
{
	Matrix *A = new Matrix(); A->set_size(n, m);
	if (n != m) {
		std::cout << "\nYou can not find minor for this matrix (not square matrix)!\n";
	}
	else {
		int sign = -1;
		for (int i = 0; i < n; i++) {
			std::vector<double> vec;
			for (int j = 0; j < m; j++) {
				sign *= -1;
				vec.push_back(sign*minor(i, j));
			}
			A->matrix.push_back(vec);
		}
	}
	return *A;
}

double Matrix::minor(int index1, int index2) 
{
	double min = 0;
	if (n != m) {
		std::cout << "\nYou can not find minor for this matrix (not square matrix)!\n";
	}
	else {
		Matrix b; b.set_size(n - 1, m - 1);
		for (int j = 0; j < n; j++) {
			std::vector<double> vec;
			for (int k = 0; k < m; k++) {
				if (j != index1 && k != index2) vec.push_back(matrix[j][k]);
			}
			if(!vec.empty())b.matrix.push_back(vec);
		}
		if (b.n == 1 && b.m == 1) min = b.matrix[0][0];
		else min = b.det();
	}
	return min;
}

double Matrix::det()
{
	double determin = 0;
	if (n == m) {
		if (n == 2) 
			determin = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		else {
			int sign = -1;
			for (int i = 0; i < m; i++) {
				sign *= -1;
				Matrix b; b.set_size(n - 1, m - 1);
				for (int j = 1; j < n; j++) {
					std::vector<double> vec;
					for (int k = 0; k < m; k++) {
						if (k != i) vec.push_back(matrix[j][k]);
					}
					b.matrix.push_back(vec);
				}
				determin += sign * matrix[0][i] * b.det();
			}
		}
	}
	else
		std::cout << "\nYou can not find determin for this matrix (not square matrix)!\n";
	return determin;
}


Matrix& operator/(Matrix& mat, const double divider)
{
	Matrix* result = new Matrix();
	if (divider == 0.0) {
		std::cout << "Divider can not be equal 0\n";
	}
	else {
		result->n = mat.n;
		result->m = mat.m;
		for (int i = 0; i < mat.n; i++) {
			std::vector<double> vec;
			for (int j = 0; j < mat.m; j++) {
				vec.push_back(mat.matrix[i][j] / divider);
			}
			result->matrix.push_back(vec);
		}
	}
	return *result;
}

Matrix& Matrix::operator=(const Matrix& mat)
{
	(*this).set_size(mat.n, mat.m);
	if (!matrix.empty())matrix.clear();
	for (int i = 0; i < n; i++) {
		(*this).matrix.push_back(mat.matrix[i]);
	}
	return (*this);
}

Matrix& operator*(const Matrix mat1, const Matrix mat2)
{
	Matrix* result = new Matrix();
	if (mat1.m == mat2.n) {
		result->n = mat1.n;
		result->m = mat2.m;
		for (int i = 0; i < result->n; i++) {
			std::vector<double> vec;
			for (int j = 0; j < result->m; j++) {
				double elem = 0;
				for (int k = 0; k < mat1.m; k++) {
					elem += mat1.matrix[i][k] * mat2.matrix[k][j];
				}
				vec.push_back(elem);
			}
			result->matrix.push_back(vec);
		}
	}
	else
		std::cout << "\nYou can not multiply this two matrixes!\n";

	return *result;
}
