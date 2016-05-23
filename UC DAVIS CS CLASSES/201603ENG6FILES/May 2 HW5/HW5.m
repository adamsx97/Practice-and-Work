%ENG006 A07
%Chengeng Xiao
%SID: 913186040
%These programs solves 4 problems in HW5
%% Problem 1:
A = randn(3);
B = randn(3);

% Create two 3X3 matrices called A and B
% and fill them up with random integers
% using the random number generator.

%a)
fprintf('Problem 1.a:\n'); % Print with format
disp(transpose(A + B)); % Use Matlab to compute: ( A + B ) ^ T

%b)
fprintf('Problem 1.b:\n'); % Print with format
disp(transpose(A) + transpose(B)); % Use Matlab to compute: A^T + B^T

if transpose(A + B) == (transpose(A) + transpose(B))
    fprintf('Comparing my result with the result from part (a), the results are very consistent with mathematical expectations.\n'); % Print with format
else
    fprintf('Comparing my result with the result from part (a), the results are not consistent with mathematical expectations.\n'); % Print with format
end
    
%c)
fprintf('Problem 1.c:\n'); % Print with format
disp(A * B); % Use Matlab to matrix multiply the matrix A with matrix B

%d)
fprintf('Problem 1.d:\n'); % Print with format
disp(B * A); % Use Matlab to matrix multiply the matrix A with matrix B

fprintf('Comparing my result with the result from part (c), the results are very consistent with mathematical expectations\n'); % Print with format

%e)
fprintf('Problem 1.e:\n'); % Print with format
disp(A .* B); %  Use Matlab to do element by element multiplication of the contents of matrix A and matrix B.
%% clear all;
%% Problem 2:
%% Part A:
% c for children, s for students and a for adults.
% a = (c + s) / 2;
% a + c + s == 900
% 4 * c + 6 * s + 8 * a == 5600
A = [ [1, -0.5, -0.5]; [1, 1, 1]; [8, 4, 6] ]; % Set up function
B = [0; 900; 5600]; % Set up function

%1)
fprintf('Problem 2.A.1:\n'); % Print with format
disp(A); % Display the matrices.
disp(B); % Display the matrices.

%2)
fprintf('Problem 2.A.2:\n'); % Print with format
disp(size(A)); % Display the matrices.
disp(size(B)); % Display the matrices.

%3)
fprintf('Problem 2.A.3:\nThe number of children attended the show is'); % Print with format
sol = A\B; % Solve the matrix
disp(sol(2)); % Disp the number of Children

%% clear all;
%% Part B:
% 4x - y = 4
% -6x + 2y = 4
A = [[4, -1]; [-6, 2]]; % Set up function
B = [4; 4]; % Set up function
sol = A\B;  % Solve the matrix

%1)
fprintf('Problem 2.B.1:\n'); % Print with format
disp(sol(1)); % display x
disp(sol(2)); % display y

%2)
fprintf('Problem 2.B.2:\n'); % Print with format
disp(det(A)); % Find and display the determinant D

%3)
fprintf('Problem 2.B.3:\nSince the right side of equations are all four, so if the determinant is 0, then there are infinite solutions; or contrarily, there is only one solution to the functions.\n'); % Print with format
if det(A) == 0
    fprintf('There are infinite solutions to the functions.\n'); % Print with format
else
    fprintf('There is only one solution to the functions.\n'); % Print with format
end

x = [0 : 0.001 : 10];
y1 = 4 * x - 4;
y2 = 3 * x + 2;
%Rewrite the equations above as equations of straight lines.

%4)
figure(1); % Set new figure
plot(x, y1, x, y2); % Draw plot
title('Problem 2.B.4: Plot the lines and find the point of intersection'); % Set title
xlabel('x'); % Set x label
ylabel('y'); % Set y label
legend('y1 = 4 * x - 4', 'y2 = 3 * x + 2'); % Set legend
disp('Problem 2.B.4:');
disp('I found out that in the plot the intersect is right at (6, 20). It is correspondent to our solution before.');
% Display my findings from the plot.

%5)
disp('Problem 2.B.5:');
disp('In 2.B.1, I solve the function by the law of matrix, and I found out the solution is that x is 6 and y is 20. In 2.B.5, I obeserved the plot and found out that the two lines intersect right at (6, 20), which proves the solution is correct.');
% Compare my solutions from the above methods and display my comments.

%% clear all;
%% Part C:
% 3x - y = 4
% -6x + 2y = 4
A = [[3, -1]; [-6, 2]]; % Set up function
B = [4; 4]; % Set up function
sol = A\B;  % Solve the matrix

%1)
fprintf('Problem 2.C.1:\n'); % Print with format
disp(sol(1)); % display x
disp(sol(2)); % display y

%2)
fprintf('Problem 2.C.2:\n'); % Print with format
disp(det(A)); % Find and display the determinant D

%3)
fprintf('Problem 2.C.3:\nSince the right side of equations are all four, so if the determinant is 0, then there are infinite solutions; or contrarily, there is only one solution to the functions.\n'); % Print with format
if det(A) == 0
    fprintf('There are infinite solutions to the functions.\n'); % Print with format
else
    fprintf('There is only one solution to the functions.\n'); % Print with format
end

x = [0 : 0.001 : 10];
y1 = 3 * x - 4;
y2 = 3 * x + 2;
%Rewrite the equations above as equations of straight lines.

%4)
figure(2); % Set new figure
plot(x, y1, x, y2); % Draw plot
title('Problem 2.C.4: Plot the lines and find the point of intersection'); % Set title
xlabel('x'); % Set x label
ylabel('y'); % Set y label
legend('y1 = 3 * x - 4', 'y2 = 3 * x + 2'); % Set legend
disp('Problem 2.C.4:');
disp('I found out that in the plot the two lines has no intersect, which means that they are parallel. It is correspondent to our solution before.');
% Display my findings from the plot.

%5)
disp('Problem 2.C.5:');
disp('In 2.C.1, I solve the function by the law of matrix, and I found out that there are infinite solutions. In 2.C.5, I obeserved the plot and found out that the two lines are parallel, which proves the solution is correct.');
% Compare my solutions from the above methods and display my comments.

%% clear all;
%% Problem 3:
results=[10 30 20 50; 30 20 20 40; 50 50 30 10; 20 10 50 30; 40 40 40 20];
category=['Category 1';'Category 2';'Category 3';'Category 4'];
robots=['A','B','C','D','E']';
% Pre-set data

%a)
lagt25 = logical(results(1, :) > 25); % Calculate logical array for robot A greater than 25
fprintf('Problem 3.a:\nThe categorys that robot A scores more than 25 points are:\n'); % Print with format
disp(category(lagt25, :)); % Display answer

%b)
lc4gt35 = logical(results(:, 4) > 35); % Calculate logical array for Category 4 greater than 35
fprintf('Problem 3.b:\nThe robots that in category 4 score more than 35 points are:\n'); % Print with format
disp(robots(lc4gt35, :)); % Display answer

%c)
lDbB = logical(results(2, :) < results(4, :)); % Calculate logical array for Categorys that robot D beat robot B
fprintf('Problem 3.c:\nThe categories that robot D beats robot B are:\n'); % Print with format
disp(category(lDbB, :)); % Display answer

%d)
robots(3) = []; % Delete the robot name from the array, robots
results(3, :) = []; % Delete the points earned from matrix, results
disp('Problem 4.c:');
disp(results);
disp(robots);
% Display both after deletion.