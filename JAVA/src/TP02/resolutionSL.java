package TP02;
/**
 * 
 * 
 * @author B BOUALEM
 *
 */
public class resolutionSL {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double R1=2,R2=2,R3=3,R4=2,R5=1,E=14;
		Matrix R = new Matrix (3,3);
		Matrix L = new Matrix (3,3);
		Matrix U = new Matrix (3,3);
		Matrix V = new Matrix (3,1);
		Matrix I = new Matrix (5,1);
		R.set(0, 0, R1+R2);R.set(0, 1, R1);R.set(0, 2, 0);
		R.set(1, 0, -R2);R.set(1, 1, R3);R.set(1, 2, -R4);
		R.set(2, 0, 0);R.set(2, 1, R5);R.set(2, 2, R4+R5);
		
		V.set(0, 0, E);
		V.set(1, 0, 0);
		V.set(2, 0, E);
		
		System.out.println(R);
		R.LU(L, U);
		System.out.println(L);
		System.out.println(U);
		System.out.println(L.mul(U));
		System.out.println(R.sub(L.mul(U)).norm());
		System.out.println("-_-_-_-_-_-_-_-");
		Matrix z = Matrix.descente(L, V);
		Matrix x = Matrix.montee(U, z);
		System.out.println(z);
		System.out.println(x);
		System.out.println(V.sub(L.mul(z)));
		System.out.println(R.mul(x));
		
		I.set(1, 0, x.get(0, 0));
		I.set(2, 0, x.get(1, 0));
		I.set(3, 0, x.get(2, 0));
		I.set(0, 0, I.get(1, 0)+I.get(2, 0));
		I.set(4, 0, I.get(2, 0)+I.get(3, 0));
		System.out.println(I);
		
		

	}

}
