% <ENG 6, SQ16 Lab 005>
% <Chengeng, Xiao>
% <913186040>
% <A07>
%% Problem 1
% 1) The function file
function X = Lab5(A, B)
    A = fliplr(A); % flip matrix from left to right since b&d are index for x and a&c for index for y
    if det(A) == 0 % There is no solution or there are multiple solutions
        X = []; %  the function returns X=empty array (i.e. X=[])
        disp('cannot solve'); % and display “cannot solve”
    else % else there is only one solution
        X = A\B; % Solve the function and save the solution by a column vector
    end % end if
end % end function
