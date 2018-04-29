function x = montee (U,z)
n=length(z);
x(n)=z(n)/U(n,n);

for i=n-1:-1:1
    summ=0;
    for j=n:-1:i+1
        summ=summ+(U(i,j)*x(j));
    end
        
    x(i)=(z(i)-summ)/U(i,i);
end
x=x';