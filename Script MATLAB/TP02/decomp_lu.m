function [L,U]=decomp_lu(A)
n=size(A);
L=zeros(n);
U=zeros(n);%
%premiere ligne
L(1,1)=1;
for j=1:n
    U(1,j)=A(1,j)/L(1,1);
end
for i=1:n
    L(i,1)=A(i,1)/U(1,1);
end
for p=1:n-1
    L(p+1,p+1)=1;
    
    for j=p+1:n
        somme=0;
        for k=1:(p)
            somme =somme+ (L(p+1,k)*U(k,j));
        end
        U(p+1,j)=(A(p+1,j)-somme)/L(p+1,p+1);
    end
    for i=p+2:n
        somme=0;
        for k=1:(p)
            somme =somme+ (L(i,k)*U(k,p+1));
        end
        L(i,p+1)=(A(i,p+1)-somme)/U(p+1,p+1);
    end
end