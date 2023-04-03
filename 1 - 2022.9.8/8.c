#include <stdio.h>
#include <string.h>
int n;
struct student {
    char name[15];
    double math;
}stu[50];
double average() {
    double sum = 0;
    for (int i = 0; i < n; i ++) sum += stu[i].math;
    sum /= 1.0 * n;
    return sum;
}
int main() {
    // x 80
    // y 90
    n = 2;
    strcpy(stu[0].name, "x"); strcpy(stu[1].name, "y");
    stu[0].math = 80; stu[1].math = 90;
    printf("%.2lf\n", average());
    // mike 85.5
    // tony 100
    n = 2;
    strcpy(stu[0].name, "mike"); strcpy(stu[1].name, "tony");
    stu[0].math = 85.5; stu[1].math = 100;
    printf("%.2lf\n", average());
    // man 60
    // woman 85.5
    n = 2;
    strcpy(stu[0].name, "man"); strcpy(stu[1].name, "woman");
    stu[0].math = 60; stu[1].math = 85.5;
    printf("%.2lf\n", average());
    return 0;
}