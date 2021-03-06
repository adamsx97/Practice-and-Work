%%% First Name: Ziyue
%%% Last Name: Gao
%%% Student ID: 913192160
%%% Section: A07

%% Problem 1

% clear the variables at the beginning of the script
clear;

% 1)
% store the given values
m = [2, 5, 10, 15, 20, 25, 30, 35, 40];
G = [5.7, 4.1, 3.3, 2.5, 2.1, 2.2, 1.7, 1.6, 1.3];
% change x to 1/m
x = 1 ./ m;
% calculate y
y = exp(G);
% calculate the curve
p = polyfit(x, y, 2);
% store the answer
a = p(1);
b = p(2);
c = p(3);
% print the answers
fprintf('The coefficients a, b and c are %.2f, %.2f and %.2f.\n', a, b, c);

% 2)
% store the given values
monthss = [1:60];
x2 = 1 ./ monthss;
% calculated the estimated function
growths = polyval(p, x2);
y2 = reallog(growths);
% draw the figure
figure(1)
% plot the figures
plot(m, G, 'o');
hold on
plot(monthss, y2);
hold off
xlabel('m (months)');
ylabel('G (cm)');
title('growth vs. month');
legend('original data', 'estimated growth');

% 3)
% set month to the 100th month
x3 = 1/100;
% calculated the estimated growth at the 100th month
y3 = reallog(polyval(p, x3));
% print the result
fprintf('The estimated growth at the 100th month is %.2f.\n', y3);

%% Problem 2

% clear the variables at the beginning of the script
clear;

% 1)
% store the given values
t = [0.04, 0.08, 0.12, 0.17, 0.43, 0.48, 0.53, 0.58, 0.64, 0.67, 0.75, 0.92];
y = [0.59, 0.95, 0.96, 0.25, 0.16, 0.95, 0.89, 0.31, -0.59, -0.89, -0.71, 0.95];
T1 = linspace(0, 1, 1000);
% calculate the spline interpolation
R1 = spline(t, y, T1);
% plot the figure
figure(2)
plot(t, y, 'o');
hold on
plot(T1, R1);
hold off
xlabel('period');
ylabel('ambient noise');
title('period vs. ambient noise');
legend('original data', 'interpolated curve');

% 2)
% find the min value
[peaks, locals] = findpeaks(R1);
local1 = locals(1) / 1000;
local2 = locals(2) / 1000;
local3 = locals(3) / 1000;
temp1 = (local1 + local2) / 2;
temp2 = (local2 + local3) / 2;
period = (temp1 + temp2) / 2;
fprintf('The period of the waveform is %.2f.\n', period);

% 3)
T = period * 1000
T_2 = T / 2;
R2 = R1;
R2(1:end - T_2) = R1(T_2 + 1:end);
R2(end - T_2 + 1:end) = R1(507:507 + T_2 - 1);
R2 = spline(T1, R2, T1 + T_2);
Rfinal = R1 + R2;
figure(3)
plot(T1, R1);
hold on
plot(T1, R2);
plot(T1, Rfinal);
hold off
% left side = new_x <= shift;
% right side = new_x > shift;
% spline & interp1 -> two parameters (first x&y, whatever you want to find)
% new_x(left_side)+shift -> last parameter to the spline function
% new_x(right_side)-shift -> last parameter to the spline function
%% Problem 3

% clear the variables at the beginning of the script
clear;

fprintf('Answer the following questions with either Y for Yes or N for No.\n');
% get the answer of whether employeed
employed_cell = inputdlg('Are you employed?');
employed = employed_cell{1};
if (employed == 'Y')
    % get the answer of whether graduated in the past two years
    graduate_cell = inputdlg('Have you graduated from college in the past two years?');
    graduate = graduate_cell{1};
    if (graduate == 'Y')
        % print the answers
        fprintf('You qualify for the special interest rate.\n');
    else
        fprintf('You do not qualify for the special interest rate.\n');
    end
else
    fprintf('You do not qualify for the special interest rate.\n');
end

%% Problem 4

% clear the variables at the beginning of the script
clear;

% 1)
% initialize the first point
x100(1) = 50;
y100(1) = 50;
time1 = 100;
% get the random route for 100 times
x1 = randi([-1, 1], 1, time1);
y1 = randi([-1, 1], 1, time1);
for(i = 2:time1)
    x100(i) = x100(i - 1) + x1(i);
    y100(i) = y100(i - 1) + y1(i);
    % check if its larger than 100
    if (x100(i) > 100)
        x100(i) = 100 - (x100(i) - 100);
    end
    % check if its larger than 100
    if (y100(i) > 100)
        y100(i) = 100 - (y100(i) - 100);
    end
    % check if its smaller than 0
    if (x100(i) < 0)
        x100(i) = -x100(i);
    end
    % check if its smaller than 0
    if (y100(i) < 0)
        y100(i) = -y100(i);
    end
end
% plot the figure
figure(4)
for(i = 1:time1)
    plot(x100(i), y100(i), '^');
    % pause 0.01 second after printing a point
    pause(0.01);
    hold on;
end
axis([0, 100, 0, 100]);
xlabel('x');
ylabel('y');
title('Brownian motion');
legend('points');

% 2)
% initialize the first point
x1000(1) = 50;
y1000(1) = 50;
time2 = 1000;
% get the random route for 1000 times
x2 = randi([-1, 1], 1, time2);
y2 = randi([-1, 1], 1, time2);
for(i = 2:time2)
    x1000(i) = x1000(i - 1) + x2(i);
    y1000(i) = y1000(i - 1) + y2(i);
    % check if its larger than 100
    if (x1000(i) > 100)
        x1000(i) = 100 - (x1000(i) - 100);
    end
    % check if its larger than 100
    if (y1000(i) > 100)
        y1000(i) = 100 - (y1000(i) - 100);
    end
    % check if its smaller than 0
    if (x1000(i) < 0)
        x1000(i) = -x1000(i);
    end
    % check if its smaller than 0
    if (y1000(i) < 0)
        y1000(i) = -y1000(i);
    end
end
% plot the figure
figure(5)
for(i = 1:time2)
    plot(x1000(i), y1000(i), '^');
    % pause 0.01 second after printing a point
    pause(0.01);
    hold on;
end
axis([0, 100, 0, 100]);
xlabel('x');
ylabel('y');
title('Brownian motion');
legend('points');

% 3)
% initialize the first point
x10000(1) = 50;
y10000(1) = 50;
time3 = 10000;
% get the random route for 10000 times
x3 = randi([-1, 1], 1, time3);
y3 = randi([-1, 1], 1, time3);
for(i = 2:time3)
    x10000(i) = x10000(i - 1) + x3(i);
    y10000(i) = y10000(i - 1) + y3(i);
    % check if its larger than 100
    if (x10000(i) > 100)
        x10000(i) = 100 - (x10000(i) - 100);
    end
    % check if its larger than 100
    if (y10000(i) > 100)
        y10000(i) = 100 - (y10000(i) - 100);
    end
    % check if its smaller than 0
    if (x10000(i) < 0)
        x10000(i) = -x10000(i);
    end
    % check if its smaller than 0
    if (y10000(i) < 0)
        y10000(i) = -y10000(i);
    end
end
% plot the figure
figure(6)
for(i = 1:time3)
    plot(x10000(i), y10000(i), '^');
    % pause 0.01 second after printing a point
    pause(0.01);
    hold on;
end
axis([0, 100, 0, 100]);
xlabel('x');
ylabel('y');
title('Brownian motion');
legend('points');