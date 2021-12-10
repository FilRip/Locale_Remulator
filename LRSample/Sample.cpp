#include <iostream>
#include <Windows.h>

LRESULT CALLBACK WinSunProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main()
{
	for (int i = 0; i < 5; i++) {
		std::cout << "From simple program " << i << "\n";
		Sleep(500);
	}
	MessageBox(NULL, "�F", "����", NULL);
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW; //���õ�ˮƽ���Ȼ�ֱ���ȸı���ƶ�����ʱ���ػ���������
    wndclass.lpfnWndProc = (WNDPROC)WinSunProc; //����WinSunProcΪ���ڴ�����
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = NULL;
    wndclass.hIcon = LoadIcon(NULL, IDI_ERROR);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = "WeiXin";
    RegisterClass(&wndclass);
    HWND hwnd;
    hwnd = CreateWindow("WeiXin",
        "�F",
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
        100, 100, 640, 480,
        NULL,
        NULL,
        NULL,
        NULL);
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}