#pragma once
#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "Log: " << message << "\n";
    }
};

class FileLogCommand : public LogCommand {
private:
    std::fstream write;
public: 
    FileLogCommand() {
        write.open("file.txt", std::fstream::app);
        if (!write.is_open()) {
            std::cout << "Can't open file!\n";
        }
    }

    ~FileLogCommand() {
        write.close();
    }

    void print(const std::string& message) override {
        write << "Log: " << message << "\n";
    }
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}