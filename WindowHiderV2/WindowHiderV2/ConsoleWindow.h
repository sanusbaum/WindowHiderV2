/*
 * Author: Spencer Nusbaum
 * File: ConsoleWindow.h
 * Last Updated: 2/8/2019
 * Purpose: Provide a simple way to organize data in a Microsoft Windows console window,
 *     with borders and separators. Also provide a way to get input within the organized
 *     output with borders.
 */

#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <string>

class ConsoleWindow
{
public:

	void writeLine(std::string string_);
	void writeSeparator();
	std::string getInput(std::string string_);

private:

	unsigned int getConsoleWindowWidth();

};

#endif // CONSOLEWINDOW_H