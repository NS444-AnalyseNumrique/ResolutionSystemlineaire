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
		double R1=2,R2=2,R3=2,R4=2,R5=1;
		Matrix R = new Matrix (3,3);
		Matrix L = new Matrix (3,3);
		Matrix U = new Matrix (3,3);
		R.set(0, 0, R1+R2);R.set(0, 1, R3);R.set(0, 2, 0);
		R.set(1, 0, R2);R.set(1, 1, -R3);R.set(1, 2, R4);
		R.set(2, 0, 0);R.set(2, 1, R5);R.set(2, 2, R4+R5);
		System.out.println(R);
		R.LU(L, U);
		System.out.println(L);
		System.out.println(U);
		System.out.println(L.mul(U));
		System.out.println(R.sub(L.mul(U)).norm());

	}

}
