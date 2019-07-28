#pragma once

class Matrix {
private:
	int row, col;
	int** data;

public:
	Matrix(int _row, int _col);
	~Matrix();
	void doPrint();
	int getElement(int _row, int _col);
	void setElement(int _row, int _col, int num);
	void doTranspose();
	bool operator==(const Matrix& rhs);
	Matrix operator*(const Matrix &rhs);
};