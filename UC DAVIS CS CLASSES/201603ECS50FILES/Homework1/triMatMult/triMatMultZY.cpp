#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int tran(int size, int x, int y)
{
    int index = 0;
    if (x == 0)
        return y;
    for (int i = 0; i < x; i++)
        index += size - i;
    return index + y - x;
}

int main(int argc, char* argv[])
{
    ifstream fin1(argv[1]);
	ifstream fin2(argv[2]);

    int n = 0, num = 0;
    int i, j, k;
    int valueA = 0, valueB = 0;

    fin1 >> n;
    for (i = 1; i <= n; i++)
    	num = num + i;

    int *matrixA = new int[num], *matrixB = new int[num], *matrixC = new int[num];
    memset(matrixC, 0, sizeof(int) * num + 2);

    for (i = 0; i < num; i++)
    	fin1 >> matrixA[i];

    fin2 >> n;
    for (i = 0; i < num; i++)
    	fin2 >> matrixB[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (i > j) break;

                if (k < i) valueA = 0;
                else
                    valueA = matrixA[tran(n, i, k)];

                if (j <= k - 1) valueB = 0;
                else
                    valueB = matrixB[tran(n, k, j)];

                matrixC[tran(n, i, j)] += valueA * valueB;
            }
        }
    }

    for (int i = 0; i < num; i++)
    	cout << matrixC[i] << endl;

    delete [] matrixA;
    delete [] matrixB;
    delete [] matrixC;

	return 0;
}