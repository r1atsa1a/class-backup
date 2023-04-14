#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
        "The Windows Program",    // window caption
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,            // initial x position
        CW_USEDEFAULT,            // initial y position
        800,            // initial x size
        800,            // initial y size
        NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC          hdc;
    RECT         rect;
    PAINTSTRUCT  ps;
    POINT        pt;
    HPEN         hPen;
    HBRUSH       hBrush;
    GetClientRect(hwnd, &rect);
    
    static int x, y;
    static int vX = 3, vY = 3;
    static int radius = 30, type = 1;
    
    static int pos_x, pos_y;
    static bool CLK = false;
    
    switch (message) {
    case WM_CREATE:
        x = rect.right / 2;
        y = rect.bottom / 2;
        return 0;
        
    case WM_LBUTTONDOWN:
        pos_x = LOWORD(lParam);
        pos_y = HIWORD(lParam);
        CLK = true;
        InvalidateRect(hwnd, NULL, TRUE);
        break;
        
    case WM_PAINT:
        hdc = BeginPaint (hwnd, &ps);
        
        if (CLK == true) {
            if ((pos_x - x) * (pos_x - x) + (pos_y - y) * (pos_y - y) <= radius * radius) {
                type ++;
                if (type == 0 ||type == 4) type = 1;
            } else {
                type = -1;
            }
            CLK = false;
        }
        
        if (type == 1) {
            hBrush  = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
        } else if (type == 2) {
            hBrush  = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
        } else if (type == 3) {
            hBrush  = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
        } else if (type == -1) {
            hBrush  = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
        }
        SelectObject(hdc, hBrush);
        
        Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
        
        DeleteObject(hBrush);
        
        x += vX;
        y += vY;
        
        if (x < radius || x > rect.right - radius) vX *= -1;
        if (y < radius || y > rect.bottom - radius) vY *= -1;
        
        Sleep(25);
        InvalidateRect(hwnd, NULL, 1);
        EndPaint(hwnd, &ps);
        
        return 0;
    case WM_DESTROY:
        PostQuitMessage (0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}
