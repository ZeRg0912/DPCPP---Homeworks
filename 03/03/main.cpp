#include <iostream>
#include "LogMessage.h"

int main() {
    LogMessage log1(Type::Error, "Error!");
    LogMessage log2(Type::Warning, "Warning!");
    LogMessage log3(Type::Unknown, "Unknown message!");
    LogMessage log4(Type::FatalError, "Fatal error, programm closed!");

    FatalError fatalErrorHandler;
    Error errorHandler("file.txt");
    Warning warningHandler;
    Unknown unknownHandler;

    fatalErrorHandler.setNext(&errorHandler);
    errorHandler.setNext(&warningHandler);
    warningHandler.setNext(&unknownHandler);

    fatalErrorHandler.handleMessage(log1);
    fatalErrorHandler.handleMessage(log2);

    try {
        fatalErrorHandler.handleMessage(log3);
        fatalErrorHandler.handleMessage(log4);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}