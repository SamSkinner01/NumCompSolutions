%Jacobi Function

function [x] = Jacobi(A, inApprox, tolerance, choice)

[n,m]=size(A);

for i=1:n
    b(i)= A(i,m);
end

for i=1:n
    b(i)=b(i)/A(i,i);
    new_x(i)=inApprox(i);
    
    for j=1:n
        if(i ~= j)
            A(i,j)=A(i,j)/A(i,i);
        end
    end
end

error = 9999;

while(error>tolerance)
    error = 0;
    for i=1:n
        old_x(i)=new_x(i);
        new_x(i)=b(i);
    end
    for i=1:n
        for j=1:n
            if(i~=j)
            new_x(i)=new_x(i)-A(i,j)*old_x(j);
            end
        end
    
    error = error+abs(new_x(i)-old_x(i));
    end
error=error/n;

end

for i=1:n
    x(i)=new_x(i);
end

    
