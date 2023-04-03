#include<windows.h>

int i = 0;

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

void ShowNum(HDC hdc, int x1, int y1, int x2, int y2, int param) {
	int n;
	if (param == 0) {
		n = i / 60 / 10;
	} else if (param == 1) {
		n = i / 60 % 10;
	} else if (param == 2) {
		n = i % 60 / 10;
	} else if (param == 3) {
		n = i % 60 % 10;
	}
	if (n == 0) {
		Rectangle(hdc, x1, y1, x2, y2);
	} else if (n == 1) {
		MoveToEx(hdc, (x1 + x2) / 2, y1, NULL);
		LineTo(hdc, (x1 + x2) / 2, y2);
	} else if (n == 2) {
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y1);
		LineTo(hdc, x2, (y1 + y2) / 2);
		LineTo(hdc, x1, (y1 + y2) / 2);
		LineTo(hdc, x1, y2);
		LineTo(hdc, x2, y2);
	} else if (n == 3) {
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y1);
		LineTo(hdc, x2, y2);
		LineTo(hdc, x1, y2);
		MoveToEx(hdc, x2, (y1 + y2) / 2, NULL);
		LineTo(hdc, x1, (y1 + y2) / 2);
	} else if (n == 4) {
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x1, (y1 + y2) / 2);
		LineTo(hdc, x2, (y1 + y2) / 2);
		MoveToEx(hdc, (x1 + x2) / 2, y1, NULL);
		LineTo(hdc, (x1 + x2) / 2, y2);
	} else if (n == 5) {
		MoveToEx(hdc, x2, y1, NULL);
		LineTo(hdc, x1, y1);
		LineTo(hdc, x1, (y1 + y2) / 2);
		LineTo(hdc, x2, (y1 + y2) / 2);
		LineTo(hdc, x2, y2);
		LineTo(hdc, x1, y2);
	} else if (n == 6) {
		MoveToEx(hdc, x2, y1, NULL);
		LineTo(hdc, x1, y1);
		LineTo(hdc, x1, y2);
		LineTo(hdc, x2, y2);
		LineTo(hdc, x2, (y1 + y2) / 2);
		LineTo(hdc, x1, (y1 + y2) / 2);
	} else if (n == 7) {
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y1);
		LineTo(hdc, x2, y2);
	} else if (n == 8) {
		Rectangle(hdc, x1, y1, x2, y2);
		MoveToEx(hdc, x1, (y1 + y2) / 2, NULL);
		LineTo(hdc, x2, (y1 + y2) / 2);
	} else if (n == 9) {
		Rectangle(hdc, x1, y1, x2, (y1 + y2) / 2);
		MoveToEx(hdc, x2, (y1 + y2) / 2, NULL);
		LineTo(hdc, x2, y2);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	int margins = 20;
	int dis;

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

			hPen = CreatePen(PS_SOLID, 6, RGB(0, 255, 0));
			SelectObject(hdc, hPen);
			Rectangle(hdc, margins, margins, rect.right - margins, rect.bottom - margins);
			MoveToEx(hdc, rect.right / 2, margins, &pt);
			LineTo(hdc, rect.right / 2, rect.bottom - margins);

			dis = (rect.right - 2 * margins) / 4;
			for (int o = 0; o < 4; o ++) {
				ShowNum(hdc, 2 * margins + o * dis, 2 * margins, (o + 1) * dis, rect.bottom - 2 * margins, o);
			}

			EndPaint(hwnd, &ps);

			i ++;
			Sleep(1000);
			InvalidateRect(hwnd, NULL, 1);

			return 0;
		case WM_DESTROY:
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
