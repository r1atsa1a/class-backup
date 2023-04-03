#include<windows.h>
#include<math.h>
using namespace std;

#define PI 3.1415926
#define HEIGHT 500
#define WEIGHT 1000
#define CIRCLE_NUM 12

POINTS points[CIRCLE_NUM];
double Heat[12][12] = {
    0.00, 0.85, 0.55, 0.68, 0.69, 0.88, 1.00, 1.11, 1.36, 1.38, 1.22, 0.89,
    0.85, 0.00, 0.57, 0.45, 0.51, 0.70, 0.80, 0.89, 1.09, 1.18, 1.09, 0.85,
    0.55, 0.57, 0.00, 0.17, 0.20, 0.37, 0.49, 0.54, 0.63, 0.69, 0.69, 0.57,
    0.68, 0.45, 0.17, 0.00, 0.21, 0.49, 0.61, 0.69, 0.82, 0.90, 0.91, 0.77,
    0.69, 0.51, 0.20, 0.21, 0.00, 0.44, 0.53, 0.62, 0.79, 0.91, 0.85, 0.72,
    0.88, 0.70, 0.37, 0.49, 0.44, 0.00, 0.58, 0.92, 1.02, 1.15, 1.13, 0.95,
    1.00, 0.80, 0.49, 0.61, 0.53, 0.58, 0.00, 1.22, 1.19, 1.24, 1.21, 1.08,
    1.11, 0.89, 0.54, 0.69, 0.62, 0.92, 1.22, 0.00, 0.64, 1.43, 1.32, 1.19,
    1.36, 1.09, 0.63, 0.82, 0.79, 1.02, 1.19, 0.64, 0.00, 1.67, 1.51, 1.36,
    1.38, 1.18, 0.69, 0.90, 0.91, 1.15, 1.24, 1.43, 1.67, 0.00, 1.27, 1.40,
    1.22, 1.09, 0.69, 0.91, 0.85, 1.13, 1.21, 1.32, 1.51, 1.27, 0.00, 1.50,
    0.89, 0.85, 0.57, 0.77, 0.72, 0.95, 1.08, 1.19, 1.36, 1.40, 1.50, 0.00 };
double Area[HEIGHT + 5][HEIGHT + 5];
double Heats[HEIGHT + 5][HEIGHT + 5];

void GetPoints(int Parameter) {
    POINT CenterPoint;
    CenterPoint.x = WEIGHT / 4 + Parameter * WEIGHT / 2;
    CenterPoint.y = HEIGHT / 2;
    double dblRadiusx = WEIGHT / 4, dblRadiusy = HEIGHT / 2;
    double dblAngle = 3 * PI / 2, dblDiff = 2 * PI / CIRCLE_NUM;
    for (int i = 0; i < CIRCLE_NUM; i++) {
        points[i].x = (int)(dblRadiusx * cos(dblAngle) + CenterPoint.x + 0.5);
        points[i].y = (int)(dblRadiusy * sin(dblAngle) + CenterPoint.y + 0.5);
        dblAngle += dblDiff;
    }
}

COLORREF GetColor(int i, int j) {
    int x = Heat[i][j] / 0.004;
    if (x <= 255) return RGB(255, x, 0);
    else return RGB(abs(2 * 255 - x), 255, 0);
}
COLORREF GetColor(double Heat) {
    int x = Heat / 0.004;
    if (x <= 255) return RGB(255, x, 0);
    else return RGB(abs(2 * 255 - x), 255, 0);
}

int F1(int x1, int y1, int x2, int y2, int v) {
    int ans = (double)(y2 - y1) / (x2 - x1) * (v - x1) + y1;
    return ans;
}
int F2(int x1, int y1, int x2, int y2, int v) {
    int ans = (double)(x2 - x1) / (y2 - y1) * (v - y1) + x1;
    return ans;
}

void LineHeats(int x1, int y1, int x2, int y2, double v) {
    if (x1 == x2) {
        for (int i = min(y1, y2); i <= max(y1, y2); i++) {
            Area[i][x1 - HEIGHT] = v;
        }
    }
    else if (y1 == y2) {
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            Area[y1][i - HEIGHT] = v;
        }
    }
    else {
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            int x = F1(x1, y1, x2, y2, i);
            Area[x][i - HEIGHT] = v;
        }
        for (int i = min(y1, y2); i <= max(y1, y2); i++) {
            int x = F2(x1, y1, x2, y2, i);
            Area[i][x - HEIGHT] = v;
        }
    }
}

void SetHeat() {
    double x;
    int stX, stY, edX, edY;
    memset(Area, 0, sizeof Area);
    for (int i = 0; i < CIRCLE_NUM; i++) {
        stX = points[i].x;
        stY = points[i].y;
        for (int j = 0; j < CIRCLE_NUM; j++) {
            if (i != j) {
                x = Heat[i][j];
                edX = points[j].x;
                edY = points[j].y;
                LineHeats(stX, stY, edX, edY, x);
            }
        }
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    double val;
    int radius = 50, cnt;
    
    HDC          hdc;
    RECT         rect;
    PAINTSTRUCT  ps;
    POINT        pt;
    HPEN         hPen;
    HBRUSH       hBrush;
    
    switch (message) {
    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc = BeginPaint(hwnd, &ps);
        
        GetPoints(0);
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
        hBrush = (HBRUSH)CreateSolidBrush(RGB(200, 200, 200));
        SelectObject(hdc, hPen), SelectObject(hdc, hBrush);
        Ellipse(hdc, 0, 0, WEIGHT / 2, HEIGHT);
        DeleteObject(hPen), DeleteObject(hBrush);
        for (int i = 0; i < CIRCLE_NUM; i++) {
            for (int j = 0; j < CIRCLE_NUM; j++) {
                if (i != j) {
                    hPen = CreatePen(PS_SOLID, 5, GetColor(i, j));
                    SelectObject(hdc, hPen);
                    MoveToEx(hdc, points[i].x, points[i].y, &pt);
                    LineTo(hdc, points[j].x, points[j].y);
                    DeleteObject(hPen);
                }
            }
        }
        
        GetPoints(1);
        SetHeat();
        for (int i = 0; i <= HEIGHT; i++) {
            for (int j = 0; j <= HEIGHT; j++) {
                if ((i - HEIGHT / 2) * (i - HEIGHT / 2) + (j - HEIGHT / 2) * (j - HEIGHT / 2) > HEIGHT * HEIGHT / 4) continue;
                val = 0; cnt = 0;
                for (int p = max(0, i - radius); p <= min(HEIGHT, i + radius); p++) {
                    for (int q = max(0, j - radius); q <= min(HEIGHT, j + radius); q++) {
                        if ((p - i) * (p - i) + (q - j) * (q - j) > radius * radius
                            || (p - HEIGHT / 2) * (p - HEIGHT / 2) + (q - HEIGHT / 2) * (q - HEIGHT / 2) > HEIGHT * HEIGHT / 4) continue;
                        if (Area[p][q]) {
                            val += Area[p][q];
                            cnt++;
                        }
                    }
                }
                Heats[i][j] = val / cnt;
            }
        }
        for (int i = 0; i <= HEIGHT; i++) {
            for (int j = 0; j <= HEIGHT; j++) {
                if ((i - HEIGHT / 2) * (i - HEIGHT / 2) + (j - HEIGHT / 2) * (j - HEIGHT / 2) > HEIGHT * HEIGHT / 4) continue;
                val = 0; cnt = 0;
                for (int p = max(0, i - radius); p <= min(HEIGHT, i + radius); p++) {
                    for (int q = max(0, j - radius); q <= min(HEIGHT, j + radius); q++) {
                        if ((p - i) * (p - i) + (q - j) * (q - j) > radius * radius
                            || (p - HEIGHT / 2) * (p - HEIGHT / 2) + (q - HEIGHT / 2) * (q - HEIGHT / 2) > HEIGHT * HEIGHT / 4) continue;
                        val += Heats[p][q];
                        cnt++;
                    }
                }
                SetPixel(hdc, i + HEIGHT, j, GetColor(val / (double)cnt));
            }
        }
        
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static char  szAppName[] = "HelloWin";
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;
    
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = (WNDPROC)WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    
    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, "This program requires Windows NT!", szAppName, MB_ICONERROR);
        return 0;
    }
    
    hwnd = CreateWindow(szAppName,
        "HeatMap-Like 2Ellipse | By Riatsala",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WEIGHT + 15, HEIGHT + 40, NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
