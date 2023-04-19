#include<windows.h>
#include<string>
#include<unordered_map>
using namespace std;

#define BOARD_SIZE 15

/*
  MODE:
  [1]Player VS PC
  [2]Player VS Player
  INFO:
  [+1]Black
  [-1]White/PC
 */

int mode, now, who;
int ChessBoard[BOARD_SIZE + 1][BOARD_SIZE + 1];
char singlePlayer[] = "[1]人机对战";
char doublePlayer[] = "[2]玩家对战";
char title[] = "GOBANG";
char black[] = "BLACK WON!";
char white[] = "WHITE WON!";
unordered_map<string, int> scoreMap;
bool winner, menu;

void InitGame() {
    now = 1;
    who = 0;
    menu = true;
    winner = false;
    
    scoreMap["11111"]  = 50000; scoreMap["11110"]  = 720;
    scoreMap["01111"]  = 720;   scoreMap["11011"]  = 720;
    scoreMap["10111"]  = 720;   scoreMap["11101"]  = 720;
    
    scoreMap["001100"] = 120;   scoreMap["001010"] = 120;
    scoreMap["010100"] = 120;   scoreMap["000100"] = 20;
    scoreMap["001000"] = 20;    scoreMap["011110"] = 4320;
    scoreMap["011100"] = 720;   scoreMap["001110"] = 720;
    scoreMap["011010"] = 720;   scoreMap["010110"] = 720;
    
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            ChessBoard[i][j] = 0;
        }
    }
}

void ShowChessBoard(HWND hwnd) {
    HDC hdc;
    RECT rect;
    HPEN hPen;
    HBRUSH hBrush;
    
    hdc = GetDC(hwnd);
    GetClientRect(hwnd, &rect);
    
    int margin = 36;
    int point_radius = 5;
    
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Rectangle(hdc, rect.left + margin, rect.top + margin, rect.right - margin - 10, rect.bottom - margin + 5);
    int unit_dis = (rect.right - rect.left - 2 * margin) / (BOARD_SIZE - 1);
    for (int i = 0; i < BOARD_SIZE - 2; i ++) {
        int x = rect.left + margin + (i + 1) * unit_dis;
        MoveToEx(hdc, x, rect.top + margin, NULL);
        LineTo(hdc, x, rect.bottom - margin + 4);
        int y = rect.top + margin + (i + 1) * unit_dis;
        MoveToEx(hdc, rect.left + margin, y, NULL);
        LineTo(hdc, rect.right - margin - 11, y);
    }
    
    hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, rect.left + margin + 3 * unit_dis - point_radius, rect.top + margin + 3 * unit_dis - point_radius, rect.left + margin + 3 * unit_dis + point_radius, rect.top + margin + 3 * unit_dis + point_radius);
    Ellipse(hdc, rect.left + margin + 11 * unit_dis - point_radius, rect.top + margin + 3 * unit_dis - point_radius, rect.left + margin + 11 * unit_dis + point_radius, rect.top + margin + 3 * unit_dis + point_radius);
    Ellipse(hdc, rect.left + margin + 7 * unit_dis - point_radius, rect.top + margin + 7 * unit_dis - point_radius, rect.left + margin + 7 * unit_dis + point_radius, rect.top + margin + 7 * unit_dis + point_radius);
    Ellipse(hdc, rect.left + margin + 3 * unit_dis - point_radius, rect.top + margin + 11 * unit_dis - point_radius, rect.left + margin + 3 * unit_dis + point_radius, rect.top + margin + 11 * unit_dis + point_radius);
    Ellipse(hdc, rect.left + margin + 11 * unit_dis - point_radius, rect.top + margin + 11 * unit_dis - point_radius, rect.left + margin + 11 * unit_dis + point_radius, rect.top + margin + 11 * unit_dis + point_radius);
    DeleteObject(hBrush);
    DeleteObject(hPen);
    
    int chess_radius = 20;
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            if (ChessBoard[i][j] == 0) continue;
            else {
                int x = rect.left + margin + (j - 1) * unit_dis;
                int y = rect.top + margin + (i - 1) * unit_dis;
                if (ChessBoard[i][j] == 1) {
                    hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
                } else if (ChessBoard[i][j] == -1) {
                    hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
                }
                SelectObject(hdc, hBrush);
                Ellipse(hdc, x - chess_radius, y - chess_radius, x + chess_radius, y + chess_radius);
                DeleteObject(hBrush);
            }
        }
    }
    ReleaseDC(hwnd, hdc);
}

void ShowValidGrid(HWND hwnd, int cX, int cY) {
    HDC hdc;
    RECT rect;
    HPEN hPen;
    
    hdc = GetDC(hwnd);
    GetClientRect(hwnd, &rect);
    
    int margin = 36;
    int unit_dis = (rect.right - rect.left - 2 * margin) / (BOARD_SIZE - 1);
    int space = unit_dis / 2;
    int noX = 0, noY = 0;
    
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            int x = rect.left + margin + (j - 1) * unit_dis;
            int y = rect.top + margin + (i - 1) * unit_dis;
            if (cX >= x - space && cX <= x + space
                && cY >= y - space && cY <= y + space) {
                noX = i, noY = j;
                break;
            }
        }
    }
    
    if (ChessBoard[noX][noY] || (!noX && !noY)) return;
    
    int chess_radius = 20, slct_len = 15;
    int x = rect.left + margin + (noY - 1) * unit_dis;
    int y = rect.top + margin + (noX - 1) * unit_dis;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    
    MoveToEx(hdc, x - chess_radius, y - chess_radius, NULL);
    LineTo(hdc, x - chess_radius, y - chess_radius + slct_len);
    MoveToEx(hdc, x - chess_radius, y - chess_radius, NULL);
    LineTo(hdc, x - chess_radius + slct_len, y - chess_radius);
    
    MoveToEx(hdc, x + chess_radius, y - chess_radius, NULL);
    LineTo(hdc, x + chess_radius, y - chess_radius + slct_len);
    MoveToEx(hdc, x + chess_radius, y - chess_radius, NULL);
    LineTo(hdc, x + chess_radius - slct_len, y - chess_radius);
    
    MoveToEx(hdc, x + chess_radius, y + chess_radius, NULL);
    LineTo(hdc, x + chess_radius, y + chess_radius - slct_len);
    MoveToEx(hdc, x + chess_radius, y + chess_radius, NULL);
    LineTo(hdc, x + chess_radius - slct_len, y + chess_radius);
    
    MoveToEx(hdc, x - chess_radius, y + chess_radius, NULL);
    LineTo(hdc, x - chess_radius, y + chess_radius - slct_len);
    MoveToEx(hdc, x - chess_radius, y + chess_radius, NULL);
    LineTo(hdc, x - chess_radius + slct_len, y + chess_radius);
    
    DeleteObject(hPen);
}

bool CheckFive(int noX, int noY) {
    for (int i = max(1, noY - 4); i <= min(noY, BOARD_SIZE - 4); i ++) {
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (ChessBoard[noX][j] == 1) info.push_back('1');
            else if (ChessBoard[noX][j] == -1) info.push_back('0');
        }
        if (info == "11111" || info == "00000") return true;
    }
    for (int i = max(1, noX - 4); i <= min(noX, BOARD_SIZE - 4); i ++) {
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (ChessBoard[j][noY] == 1) info.push_back('1');
            else if (ChessBoard[j][noY] == -1) info.push_back('0');
        }
        if (info == "11111" || info == "00000") return true;
    }
    for (int i = noY - 4; i <= noY; i ++) {
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX - (noY - j) < 1 || noX - (noY - j) > BOARD_SIZE) {
                break;
            }
            if (ChessBoard[noX - (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX - (noY - j)][j] == -1) info.push_back('0');
        }
        if (info == "11111" || info == "00000") return true;
    }
    for (int i = noY - 4; i <= noY; i ++) {
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX + (noY - j) < 1 || noX + (noY - j) > BOARD_SIZE) {
                break;
            }
            if (ChessBoard[noX + (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX + (noY - j)][j] == -1) info.push_back('0');
        }
        if (info == "11111" || info == "00000") return true;
    }
    return false;
}

void WinnerShowUP() {
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            if (ChessBoard[i][j]) {
                if (CheckFive(i, j)) {
                    who = ChessBoard[i][j];
                    winner = true;
                    return;
                }
            }
        }
    }
}

int Dir1Score(int noX, int noY) {
    int sumScore = 0;
    bool is;
    
    for (int i = max(1, noY - 4); i <= min(noY, BOARD_SIZE - 4); i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (ChessBoard[noX][j] == 1) info.push_back('1');
            else if (ChessBoard[noX][j] == 0) info.push_back('0');
            else if (ChessBoard[noX][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    for (int i = max(1, noY - 4); i <= min(noY - 1, BOARD_SIZE - 5); i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 6; j ++) {
            if (ChessBoard[noX][j] == 1) info.push_back('1');
            else if (ChessBoard[noX][j] == 0) info.push_back('0');
            else if (ChessBoard[noX][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    return sumScore;
}

int Dir2Score(int noX, int noY) {
    int sumScore = 0;
    bool is;
    
    for (int i = max(1, noX - 4); i <= min(noX, BOARD_SIZE - 4); i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (ChessBoard[j][noY] == 1) info.push_back('1');
            else if (ChessBoard[j][noY] == 0) info.push_back('0');
            else if (ChessBoard[j][noY] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    for (int i = max(1, noX - 4); i <= min(noX - 1, BOARD_SIZE - 5); i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 6; j ++) {
            if (ChessBoard[j][noY] == 1) info.push_back('1');
            else if (ChessBoard[j][noY] == 0) info.push_back('0');
            else if (ChessBoard[j][noY] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    return sumScore;
}

int Dir3Score(int noX, int noY) {
    int sumScore = 0;
    bool is;
    
    for (int i = noY - 4; i <= noY; i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX - (noY - j) < 1 || noX - (noY - j) > BOARD_SIZE) {
                is = false;
                break;
            }
            if (ChessBoard[noX - (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX - (noY - j)][j] == 0) info.push_back('0');
            else if (ChessBoard[noX - (noY - j)][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    for (int i = noY - 4; i <= noY - 1; i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 6; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX - (noY - j) < 1 || noX - (noY - j) > BOARD_SIZE) {
                is = false;
                break;
            }
            if (ChessBoard[noX - (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX - (noY - j)][j] == 0) info.push_back('0');
            else if (ChessBoard[noX - (noY - j)][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    return sumScore;
}

int Dir4Score(int noX, int noY) {
    int sumScore = 0;
    bool is;
    
    for (int i = noY - 4; i <= noY; i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 5; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX + (noY - j) < 1 || noX + (noY - j) > BOARD_SIZE) {
                is = false;
                break;
            }
            if (ChessBoard[noX + (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX + (noY - j)][j] == 0) info.push_back('0');
            else if (ChessBoard[noX + (noY - j)][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    for (int i = noY - 4; i <= noY - 1; i ++) {
        is = true;
        string info;
        for (int j = i; j < i + 6; j ++) {
            if (j < 1 || j > BOARD_SIZE || noX + (noY - j) < 1 || noX + (noY - j) > BOARD_SIZE) {
                is = false;
                break;
            }
            if (ChessBoard[noX + (noY - j)][j] == 1) info.push_back('1');
            else if (ChessBoard[noX + (noY - j)][j] == 0) info.push_back('0');
            else if (ChessBoard[noX + (noY - j)][j] == -1) {
                is = false;
                break;
            }
        }
        if (is) sumScore += scoreMap[info];
    }
    
    return sumScore;
}

void IterCoordinate() {
    int maxScore = 0, nowScore;
    int ansX, ansY;
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            if (!ChessBoard[i][j]) {
                nowScore = Dir1Score(i, j) + Dir2Score(i, j) + Dir3Score(i, j) + Dir4Score(i, j);
                if (nowScore > maxScore) {
                    ansX = i, ansY = j;
                    maxScore = nowScore;
                }
            }
        }
    }
    ChessBoard[ansX][ansY] = -1;
}

void SetChess(HWND hwnd, int cX, int cY) {
    RECT rect;
    GetClientRect(hwnd, &rect);
    
    int margin = 36;
    int unit_dis = (rect.right - rect.left - 2 * margin) / (BOARD_SIZE - 1);
    int space = unit_dis / 2;
    int noX = 0, noY = 0;
    
    for (int i = 1; i <= BOARD_SIZE; i ++) {
        for (int j = 1; j <= BOARD_SIZE; j ++) {
            int x = rect.left + margin + (j - 1) * unit_dis;
            int y = rect.top + margin + (i - 1) * unit_dis;
            if (cX >= x - space && cX <= x + space
                && cY >= y - space && cY <= y + space) {
                noX = i, noY = j;
                break;
            }
        }
    }
    
    if (ChessBoard[noX][noY] || (!noX && !noY)) return;
    
    if (now == 1) {
        ChessBoard[noX][noY] = now;
        WinnerShowUP();
        if (!winner && mode == 1) {
            IterCoordinate();
            WinnerShowUP();
        } else now = -1;
    } else {
        ChessBoard[noX][noY] = now;
        WinnerShowUP();
        now = 1;
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC          hdc;
    RECT         rect;
    PAINTSTRUCT  ps;
    POINT        pt;
    HPEN         hPen;
    HBRUSH       hBrush;
    HFONT        hF_title, hF_info;
    
    static int CursorX, CursorY;
    
    switch (message) {
    case WM_CREATE:
        InitGame();
        break;
        
    case WM_MOUSEMOVE:
        CursorX = LOWORD(lParam);
        CursorY = HIWORD(lParam);
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_LBUTTONDOWN:
        CursorX = LOWORD(lParam);
        CursorY = HIWORD(lParam);
        SetChess(hwnd, CursorX, CursorY);
        InvalidateRect(hwnd, NULL, 1);
        break;
        
    case WM_KEYDOWN:
        if (winner == true) {
            winner = false;
            InitGame();
            break;
        }
        
    case WM_CHAR:
        if (wParam == '1') {
            mode = 1;
            menu = false;
        } else if (wParam == '2') {
            mode = 2;
            menu = false;
        }
        break;
        
    case WM_PAINT:
        hF_title = CreateFont(100,
            0, 0, 0,
            FW_HEAVY,
            0, 0, 0,
            ANSI_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "字体一" );
        hF_info = CreateFont(40,
            0, 0, 0,
            FW_HEAVY,
            0, 0, 0,
            ANSI_CHARSET,
            OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE,
            "字体二" );
        
        if (menu) {
            hdc = BeginPaint(hwnd, &ps);
            
            SetBkColor(hdc, RGB(255, 255, 255));
            SetTextColor(hdc, RGB(0, 0, 0));
            
            SelectObject(hdc, hF_title);
            TextOut(hdc, 200, 40, title, strlen(title));
            DeleteObject(hF_title);
            
            SelectObject(hdc, hF_info);
            TextOut(hdc, 150, 200, singlePlayer, strlen(singlePlayer));
            TextOut(hdc, 150, 300, doublePlayer, strlen(doublePlayer));
            DeleteObject(hF_info);
            
            Sleep(100);
            InvalidateRect(hwnd, NULL, 1);
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        ShowChessBoard(hwnd);
        
        if (winner) {
            hdc = BeginPaint(hwnd, &ps);
            
            if (who == 1) {
                SetBkColor(hdc, RGB(255, 255, 255));
                SetTextColor(hdc, RGB(0, 0, 0));
                SelectObject(hdc, hF_title);
                TextOut(hdc, 110, 60, black, strlen(black));
            } else if (who == -1) {
                SetBkColor(hdc, RGB(0, 0, 0));
                SetTextColor(hdc, RGB(255, 255, 255));
                SelectObject(hdc, hF_title);
                TextOut(hdc, 110, 60, white, strlen(white));
            }
            DeleteObject(hF_title);
            
            Sleep(100);
            InvalidateRect(hwnd, NULL, 1);
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        ShowValidGrid(hwnd, CursorX, CursorY);
        Sleep(200);
        InvalidateRect(hwnd, NULL, 1);
        return 0;
        
    case WM_DESTROY:
        PostQuitMessage (0);
        return 0;
    }
    
    return DefWindowProc(hwnd, message, wParam, lParam);
}

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
    
    hwnd = CreateWindow(szAppName,
        "GoBang | By Riatsala",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800, 800,
        NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
