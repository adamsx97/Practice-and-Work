%ENG006 A07
%Chengeng Xiao
%SID: 913186040
%These programs solves 4 problems in HW4
%% Problem 1:
%1):
m = [2, 5, 10, 15, 20, 25, 30, 35, 40]; % Set list m
G = [5.7, 4.1, 3.3, 2.5, 2.1, 2.2, 1.7, 1.6, 1.3]; % Set list G

m1 = 1 ./ m; % Calculate 1/m
G1 = exp(G); % Make G expoent of e
coeffs = polyfit(m1, G1, 2); % Fit value into polymals
a = coeffs(1); % Get first coefficient
b = coeffs(2); % Get second coefficient
c = coeffs(3); % Get third coefficient
fprintf('Problem 1.1:\na is %f, b is %f, c is %f.\n',a, b, c); % Print with format

%2):
m21 = [1 : 1 : 60]; % Set month
m22 = 1 ./ m21; % Set 1 / month
G21 = polyval(coeffs, m22);
G22 = log(G21);

figure(1) % Set new figure
plot(m, G, 'o', m21, G22); % Draw plot
title('Problem 1.2: Curve of growth vs month & original data.'); % Set title
xlabel('month'); % Set label x
ylabel('Growth in cm'); % Set label y
legend('Original data', 'Curve of growth vs month'); % Set legend

%3):
G3 = log(polyval(coeffs, 1/100)); % Calculate growth at month 100
fprintf('Problem 1.3:\nThe estimated the growth at the 100th month is %f.\n', G3); % Print with format
%% Problem 2:
%1):
t = [0.04 0.08 0.12 0.17 0.43 0.48 0.53 0.58 0.64 0.67 0.75 0.92]; % Set list t
y = [0.59 0.95 0.96 0.25 0.16 0.95 0.89 0.31 -0.59 -0.89 -0.71 0.95]; % Set list y
x = [0 : 0.001 : 1]; % Set x
pp = spline(t, y, x);

figure(2); % Set new figure
plot(t, y, 'o', x, pp); % Draw plot
title('Problem 2.1: Plot of original data points and the interpolated curve.'); % Set title
xlabel('t'); % Set label x
ylabel('y'); % Set label y

%2):
pks = findpeaks(pp);

%% Problem 3:
fprintf('Answer the following questions with either Y for Yes or N for No.\n'); % Print with format
employed_cell = inputdlg('Are you employed?'); % Get employed cell string
employed = employed_cell{1}; % Get employed status
graduate_cell = inputdlg('Have you graduated from college in the past two years?'); % Get graduate cell string
graduate = graduate_cell{1}; % Get graduate status
if (graduate == 'Y' || employed == 'Y')
    fprintf('Problem 3:\nYou qualify for the special interest rate.\n'); % Print with format
else
    fprintf('Problem 3:\nYou do not qualify for the special interest rate.\n'); % Print with format
end
%% Problem 4:
%1):
x41(1) = 50;
y41(1) = 50;
x1 = randi([-1, 1], 1, 100);
y1 = randi([-1, 1], 1, 100);
for i = 2 : 1 : 100
    x41(i) = x41(i - 1) + x1(i);
    y41(i) = y41(i - 1) + y1(i);
    if x41(i) > 100
        x41(i) = 200 - x41(i);
    end
    
    if x41(i) < 0
        x41(i) = -x41(i);
    end
    
    if y41(i) > 100
        y41(i) = 200 - y41(i);
    end
    
    if y41(i) < 0
        y41(i) = -y41(i);
    end
end

figure(3) % Set new figure
for i = 1 : 1 : 100
    plot(x41(i), y41(i), '^');
    pause(0.01);
    hold on;
end % Draw plot 0.1 sec a dot

title('Problem 4.1: Brownian motion 100 times'); % Set title
axis([0, 100, 0, 100]); % Set axis
xlabel('x'); % Set label x
ylabel('y'); % Set label y

%2):
x42(1) = 50;
y42(1) = 50;
x2 = randi([-1, 1], 1, 1000);
y2 = randi([-1, 1], 1, 1000);
for i = 2 : 1 : 1000
    x42(i) = x42(i - 1) + x2(i);
    y42(i) = y42(i - 1) + y2(i);
    if x42(i) > 100
        x42(i) = 200 - x42(i);
    end
    
    if x42(i) < 0
        x42(i) = -x42(i);
    end
    
    if y42(i) > 100
        y42(i) = 200 - y42(i);
    end
    
    if y42(i) < 0
        y42(i) = -y42(i);
    end
end

figure(4) % Set new figure
for i = 1 : 1 : 1000
    plot(x42(i), y42(i), '^');
    pause(0.01);
    hold on;
end % Draw plot 0.1 sec a dot

title('Problem 4.2: Brownian motion 1000 times'); % Set title
axis([0, 100, 0, 100]); % Set axis
xlabel('x'); % Set label x
ylabel('y'); % Set label y

%3):
x43(1) = 50;
y43(1) = 50;
x3 = randi([-1, 1], 1, 10000);
y3 = randi([-1, 1], 1, 10000);
for i = 2 : 1 : 10000
    x43(i) = x43(i - 1) + x3(i);
    y43(i) = y43(i - 1) + y3(i);
    if x43(i) > 100
        x43(i) = 200 - x43(i);
    end
    
    if x43(i) < 0
        x43(i) = -x43(i);
    end
    
    if y43(i) > 100
        y43(i) = 200 - y43(i);
    end
    
    if y43(i) < 0
        y43(i) = -y43(i);
    end
end

figure(5) % Set new figure
for i = 1 : 1 : 10000
    plot(x43(i), y43(i), '^');
    pause(0.01);
    hold on;
end % Draw plot 0.1 sec a dot

title('Problem 4.3: Brownian motion 10000 times'); % Set title
axis([0, 100, 0, 100]); % Set axis
xlabel('x'); % Set label x
ylabel('y'); % Set label y

%4):