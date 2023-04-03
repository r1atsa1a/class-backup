#include <iostream>
#include <cstdlib>
using namespace std;
int solve() {
    int flag1 = 0, flag2 = 0;
    int sum1 = 0, sum2 = 0, i = 0;
    while (sum1 < 30 && sum2 < 30) {
        i ++;
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;
        if (flag1) sum1 += die1;
        if (flag2) sum2 += die2;
        if (die1 == 6) flag1 = 1;
        if (die2 == 6) flag2 = 1;
        printf("Round %d: 甲 %d vs %d 乙\n累计点数: 甲 %d vs %d 乙\n", i, die1, die2, sum1, sum2);
    }
    if (sum1 >= 30 && sum2 >= 30) return 0;
    else if (sum1 >= 30) return 1;
    else return 2;
}
int main() {
    int seed;
    seed = 5;
    srand(seed);
    switch (solve()) {
        case 0: cout << "平局！" << endl; break;
        case 1: cout << "The winner is 甲!" << endl; break;
        case 2: cout << "The winner is 乙!" << endl; break;
    }
    puts("");
    seed = 10;
    srand(seed);
    switch (solve()) {
        case 0: cout << "平局！" << endl; break;
        case 1: cout << "The winner is 甲!" << endl; break;
        case 2: cout << "The winner is 乙!" << endl; break;
    }
    puts("");
    seed = 15;
    srand(seed);
    switch (solve()) {
        case 0: cout << "平局！" << endl; break;
        case 1: cout << "The winner is 甲!" << endl; break;
        case 2: cout << "The winner is 乙!" << endl; break;
    }
    return 0;
}