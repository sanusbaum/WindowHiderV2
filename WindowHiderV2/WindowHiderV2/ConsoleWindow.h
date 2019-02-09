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

	int getConsoleWindowWidth();

};

#endif // CONSOLEWINDOW_H