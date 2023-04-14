#include<windows.h>
#include<cstdio>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static char  szAppName[] = "HelloWin";
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;
    
    wndclass.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
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
        CW_USEDEFAULT,            // initial x size
        CW_USEDEFAULT,            // initial y size
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
    
    static int x, y;
    static char str[100], num[15];
    static bool lB, rB, lDB;
    
    switch (message) {
    case WM_CREATE:
        lB = false, rB = false, lDB = false;
    case WM_MOUSEMOVE:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_LBUTTONDBLCLK:
        lDB = true;
        break;
    case WM_LBUTTONDOWN:
        lB = true;
        break;
    case WM_RBUTTONDOWN:
        rB = true;
        break;
    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc = BeginPaint (hwnd, &ps);
        
        if (lB) {
            sprintf(str, "你在坐标[                ]处单击了左键\0");
            lB = false;
        } else if (rB) {
            sprintf(str, "你在坐标[                ]处单击了右键\0");
            rB = false;
        } else if (lDB) {
            sprintf(str, "你在坐标[                ]处双击了左键\0");
            lDB = false;
        }
        sprintf(num, "%d,%d\0", x, y);
        TextOut(hdc, rect.right / 2 - 50, rect.bottom / 2 - 10, str, lstrlen(str));
        TextOut(hdc, rect.right / 2 + 15, rect.bottom / 2 - 10, num, lstrlen(num));
        
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage (0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}
