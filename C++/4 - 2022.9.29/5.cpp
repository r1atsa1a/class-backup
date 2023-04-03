#include <iostream>
#include <cstring>
using namespace std;
class Person {
    public:
        Person();
        Person(char *_name, char *_gender, char *_part, char *_tel, int _age);
        Person(const Person &t);
        ~Person();
        void Show();
    private:
        char name[20], gender[5], part[20], tel[20];
        int age;
};
Person::Person() {
    strcpy(name, "Mike");
    strcpy(gender, "Boy");
    strcpy(part, "1-1");
    strcpy(tel, "123456789");
    age = 18;
}
Person::Person(char *_name, char *_gender, char *_part, char *_tel, int _age) {
    strcpy(name, _name);
    strcpy(gender, _gender);
    strcpy(part, _part);
    strcpy(tel, _tel);
    age = _age;
}
Person::Person(const Person &t) {
    strcpy(name, t.name);
    strcpy(gender, t.gender);
    strcpy(part, t.part);
    strcpy(tel, t.tel);
    age = t.age;
}
Person::~Person() {
    
}
void Person::Show() {
    printf("name = %s\n", name);
    printf("age = %d\n", age);
    printf("gender = %s\n", gender);
    printf("part = %s\n", part);
    printf("tel = %s\n\n", tel);
}
int main() {
    Person t1;
    t1.Show();
    Person t2("Tony", "Boy", "1-2", "987654321", 20);
    t2.Show();
    Person t("Betty", "Girl", "1-3", "456987321", 17);
    Person t3(t);
    t3.Show();
    return 0;
}