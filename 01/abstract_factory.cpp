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
        std::cout << "Windows Button" << std::endl;
    }

    void onClick(std::function<void()>) const noexcept override {}
};

class MacOSButton : public Button {
public:
    void render() const noexcept override {
        std::cout << "MacOS Button" << std::endl;
    }

    void onClick(std::function<void()>) const noexcept override {}
};

class TextBox {
public:
    virtual void render() const noexcept = 0;

    void setText(const std::string &text) noexcept {
        this->text = text;
    };
    std::string text;
};

class WinText : public TextBox {
public:
    void render() const noexcept override {
        std::cout << "This is windows style text: " << text << std::endl;
    }
};

class MacOSText : public TextBox {
public:
    void render() const noexcept override {
        std::cout << "This is MacOS style text: " << text << std::endl;
    }
};


class AbstractModalDialogFactory {
public:

    virtual Button *createButton() const noexcept = 0;

    virtual TextBox *createTextBox() const noexcept = 0;
};

class WindowsModalDialogFactory : public AbstractModalDialogFactory {
public:
    Button *createButton() const noexcept override {
        return new WinButton();
    }

    TextBox *createTextBox() const noexcept override {
        return new WinText();
    }
};

class MacOSModalDialogFactory : public AbstractModalDialogFactory {
public:
    Button *createButton() const noexcept override {
        return new MacOSButton();
    }

    TextBox *createTextBox() const noexcept override {
        return new MacOSText();
    }
};

class Application {
public:
    explicit Application(AbstractModalDialogFactory *factory) : factory_(factory) {
        render();
    }
    void render() const noexcept {
        Button* b = factory_->createButton();
        TextBox* t = factory_->createTextBox();
        t->setText("Hello world");
        b->render();
        t->render();
    }

private:
    AbstractModalDialogFactory *factory_;
};

int main() {
    std::string platform;
    std::cout << "Enter target platform:" << std::endl;
    std::cin >> platform;
    AbstractModalDialogFactory* factory;
    if (platform == "win") {
        factory = new WindowsModalDialogFactory();
    } else if (platform == "macos") {
        factory = new MacOSModalDialogFactory();
    }
    auto app = Application(factory);
    return 0;
}
