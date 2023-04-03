#include <iostream>
#include <cstring>
using namespace std;
class Student {
    public:
        Student();
        Student(char *_name, char *_id, char *_aca, char *_major);
        Student(const Student &t);
        ~Student();
        void Edit(char *_name, char *_id, char *_aca, char *_major);
        char name[20], id[20];
        char aca[20], major[20];
};
Student::Student() {
    strcpy(name, "Mike");
    strcpy(id, "10001");
    strcpy(aca, "1-1");
    strcpy(major, "101");
}
Student::Student(char *_name, char *_id, char *_aca, char *_major) {
    strcpy(name, _name);
    strcpy(id, _id);
    strcpy(aca, _aca);
    strcpy(major, _major);
}
Student::Student(const Student &t) {
    strcpy(name, t.name);
    strcpy(id, t.id);
    strcpy(aca, t.aca);
    strcpy(major, t.major);
}
Student::~Student() {
    
}
void Student::Edit(char *_name, char *_id, char *_aca, char *_major) {
    strcpy(name, _name);
    strcpy(id, _id);
    strcpy(aca, _aca);
    strcpy(major, _major);
}
class StuRoom {
    public:
        StuRoom();
        StuRoom(char *_name, char *_tel, Student _stu[]);
        StuRoom(const StuRoom &t);
        ~StuRoom();
        void ChangeName(char *_name);
        void ChangeTel(char *_tel);
        void Display();
    private:
        char name[20], tel[20];
        Student stu[4];
};
StuRoom::StuRoom() {
    strcpy(name, "101");
    strcpy(tel, "101010101");
    Student _stu[4];
    for (int i = 0; i < 4; i ++) stu[i] = _stu[i];
}
StuRoom::StuRoom(char *_name, char *_tel, Student _stu[]) {
    strcpy(name, _name);
    strcpy(tel, _tel);
    for (int i = 0; i < 4; i ++) stu[i] = _stu[i];
}
StuRoom::StuRoom(const StuRoom &t) {
    strcpy(name, t.name);
    strcpy(tel, t.tel);
    for (int i = 0; i < 4; i ++) stu[i] = t.stu[i];
}
StuRoom::~StuRoom() {
    
}
void StuRoom::ChangeName(char *_name) {
    strcpy(name, _name);
}
void StuRoom::ChangeTel(char *_tel) {
    strcpy(tel, _tel);
}
void StuRoom::Display() {
    printf("name:%s tel:%s\n", name, tel);
    for (int i = 0; i < 4; i ++)
        printf("stu[%d] | name:%s id:%s academic:%s major:%s\n", i + 1, stu[i].name, stu[i].id, stu[i].aca, stu[i].major);
}
int main() {
    Student sarr[4];
    sarr[0].Edit("Jack1", "10001", "1-1", "101");
    sarr[1].Edit("Jack2", "10002", "1-2", "102");
    sarr[2].Edit("Jack3", "10003", "1-3", "103");
    sarr[3].Edit("Jack4", "10004", "1-4", "104");
    StuRoom t("205", "13579", sarr);
    t.Display();
    t.ChangeName("309");
    t.ChangeTel("2468X");
    t.Display();
    return 0;
}