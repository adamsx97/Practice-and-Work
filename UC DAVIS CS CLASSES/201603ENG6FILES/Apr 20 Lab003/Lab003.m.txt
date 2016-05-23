% <Xiao,Chengeng>
% <913186040>
% <A07>
%% Clear
clear;
%% Problem 1
%1)
x = [1, 2, 3, 4, 5, 6]; % Create an array x containing the data of time
y = [2.2, 2.7, 3.1, 3.8, 4.9, 6.2]; % Create an array y containing the data of height

%2)
p = polyfit(x, y, 2); % Generate a function applies the method of least squares.

%3)
y0 = polyval(p, 0); % Compute the height at year 0
y7 = polyval(p, 7); % Compute the height at year 7
fprintf('Problem 1.3:\nThe height at year 0 is _%f_ m, and at year 7 is _%f__ m.\n', y0, y7); % Print with format

%4)
x2 = [0:1:7];
yy = polyval(p, x2);
figure(1); % Set new figure
plot(x2, yy); % Draw plot
hold on;
plot(x, y, 'o');  % Draw plot
title('Problem 1.4: Tree Height Data'); % Set title
xlabel('time(years)'); % Set label x
ylabel('Height(m)'); % Set label y
legend('Best Fit Poly', 'o Raw Height Data'); % Set legned
%% Clear
clear;
%% Problem 2
%a.
step = 0.001; % Set step
x = [0:step:2*pi]; % Create a vector x starts at 0 and stop at 2*pi with a step of 0.001. 

%b.
y = sin(x); % Calculate vector y
figure(2); % Set new figure
plot(x, y); % Draw plot
title('Problem 2.b: Plot the vector y where y = sin(x)'); % Set title
xlabel('x'); % Set label x
ylabel('y'); % Set label y
legend('y = sin(x)'); % Set legned

%c.
z = diff(y); % Differentiate the vector y numerically using the Matlab function diff and assign the output to z.

%d.
zVector = z / step; % Calculate zVector created by z/step, dividing z by the step.
zVector(end + 1) = 1; % After diff it is one element shorter, add the estimated value
figure(3); % Set new figure
plot(x, zVector); % Draw plot
hold on;
dy = cos(x); % Calculate  the mathematical closed form expression of the differentiation dy/dx
plot(x, dy); % Draw plot
title('Problem 2.d: Plot of differentiate y = sin(x)'); % Set title
xlabel('x'); % Set label x
ylabel('y'); % Set label y
legend('dy = cos(x)dx', 'zVector'); % Set legned