/*
 * Author: Spencer Nusbaum
 * File: EnumerateWindows.h
 * Last Updated: 2/8/2019
 * Purpose: Provide a simple way to enumerate the windows currently running.
 */

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