/*
 ID: nyyl1303
 TASK: test
 LANG: C++
 */

#include <iostream>
#include <cstring>
#define isleap(a) (a%4 == 0 && (a%100 != 0|| a%400 == 0))?1:0

using namespace std;

int main(void) {
    int monthindex[]={0,31,31,28,31,30,31,30,31,31,30,31,30};
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int last=3,n,week[7];
    memset(week, 0, sizeof(week));
    cin >> n;
    for (int year = 1900; year < 1900+n; year++) {
        if (isleap(year)) {
            monthindex[4] = 29;
        }
        for (int month = 1; month <= 12; month++) {
            last = (last + monthindex[month])%7;
            week[last]++;
        }
        monthindex[4] = 28;
    }
    cout << week[6];
    for (int i = 0; i <= 5; i++) {
        cout << " " << week[i];
    }
    cout << endl;
}