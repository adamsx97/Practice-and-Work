% <Chengeng, Xiao>
% <913186040>
% <A07>
%% Part 1:
% 1.
baboon = imread('baboon.png'); % Use the imread() command to load ‘baboon.png’ into a matrix. 

% 2.a Swap Red with Blue
swapRwB = baboon;
temp = swapRwB(:,:,1);
swapRwB(:,:,1) = swapRwB(:,:,3);
swapRwB(:,:,3) = temp;

% 2.a Swap Blue with Green
swapBwG = baboon;
temp = swapBwG(:,:,2);
swapBwG(:,:,2) = swapBwG(:,:,3);
swapBwG(:,:,3) = temp;

% 2.a Swap Red with Green
swapRwG = baboon;
temp = swapRwG(:,:,1);
swapRwG(:,:,1) = swapRwG(:,:,2);
swapRwG(:,:,2) = temp;

%Use the subplot() command to place all of the images on the same figure.
figure(1);
subplot(1,3,1);
imshow(swapRwB);
title('Swap R w/ B');
hold on;

subplot(1,3,2);
imshow(swapBwG);
title('Swap G w/ B');
hold on;

subplot(1,3,3);
imshow(swapRwG);
title('Swap R w/ G');
hold off;

%% Part 2:
% 1. Create ? and ? variables based on the following information:
% x ? [?2, 2]
% y ? [?1, 1]
% Both arrays, x and y, should contain 40 elements. 
x = linspace(-2, 2, 40);
y = linspace(-1, 1, 40);

% 2. Define the following planes
[x1, y1] = meshgrid(x, y);
z1 = x1 + y1;
z2 = x1 - y1;

% 3. Overlay both plots on the same graph using the hold command. Your final plot should contain two
% planes that intersect each other and appear as shown below. 
figure(2);
mesh(x1, y1, z1);
hold on;
mesh(x1, y1, z2);
hold off;
title('Lab7 Part2.c');
xlabel('x');
ylabel('y');
zlabel('z');