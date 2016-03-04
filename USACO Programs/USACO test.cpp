/*
 ID: nyyl1303
 TASK: test
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    int a,b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
