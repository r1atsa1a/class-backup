#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;
    POINT pt;
    HPEN hPen;
    HBRUSH hBrush;
    HFONT hF;
    TEXTMETRIC tm;
    
    static int show_n, inum;
    static char num[] = "0123456789";
    static bool refresh_num = false;
    
    switch (message) {
    case WM_CREATE:
        SetTimer(hwnd, 1, 2000, NULL);
        
    case WM_KEYUP:
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_CHAR:
        switch (wParam) {
        case '0':
            inum = 0;
            break;
        case '1':
            inum = 1;
            break;
        case '2':
            inum = 2;
            break;
        case '3':
            inum = 3;
            break;
        case '4':
            inum = 4;
            break;
        case '5':
            inum = 5;
            break;
        case '6':
            inum = 6;
            break;
        case '7':
            inum = 7;
            break;
        case '8':
            inum = 8;
            break;
        case '9':
            inum = 9;
            break;
        }
        break;
    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc     = BeginPaint (hwnd, &ps);
        
        hF = CreateFont(300,
            0, 0, 0,
            FW_HEAVY,
            0, 0, 0,
            ANSI_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "字体" );
        SelectObject(hdc, hF);
        GetTextMetrics(hdc, &tm);
        
        if (refresh_num == true) {
            show_n = rand() % 10;
            SetTextColor(hdc, RGB(0, 0, 0));
            TextOut(hdc, rect.right / 2 - tm.tmAveCharWidth / 2, rect.bottom / 2 - tm.tmHeight / 2, num + show_n, 1);
            refresh_num = false;
        } else {
            if (inum == show_n) {
                SetTextColor(hdc, RGB(0, 0, 255));
            } else {
                SetTextColor(hdc, RGB(255, 0, 0));
            }
            TextOut(hdc, rect.right / 2 - tm.tmAveCharWidth / 2, rect.bottom / 2 - tm.tmHeight / 2, num + show_n, 1);
        }
        
        EndPaint(hwnd, &ps);
        return 0;
        
    case WM_TIMER:
        refresh_num = true;
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_DESTROY:
        KillTimer(hwnd, 1);
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
        "The Windows Program",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
