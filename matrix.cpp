#include <windows.h>
#include "math.h" 
#include <iostream>
#include "MATRIX.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("Class");
//전역에 4x4를 만들것, 1x4도 만듬 3x1로 2번과 1번 곱해서 3번째 에 결과

static int m4x4[4][4] = { {2,3,1,1},
                        {1,4,3,2},
                        {10,10,10,10},
                        {2,6,5,4} };
static int m1x4[1][4] = { 3,2,5,1 };
static int m4x1[4][4] = { 0 };
static int result[4][4] = { 0 };
void matrix_multply(int x[][4], int y[][4], int result[][4], int x_row, int x_col, int y_col) {
    for (int i = 0; i < x_row; i++) {
        for (int j = 0; j < y_col; j++) {
            for (int k = 0; k < x_col; k++)
                result[i][j] += x[i][k] * y[k][j];
		}
    }
}
void matrix_print(MATRIX m) {
    for (int i = 0; i < m.get_row(); i++) {
        for (int j = 0; j < m.get_col(); j++) {
            printf("%d\t", m.get_array(i,j));
        }
        printf("\n");
    }
    printf("\n");
}
/*
void matrix_print(int x[][4], int l, int m) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/
void matrix_transpose(MATRIX x, MATRIX y) {
    for (int i = 0; i < y.get_row(); i++) {
        for (int j = 0; j < y.get_col(); j++) {
            //y[j][i] = x[i][j];
            y.set_array(i, j,x.get_array(j,i));
        }
    }
}
int main() {
    
    MATRIX m1(4, 4, 1);
    MATRIX m2(1, 4, 5);
    MATRIX m3(4, 1);
    matrix_print(m2);
    matrix_print(m3);
    matrix_transpose(m2, m3); //1x4 -> 4x1
    matrix_print(m3);
    //matrix_print(m2.get_p_array(), 1, 4);
    //matrix_print(m3.get_p_array(), 4, 1);
    //matrix_transpose(m2.get_p_array(), m3.get_p_array(), 4, 1);
    //matrix_print(m3.get_p_array(), 4, 1);
    //matrix_multply(m1.get_p_array(), m2.get_p_array(), m3.get_p_array(), 4, 4, 1);
    //matrix_print(m3.get_p_array(), 4, 1);
    return 0;
}
/*
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&Message, NULL, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    double f;
    int y;

    switch (iMessage)
    {
    case WM_CREATE:
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SetMapMode(hdc, MM_LOENGLISH);   // exchange coodinate
        SetViewportOrgEx(hdc, 300, 300, NULL);  // exchange orgion

        for (f = -300; f < 800; f++)
        {
            y = (int)(sin(f * 3.14 / 180) * 100);
            SetPixel(hdc, (int)f, y, RGB(100, 100, 100));
        }

        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
*/