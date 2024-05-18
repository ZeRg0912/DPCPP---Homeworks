#include "iostream"
#include "functional"

class Button {
public:
    virtual void render() const noexcept = 0;

    virtual void onClick(std::function<void()>) const noexcept = 0;
};

class WinButton : public Button {
public:
    void render() const noexcept override {
        std::cout << "Windows Button";
    }

    void onClick(std::function<void()>) const noexcept override {}
};

class MacOSButton : public Button {
public:
    void render() const noexcept override {
        std::cout << "MacOS Button";
    }

    void onClick(std::function<void()>) const noexcept override {}
};

class ModalDialog {
public:
    void createWindow() const noexcept {
        Button *b = createButton();
        b->render();
        b->onClick([](){});
    }

    virtual Button *createButton() const noexcept = 0;
};

class WindowsModalDialog : public ModalDialog {
public:
    Button *createButton() const noexcept override {
        return new WinButton();
    }
};

class MacOSModalDialog : public ModalDialog {
public:
    Button *createButton() const noexcept override {
        return new MacOSButton();
    }
};

int main() {
    std::string platform;
    std::cout << "Enter target platform:" << std::endl;
    std::cin >> platform;
    if (platform == "win") {
        WindowsModalDialog().createWindow();
    } else if (platform == "macos") {
        MacOSModalDialog().createWindow();
    }
    return 0;
}
