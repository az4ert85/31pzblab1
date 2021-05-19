#pragma once
#include <vector>

class Matrix
{
	int n, m;
	std::vector<std::vector<double>> matrix;
public:

	Matrix();
	Matrix(int a, int b);
	Matrix(Matrix& mat);

	void set_size(int a, int b);
	void set_matrix();
	void Print();

	friend Matrix& operator+(const Matrix& mat1, const Matrix& mat2);//додавання двох матриць
	Matrix& operator/(Matrix& mat);//частка двох матриць - множення на обернену матрицю дільника
	Matrix& Trans();//транспонування матриці
	friend Matrix& operator/(Matrix& mat,const double divider);//ділення матриці на число

	Matrix& algadditions();//повертає матрицю алгебраїчних доповнень
	double minor(int index1, int index2);//повертає мінор відносно елемента матриці
	double det();//визначник матриці
	
	friend Matrix& operator*(const Matrix mat1, const Matrix mat2);//множення матриць
	Matrix& operator=(const Matrix& mat);
	
};

