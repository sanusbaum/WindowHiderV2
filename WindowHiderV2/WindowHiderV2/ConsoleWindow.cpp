#include "ConsoleWindow.h"

#include <iostream>
#include <Windows.h>

void ConsoleWindow::writeLine(std::string string_)
{
	int consoleWindowWidth = getConsoleWindowWidth();

	// Output the text to the screen with a border made of "| " and ending with " |"
	std::cout << "| ";
	std::cout << string_.substr(0, consoleWindowWidth - 4);
	if (string_.length() < consoleWindowWidth - 4)
	{
		for (int whiteSpaceIndex = 0; whiteSpaceIndex < consoleWindowWidth - (string_.length() % (consoleWindowWidth - 4)) - 4; whiteSpaceIndex++)
		{
			std::cout << " ";
		}
	}
	std::cout << " |";

	// 
	if (string_.size() >= consoleWindowWidth - 4) // 4 for start "| " and ending " |"
	{
		writeLine(string_.substr(consoleWindowWidth - 4));
	}
}

void ConsoleWindow::writeSeparator()
{
	int consoleWindowWidth = getConsoleWindowWidth();

	// write a '=' for each column of the console window width
	for (int column = 0; column < consoleWindowWidth; column++)
	{
		std::cout << "=";
	}
}

std::string ConsoleWindow::getInput(std::string string_)
{
	int consoleWindowWidth = getConsoleWindowWidth();
	writeLine(string_);

	// Move the console cursor to the desired position on screen, which is right after the `string_` has finished being printed
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenInfo;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenInfo))
	{
		COORD cursorPosition;
		cursorPosition.X = (string_.length() % (consoleWindowWidth - 4)) + 2; // + 2 for "| "
		cursorPosition.Y = consoleScreenInfo.dwCursorPosition.Y - 1;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
	}

	std::string input;
	std::cin >> input;
	return input;
}

int ConsoleWindow::getConsoleWindowWidth()
{
	int columns = 0;

	CONSOLE_SCREEN_BUFFER_INFO consoleScreenInfo;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenInfo))
	{
		columns = consoleScreenInfo.srWindow.Right - consoleScreenInfo.srWindow.Left + 1;
	}

	return columns;
}