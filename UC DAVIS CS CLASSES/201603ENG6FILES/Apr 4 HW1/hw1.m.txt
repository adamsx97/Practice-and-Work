
%	Academic License

% Engineering 006 Homework
%
% These programs, solves the 5 problems in homework 1 prompt.
% 
% Eng 6, Spring 2016
% Name: <Chengeng Xiao>
% Student ID: <913186040>
% Lab Section: <A07>

%% Problem 1
angleAd = 51; % angle A in degree
angleBd = 45; % angle B in degree
angleCd = 180 - angleAd - angleBd; % Calculate angle C
lengthAB = 7; % length of AB
lengthBC = lengthAB / sind(angleCd) * sind(angleAd); % Calculate length of bc 
areaTriangle = 0.5 * lengthAB * lengthBC * sind(angleBd); % calculate the area
fprintf('Problem 1:\nThe length of side BC is %f.\nThe area of the triangle is %f.\n'...
    , lengthBC, areaTriangle); % print with format
%% Problem 2
area = 9930 * (5280 ^ 2) * (12 ^ 2); % The area of the lake in in^2.
height = 1; % The height increased.
volume = area * height; % Calculate volume increased, in in^3.
volumeG = volume / 231;  % Change volume into US gallons
volumeL = volume / 231 * 3.785; % Change volume in in^3 into Liters.
fprintf('Problem 2:\n%f US gallons of rains have been added to the Lake''s volume.\nIn liters, it is %f liters.\n'...
    , volumeG, volumeL); % print with format
%% Problem 3
x = pi / 3; % set variable x
aLeft = tan(x)^2 + 1 + tan(x) * sec(x); % Calculate the left side of equation a.
aRight = (1 + sin(x)) / (cos(x)^2); % Calculate the right side of equation a.
if logical(aLeft == aRight) == 1
    fprintf('Problem 3:\nThe equation A has its left side equal to right side.\n'); % print with format
else
    fprintf('Problem 3:\nThe equation A has its left side not equal to right side.\n'); % print with format
end
bLeft = tan(x / 2); % Calculate the left side of equation b.
bRight = sin(x) / (1 + cos(x)); % Calculate the right side of equation b.
if logical(bLeft == bRight) == 1
    fprintf('The equation B has its left side equal to right side.\n'); % print with format
else
    fprintf('The equation B has its left side not equal to right side.\n'); % print with format
end
%% Problem 4
radius = 3 / 2 / 12; % Calculate radius into feets
height = 9 / 12; % Change height into feets
volume = (1 / 3) * pi * (radius ^ 2) * height + 2 / 3 * pi * (radius ^ 3); % Calculate the volume.
volumeG = volume / 0.115; % Change volume into Gallon.
weight = volumeG * 10; % Calculate the weight of the ice cream.
fprintf('Problem 4:\nThe weight of the ice cream is %f lbs.\n', weight); % print with format
%% Problem 5
d1 = 228; % top diameter.
d2 = 1799; % bottom diameter.
h = 1841; % height of the volcano.
density = 2670; % density of volcanic rock.
rt = d1 / 2; % top radius.
rb = d2 / 2; % bottom radius.
volume = pi * h / 3 * ((rt ^ 2) + (rb ^ 2) + rt * rb) - 2 / 3 * pi * (rt ^ 3); % Calculate the volume of the volcano
mass = volume * density; % Calculate the mass.
fprintf('Problem 5:\nThe volume of the volcano is %fm^3, and the mass is %fkg.\n', volume, mass); % print with format