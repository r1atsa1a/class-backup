#include<windows.h>

#define POINTS_NUM 1000

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
    static POINTS points[POINTS_NUM];
    static int nCnt;
    
    switch (message) {
    case WM_LBUTTONDOWN:
        nCnt = 0;
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
        
    case WM_MOUSEMOVE:
        if (wParam & MK_LBUTTON && nCnt < POINTS_NUM) {
            points[nCnt ++] = MAKEPOINTS(lParam);
            hdc = GetDC(hwnd);
            SetPixel(hdc, points[nCnt - 1].x, points[nCnt - 1].y, RGB(0, 0, 0));
            ReleaseDC(hwnd, hdc);
        }
        return 0;
        
    case WM_LBUTTONUP:
        InvalidateRect (hwnd, NULL, FALSE) ;
        return 0 ;
        
    case WM_PAINT:
        hdc     = BeginPaint (hwnd, &ps);
        
        hPen    = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        for (int i = 1; i < nCnt - 1; i ++) {
            MoveToEx(hdc, points[0].x, points[0].y, &pt);
            LineTo(hdc, points[i].x, points[i].y);
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
