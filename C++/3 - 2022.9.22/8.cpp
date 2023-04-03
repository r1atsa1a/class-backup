#include <iostream>
#include <cstring>
using namespace std;
typedef struct student {
    int num;  	    //学号
    char name[20];  //姓名
    char gender;    //性别
    int age;        //年龄
    char addr[30];  //寝室
}stu;
void struct_swap(stu &x, stu &y) {
    int tn;
    char ts1[20], ts2, ts3[30];
    tn = x.num; x.num = y.num; y.num = tn;
    strcpy(ts1, x.name); strcpy(x.name, y.name); strcpy(y.name, ts1);
    ts2 = x.gender; x.gender = y.gender; y.gender = ts2;
    tn = x.age; x.age = y.age; y.age = tn;
    strcpy(ts3, x.addr); strcpy(x.addr, y.addr); strcpy(y.addr, ts3);
}
int main() {
    stu x1 = {101, "Mike", '1', 18, "201"};
    stu y1 = {102, "Tony", '0', 18, "202"};
    printf("x->%d %s %c %d %s\n", x1.num, x1.name, x1.gender, x1.age, x1.addr);
    printf("y->%d %s %c %d %s\n", y1.num, y1.name, y1.gender, y1.age, y1.addr);
    struct_swap(x1, y1);
    printf("x->%d %s %c %d %s\n", x1.num, x1.name, x1.gender, x1.age, x1.addr);
    printf("y->%d %s %c %d %s\n", y1.num, y1.name, y1.gender, y1.age, y1.addr);
    puts("");
    stu x2 = {103, "CPP", '1', 20, "203"};
    stu y2 = {104, "PY", '0', 20, "204"};
    printf("x->%d %s %c %d %s\n", x2.num, x2.name, x2.gender, x2.age, x2.addr);
    printf("y->%d %s %c %d %s\n", y2.num, y2.name, y2.gender, y2.age, y2.addr);
    struct_swap(x2, y2);
    printf("x->%d %s %c %d %s\n", x2.num, x2.name, x2.gender, x2.age, x2.addr);
    printf("y->%d %s %c %d %s\n", y2.num, y2.name, y2.gender, y2.age, y2.addr);
    puts("");
    stu x3 = {105, "iii", '1', 50, "205"};
    stu y3 = {106, "yyy", '0', 50, "206"};
    printf("x->%d %s %c %d %s\n", x3.num, x3.name, x3.gender, x3.age, x3.addr);
    printf("y->%d %s %c %d %s\n", y3.num, y3.name, y3.gender, y3.age, y3.addr);
    struct_swap(x3, y3);
    printf("x->%d %s %c %d %s\n", x3.num, x3.name, x3.gender, x3.age, x3.addr);
    printf("y->%d %s %c %d %s\n", y3.num, y3.name, y3.gender, y3.age, y3.addr);
    return 0;
}