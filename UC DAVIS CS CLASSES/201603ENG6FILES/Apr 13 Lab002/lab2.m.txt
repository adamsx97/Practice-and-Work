% First Name: <Chengeng>
% Last Name: <Xiao>
% Stu. ID: <913186040>
%% Part 1
x = linspace(-7,7,1000); % Use Linspace to create a vector x
f = sin(10 .* x) .* x; % Set f(x)
g = sin(10 .* x); % Set g(x)
figure(1); % Initialize figure 1
plot(x, f, 'r', x, g, 'b'); % Draw f(x) in red & g(x) in blue
axis([-7, 7, -4, 4]); % Set axis limits
title('Lab2 Part1, plot of function f(x)&g(x)'); % Set title
legend('f(x) = x * sin(10 * x)', 'g(x) = sin(10 * x)'); % Set legend
xlabel ('x'); % set x-axis
ylabel ('y'); % set y-axis
hold on; % hold on the figure
%% Part 2
AGTU30 = [51, 62, 74]; % Age group totals under or equal to 30
AGT31 = [45, 78, 71]; % Age group totals more than 31
GM = [29, 89, 52]; % Gender Male
GF = [67, 51, 93]; % Gender Female
% Loading datas

%2.A
LMgtF = GM > GF; % Logical array that Male amount greater Female
QMgtF = find(LMgtF == 1); % Quarters that Male amount greater Female
fprintf('2.A:\nThe quarter(s) that male toals were larger than Female are:\n');
disp(QMgtF);

%2.B
LU30gt31 = AGTU30 > AGT31; % Logical array that 17-30 age group totals were larger than the 31+ age group totals
QU30gt31 = find(LU30gt31 == 1); % Quarters that 17-30 age group totals were larger than the 31+ age group totals
fprintf('2.B:\nThe quarter(s) that 17-30 age group totals were larger than the 31+ age group totals are:\n');
disp(QU30gt31);

%2.C
LFgtM = GF > GM; % Logical array that Female amount greater Male
L31gtU30 = AGT31 > AGTU30; % Logical array that 31+ group totals were larger than the 17-30 age age group totals
QC = find((LFgtM == 1) | (L31gtU30 == 1)); % Quarters that matches either one of the requirements above which meets 2.C's requirement
fprintf('2.C:\nThe quarter(s) that Female totals were larger than Male totals or the 31+ age group totals were larger than the 17-30 age group totals are:\n');
disp(QC);