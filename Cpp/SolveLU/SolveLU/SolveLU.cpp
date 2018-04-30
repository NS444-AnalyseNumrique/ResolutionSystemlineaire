
/*
	NS444 - TP Analyse Numerique
	Resolution d'un systeme d'equation lineaire par la methode LU
	A*x = B
	ce programme est utilise pour un but educatif
	Il est permis d'utiliser, modifier et distribuer ce code.
	Veuillez soumetre toute amelioration au code sur
	github.com/ResolutionSystemlineaire/Cpp/SolveLU/SolveLU/SolveLU.cpp
	Auteur : B BOUALEM
*/
#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
int main()
{
	
	float R1 = 2, R2 = 2, R3 = 3, R4 = 2, R5 = 1, E=14;
	
	Matrix R(3, 3), L(3, 3), U(3, 3), V(3, 1), z(3, 1), x(3, 1);
	// initialisation de la matrice R
	R(0, 0) = R1+R2;R(0, 1) = R1; R(0, 2) = 0;
	
	R(1, 0) = -R2;R(1, 1) = R3; R(1, 2) = -R4;
	
	R(2, 0) = 0; R(2, 1) = R5; R(2, 2) = R4+R5;
	// initialisation du vecteur V
	V(0, 0) = E;
	V(1, 0) = 0;
	V(2, 0) = E;
	std::cout << "Matrice R \n" << R;//Affichage de R
	R.LU(L, U);// Decomposition de R en L et U
	
	std::cout <<"Matrice L \n" << L;// Affichage de la Matrice L
	std::cout << "Matrice U \n" << U;// Affichage de la Matrice U
	std::cout << "||R-L*U|| \n" << (R-(L*U)).norm()<< std::endl;// Calcul ||R-L*U|| si = 0 R = L*U  
	z = SolveLz(L, V);// resoudre Lz=V
	std::cout << "Matrice z \n" << z;//Afficher z
	x = SolveUx(U, z);// resoudre Ux=z
	std::cout << "Matrice x \n" << x; // afficher x
	Matrix I(5, 1);//declaration de I
	I(1, 0) = x(0, 0);
	I(2, 0) = x(1, 0);
	I(3, 0) = x(2, 0);
	I(0, 0) = I(1, 0) + I(2, 0);
	I(4, 0) = I(3, 0) + I(2, 0);
	std::cout << "Les courants \n" << I;// Affichage des courants
	getchar();
    return 0;
}

