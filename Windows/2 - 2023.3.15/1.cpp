#include<windows.h>

int i = 1;

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

	switch (message) {
		case WM_PAINT:
			GetClientRect(hwnd, &rect);
			hdc = BeginPaint (hwnd, &ps);

			if (i == 1) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
			} else if (i == 2) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 125, 0));
			} else if (i == 3) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
			} else if (i == 4) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
			} else if (i == 5) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 255));
			} else if (i == 6) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
			} else if (i == 7) {
				hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
			}

			SelectObject(hdc, hBrush);

			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

			DeleteObject(hBrush);

			EndPaint(hwnd, &ps);

			i ++;
			if (i == 8) i = 1;
			Sleep(500);
			InvalidateRect(hwnd, NULL, 1);

			return 0;
		case WM_DESTROY:
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
