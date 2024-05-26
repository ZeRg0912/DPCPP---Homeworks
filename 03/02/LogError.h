#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class Observer {
public:
	virtual void onWarning(const std::string& message) {};
	virtual void onError(const std::string& message) {};
	virtual void onFatalError(const std::string& message) {};
	virtual ~Observer() = default;
};

class LogError {
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs) {
		auto it = remove(observers.begin(), observers.end(), obs);
		observers.erase(it, observers.end());
	}

	void warning() {
		for (auto obs : observers) {
			obs->onWarning("Warning!");
		}
	}

	void error() {
		for (auto obs : observers) {
			obs->onError("Error!");
		}
	}

	void fatalError() {
		for (auto obs : observers) {
			obs->onFatalError("Fatal Error!");
		}
	}
};

class ConsoleObserver : public Observer {
public:
	void onWarning(const std::string& message) override {
		std::cout << "Warning: " << message << "\n";
	}
};

class FileObserer : public Observer {
private:
	std::ofstream write;
public:
	FileObserer(const std::string& filename) {
		write.open(filename, std::ofstream::app);
		if (!write.is_open()) {
			std::cout << "Can't open file!\n";
		}
	}

	~FileObserer() {
		write.close();
	}

	void onError(const std::string& message) override {
		write << "Error: " << message << "\n";
	}
};

class FatalObserver : public Observer {
private:
	std::ofstream write;
public:
	FatalObserver(const std::string& filename) {
		write.open(filename, std::ofstream::app);
		if (!write.is_open()) {
			std::cout << "Can't open file!\n";
		}
	}

	~FatalObserver() {
		write.close();
	}

	void onError(const std::string& message) override {
		std::cout << "Fatal error: " << message << "\n";
		write << "Fatal error: " << message << "\n";
	}
};