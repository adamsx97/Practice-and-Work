% <ENG 6, SQ16 Lab 004>
% <Chengeng, Xiao>
% <913186040>
% <A07>
%% Problem 1:
avgEC = [200, 170, 150, 260, 120, 430, 300, 320, 340, 460, 310, 370, 380, 50, 430, 180, 400]; % Set Average Energy Consumed Each Month(kWh)
EG = 400; % Set energy generated every month (kWh)
RF = 25; % Set rental fee per month
SB = 5 * 0.01; % Set sold back price in Dollar per kWh

%a):
MR = 0; % Initialize monthly revenue
TEAFS = 0; % Initialize total energy available for sale
for i = 1 : 1: 17
    MR = MR + 25; % each customer’s rental fee is $25 per month
    TEAFS = EG - avgEC(i); % Calculate the total energy available for sale
    if (TEAFS > 0)
        MR = MR + 0.8 * TEAFS * SB; % 80% * total energy available for sale * cost per kWh
    end
end

fprintf('Problem 1.a:\nThe company’s total monthly revenue is %f.\n', MR); % Print with format

%b):
m = 0; % Initialize the month company getting profit
IC = 150000; % Set initial cost
while (IC > 0)
    m = m + 1; % Accumulate
    IC = IC - MR; % Calculate new balance
end

fprintf('Problem 1.b:\nIt takes %d months until the company breaks even.\n', m); % Print with format
