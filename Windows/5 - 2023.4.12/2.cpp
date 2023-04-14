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
    static RECT area;
    static bool DrawEllipse = false, DrawRect = false;
    
    switch (message) {
    case WM_LBUTTONDOWN:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        if (wParam & MK_CONTROL) {
            DrawEllipse = true;
            area.left = x;
            area.top = y;
        } else if (wParam & MK_SHIFT) {
            DrawRect = true;
            area.left = x;
            area.top = y;
        }
        break;
        
    case WM_LBUTTONUP:
        DrawEllipse = false;
        DrawRect = false;
        break;
        
    case WM_MOUSEMOVE:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        area.right = x;
        area.bottom = y;
        if (DrawEllipse || DrawRect) {
            InvalidateRect(hwnd, NULL, TRUE);
        }
        break;
        
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        
        hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        
        if (DrawEllipse) {
            Ellipse(hdc, area.left, area.top, area.right, area.bottom);
        } else if (DrawRect) {
            Rectangle(hdc, area.left, area.top, area.right, area.bottom);
        }
        
        DeleteObject(hPen);
        
        EndPaint(hwnd, &ps);
        return 0;
        
    case WM_DESTROY:
        PostQuitMessage (0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}
