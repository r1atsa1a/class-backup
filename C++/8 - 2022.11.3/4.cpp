#include <iostream>
#include <string>
using namespace std;
class Worker {
    public:
        Worker(char *_name, char *_age) {
            name = _name;
            age = _age;
        }
        void Disp() {
            cout << "姓名: " << name << '\n';
            cout << "年龄: " << age << '\n';
        }
        string name, age;
};
class Manager : virtual public Worker {
    public:
        Manager(char *_name, char *_age, char *_job, char *_part) : Worker(_name, _age) {
            job = _job;
            part = _part;
        }
        void Disp() {
            cout << "职务: " << job << '\n';
            cout << "部门: " << part << '\n';
        }
    private:
        string job, part;
};
class Designer : virtual public Worker {
    public:
        Designer(char *_name, char *_age, char *_pos, char *_major) : Worker(_name, _age) {
            pos = _pos;
            major = _major;
        }
        void Disp() {
            cout << "职称: " << pos << '\n';
            cout << "专业: " << major << '\n';
        }
    private:
        string pos, major;
};
class DesManager : public Manager, public Designer {
    public:
        DesManager(char *_name, char *_age, char *_job, char *_part, char *_pos, char *_major, char *_fare) : Worker(_name, _age), Manager(_name, _age, _job, _part), Designer(_name, _age, _pos, _major) {
            fare = _fare;
        }
        void Disp() {
            cout << "工资: " << fare << '\n' << '\n';
        }
    private:
        string fare;
};
int main() {
    char t1_name[25] = "一个名字 - Test<1>", t1_age[25] = "一个年龄 - Test<1>", t1_job[25] = "一个职务 - Test<1>", t1_part[25] = "一个部门 - Test<1>", t1_pos[25] = "一个职称 - Test<1>", t1_major[25] = "一个专业 - Test<1>", t1_fare[25] = "一个工资 - Test<1>";
	DesManager t1(t1_name, t1_age, t1_job, t1_part, t1_pos, t1_major, t1_fare);
    t1.Worker::Disp();
    t1.Manager::Disp();
    t1.Designer::Disp();
    t1.DesManager::Disp();
    char t2_name[25] = "一个名字 - Test<2>", t2_age[25] = "一个年龄 - Test<2>", t2_job[25] = "一个职务 - Test<2>", t2_part[25] = "一个部门 - Test<2>", t2_pos[25] = "一个职称 - Test<2>", t2_major[25] = "一个专业 - Test<2>", t2_fare[25] = "一个工资 - Test<2>";
	DesManager t2(t2_name, t2_age, t2_job, t2_part, t2_pos, t2_major, t2_fare);
    t2.Worker::Disp();
    t2.Manager::Disp();
    t2.Designer::Disp();
    t2.DesManager::Disp();
    char t3_name[25] = "一个名字 - Test<3>", t3_age[25] = "一个年龄 - Test<3>", t3_job[25] = "一个职务 - Test<3>", t3_part[25] = "一个部门 - Test<3>", t3_pos[25] = "一个职称 - Test<3>", t3_major[25] = "一个专业 - Test<3>", t3_fare[25] = "一个工资 - Test<3>";
	DesManager t3(t3_name, t3_age, t3_job, t3_part, t3_pos, t3_major, t3_fare);
    t3.Worker::Disp();
    t3.Manager::Disp();
    t3.Designer::Disp();
    t3.DesManager::Disp();
    return 0;
}
