/*
 * Author: Spencer Nusbaum
 * File: Window.h
 * Last Updated: 2/8/2019
 * Purpose: Provide a simple way encapsulation of window information and functionality,
 *     including title andhandle, and ways to view and toggle the visibility of that
 *     window.
 */

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