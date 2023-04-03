#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	static char  szAppName[] = "HelloWin" ;
	HWND         hwnd ;
	MSG          msg ;
	WNDCLASS     wndclass ;

	wndclass.style          = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc    = (WNDPROC)WndProc ;
	wndclass.cbClsExtra     = 0 ;
	wndclass.cbWndExtra     = 0 ;
	wndclass.hInstance      = hInstance ;
	wndclass.hIcon          = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor        = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground  = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName   = NULL ;
	wndclass.lpszClassName  = szAppName ;

	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, "This program requires Windows NT!", szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,                  // window class name
	                    "The Windows Program",      // window caption
	                    WS_OVERLAPPEDWINDOW,        // window style
	                    CW_USEDEFAULT,              // initial x position
	                    CW_USEDEFAULT,              // initial y position
	                    CW_USEDEFAULT,              // initial x size
	                    CW_USEDEFAULT,              // initial y size
	                    NULL,                       // parent window handle
	                    NULL,                       // window menu handle
	                    hInstance,                  // program instance handle
	                    NULL) ;                     // creation parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam ;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC          hdc;
	RECT         rect;
	PAINTSTRUCT  ps;
	POINT        pt;
	HPEN         hPen;

	switch (message) {
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rect);

			hPen = (HPEN)GetStockObject(BLACK_PEN);
			SelectObject(hdc, hPen);

			Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);

			hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
			SelectObject(hdc, hPen);

			MoveToEx(hdc, (rect.left + rect.right) / 2, rect.top, &pt);
			LineTo(hdc, rect.left, rect.bottom);
			LineTo(hdc, rect.right, rect.bottom);
			LineTo(hdc, (rect.left + rect.right) / 2, rect.top);

			DeleteObject(hPen);

			EndPaint (hwnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage (0) ;
			return 0 ;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
