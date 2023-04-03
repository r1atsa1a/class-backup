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
	POINT ZZZ[22]    = {{118, 157}, {122, 147}, {127, 137}, {134, 132},
                        {137, 131}, {142, 129}, {198, 129}, {102, 269},
                        {224, 269}, {228, 253}, {231, 231}, {229, 231},
                        {225, 242}, {219, 251}, {210, 259}, {204, 261},
                        {201, 263}, {132, 263}, {228, 121}, {119, 121},
                        {117, 134}, {116, 157}};
	POINT GGG[47]    = {{445, 119}, {449, 119}, {452, 166}, {447, 165},
                        {442, 151}, {435, 141}, {425, 134}, {412, 127},
                        {392, 127}, {379, 131}, {363, 140}, {350, 159},
                        {344, 180}, {344, 202}, {346, 219}, {352, 231},
                        {361, 245}, {374, 256}, {389, 262}, {406, 263},
                        {418, 260}, {431, 256}, {431, 202}, {425, 195},
                        {412, 192}, {412, 188}, {470, 189}, {470, 191},
                        {460, 193}, {456, 201}, {454, 257}, {434, 268},
                        {411, 272}, {389, 271}, {354, 261}, {335, 246},
                        {321, 221}, {318, 197}, {322, 175}, {329, 157},
                        {341, 143}, {361, 126}, {392, 118}, {418, 119},
                        {436, 126}, {440, 127}, {445, 124}};
	POINT JJJ[25]    = {{587, 121}, {651, 121}, {651, 125}, {640, 126},
                        {630, 133}, {630, 235}, {627, 245}, {622, 255},
                        {611, 266}, {601, 271}, {585, 272}, {573, 266},
                        {569, 257}, {571, 249}, {576, 247}, {584, 245},
                        {590, 251}, {595, 261}, {601, 265}, {608, 259},
                        {610, 246}, {610, 134}, {603, 128}, {598, 125},
                        {587, 125}};
	POINT YYY[30]    = {{755, 121}, {820, 121}, {820, 125}, {808, 127},
                        {803, 133}, {804, 140}, {841, 196}, {877, 135},
                        {873, 129}, {869, 126}, {862, 125}, {862, 121},
                        {914, 121}, {914, 125}, {906, 127}, {896, 132},
                        {845, 208}, {845, 256}, {851, 264}, {859, 267},
                        {865, 266}, {865, 271}, {803, 271}, {803, 265},
                        {814, 267}, {822, 262}, {822, 209}, {774, 134},
                        {767, 128}, {755, 125}};
	double tmp_x = 0, tmp_y = 0;
	switch (message) {
		case WM_PAINT:
			hdc     = BeginPaint (hwnd, &ps);

			GetClientRect(hwnd, &rect);
			tmp_x = rect.right * 1.0 / 1000;
			tmp_y = rect.bottom * 1.0 / 1000;

			for (int i = 0; i < 22; i++) {
				ZZZ[i].x = (LONG) ZZZ[i].x * tmp_x;
				ZZZ[i].y = (LONG) ZZZ[i].y * tmp_y;
			}

			for (int i = 0; i < 47; i++) {
				GGG[i].x = (LONG) GGG[i].x * tmp_x;
				GGG[i].y = (LONG) GGG[i].y * tmp_y;
			}

			for (int i = 0; i < 25; i++) {
				JJJ[i].x = (LONG) JJJ[i].x * tmp_x;
				JJJ[i].y = (LONG) JJJ[i].y * tmp_y;
			}

			for (int i = 0; i < 30; i++) {
				YYY[i].x = (LONG) YYY[i].x * tmp_x;
				YYY[i].y = (LONG) YYY[i].y * tmp_y;
			}

			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);

			Polygon(hdc, ZZZ, 22);
			Polygon(hdc, GGG, 47);
			Polygon(hdc, JJJ, 25);
			Polygon(hdc, YYY, 30);

			DeleteObject(hBrush);

			EndPaint(hwnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
