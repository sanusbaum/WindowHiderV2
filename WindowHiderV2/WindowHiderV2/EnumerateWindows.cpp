#include "EnumerateWindows.h"

#define WINDOW_TITLE_ALLOCATION_SIZE 1024

std::vector<Window> EnumerateWindows::_windows;

BOOL CALLBACK EnumerateWindows::EnumerateWindowsProcesses(HWND windowHandle_, LPARAM parameter_)
{
	LPSTR windowTitle = (LPSTR)malloc(WINDOW_TITLE_ALLOCATION_SIZE);

	int lengthOfWindowTitle = GetWindowTextA(windowHandle_, windowTitle, WINDOW_TITLE_ALLOCATION_SIZE);
	_windows.push_back(Window(windowHandle_, windowTitle));

	free(windowTitle);

	return TRUE;
}

EnumerateWindows::EnumerateWindows()
{
	_windows.clear();
	EnumWindows(EnumerateWindows::EnumerateWindowsProcesses, NULL);
}

std::vector<Window> EnumerateWindows::getWindows()
{
	return _windows;
}