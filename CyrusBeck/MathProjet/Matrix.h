#pragma once
#include <vector>
#include <iostream>


class Matrix
{
public:
	Matrix(float matrix[2][1]);
	Matrix(float matrix[2][2]);
	Matrix(float matrix[3][3]);
	Matrix(std::vector<std::vector<float>> matrix);
	std::vector<std::vector<float>> matrix_get();
	float determinant();
	Matrix comatrice();
	Matrix transpose();
	Matrix inverse();
	Matrix produitReel(float real);
	Matrix produitMatrice(Matrix matrix);
	void Matrix::printMatrix();
	~Matrix();
private:
	std::vector<std::vector<float>> matrix_;
};