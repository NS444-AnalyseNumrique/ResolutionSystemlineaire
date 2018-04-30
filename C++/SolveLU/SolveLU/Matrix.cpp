#include "stdafx.h"
#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
}

Matrix::Matrix(unsigned n, unsigned m)
{
	this->row = n;
	this->col = m;
	allocmem();
	for (unsigned i = 0; i < this->row; i++)
		for (unsigned j = 0; j < this->col; j++)
			this->val[i][j] = 0.0f;
}

Matrix::Matrix(Matrix & M)
{
	this->row = M.row;
	this->col = M.col;
	allocmem();
	for (unsigned i = 0; i < this->row; i++)
		for (unsigned j = 0; j < this->col; j++)
			this->val[i][j] = M.val[i][j];
}


Matrix::~Matrix()
{
	for (unsigned i = 0; i < row; ++i)
	{
		delete[] val[i];
	}
	delete[] val;

}

float & Matrix::operator()(int i, int j)
{
	return this->val[i][j];
}

Matrix operator*(const Matrix &M, const Matrix &M1)
{
	Matrix temp(M.row,M1.col);
	for (unsigned i = 0; i < M.row; ++i)
		for (unsigned k = 0; k < M1.col; ++k)
			for (unsigned j = 0; j < M.col; ++j)
				temp.val[i][k] += M.val[i][j]* M1.val[j][k];
	return temp;
}

Matrix  operator*(Matrix &M, float a)
{
	Matrix temp(M);
	for (unsigned i = 0; i < M.row; ++i)
		for (unsigned j = 0; j < M.col; ++j)
			temp.val[i][j] = M.val[i][j] * a;
	return temp;
}
Matrix  operator*( float a, Matrix &M)
{
	return M*a;
}
Matrix  Matrix::operator+(const Matrix &M)
{
	Matrix temp(*this);
	return (temp += M);
}

Matrix & Matrix::operator+=(const Matrix & M)
{

	for (unsigned i = 0; i < M.row; ++i)
		for (unsigned j = 0; j < M.col; ++j)
			 this->val[i][j] +=M.val[i][j];
	return *this;
}

Matrix  Matrix::operator-(Matrix &M)
{
	Matrix temp(M.row, M.col);
	for (unsigned i = 0; i < this->row; ++i)
		for (unsigned j = 0; j < this->col; ++j)
			temp(i, j) = this->val[i][j] - M(i, j);
	return temp;
}

Matrix & Matrix::operator=(const Matrix & M)
{
	if (this==&M)
	{
		return *this;
	}
	else
	{
		if (this->row != M.row || this->col != M.col)
		{
			this->~Matrix();
			this->row = M.row;
			this->col = M.col;
			allocmem();
		}
		for (unsigned i = 0; i < this->row; ++i)
			for (unsigned j = 0; j < this->col; ++j)
				this->val[i][j] = M.val[i][j];
		return *this;
	}
}

Matrix & Matrix::operator=(float a)
{
	for (unsigned i = 0; i < this->row; ++i)
		for (unsigned j = 0; j < this->col; ++j)
			this->val[i][j] = a;
	return *this;
}

Matrix SolveLz(Matrix L, Matrix B)
{
	Matrix z(L.row, 1);
	for (int i = 0; i<L.row; ++i)
	{
		z(i, 0) = B(i, 0);
		for (int j = 0; j<i; ++j)
		{
			z(i, 0) -= (L(i, j)*z(j, 0));
		}

	}
	return z;
}

Matrix SolveUx(Matrix U, Matrix z)
{
	Matrix x(U.row, 1);

	for (int i = x.row - 1; i > -1; i--)
	{
		x(i, 0) = z(i, 0);
		for (int j = x.row-1; j > i; j--)
		{
			x(i, 0) -= U(i, j)*x(j, 0);
		}
		x(i, 0) /= U(i, i);
	}
	return x;
}

float Matrix::norm()
{
	float somme = 0.0f;
	for (unsigned i = 0; i < this->row; ++i)
		for (unsigned j = 0; j < this->col; ++j)
			somme += pow(this->val[i][j], 2);

	return sqrt(somme);
}

bool Matrix::LU(Matrix & L, Matrix & U)
{
	if (L.col != this->col || L.row != this->row || U.row != this->row || U.col != this->col)
		return false;
	if (this->row != this->col)
		return false;
	int n = this->col;
	L.val[0][0] = 1.0f;
	for (unsigned j = 0; j < n; ++j)
	{
		U.val[0][j] = this->val[0][j] / L.val[0][0];
	}
	for (unsigned i = 0; i < n; ++i)
	{
		L.val[i][0] = this->val[i][0] / U.val[0][0];
	}
	float somme = 0.0f;
	for (unsigned p = 0; p < n - 1; ++p)
	{
		L.val[p+1][p + 1] = 1.0f;
		for (unsigned j = p + 1; j < n; ++j)
		{
			somme = 0.0f;
			for (unsigned k = 0; k < p + 1; ++k)
			{
				somme += L.val[p + 1][k] * U.val[k][j];
			}
			U.val[p + 1][j] = (this->val[p + 1][j] - somme) / L.val[p + 1][p+1];
		}
		for (unsigned i = p + 1; i < n; ++i)
		{
			somme = 0.0f;
			for (unsigned k = 0; k < p + 1; ++k)
			{
				somme += L.val[i][k] * U.val[k][p+1];
			}
			L.val[i][p + 1] = (this->val[i][p + 1] - somme) / U.val[p + 1][p + 1];
		}
	}

}

std::ostream & operator<<(std::ostream & os, const Matrix & M)
{
	for (unsigned i = 0; i< M.row; ++i)
	{
		for (unsigned j = 0; j<M.col; ++j)
		{
			os << M.val[i][j] << " ";
		}
		os << "\n";
	}
	return os;

}/**/
