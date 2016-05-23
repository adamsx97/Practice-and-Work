
%	Academic License

% Engineering 6 Introduction Demo Script
%
% This program, plots both a sine wave and a cosine 
% wave over one period (from 0 to 2*pi).
%
% Instruction: Replace quantities in <> with your information.
% 
% Eng 6, Spring 2016
% Name: <Chengeng Xiao>
% Student ID: <913186040>
% Lab Section: <A07>



%% Item 1: Good habits:
% Clear all defined variables from current Workspace
clear all; 

% Close any existing figures that are open
close all; 

% Clear the Command Window so it will be easy to locate the answers printed
% out from this program
clc;
disp('Cleared all defined variables, close all figures and clear the command window')


%% Item 2: Define the variable 't' to be an array that starts at 0 and ends at 2*pi with enough intermediate values so that the plots will look smooth. 

% The format used below is start:step_size:stop, so if there wasn't a major error
% here, the array t would contain all values starting from 0 to 2*pi in
% steps of 1/1000.
start = 0;
stop = 2*pi;
stepSize = 1/1000;   % Note Camel Case Naming convention
timeIncrement = start:stepSize:stop;
who

%% Item 3: Evaluate sine and cosine from 0 to 2*pi.
% Do so by using MatLab's built-in functions sin( ) and cos( );
sineValues = sin(timeIncrement);
cosValues = cos(timeIncrement);
who

%% Item 4: Create the figure and number it Figure 1.
figure(1);
% Item 5: Create and plot the sine and cosine functions.
plot(timeIncrement, sineValues);

% Use the command below to hold the current plot, so the next plot can be
% overlaid on top of it.
hold on

% Plot the cosine function using red dashed line
plot( timeIncrement, cosValues, 'r--');

%% Item 6: Add a title, axis labels and a legend.

% Adding a title
title('My first plot generated in ENG 6!')

% Adding axis labels
xlabel('t (radians)') % Note that it doesn't have to be 'tArray' on the plot.
ylabel('Sin(t) and Cos(t) (dimensionless)')

% Legend. Type the names of each line in the order that you plotted them,
% in this case, type 'Sin' before 'Cos'.
legend('Sin', 'Cos');

%% Item 7: Submitting the code onto SmartSite
% 
% Step 1: Login to smartsite.ucdavis.edu, and go to the ENG6 WIN 2013 page.
%
% Step 2: Click on Assignments on the left panel.
%
% Step 3: Click on Lab 1.
%
% Step 4: Attach your MATLAB code (the .m file, NOT .asv).
%
% Step 5: Check the honor pledge (the square checkbox).
%
% Step 6: Click Submit.
%
% Step 7: Look for the confirmation message on the webpage for successful submission.
%
% Step 8: Check your e-mail box for the confirmation e-mail from SmartSite.
%        DO NOT DELETE THIS E-MAIL UNTIL YOU'VE RECEIVED A GRADE FOR THE ASSIGNMENT
% 
% Step 9: Check Smartsite->Assignment->Lab 1 to see if attachment was
%        uploaded correctly. If not, submit again.