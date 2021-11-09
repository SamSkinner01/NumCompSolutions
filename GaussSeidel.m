%Gauss-Seidel

function [x] = GaussSeidel(A,inApprox,tolerance,choice)

[n,m]=size(A);

for i=1:n
    b(i)= A(i,m);
end

for i=1:n
    b(i)=b(i)/A(i,i);
    x(i)=inApprox(i);
    old_x(i)=x(i);
    
    for j=1:n
        if(i~=j)
            A(i,j)=A(i,j)/A(i,i);
        end
    end
end

error = 9999;

while(error > tolerance)
    error = 0;
    for i=1:n
        x(i)=b(i);
        for j=1:n
            if(i~=j)
               x(i)=x(i)-A(i,j)*x(j);
            end
        end
        error = error + abs(x(i)-old_x(i));
        old_x(i)=x(i);
    end
    error=error/n;
end
