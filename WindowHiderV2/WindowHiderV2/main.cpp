#include "ConsoleWindow.h"
#include "EnumerateWindows.h"

#include <vector>

int main(int argc_, char** argv_)
{
	ConsoleWindow console;

	std::string selection;
	while (selection != "1" && selection != "2")
	{
		console.writeSeparator();
		console.writeLine("Select mode:");
		console.writeLine("1.) Basic Mode");
		console.writeLine("2.) Advanced Mode");
		console.writeSeparator();

		selection = console.getInput("Enter Selection ID: ");
	}

	console.writeSeparator();

	EnumerateWindows enumerateWindows;
	std::vector<Window> windows = enumerateWindows.getWindows();
	if (selection == "1") // Basic Mode
	{
		// create a shortened list that only consists of visible windows
		std::vector<Window> shortenedList;
		for (int windowIndex = 0; windowIndex < windows.size(); windowIndex++)
		{
			if (windows.at(windowIndex).isVisible()) {
				shortenedList.push_back(windows.at(windowIndex));
			}
		}

		windows = shortenedList;
	}

	// print out all the window IDs and titles
	for (int windowIndex = 0; windowIndex < windows.size(); windowIndex++)
	{
		console.writeLine(std::to_string(windowIndex + 1) + ".) " + windows.at(windowIndex).getTitle());
	}
	console.writeLine("0.) Exit");
	console.writeSeparator();

	// loop forever asking what window ID to toggle
	while (true)
	{
		std::string windowIdToToggle = console.getInput("Enter Window ID To Toggle: ");
		
		int windowId = std::stoi(windowIdToToggle);
		if (windowId >= 0 && windowId <= windows.size())
		{
			if (windowId == 0)
			{
				break;
			}
			windows.at(windowId - 1).toggleVisibility();
		}
		else
		{
			console.writeLine("ERROR: Invalid Window ID");
		}
	}
}