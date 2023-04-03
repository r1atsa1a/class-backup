#include<windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Pi 3.1415926

double dfRange = 100.0;
long i = 0, j = 0;
long lCentreX = 0, lCentreY = 0, lRadious = (long)(0.2 * dfRange);
POINT lpSin[100];

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

	for (int j = 0; j < 100; j++) {
		lpSin[j].x = (long)(j * 2 * Pi / 100 * 60);
		lpSin[j].y = (long)(dfRange * sin(j * 2 * Pi / 100));
	}

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	HBRUSH hBrush;
	HPEN hPen;
	PAINTSTRUCT PtStr;

	switch (message) {
		case WM_PAINT:
			hDC = BeginPaint(hwnd, &PtStr);
			SetWindowOrgEx(hDC, -200, -200, NULL);

			hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			SelectObject(hDC, hPen);

			Polyline(hDC, lpSin, 100);

			DeleteObject(hPen);

			if (i <= 25) {
				hPen = CreatePen(PS_DASH, 1, RGB(255, 0, 0));
				hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 0, 0));
				lRadious = (long)(dfRange * 0.2 + i % 25 * dfRange * 0.4 / 25);
			} else if (i <= 50) {
				hPen = CreatePen(PS_DASH, 1, RGB(0, 255, 0));
				hBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 0));
				lRadious = (long)(dfRange * 0.2 + i % 25 * dfRange * 0.4 / 25);
			} else if (i <= 75) {
				hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 255));
				hBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));
				lRadious = (long)(dfRange * 0.2 + i % 25 * dfRange * 0.4 / 25);
			} else {
				hPen = CreatePen(PS_DASH, 1, RGB(255, 255, 0));
				hBrush = CreateHatchBrush(HS_VERTICAL, RGB(255, 255, 0));
				lRadious = (long)(dfRange * 0.2 + i % 25 * dfRange * 0.4 / 25);
			}

			SelectObject(hDC, hBrush);
			SelectObject(hDC, hPen);

			lCentreX = lpSin[i].x;
			lCentreY = lpSin[i].y;
			Ellipse(hDC, lCentreX - lRadious, lCentreY - lRadious, lCentreX + lRadious, lCentreY + lRadious);


			DeleteObject(hPen);
			DeleteObject(hBrush);

			EndPaint(hwnd, &PtStr);

			i++;
			Sleep(100);
			if (i < 100) InvalidateRect(hwnd, NULL, 1);

			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return (DefWindowProc(hwnd, message, wParam, lParam));
	}
}
