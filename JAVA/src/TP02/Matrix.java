package TP02;
/**
 * 
 * 
 * @author B BOUALEM
 *
 */
public class Matrix {
		public int col;
		public int lin;
		public double[][] val;
		
		public Matrix (int x, int y)
		{
			this.lin = x;
			this.col = y;
			this.val= new double [this.lin][this.col];
		}
		
		public double get(int i, int j)
		{
			return this.val[i][j];
		}
		
		public void set (int i, int j, double a)
		{
			this.val[i][j]=a;
		}
		
		public Matrix add (Matrix M)
		{
			Matrix out = new Matrix (this.lin,this.col);
			for (int i =0; i< this.lin;i++)
				for (int j =0;j<this.col;j++)
					out.val[i][j]=this.val[i][j]+M.val[i][j];
			return out;
		}
		public Matrix sub (Matrix M)
		{
			Matrix out = new Matrix (this.lin,this.col);
			for (int i =0; i< this.lin;i++)
				for (int j =0;j<this.col;j++)
					out.val[i][j]=this.val[i][j]-M.val[i][j];
			return out;
		}
		public Matrix mul (Matrix M)
		{
			Matrix out = new Matrix (this.lin,M.col);
			for (int i =0; i< this.lin;i++)
				for (int k=0;k<M.col;k++)
				for (int j =0;j<this.col;j++)
				{
					
					out.val[i][k]+=this.val[i][j]*M.val[j][k];
					
				}
			return out;
		}
		public void LU(Matrix L,Matrix U)
		{
			int n = this.lin;
			L.set(0, 0, 1);
			for (int j=0;j<n;j++)
			{
				U.set(0, j, this.get(0, j)/L.get(0, 0));
			}
			for (int i=1;i<n;i++)
			{
				L.set(i, 0, this.get(i,0)/U.get(0, 0));
			}
			for (int p = 0; p<n-1;p++)
			{
				L.set(p+1, p+1,1);
				for (int j=p+1;j<n;j++)
				{
					double somme=0.0;
					for (int k=0;k<p+1;k++)
						somme+=L.get(p+1, k)*U.get(k, j);
					U.set(p+1, j, (this.get(p+1, j)-somme)/L.get(p+1, p+1));
				}
				for (int i=p+2;i<n;i++)
				{
					double somme=0.0;
					for (int k=0;k<p+1;k++)
						somme+=L.get(i, k)*U.get(k, p+1);
					L.set(i, p+1, (this.get(i,p+1)-somme)/U.get(p+1, p+1));
				}
			}
		}
		public static Matrix descente (Matrix L,  Matrix B)
		{
			
			int n = L.lin;
			Matrix z = new Matrix (n,1);
			double somme;
			for (int i=0;i<n;i++)
			{
				somme=0.0;
				for (int j=0;j<i;j++)
				{
					somme+= L.get(i, j)*z.get(j, 0);
				}
				z.set(i, 0, (B.get(i, 0)-somme)/L.get(i, i));
			}
			
			return z;
		}
		public static Matrix montee (Matrix U,  Matrix z)
		{
			
			int n = U.lin;
			Matrix x = new Matrix (n,1);
			double somme;
			for (int i=n-1;i>-1;i--)
			{
				somme=0.0;
				for (int j=n-1;j>i;j--)
				{
					somme+= U.get(i, j)*x.get(j, 0);
				}
				x.set(i, 0, (z.get(i, 0)-somme)/U.get(i, i));
			}
			
			return x;
		}
		public double norm()
		{
			double out=0.0;
			for (int i =0; i< this.lin;i++)
				for (int j =0;j<this.col;j++)
					out+=Math.pow(this.val[i][j],2);
			return Math.sqrt(out);
		}
		public String toString()
		{
			String out="";
			for (int i =0; i< this.lin;i++)
				{for (int j =0;j<this.col;j++) {
					out+=this.val[i][j]+" ";}
				out+="\n";
				}
			
			return out;
		}

}
