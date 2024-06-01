#pragma once
#include <fstream>

enum class Format {
    kText, kHTML, kJSON
};





class Printable {
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};

class PrintableAsHTML : public Printable {
public:
    virtual ~PrintableAsHTML() = default;
    virtual std::string print() const = 0;
};

class PrintableAsText : public Printable {
public:
    virtual ~PrintableAsText() = default;
    virtual std::string print() const = 0;
};

class PrintableAsJSON : public Printable {
public:
    virtual ~PrintableAsJSON() = default;
    virtual std::string print() const = 0;
};





class DataAsHTML : public PrintableAsHTML {
private:
    std::string data;
    Format format;
public:
    DataAsHTML(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
    std::string print() const override;
};

class DataAsText : public PrintableAsText {
private:
    std::string data;
    Format format;
public:
    DataAsText(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
    std::string print() const override;
};

class DataAsJSON : public PrintableAsJSON {
private:
    std::string data;
    Format format;
public:
    DataAsJSON(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
    std::string print() const override;
};





class SaveTo {
public:
    virtual void save(std::ofstream& file, const Printable* printable) const = 0;
};

class SaveToAsHTML : public SaveTo {
private:
    void saveToAsHTML(std::ofstream& file, const Printable* printable) const;
public:
    void save(std::ofstream& file, const Printable* printable) const override;
};

class SaveToAsJSON : public SaveTo {
private:
    void saveToAsJSON(std::ofstream& file, const Printable* printable) const;
public:
    void save(std::ofstream& file, const Printable* printable) const override;
};

class SaveToAsText : public SaveTo {
private:
    void saveToAsText(std::ofstream& file, const Printable* printable) const;
public:
    void save(std::ofstream& file, const Printable* printable) const override;
};