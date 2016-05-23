
%	Academic License

% Engineering 006 Homework
%
% These programs, solves the 4 problems in homework 2 prompt.
% 
% Eng 6, Spring 2016
% Name: <Chengeng Xiao>
% Student ID: <913186040>
% Lab Section: <A07>
%% Problem 1:
start = 0;
stop = 50;
stepSize = 1;
timeIncrement = start:stepSize:stop;
lambda = 1550 / 1000; % ? in ?m
nCore = 1.5;
nCladding = 1.45;
V = 2 * pi * timeIncrement / lambda * sqrt(nCore ^ 2 - nCladding ^ 2);
figure(1);
plot(timeIncrement, V);
hold on
title('Plot of core radius to frequency V')
xlabel('a (core radius)') % Note that it doesn't have to be 'tArray' on the plot.
ylabel('V')