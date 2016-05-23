
%	Academic License

% Engineering 6 Lab Quiz
%
% These programs, solve Lab007 3 quiz problems.
% 
% Eng 6, Spring 2016
% Name: <Chengeng Xiao>
% Student ID: <913186040>
% Lab Section: <A07>
%% Problem 1
answer = sin(7 * pi / 9) / (cos(5 * pi / 7)) ^ 2 + tan(5 * pi / 12) / 7;
os = sprintf('Problem 1.a:\nThe answer to the equation is %f.\n', answer);
disp(os);
%% Problem 2
x = pi / 9;
bleft = cos(2 * x);
bright = (1 - (tan(x)) ^ 2) / (1 + (tan(x)) ^ 2);

if logical(bleft == bright) == 1
    os = sprintf('Problem 2.b:\nThe equation b has its left side equal to right side.\n'); % print with format
else
    os = sprintf('Problem 2.b:\nThe equation b has its left side not equal to right side.\n'); % print with format
end
disp(os);
%% Problem 3
angleAd = 120; % angle a in degree
b = 3; % length of b
c = 5; % length of c
a = sqrt(b ^ 2 + c ^ 2 - 2 * b * c * cosd(angleAd));
os = sprintf('Problem 3:\nThe length of a is %f.\n', a);
disp(os);