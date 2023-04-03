#include <iostream>
#include <string>
using namespace std;
class Rectangle {
    public:
        Rectangle(int _x, int _y) {
            x = _x;
            y = _y;
        }
        int GetArea() {
            cout << "面积: " << x * y << '\n';
        }        
    private:
        int x, y;
};
class Desk {
    public:
        Desk(int _height) {
            height = _height;
        }
        int GetHeight() {
            cout << "高度: " << height << '\n';
        }        
    private:
        int height;
};
class RectDesk : public Rectangle, public Desk {
    public:
        RectDesk(int _x, int _y, int _height, char *_color) : Rectangle(_x, _y), Desk(_height) {
            color = _color;
        }
        void GetColor() {
            cout << "颜色: " << color << '\n' << '\n';
        }
    private:
        string color;
};
int main() {
    char t1_color[20] = "白色";
	RectDesk t1(2, 3, 4, t1_color);
    t1.GetArea();
    t1.GetHeight();
    t1.GetColor();
    char t2_color[20] = "灰色";
	RectDesk t2(3, 4, 5, t2_color);
    t2.GetArea();
    t2.GetHeight();
    t2.GetColor();
    char t3_color[20] = "黑色";
	RectDesk t3(4, 5, 6, t3_color);
    t3.GetArea();
    t3.GetHeight();
    t3.GetColor();
    return 0;
}
