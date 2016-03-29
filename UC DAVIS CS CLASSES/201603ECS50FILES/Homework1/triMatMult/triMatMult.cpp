// Author Chengeng Xiao 2016.03.28
// ECS50 HW1
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin1(argv[1]);
	ifstream fin2(argv[2]);
	int n, matA[100][100] = {{0}}, matB[100][100] = {{0}}, ans[100][100] = {{0}};
	fin1 >> n;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			fin1 >> matA[i][j];
	fin2 >> n;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			fin2 >> matB[i][j];

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			for (int k = 0; k < n; k++)
				ans[i][j] += matA[i][k] * matB[k][j];

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cout << ans[i][j] << " ";
	cout << endl;
	return 0;
} // main()