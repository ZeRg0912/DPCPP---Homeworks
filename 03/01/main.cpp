#include <iostream>
#include "Log.h"


int main() {
	ConsoleLogCommand console;
	FileLogCommand file;

	//console.print("Console message");
	//file.print("File message");

	print(console, "Console message");
	print(file, "file message");

	return 0;
}