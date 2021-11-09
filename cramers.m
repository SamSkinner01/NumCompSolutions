%Sam Skinner
%Project 4
function x = cramer(augMat) 
    s = size(augMat);   %Get size of augmented matrix
    sR = s(1);  %Getting row size, because s(#ofrow,#ofcol)
    sC = s(2);  %Getting column size
    %Define zero matrixes which will be populated 
    A = zeros(sR,sR); 
    x = zeros(1,sR);
    b = zeros(sR,1);
    %Populating A with n x n matrix
    for row=1:sR
        for col=1:sR
            A(row,col) = augMat(row,col);
        end
    end 
    disp(A)
    %Fill b with last column in augmented matrix
    for row=1:sR
        b(row,1)=augMat(row,sC);
    end
    disp(b)
    if det(A) == 0 %If det(A) is 0, it is singular
        disp("This system is singular, therefore there is no unique solution")
    else
        for col=1:sC-1                      %This nested for loop will add b into each row in
            copyMat = A;                    %a column, take the determinant of that, divide
            for row=1:sR                    %by det(A) and get the solution, and put it into
                copyMat(row,col)=b(row,1);  %a matrix x. 
            end
            x(1,col) = det(copyMat)/det(A); 
        end
    end
end

    

