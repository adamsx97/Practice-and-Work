%% ENG 6 SQ 2016 Project 1
% Chengeng, Xiao
% A07
% 913186040
% NULL, NULL
% NULL, NULL
%% Task 1:
clear all; % Clear any previous data
close all; %Close all previous figures
clc; % Clears the command window
load Abilene.mat; % Load the Abilene data

%% Task 2:
routerNum = length(city); % Get number of backbone routers
linkNum = length(LinkInfo); % Get number of links
fprintf('Task 2: In total, %d backbone routers and %d links are given in the database.\n', routerNum, linkNum); % Print with format

%% Task 3:
numS = 0;
initial = city(:,1); % Parse initial out
for i = 1:routerNum
	% Go through the whole city list
	if initial(i,1) == 'S'
		% Check if the initial is S
		numS = numS + 1; % if is then increase the accumulator 
	end
end
fprintf('Task 3: In total, %d cities in the database have names starting with the letter S.\n', numS); % Print with format


%% Task 4:
numLong = 0;
for i = 1:routerNum
	% Go through the whole city list
	buf = city(i,:); % Get the city name string
    buf = strtrim(buf); % Remove whitespace
	sizeCity = size(buf, 2); % Get the length of name of the city
	if sizeCity > 8
		% Check if length of the name is longer than 8
		numLong = numLong + 1; % if is then increase the accumulator 
	end
end
fprintf('Task 4: %d cities in the database have names longer than 8 characters.\n', numLong); % Print with format


%% Task 5:
sumAbilene_All = sum(Abilene_All, 2); % Calc sum of each link
indexSum = [1:144]; 
indexSum = indexSum';
sumCity(:, 1) = indexSum(:,1);
sumCity(:, 2) = sumAbilene_All;
% Put the sum with index in a matrix
sumCitySorted = sortrows(sumCity, 2); % Sort the matrix based on sum
i = 144; % Set index i at the largest sum index 144
count = 0; % Count the leagel pair found and printed
fprintf('Task 5: The top three demands sorted according to highest weekly average are:\n'); % Print with format
while count < 3
    curr = sumCitySorted(i, 1);
    depart = DemandPair(i, 1);
    arrival = DemandPair(i, 2);
    % Get current dpart and arrival city index
    if depart ~= arrival
        a = NodeNumber{depart};
        b = NodeNumber{arrival};
        % Get the name of depart and arrival city
        fprintf('%s to %s\n',a, b); % Print with format
        count = count + 1; % Increase number of leagal pair printed
    end
    i = i - 1;
end

%% Task 6:
idChichago = 0;
idSeattle = 0;
% Set initial value
for i = 1: routerNum
    if strcmp(NodeNumber{i}, 'Chicago')
        idChichago = i;
    end
    if strcmp(NodeNumber{i}, 'Seattle')
        idSeattle = i;
    end
end
if idChichago == 0 | idSeattle == 0
    error('Task 6: City not found!');
end
CtoSPair = (idSeattle - 1) * 12 + idChichago; % Calc the DemandPair number of Chichago to Seattle
sumWeek = [0,0,0,0];
for i = 1:2016
    sumWeek(1) = sumWeek(1) + Abilene_All(CtoSPair, i);
end

for i = 2017:4032
    sumWeek(2) = sumWeek(2) + Abilene_All(CtoSPair, i);
end

for i = 4033:6048
    sumWeek(3) = sumWeek(3) + Abilene_All(CtoSPair, i);
end

for i = 6049:8064
    sumWeek(4) = sumWeek(4) + Abilene_All(CtoSPair, i);
end
% Calc the sum of each week 
fprintf('Task 6: The average traffic from Chicago to Seattle was maximum during Week %d.\n', find(max(sumWeek))); % Print with format

%% Task 7:
reverseLinkInfo = [LinkInfo(:, 2) LinkInfo(:, 1) LinkInfo(:, 3)]; % Get the reverse LinkInfo
BiLinkInfo = [LinkInfo; reverseLinkInfo]; % Combine together
fprintf('Task 7:\n'); % Print with format
disp(BiLinkInfo); % Displag BiLinkInfo

%% Task 8:
AdjMat = zeros(routerNum); % Initialize a Adjacency matrix with all zero
for i = 1:linkNum*2
    AdjMat(BiLinkInfo(i, 1), BiLinkInfo(i, 2)) = 1; % Mark according to the BiLinkInfo
end
fprintf('Task 8:\n'); % Print with format
disp(AdjMat); % Display Adjacency matrix
if issymmetric(AdjMat)
    fprintf('It is symmetric.\n');
else
    fprintf('It is not symmetric.\n');
end

%% Task 9:
OSPFWeight = zeros(routerNum); % Initialize a OSPFWeight matrix with all zero
for i = 1:linkNum*2
    OSPFWeight(BiLinkInfo(i, 1), BiLinkInfo(i, 2)) = BiLinkInfo(i, 3); % Mark according to the BiLinkInfo
end
figure(1); % Set new figure
imagesc(OSPFWeight); % Draw the plot
colorbar; % Add colorbar
set(gca, 'XTick', [1:12]); % Set tick number
set(gca, 'YTick', [1:12]); % Set tick number
set(gca, 'XTickLabel', city); % Set tick
set(gca, 'YTickLabel', city); % Set tick
set(gca, 'XTickLabelRotation', 90); % Rotate it
title('Task 9: OSPF Weights'); % Add title

%% Task 10:
figure(2); % Set new figure
gplot(AdjMat, fliplr(coordinates(:, 2:3)), '-sb'); % Draw the lines in blue
hold on; % hold plot
gplot(AdjMat, fliplr(coordinates(:, 2:3)), 'sr'); % Draw the dots in red
title('Task 10: Abilene Topology'); % Add title
coordinates1 = fliplr(coordinates); % Calc the fliped matrix
text(coordinates1(1, 1), coordinates1(1, 2), ' Atlanta', 'HorizontalAlignment', 'left');
text(coordinates1(2, 1), coordinates1(2, 2), ' Atlanta2    ', 'HorizontalAlignment', 'right');
text(coordinates1(3, 1), coordinates1(3, 2), ' Chicago', 'HorizontalAlignment', 'left');
text(coordinates1(4, 1), coordinates1(4, 2), ' Denver', 'HorizontalAlignment', 'left');
text(coordinates1(5, 1), coordinates1(5, 2), ' Houston', 'HorizontalAlignment', 'left');
text(coordinates1(6, 1), coordinates1(6, 2), ' Indianapolis', 'HorizontalAlignment', 'left');
text(coordinates1(7, 1), coordinates1(7, 2), ' Kansas City', 'HorizontalAlignment', 'left');
text(coordinates1(8, 1), coordinates1(8, 2), ' Los Angeles', 'HorizontalAlignment', 'left');
text(coordinates1(9, 1), coordinates1(9, 2), ' New York', 'HorizontalAlignment', 'left');
text(coordinates1(10, 1), coordinates1(10, 2), ' Sunnyvale', 'HorizontalAlignment', 'left');
text(coordinates1(11, 1), coordinates1(11, 2), ' Seattle', 'HorizontalAlignment', 'left');
text(coordinates1(12, 1), coordinates1(12, 2), ' Washington', 'HorizontalAlignment', 'left');
% Add the name of cities to the plot

%% Task 11:
prompt = 'Task 11:\nEnter the first node: '; % Set prompt
s = input(prompt, 's');
for i = 1:12
    if(strcmpi(NodeNumber(i, 1),s))
        s = i;
        break;
    end
end
% Get source city
prompt = 'Enter the second node: '; % Set prompt
d = input(prompt, 's');
for i = 1:12
    if(strcmpi(NodeNumber(i, 1),d))
        d = i;
        break;
    end
end
% Get destiny city
L = dijkstra(OSPFWeight,s,d); % Get the lane
fprintf('The shortest path for given pair of nodes is: %s', NodeNumber{L(1)}); % Print with fotmat
for i = 2:length(L)
    fprintf(' > %s', NodeNumber{L(i)}); % Print with fotmat
end
fprintf('.\n'); % Print with fotmat

cost = 0; % Initialize cost
for i = 1:length(L)-1
    cost = cost + OSPFWeight(L(i), L(i + 1)); % Calc cost
end
fprintf('The cost of the path is: %d.\n', cost); % Print with fotmat

%% Task 12:
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Sunnyvale'))
        SunnyvaleID = i;
        break;
    end
end
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Seattle'))
        SeattleID = i;
        break;
    end
end
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Houston'))
        HoustonID = i;
        break;
    end
end
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Denver'))
        DenverID = i;
        break;
    end
end
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Indianapolis'))
        IndianapolisID = i;
        break;
    end
end
for i = 1:12
    if(strcmpi(NodeNumber(i, 1), 'Kansas'))
        KansasID = i;
        break;
    end
end

%% Task 13: