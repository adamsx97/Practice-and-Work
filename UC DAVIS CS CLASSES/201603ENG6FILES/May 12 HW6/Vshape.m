function matrixVshape = Vshape(N)
    matrixVshape = zeros(N, 2 * N - 1);
    for i = 1:N
        for j = 1:i
            matrixVshape(i, j) = j;
            matrixVshape(i, 2 * N - j) = j;
        end
    end
end
