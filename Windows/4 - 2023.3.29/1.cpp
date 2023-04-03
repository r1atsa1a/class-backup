#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;
    POINT pt;
    HPEN hPen;
    HBRUSH hBrush;
    
    static int color = 0;
    static bool _ctrl = false, _shift = false, _up = false;
    static char upup[] = "您按下了UP键！";
    static char ctrlctrl[] = "您按下了CTRL键！";
    
    switch (message) {
    case WM_KEYUP:
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_UP:
            _up = true;
            break;
        case VK_SHIFT:
            _shift = true;
            break;
        case VK_CONTROL:
            _ctrl = true;
            break;
        default:
            break;
        }
        break;
    case WM_CHAR:
        if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState('R')) {
            color = 4;
            _ctrl = false;
            break;
        }
        if ((wParam == 'b' || wParam == 'B') && _shift) {
            color = 5;
            _shift = false;
            break;
        }
        switch (wParam) {
        case 'R':
            color = 1;
            break;
        case 'G':
            color = 2;
            break;
        case 'B':
            color = 3;
            break;
        }
    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc = BeginPaint(hwnd, &ps);
        
        if (_up) {
            TextOut(hdc, rect.right / 2 - 20, rect.bottom / 2, upup, strlen(upup));
            _up = false;
        } else if (_ctrl) {
            TextOut(hdc, rect.right / 2 - 20, rect.bottom / 2, ctrlctrl, strlen(ctrlctrl));
            _ctrl = false;
        } else {
            switch (color) {
            case 1:
                hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
                break;
            case 2:
                hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
                break;
            case 3:
                hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
                break;
            case 4:
                hBrush = (HBRUSH)CreateSolidBrush(RGB(237, 111, 0));
                break;
            case 5:
                hBrush = (HBRUSH)CreateSolidBrush(RGB(128, 0, 128));
                break;
            }
            SelectObject(hdc, hBrush);
            Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
            DeleteObject(hBrush);
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
