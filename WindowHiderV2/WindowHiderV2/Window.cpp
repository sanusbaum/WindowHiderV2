#include "Window.h"

Window::Window(HWND windowHandle_, std::string windowTitle_)
{
	_windowHandle = windowHandle_;
	_windowTitle = windowTitle_;
}

void Window::toggleVisibility()
{
	if (isVisible())
	{
		ShowWindow(_windowHandle, SW_HIDE);
	}
	else	
	{
		ShowWindow(_windowHandle, SW_SHOW);
	}
}

bool Window::isVisible()
{
	return IsWindowVisible(_windowHandle) == TRUE;
}

std::string Window::getTitle()
{
	return _windowTitle;
}