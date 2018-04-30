package TP02;
/**
 * NS444 - TP Analyse Numerique
 * utilisation de la class Matrix pour resoudre le probleme R i = V
 * @author B BOUALEM
 *
 */
public class resolutionSL {

	public static void main(String[] args) {
		// Definition des Resistances 
		double R1=2,R2=2,R3=3,R4=2,R5=1,E=14;
		// declaration des matrices
		Matrix R = new Matrix (3,3);
		Matrix L = new Matrix (3,3);
		Matrix U = new Matrix (3,3);
		Matrix V = new Matrix (3,1);
		Matrix I = new Matrix (5,1);
		//definition de la matrice de resistance.
		R.set(0, 0, R1+R2);R.set(0, 1, R1);R.set(0, 2, 0);
		R.set(1, 0, -R2);R.set(1, 1, R3);R.set(1, 2, -R4);
		R.set(2, 0, 0);R.set(2, 1, R5);R.set(2, 2, R4+R5);
		// definition du vecteur de tension V
		V.set(0, 0, E);
		V.set(1, 0, 0);
		V.set(2, 0, E);
		
		System.out.println(R);// Affichage de R
		R.LU(L, U);// Dcomposition de R en deux matrices L et U
		System.out.println(L);//Affichage de la matrice L
		System.out.println(U);// Affichage de la matrice U
		System.out.println(L.mul(U));// Calcul de L*U
		System.out.println(R.sub(L.mul(U)).norm());// Calul de ||R-(L*U)||
		System.out.println("-_-_-_-_-_-_-_-");
		Matrix z = Matrix.descente(L, V);//resoudre le probleme L z = V
		Matrix x = Matrix.montee(U, z);//  resoudre le probleme U x = z
		System.out.println(z);// Afficher z
		System.out.println(x);// Afficher x
		System.out.println(V.sub(L.mul(z)));// Calcul de V- L*z
		System.out.println(R.mul(x));// Calcul R*x
		//calcul les courants a partir du vecteur x
		I.set(1, 0, x.get(0, 0));
		I.set(2, 0, x.get(1, 0));
		I.set(3, 0, x.get(2, 0));
		I.set(0, 0, I.get(1, 0)+I.get(2, 0));
		I.set(4, 0, I.get(2, 0)+I.get(3, 0));
		System.out.println(I);// Afficher les courants
		
		

	}

}
