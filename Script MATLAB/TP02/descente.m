function z=descente(L,B)
z(1)=B(1)/L(1,1);
n=length(B);
for i=2:n
    summ=0;
    for j=1:i-1
        summ=summ+(L(i,j)*z(j));
    end
        
    z(i)=(B(i)-summ)/L(i,i);
end
z=z';