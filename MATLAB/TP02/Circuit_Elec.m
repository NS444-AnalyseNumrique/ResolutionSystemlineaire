clear all
clc
% les résistances
R1=2;
R2=2;
R3=3;
R4=2;
R5=1;
% la tension 
E = 14;
% la matrice des resistances
R = [R2+R1 R1 0;
     -R2 R3 -R4;
     0 R5 R4+R5]
% vecteur des tensions
V= [E 0 E]'
[L,U]=decomp_lu(R)
R-(L*U)%Verifier que R = L*U
% Resoudre le probleme Lz = V
z=descente(L,V)
% Resoudre le probleme U x = z
x = montee (U,z)
V-(R*x) % verifier que R*i = Vffffff
% Calcul des cinq courants
I(2:4) = x;
I(1)= I(2)+ I(3);
I(5)= I(4)+ I(3);
I

     