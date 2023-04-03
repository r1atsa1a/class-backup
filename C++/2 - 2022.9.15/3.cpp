#include <iostream>
using namespace std;
int level(int score) {
    switch (score / 10) {
        case 0: case 1: case 2: case 3: case 4: case 5: return 0;
        case 6: case 7: return 1;
        case 8: return 2;
        case 9: case 10: return 3;
    }
    return 0;
}
int main() {
    int lv;
    cout << "你考了几分？" << endl;
    lv = level(55);
    switch (lv) {
        case 0: printf("55分，鉴定为：差！\n"); break;
        case 1: printf("68分，鉴定为：中！\n"); break;
        case 2: printf("85分，鉴定为：良！\n"); break;
        case 3: printf("95分，鉴定为：优！\n"); break;
    }
    lv = level(68);
    switch (lv) {
        case 0: printf("55分，鉴定为：差！\n"); break;
        case 1: printf("68分，鉴定为：中！\n"); break;
        case 2: printf("85分，鉴定为：良！\n"); break;
        case 3: printf("95分，鉴定为：优！\n"); break;
    }
    lv = level(85);
    switch (lv) {
        case 0: printf("55分，鉴定为：差！\n"); break;
        case 1: printf("68分，鉴定为：中！\n"); break;
        case 2: printf("85分，鉴定为：良！\n"); break;
        case 3: printf("95分，鉴定为：优！\n"); break;
    }
    lv = level(95);
    switch (lv) {
        case 0: printf("55分，鉴定为：差！\n"); break;
        case 1: printf("68分，鉴定为：中！\n"); break;
        case 2: printf("85分，鉴定为：良！\n"); break;
        case 3: printf("95分，鉴定为：优！\n"); break;
    }
    return 0;
}