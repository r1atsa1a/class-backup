#include <windows.h>
#include <algorithm>
using namespace std;

#define DEFAULT_HEIGHT 650
#define DEFAULT_WIDTH  1200
#define ROW 5
#define COL 10

struct Node {
    int x, y;
    bool vis;
    COLORREF color;
} bricks[ROW * COL];

int score = 0;
bool start, failed, won;

int bricks_height = 28, bricks_width = 58;

int table_x, table_v;
int table_height = 22, table_width = 68;
bool table_left, table_right;

int ball_x, ball_y, ball_radius = 20;
int ball_vX, ball_vY;

char title[] = "BRICK-DESTORYER";
char win[]   = "ALL-KILLED!";
char fail[]  = "YOU-FAILED!";
char tryit[] = "<PRESS ANY KEY>";

COLORREF GetColor(int idx) {
    switch (idx) {
    case 0:
        return RGB(255, 0, 255);
    case 1:
        return RGB(0, 0, 205);
    case 2:
        return RGB(135, 206, 250);
    case 3:
        return RGB(0, 255, 255);
    case 4:
        return RGB(0, 255, 127);
    case 5:
        return RGB(173, 255, 47);
    case 6:
        return RGB(255, 255, 0);
    case 7:
        return RGB(255, 165, 0);
    case 8:
        return RGB(255, 0, 0);
    case 9:
        return RGB(255, 192, 203);
    }
    return RGB(0, 0, 0);
}

void InitGame() {
    for (int i = 0; i < ROW * COL; i++) {
        bricks[i].x = 60 + (i % COL) * 120;
        bricks[i].y = 30 + (i / COL) * 60;
        bricks[i].color = GetColor(i % COL);
        bricks[i].vis = false;
    }
    table_x = 600, table_v = 15;
    ball_x = table_x, ball_y = DEFAULT_HEIGHT - 160;
    ball_radius = 20;
    ball_vX = 5, ball_vY = 5;
    start = true;
    failed = false;
    won = false;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;
    POINT pt;
    HPEN hPen;
    HBRUSH hBrush;
    HFONT hF_title, hF_press;
    TEXTMETRIC tm;
    
    switch (message) {
    case WM_CREATE:
        GetClientRect(hwnd, &rect);
        InitGame();
        break;
        
    case WM_KEYDOWN:
        if (failed == true || won== true) {
            InitGame();
            break;
        }
        if (start == true) {
            start = false;
            break;
        }
        switch (wParam) {
        case VK_LEFT:
            table_left = true;
            break;
        case VK_RIGHT:
            table_right = true;
            break;
        }
        break;
        
    case WM_CHAR:
        if (wParam == 'a' || wParam == 'A') {
            table_left = true;
        } else if (wParam == 'd' || wParam == 'D') {
            table_right = true;
        }
        break;
        
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        
        hBrush = (HBRUSH)CreateSolidBrush(RGB(220, 220, 220));
        SelectObject(hdc, hBrush);
        Rectangle(hdc, 0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT - 40);
        DeleteObject(hBrush);
        
        hF_title = CreateFont(100,
            0, 0, 0,
            FW_HEAVY,
            0, 0, 0,
            ANSI_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "标题字体" );
        hF_press = CreateFont(40,
            0, 0, 0,
            FW_HEAVY,
            0, 0, 0,
            ANSI_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "描述字体" );
        
        score = 0;
        for (int i = 0; i < ROW * COL; i++) {
            if (!bricks[i].vis) {
                hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
                hBrush = (HBRUSH)CreateSolidBrush(bricks[i].color);
                SelectObject(hdc, hPen);
                SelectObject(hdc, hBrush);
                Rectangle(hdc, bricks[i].x - bricks_width, bricks[i].y - bricks_height, bricks[i].x + bricks_width, bricks[i].y + bricks_height);
                DeleteObject(hPen);
                DeleteObject(hBrush);
            } else score ++;
        }
        if (score == ROW * COL) won = true;
        
        if (table_left == true) {
            table_x = max(table_width + 2, table_x - table_v);
            table_left = false;
        } else if (table_right == true) {
            table_x = min(DEFAULT_WIDTH - table_width - 2, table_x + table_v);
            table_right = false;
        }
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
        hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 205));
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);
        Rectangle(hdc, table_x - table_width, DEFAULT_HEIGHT - 2 * table_height - 42, table_x + table_width, DEFAULT_HEIGHT - 42);
        DeleteObject(hPen);
        DeleteObject(hBrush);
        
        if (won == true) {
            SetTextColor(hdc, RGB(0, 255, 0));
            SetBkColor(hdc, RGB(0, 0, 0));
            SelectObject(hdc, hF_title);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 335, 150, win, strlen(win));
            DeleteObject(hF_title);
            
            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkColor(hdc, RGB(220, 220, 220));
            SelectObject(hdc, hF_press);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 440, 450, tryit, strlen(tryit));
            DeleteObject(hF_press);
            
            Sleep(100);
            InvalidateRect(hwnd, NULL, 1);
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        if (failed == true) {
            SetTextColor(hdc, RGB(255, 0, 0));
            SetBkColor(hdc, RGB(0, 0, 0));
            SelectObject(hdc, hF_title);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 320, 150, fail, strlen(fail));
            DeleteObject(hF_title);
            
            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkColor(hdc, RGB(220, 220, 220));
            SelectObject(hdc, hF_press);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 440, 450, tryit, strlen(tryit));
            DeleteObject(hF_press);
            
            Sleep(100);
            InvalidateRect(hwnd, NULL, 1);
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        if (start == true) {
            SetTextColor(hdc, RGB(255, 255, 255));
            SetBkColor(hdc, RGB(0, 0, 0));
            SelectObject(hdc, hF_title);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 175, 150, title, strlen(title));
            DeleteObject(hF_title);
            
            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkColor(hdc, RGB(220, 220, 220));
            SelectObject(hdc, hF_press);
            GetTextMetrics(hdc, &tm);
            TextOut(hdc, 440, 450, tryit, strlen(tryit));
            DeleteObject(hF_press);
            
            Sleep(100);
            InvalidateRect(hwnd, NULL, 1);
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
        hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);
        Ellipse(hdc, ball_x - ball_radius, ball_y - ball_radius, ball_x + ball_radius, ball_y + ball_radius);
        DeleteObject(hPen);
        DeleteObject(hBrush);
        
        if (ball_x >= table_x - table_width - ball_radius && ball_x <= table_x + table_width + ball_radius
            && ball_y >= DEFAULT_HEIGHT - 2 * table_height - 42 && ball_y <= DEFAULT_HEIGHT - 42) {
            ball_vX *= -1;
        } else if (ball_x >= table_x - table_width && ball_x <= table_x + table_width
            && ball_y >= DEFAULT_HEIGHT - 2 * table_height - ball_radius - 42 && ball_y <= DEFAULT_HEIGHT - 2 * table_height - 42) {
            ball_y = DEFAULT_HEIGHT - 2 * table_height - ball_radius - 42;
            ball_vY *= -1;
        } else {
            if (ball_x < ball_radius || ball_x > DEFAULT_WIDTH - ball_radius) {
                ball_vX *= -1;
            } else if (ball_y < ball_radius) {
                ball_vY *= -1;
            }
            for (int i = 0; i < ROW * COL; i++) {
                if (!bricks[i].vis) {
                    if (ball_x >= bricks[i].x - bricks_width - ball_radius && ball_x <= bricks[i].x + bricks_width + ball_radius
                        && ball_y >= bricks[i].y - bricks_height && ball_y <= bricks[i].y + bricks_height) {
                        bricks[i].vis = true;
                        ball_vX *= -1;
                    } else if (ball_x >= bricks[i].x - bricks_width && ball_x <= bricks[i].x + bricks_width
                        && ball_y >= bricks[i].y - bricks_height - ball_radius && ball_y <= bricks[i].y + bricks_height + ball_radius) {
                        bricks[i].vis = true;
                        ball_vY *= -1;
                    }
                }
            }
        }
        
        ball_x += ball_vX;
        ball_y += ball_vY;
        
        if (ball_y > DEFAULT_HEIGHT - 42) {
            failed = true;
        }
        
        Sleep(25);
        InvalidateRect(hwnd, NULL, 1);
        
        EndPaint(hwnd, &ps);
        return 0;
        
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static char szAppName[] = "HelloWin";
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;
    
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
        "Brick Destroyer | By Riatsala",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        DEFAULT_WIDTH + 18,
        DEFAULT_HEIGHT,
        NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}

