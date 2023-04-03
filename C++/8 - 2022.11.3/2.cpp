#include <iostream>
#include <string>
using namespace std;
class Student {
	public:
		Student(char *_name, char *_age, char *_from, char *_tel) {
			name = _name;
			age = _age;
			from = _from;
			tel = _tel;
		}
		void Disp() {
			cout << ">> 学生类" << '\n';
			cout << "姓名: " << name << '\n';
			cout << "年龄: " << age << '\n';
			cout << "籍贯: " << from << '\n';
			cout << "电话: " << tel << '\n' << '\n';
		}
		string name, age, from, tel;
};
class StuCollege : public Student {
	public:
		StuCollege(char *_name, char *_age, char *_from, char *_tel, char *_acd, char *_mjr, char *_dom, char *_grd) : Student(_name, _age, _from, _tel) {
			acd = _acd;
			mjr = _mjr;
			dom = _dom;
			grd = _grd;
		}
		void Disp() {
			cout << ">> 大学生类" << '\n';
			cout << "姓名: " << name << '\n';
			cout << "年龄: " << age << '\n';
			cout << "籍贯: " << from << '\n';
			cout << "学院: " << acd << '\n';
			cout << "专业: " << mjr << '\n';
			cout << "寝室: " << dom << '\n';
			cout << "年级: " << grd << '\n' << '\n';
		}
		string acd, mjr, dom, grd;
};
class StuZAFU : public StuCollege {
	public:
		StuZAFU(char *_name, char *_age, char *_from, char *_tel, char *_acd, char *_mjr, char *_dom, char *_grd, char *_sch) : StuCollege(_name, _age, _from, _tel, _acd, _mjr, _dom, _grd) {
			sch = _sch;
		}
		void Disp() {
			cout << ">> ZAFU学生类" << '\n';
			cout << "姓名: " << name << '\n';
			cout << "年龄: " << age << '\n';
			cout << "籍贯: " << from << '\n';
			cout << "学院: " << acd << '\n';
			cout << "专业: " << mjr << '\n';
			cout << "寝室: " << dom << '\n';
			cout << "年级: " << grd << '\n';
			cout << "校区: " << sch << '\n' << '\n';
		}
		string sch;
};
int main() {
	char t1_name[20] = "一个学生", t1_age[20] = "一个年龄", t1_from[20] = "一个籍贯", t1_tel[20] = "一个电话";
	Student t1(t1_name, t1_age, t1_from, t1_tel);
	t1.Disp();
	char t2_name[20] = "一个大学生", t2_age[20] = "一个年龄", t2_from[20] = "一个籍贯", t2_tel[20] = "一个电话", t2_acd[20] = "一个学院", t2_mjr[20] = "一个专业", t2_dom[20] = "一个寝室", t2_grd[20] = "一个年级";
	StuCollege t2(t2_name, t2_age, t2_from, t2_tel, t2_acd, t2_mjr, t2_dom, t2_grd);
	t2.Disp();
	char t3_name[20] = "一个ZAFU大学生", t3_age[20] = "一个年龄", t3_from[20] = "一个籍贯", t3_tel[20] = "一个电话", t3_acd[20] = "一个学院", t3_mjr[20] = "一个专业", t3_dom[20] = "一个寝室", t3_grd[20] = "一个年级", t3_sch[20] = "一个校区";
	StuZAFU t3(t3_name, t3_age, t3_from, t3_tel, t3_acd, t3_mjr, t3_dom, t3_grd, t3_sch);
	t3.Disp();
	return 0;
}
