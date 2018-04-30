/*
NS444 - TP Analyse Numerique
Class Matrix : permet de realiser le calcule matricielle
ce programme est utilisé pour un but educatif
Il est permis d'utiliser, modifier et distribuer ce code.
Veuillez soumetre toute amelioration au code.
 github.com/ResolutionSystemlineaire/Cpp/SolveLU/SolveLU/Matrix.h
Auteur : B BOUALEM
*/
#pragma once
#include <iostream>
class Matrix
{
public:
	unsigned row;// nombre de lignes
	unsigned col;// nombre de colonnes
	float **val;// les elements de matrice
	Matrix();
	Matrix(unsigned n, unsigned m);// Constructeur
	Matrix(Matrix &M);// Constructeur de copie
	~Matrix();// destructeur
	float& operator () (int i, int j);// surchage de l'operateur () pour recuperer l'element i,j
	friend std::ostream& operator<<(std::ostream& os, const Matrix& M);// surcharge de l'operateur << pour affichage sur la console

	friend Matrix  operator*(const Matrix &M, const Matrix &M1);// Operateur * : M * M1
	friend Matrix  operator*(Matrix &M, float a);// Operateur * : M * a
	friend Matrix  operator*( float a, Matrix &M);// Operateur * : a * M
	Matrix  operator+(const Matrix &M);// Operateur + : this + M
	Matrix&  operator+=(const Matrix &M);// Operateur += : this += M
	Matrix  operator-(Matrix& M);// Operateur - : this - M
	Matrix& operator=(const Matrix &M);// Operateur = : this = M
	Matrix& operator=(float a);// Operateur = : this = a affecter a a tout les element de la matrice
	friend Matrix SolveLz(Matrix L, Matrix B);// Resoudre Lz=B ou L une matrice triangulaire inferieure
	friend Matrix SolveUx(Matrix U, Matrix z);// Resoudre Ux=z ou U une matrice triangulaire superieure
	float norm();// Calcul de la norme
	bool LU(Matrix& L, Matrix& U);// Decomposition d'une matrice en L et U ou L une matrice triangulaire inferieure ...
	// et U une matrice triangulaire superieure

protected :

	void allocmem()// fonction pour allouer l'espace 
	{
		this->val = new float*[row];
		for (int i = 0; i < this->row; i++)
		{
			this->val[i] = new float[this->col];
		}
	}
	
};

