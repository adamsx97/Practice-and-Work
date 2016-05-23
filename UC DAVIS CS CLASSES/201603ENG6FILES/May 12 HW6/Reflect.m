function matrixReflect = Reflect(N)
    matrixReflect = zeros(N, N);
    for i = 2:N
        for j = 1:i - 1
             matrixReflect(i, j) = j;
        end
    end
    for i = 1 : N - 1
        for j = 1:N - i
             matrixReflect(i, i + j) = N - j - i + 1;
        end
    end
    for i = 1:N
        matrixReflect(i, i) = N + 1;
    end
end
