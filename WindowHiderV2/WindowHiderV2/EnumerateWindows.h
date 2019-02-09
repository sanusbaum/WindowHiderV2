#ifndef ENUMERATEWINDOWS_H
#define ENUMERATEWINDOWS_H

#include "Window.h"

#include <vector>

class EnumerateWindows
{

	static BOOL CALLBACK EnumerateWindowsProcesses(HWND windowHandle_, LPARAM parameter_);

public:
	EnumerateWindows();

	std::vector<Window> getWindows();

private:

	static std::vector<Window> _windows;

};

#endif // ENUMERATEWINDOWS_H