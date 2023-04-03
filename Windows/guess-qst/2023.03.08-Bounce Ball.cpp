#include<windows.h>
#include<math.h>

#define  DEFAULT_HEIGHT  768
#define  DEFAULT_WIDTH   1024
#define  BALLS           10
#define  MAX_RADIUS      60
#define  MIN_RADIUS      40
#define  MAX_SPEED       6
#define  MIN_SPEED       1

class BALL {
public:
    int radius;
    int pos_x, pos_y;
    int vX, vY;
    COLORREF color;
    void init(int _radius, int _pos_x, int _pos_y, int _vX, int _vY, COLORREF _color) {
        radius = _radius;
        pos_x = _pos_x, pos_y = _pos_y;
        vX = _vX, vY = _vY;
        color = _color;
    }
};

BALL Ball[BALLS];

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC          hdc;
    RECT         rect;
    PAINTSTRUCT  ps;
    HBRUSH       hBrush;
    
    switch (message) {
    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc = BeginPaint(hwnd, &ps);
        
        for (int i = 0; i < BALLS; i ++) {
            hBrush = CreateSolidBrush(Ball[i].color);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, Ball[i].pos_x - Ball[i].radius,
                Ball[i].pos_y - Ball[i].radius,
                Ball[i].pos_x + Ball[i].radius,
                Ball[i].pos_y + Ball[i].radius);
            DeleteObject(hBrush);
            
            Ball[i].pos_x += Ball[i].vX;
            Ball[i].pos_y += Ball[i].vY;
            
            for (int o = 0; o < BALLS; o ++) {
                if (o == i) continue;
                int diffX = Ball[o].pos_x - Ball[i].pos_x;
                int diffY = Ball[o].pos_y - Ball[i].pos_y;
                double dis_now = sqrt(diffX * diffX + diffY * diffY);
                int dis_radius = Ball[o].radius + Ball[i].radius;
                if (dis_now <= (double)dis_radius) {
                    Ball[o].vX = -Ball[o].vX;
                    Ball[o].vY = -Ball[o].vY;
                    Ball[i].vX = -Ball[i].vX;
                    Ball[i].vY = -Ball[i].vY;
                }
            }
            
            if (Ball[i].pos_x - Ball[i].radius < 0) {
                Ball[i].pos_x = Ball[i].radius;
                Ball[i].vX = -Ball[i].vX;
            } else if (Ball[i].pos_x + Ball[i].radius > rect.right) {
                Ball[i].pos_x = rect.right - Ball[i].radius;
                Ball[i].vX = -Ball[i].vX;
            }
            
            if (Ball[i].pos_y - Ball[i].radius < 0) {
                Ball[i].pos_y = Ball[i].radius;
                Ball[i].vY = -Ball[i].vY;
            } else if (Ball[i].pos_y + Ball[i].radius > rect.bottom) {
                Ball[i].pos_y = rect.bottom - Ball[i].radius;
                Ball[i].vY = -Ball[i].vY;
            }
        }
        
        Sleep(10) ;
        InvalidateRect(hwnd, NULL, 1) ;
        
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage (0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static char  szAppName[] = "HelloWin";
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;
    
    wndclass.style          = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc    = (WNDPROC)WndProc;
    wndclass.cbClsExtra     = 0;
    wndclass.cbWndExtra     = 0;
    wndclass.hInstance      = hInstance;
    wndclass.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName   = NULL;
    wndclass.lpszClassName  = szAppName;
    
    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, "This program requires Windows NT!", szAppName, MB_ICONERROR);
        return 0;
    }
    
    hwnd = CreateWindow(szAppName,                // window class name
        "Bounce Ball | By Riatsala",    // window caption
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        DEFAULT_WIDTH,
        DEFAULT_HEIGHT,
        NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    for (int i = 0; i < BALLS; i ++) {
        int RADIUS = rand() % (MAX_RADIUS - MIN_RADIUS + 1) + MIN_RADIUS;
        int X = rand() % (DEFAULT_WIDTH  - RADIUS * 2 + 1) + RADIUS;
        int Y = rand() % (DEFAULT_HEIGHT - RADIUS * 2 + 1) + RADIUS;
        int vX = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        int vY = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        COLORREF COLOR = RGB(rand() % 256, rand() % 256, rand() % 256);
        Ball[i].init(RADIUS, X, Y, vX, vY, COLOR);
    }
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
