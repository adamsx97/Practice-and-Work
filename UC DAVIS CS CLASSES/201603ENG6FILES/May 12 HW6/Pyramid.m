function matrixPyramid = Pyramid(N)
    matrixPyramid = zeros(N, 2 * N - 1);
    for i = 1:N
        for j = 0:i-1
            matrixPyramid(i, N - j) = j + 1;
            matrixPyramid(i, N + j) = j + 1;
        end
    end
end
