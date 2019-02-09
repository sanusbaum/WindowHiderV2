#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <Windows.h>

class Window
{
public:

	Window(HWND windowHandle_, std::string windowTitle_);

	void toggleVisibility();
	bool isVisible();
	std::string getTitle();

private:

	HWND _windowHandle;
	std::string _windowTitle;

};

#endif // WINDOW_H