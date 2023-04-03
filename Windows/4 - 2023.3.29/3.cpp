#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;
    POINT pt;
    HPEN hPen;
    HBRUSH hBrush;
    
    int speed = 10, radius = 20;
    static int x, y;
    static bool up, down, left, right;
    
    switch (message) {
    case WM_CREATE:
        GetClientRect(hwnd, &rect);
        x = rect.right / 2;
        y = rect.bottom / 2;
    case WM_KEYUP:
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_UP:
            up = true;
            break;
        case VK_DOWN:
            down = true;
            break;
        case VK_LEFT:
            left = true;
            break;
        case VK_RIGHT:
            right = true;
            break;
        }
        break;
        
    case WM_CHAR:
        if (wParam == 'w' || wParam == 'W') {
            up = true;
        } else if (wParam == 's' || wParam == 'S') {
            down = true;
        } else if (wParam == 'a' || wParam == 'A') {
            left = true;
        } else if (wParam == 'd' || wParam == 'D') {
            right = true;
        }
        break;
        
    case WM_PAINT:
        hdc     = BeginPaint (hwnd, &ps);
        
        if (up) {
            y -= speed;
            if (left) {
                x -= speed;
            } else if (right) {
                x += speed;
            }
        } else if (down) {
            y += speed;
            if (left) {
                x -= speed;
            } else if (right) {
                x += speed;
            }
        } else if (left) {
            x -= speed;
            if (up) {
                y -= speed;
            } else if (down) {
                y += speed;
            }
        } else if (right) {
            x += speed;
            if (up) {
                y -= speed;
            } else if (down) {
                y += speed;
            }
        }
        up = down = left = right = false;
        
        hPen    = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
        hBrush  = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);
        
        Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
        
        DeleteObject(hPen);
        DeleteObject(hBrush);
        
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
