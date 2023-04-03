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
	                    WS_OVERLAPPEDWINDOW,      // window style
	                    CW_USEDEFAULT,            // initial x position
	                    CW_USEDEFAULT,            // initial y position
	                    CW_USEDEFAULT,            // initial x size
	                    CW_USEDEFAULT,            // initial y size
	                    NULL,                     // parent window handle
	                    NULL,                     // window menu handle
	                    hInstance,                // program instance handle
	                    NULL);                    // creation parameters

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
	POINT        points[16]  = {{401, 216}, {500, 200}, {800, 500}, {500, 800},
								{200, 500}, {710, 286}, {716, 707}, {285, 709},
								{293, 282}, {628, 228}, {783, 596}, {770, 369},
								{630, 770}, {384, 776}, {224, 618}, {228, 371}};

	switch (message) {
		case WM_PAINT:
			hdc = BeginPaint (hwnd, &ps);

			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			SelectObject(hdc, hPen);
			for (int i = 0; i < 16; i ++) {
				int x = points[i].x, y = points[i].y;
				for (int j = i + 1; j < 16; j ++) {
					MoveToEx(hdc, x, y, &pt);
					LineTo(hdc, points[j].x, points[j].y);
				}
			}
			DeleteObject(hPen);

			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
			SelectObject(hdc, hPen);
			for (int i = 0; i < 8; i ++) {
				for (int j = 0; j < 8; j ++) {
					int desL = 300 + i * 50;
					int desR = 300 + j * 50;
					MoveToEx(hdc, 1000, desL, &pt);
					LineTo(hdc, 1500, desR);
					int radius = 8;
					Ellipse(hdc, 1000 - radius, desL - radius, 1000 + radius, desL + radius);
					Ellipse(hdc, 1500 - radius, desR - radius, 1500 + radius, desR + radius);
				}
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
