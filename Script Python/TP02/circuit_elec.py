import numpy as np
# les resistances
R1=2;
R2=2;
R3=3;
R4=2;
R5=1;
#  la tension 
E = 14;
#  la matrice des resistances

R = np.array([ [R2+R1, R1, 0],
               [-R2, R3, -R4],
               [0, R5, R4+R5] ])
V= np.array([ [E],
              [0],
              [E] ])
def decomp_LU (A):
    # fonction python pour decomposer A en L et U
    lin,col =  A.shape
    n=lin
    L =  np.identity(n)
    U =  np.zeros(A.shape)

    for j in np.arange(n):
        U[0,j] = A[0,j]/L[0,0]
        
    for i in np.arange(n):
        L[i,0] = A[i,0]/U[0,0]

    for p in np.arange(n-1):
        for j in np.arange(p+1, n):
            somme=0
            for k in np.arange(n-1):
                somme += L[p+1,k]*U[k,j]

            U[p+1,j]=(A[p+1,j]-somme)/L[p+1,p+1]
        
        for i in np.arange(p+2,n):
            somme=0
            for k in np.arange(n-1):
                somme += L[i,k]*U[k,p+1]
            L[i,p+1]=(A[i,p+1]-somme)/U[p+1,p+1]

    return L,U

def descente (L,B):
    # fonction pour Resoudre L z = B
    lin,col =  L.shape
    n=lin
    z=np.array([])

    for i in np.arange(n):
        somme=0

        for j in np.arange(i):
            somme+=L[i,j]*z[j]

        z = np.append(z,(B[i]-somme)/L[i,i])
        
    z= z.reshape(n,1)
    return z

def montee (U,z):
    # fonction pour Resoudre U x = z
    lin,col =  U.shape
    n=lin
    x=np.zeros((n,1))

    for i in np.arange(n-1,-1,-1):
        somme=0
        for j in np.arange(n-1,i,-1):
            somme+=U[i,j]*x[j]

        x[i] = (z[i]-somme)/U[i,i]
        
    x= x.reshape(n,1)
    return x


print (R) # Afficher la matrice R
# Decomposer R en LU
L,U =  decomp_LU(R)

print (L)# Afficher la matrice L
print (U)# Afficher la matrice U
print (R-np.matmul(L,U)) # Verifier R = L*U

# Resolution du probleme L z = V
z= descente(L,V)

print ('z = ',z)# Afficher la matrice z
print (V-np.matmul(L,z))# Verifier z est solution de L*z = V
# Resolution du probleme U x = z
x=montee (U,z)
print ('x = ',x)# Afficher la matrice x
print (V-np.matmul(R,x))# Verifier x est solution de Rx = V

 # calculer les courants a partir du vecteur x
lin,col = x.shape
I= np.zeros((lin+2,1))
I[1:4] = x
I[0] = I[1]+I[2]
I[4] = I[2]+I[3]
print (I)  # Afficher les courants
