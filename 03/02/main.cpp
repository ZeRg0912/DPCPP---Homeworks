#include <iostream>
#include "LogError.h"

int main() {
    LogError logger;
    ConsoleObserver warning;
    FileObserer error("error_file.txt");
    FatalObserver fatal("fatal_file.txt");

    logger.addObserver(&warning);
    logger.addObserver(&error);
    logger.addObserver(&fatal);

    logger.warning();
    logger.error();
    logger.fatalError();

	return 0;
}