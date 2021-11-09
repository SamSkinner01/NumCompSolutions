function [x] = Gauss(A)

[n,m] = size(A); %Getting the size of row and columns

i=1;
j=1;

while i<=n && j<=m %While in the bounds of the matrix
    p=i;
    
    for k=i+1:n %For loop will find the pivot
        if abs(A(k,j)) > abs(A(p,j))
            p = k;
        end
    end
    
    if A(p,j)~=0%We want the largest number in pivot position
        U = A(i,:);
        A(i,:) = A(p,:);
        A(p,:) = U;        
        
        A(i,:) = A(i,:)/A(i,j);  %All values in A(i,j) will have value 1(pivot spots)
        
        for u=i+1:n %Values in A(u,j) will now be 0, creating upper triangular matrix
            A(u,:) = A(u,:) - A(u,j)*A(i,:);
        end
        i=i+1;
    end
    
    j=j+1;
end

if A(n,n) == 0 %If the value in this column and row = 0, cant divide by 0 so no unique solution
    disp('No unique solution');
    return
end

x(n) = A(n,n+1)/A(n,n); %Will get value of Xn(Or value in row N in x)
for i = n - 1:-1:1 %For n-1 (because we already did Xn)
    sumax = 0;
    for j = i+1:n
        sumax = sumax + A(i,j)*x(j); %Ex) We solved x3, now A(2,3) * x3 will get you a constant.
    end
    x(i) = (A(i,n+1) - sumax)/A(i,i);%Subtract sumax from column M, in ith row. Then you can solve for the missing variable before 
                                     %If x3 solved, will leave Cx2 = A(i,m)
end
        
