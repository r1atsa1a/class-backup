#include<windows.h>
#include<math.h>
#include<ctime>
#include<cstdlib>

#define FIELD_BACKGROUND_1 RGB(83, 163, 20)
#define FIELD_BACKGROUND_2 RGB(109, 173, 57)
#define WHITE RGB(255, 255, 255)
#define ARROW_GREEN RGB(87, 195, 194)
#define ARROW_YELLOW RGB(254, 204, 17)
#define ARROW_RED RGB(192, 44, 56)
#define ARROW_BLUE RGB(20, 74, 116)

void CreateArrow(HDC, int, int, int, int);

bool check(int, int);

int dis(int, int, int, int);

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
		"FootBall Field - By: Riatsala",         // window caption
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		867,                      // initial x size
		600,                      // initial y size
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
	int margins = 15;
	int radiusx = 80;
	int radiusy = 15;
	int radiusz = 6;
	int radiusi = 7;
	
	int num = 60;
	int start_x, start_y;
	int end_x, end_y;
	int color;
	
	HDC          hdc;
	RECT         rect;
	PAINTSTRUCT  ps;
	POINT        pt;
	HPEN         hPen;
	HBRUSH       hBrush;
	
	srand((unsigned int)time(0));
	
	switch (message) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		for (int i = 0; i < 16; i ++) {
			if (i & 1) {
				hPen    = CreatePen(PS_SOLID, 3, FIELD_BACKGROUND_2);
				hBrush  = (HBRUSH)CreateSolidBrush(FIELD_BACKGROUND_2);
			} else {
				hPen    = CreatePen(PS_SOLID, 3, FIELD_BACKGROUND_1);
				hBrush  = (HBRUSH)CreateSolidBrush(FIELD_BACKGROUND_1);
			}
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Rectangle(hdc, 0, i * 35, 850, (i + 1) * 35);
		}
		DeleteObject(hPen);
		DeleteObject(hBrush);
		
		hPen    = CreatePen(PS_SOLID, 3, WHITE);
		hBrush  = (HBRUSH)GetStockObject(NULL_BRUSH);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		
		Rectangle(hdc, margins, margins, 850 - margins, 560 - margins);
		Rectangle(hdc, margins, 280 - 150, margins + 120, 280 + 150);
		Rectangle(hdc, margins, 280 - 80, margins + 60, 280 + 80);
		Rectangle(hdc, 850 - margins - 120, 280 - 150, 850 - margins, 280 + 150);
		Rectangle(hdc, 850 - margins - 60, 280 - 80, 850 - margins, 280 + 80);
		
		MoveToEx(hdc, 425, margins, &pt);
		LineTo(hdc, 425, 560 - margins);
		
		Ellipse(hdc, 425 - radiusx, 280 - radiusx, 425 + radiusx, 280 + radiusx);
		
		DeleteObject(hPen);
		hPen = CreatePen(PS_SOLID, 2, WHITE);
		SelectObject(hdc, hPen);
		
		Pie(hdc, margins - radiusy, margins - radiusy, margins + radiusy, margins + radiusy, margins, margins + radiusy, margins + radiusy, margins);
		Pie(hdc, 850 - margins - radiusy, margins - radiusy, 850 - margins + radiusy, margins + radiusy, 850 - margins - radiusy, margins, 850 - margins, margins + radiusy);
		Pie(hdc, margins - radiusy, 560 - margins - radiusy, margins + radiusy, 560 - margins + radiusy, margins + radiusy, 560 - margins, margins, 560 - margins - radiusy);
		Pie(hdc, 850 - margins - radiusy, 560 - margins - radiusy, 850 - margins + radiusy, 560 - margins + radiusy, 850 - margins, 560 - margins - radiusy, 850 - margins - radiusy, 560 - margins);
		
		DeleteObject(hBrush);
		
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		SelectObject(hdc, hBrush);
		
		Ellipse(hdc, margins + 90 - radiusz, 280 - radiusz, margins + 90 + radiusz, 280 + radiusz);
		Ellipse(hdc, 425 - radiusz, 280 - radiusz, 425 + radiusz, 280 + radiusz);
		Ellipse(hdc, 850 - margins - 90 - radiusz, 280 - radiusz, 850 - margins - 90 + radiusz, 280 + radiusz);
		
		DeleteObject(hPen);
		hPen = CreatePen(PS_SOLID, 3, WHITE);
		SelectObject(hdc, hPen);
		Arc(hdc, margins + 60, 280 - 80, margins + 150, 280 + 80, margins + 120, 280 + 80, margins + 120, 280 - 80);
		Arc(hdc, 850 - margins - 150, 280 - 80, 850 - margins - 60, 280 + 80, 850 - margins - 120, 280 - 80, 850 - margins -  120, 280 + 80);
		
		DeleteObject(hPen);
		for (int i = 1; i <= num; i ++) {
			start_x  = (rand() % (830 - 20 + 1)) + 20;
			start_y  = (rand() % (540 - 20 + 1)) + 20;
			end_x    = (rand() % (830 - 20 + 1)) + 20;
			end_y    = (rand() % (540 - 20 + 1)) + 20;
			
			if (!check(start_x, start_y)) {
				i --;
				continue;
			}
			
			color = dis(start_x, start_y, end_x, end_y);
			if (color == 1) {
				hPen = CreatePen(PS_SOLID, 4, ARROW_GREEN);
			} else if (color == 2) {
				hPen = CreatePen(PS_SOLID, 4, ARROW_YELLOW);
			} else {
				hPen = CreatePen(PS_SOLID, 4, ARROW_RED);
			}
			
			SelectObject(hdc, hPen);
			CreateArrow(hdc, start_x, start_y, end_x, end_y);
			
			DeleteObject(hPen);
			DeleteObject(hBrush);
			hPen    = CreatePen(PS_SOLID, 2, WHITE);
			hBrush  = (HBRUSH)CreateSolidBrush(ARROW_BLUE);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x - radiusi, start_y - radiusi, start_x + radiusi, start_y + radiusi);
		}
		
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage (0);
		return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void CreateArrow(HDC hdc, int start_x, int start_y, int end_x, int end_y) {
	MoveToEx(hdc, start_x, start_y, NULL);
	LineTo(hdc, end_x, end_y);
	
	int tmp_x = end_x - start_x;
	int tmp_y = end_y - start_y;
	if (tmp_x > 0) {
		int x1 = end_x - 20 * cos(atan(tmp_y / (double)tmp_x) - acos(1.8 / 2));
		int y1 = end_y - 20 * sin(atan(tmp_y / (double)tmp_x) - acos(1.8 / 2));
		int x2 = end_x - 20 * cos(atan(tmp_y / (double)tmp_x) + acos(1.8 / 2));
		int y2 = end_y - 20 * sin(atan(tmp_y / (double)tmp_x) + acos(1.8 / 2));
		LineTo(hdc, x1, y1);
		MoveToEx(hdc, end_x, end_y, NULL);
		LineTo(hdc, x2, y2);
	} else {
		int x1 = end_x + 20 * cos(atan(tmp_y / (double)tmp_x) - acos(1.8 / 2));
		int y1 = end_y + 20 * sin(atan(tmp_y / (double)tmp_x) - acos(1.8 / 2));
		int x2 = end_x + 20 * cos(atan(tmp_y / (double)tmp_x) + acos(1.8 / 2));
		int y2 = end_y + 20 * sin(atan(tmp_y / (double)tmp_x) + acos(1.8 / 2));
		LineTo(hdc, x1, y1);
		MoveToEx(hdc, end_x, end_y, NULL);
		LineTo(hdc, x2, y2);
	}
}

bool check(int x, int y) {
	if (y < 280 - 150 || y > 280 + 150) return true;
	else {
		if (x > 120 + 15 && x < 850 - 15 - 120) return true;
		else return false;
	}
}

int dis(int start_x, int start_y, int end_x, int end_y) {
	int distance = sqrt((end_x - start_x) * (end_x - start_x) + (end_y - start_y) * (end_y - start_y));
	if (distance <= 400) return 1;
	else if (distance <= 600) return 2;
	else return 3;
}
