#include <iostream>
#include <string>
#include <list>
using namespace std;
class Stu {
    public:
        string name, id, tel, acd, major, grd;
        Stu(string _name, string _id, string _tel, string _acd, string _major, string _grd) {
            name = _name; id = _id;
            tel = _tel; acd = _acd;
            major = _major; grd = _grd;
        }
        void Disp() {
            cout << "name : " << name << '\n';
            cout << "id : " << id << '\n';
            cout << "tel : " << tel << '\n';
            cout << "acd : " << acd << '\n';
            cout << "major : " << major << '\n';
            cout << "grd : " << grd << '\n';
        }
};
list<Stu> ilist;
void Add(Stu _t) {
    ilist.push_back(_t);
}
void Query(string info) {
    bool is = 0;
    list<Stu>::iterator it;
    for (it = ilist.begin(); it != ilist.end(); ++ it) {
        if (it->name == info) {is = 1; it->Disp(); break;}
        if (it->id == info) {is = 1; it->Disp(); break;}
        if (it->tel == info) {is = 1; it->Disp(); break;}
        if (it->acd == info) {is = 1; it->Disp(); break;}
        if (it->major == info) {is = 1; it->Disp(); break;}
        if (it->grd == info) {is = 1; it->Disp();}
    }
    if (!is) cout << "未查询到该信息！" << '\n';
}
void Edit(string _id, Stu _t) {
    list<Stu>::iterator it;
    for (it = ilist.begin(); it != ilist.end(); ++ it) {
        if (it->id == _id) {
            it->name = _t.name; it->id = _t.id;
            it->tel = _t.tel; it->acd = _t.acd;
            it->major = _t.major; it->grd = _t.grd;
        }
    }
}
void Del(string _id) {
    list<Stu>::iterator it;
    for (it = ilist.begin(); it != ilist.end(); ++ it) {
        if (it->id == _id) {
            ilist.erase(it);
            break;
        }
    }
}
int main() {
    string t1_name = "名字", t1_id = "学号", t1_tel = "手机号", t1_acd = "学院", t1_major = "专业", t1_grd = "班级";
    Stu t1(t1_name, t1_id, t1_tel, t1_acd, t1_major, t1_grd);
    Add(t1);
    Query(t1_name);
    string t2_name = "修改后名字", t2_id = "修改后学号", t2_tel = "修改后手机号", t2_acd = "修改后学院", t2_major = "修改后专业", t2_grd = "修改后班级";
    Stu t2(t2_name, t2_id, t2_tel, t2_acd, t2_major, t2_grd);
    Add(t2);
    Edit("学号", t2);
    Query(t2_name);
    Del("修改后学号");
    Query(t2_name);
}