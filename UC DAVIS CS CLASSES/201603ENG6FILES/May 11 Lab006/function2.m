function function2(x, A, B, C, D)
    figure(1); % Set new figrue
    plot(x, A, 'r', x, B, 'b', x, C, 'g', x, D, 'y'); % Draw plot
    xlabel('x'); % Set xlabel
    ylabel('y'); % Set ylabel
    title('Lab006 plot'); % Set title
    legend('A=sin(x)', 'B=cos(x)', 'C=sin(2x)', 'D=cos(2x)');
end