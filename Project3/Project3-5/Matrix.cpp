#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int _row, int _col) {
	row = _row; col = _col;
	data = new int*[row];
	for (int i = 0; i < row; i++) {
		data[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			data[i][j] = (i*col) + j + 1;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++)
		delete[] data[i];
	delete[] data;
}

void Matrix::doPrint() {
	for (int i = 0; i < row; i++) {
		cout << "[ ";
		for (int j = 0; j < col; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

int Matrix::getElement(int _row, int _col) {
	return data[_row-1][_col-1];
}

void Matrix::setElement(int _row, int _col, int num) {
	data[_row - 1][_col - 1] = num;
}

void Matrix::doTranspose() {
	int** newData;
	int tmp = col;
	col = row;
	row = tmp;
	newData = new int*[row];
	for (int i = 0; i < row; i++) {
		newData[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			newData[i][j] = data[j][i];
		}
	}
	for (int i = 0; i < col; i++)
		delete[] data[i];
	delete[] data;
	data = newData;
}

bool Matrix::operator==(const Matrix& rhs) {
	if ((col != rhs.col) || (row != rhs.row)) return false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			if (data[i][j] != rhs.data[i][j]) return false;
		}
	}
	return true;
}

Matrix Matrix::operator*(const Matrix &rhs) {
	Matrix result(row, rhs.col);
	for (int i = 0; i < result.row; i++) {
		for (int j = 0; j < result.col; j++)
		{
			result.data[i][j] = 0;
			for (int k = 0; k < col; k++) {
				result.data[i][j] += data[i][k] * rhs.data[k][j];
			}
		}
	}
	return result;
}