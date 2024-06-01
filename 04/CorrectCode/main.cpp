#include <iostream>
#include <fstream>
#include "CorrectCode.h"

int main() {
    std::ofstream data("data.txt");

    if (data.is_open()) {
        try {
            Printable* dataAsHTML = new DataAsHTML("infoHTML", Format::kHTML);
            SaveToAsHTML SaveHTML;
            SaveHTML.save(data, dataAsHTML);
            data << '\n';
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Printable* dataAsJSON = new DataAsJSON("infoJSON", Format::kJSON);
            SaveToAsJSON SaveJSON;
            SaveJSON.save(data, dataAsJSON);
            data << '\n';
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Printable* dataAsText = new DataAsText("infoText", Format::kText);
            SaveToAsText SaveText;
            SaveText.save(data, dataAsText);
            data << '\n';
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Printable* dataAsHTML = new DataAsJSON("infoText", Format::kText);
            SaveToAsText SaveText;
            SaveText.save(data, dataAsHTML);
            data << '\n';
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else {
        std::cout << "Can't open file to write!\n";
    }

    data.close();
}