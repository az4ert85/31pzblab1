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

	friend Matrix& operator+(const Matrix& mat1, const Matrix& mat2);//��������� ���� �������
	Matrix& operator/(Matrix& mat);//������ ���� ������� - �������� �� �������� ������� �������
	Matrix& Trans();//�������������� �������
	friend Matrix& operator/(Matrix& mat,const double divider);//������ ������� �� �����

	Matrix& algadditions();//������� ������� ����������� ���������
	double minor(int index1, int index2);//������� ���� ������� �������� �������
	double det();//��������� �������
	
	friend Matrix& operator*(const Matrix mat1, const Matrix mat2);//�������� �������
	Matrix& operator=(const Matrix& mat);
	
};

