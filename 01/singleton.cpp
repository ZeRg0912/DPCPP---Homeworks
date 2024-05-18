#include "thread"
#include "iostream"

class Singleton {
public:

    // Метод для получения экземпляра
    static Singleton* GetInstance(int value)  {
        std::lock_guard<std::mutex> lock(m_);
        if (instance_) {
            return instance_;
        } else {
            instance_ = new Singleton(value);
        }
        return instance_;
    }

    void DoJob() const {
        std::cout << value_ << std::endl;
    }

    // Удаленные конструктор копирования и копирующий оператор присваивания
    Singleton(const Singleton& s) = delete;
    void operator=(const Singleton& s) = delete;

private:
    // Приватный конструктор
    explicit Singleton(int value) : value_(value) {}
    int value_;
    // Статический указатель на единственный экземпляр
    static Singleton* instance_;
    static std::mutex m_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::m_;

void worker1() {
    Singleton* s = Singleton::GetInstance(42);
    s->DoJob();
}
void worker2() {
    Singleton* s = Singleton::GetInstance(43);
    s->DoJob();
}

int main () {
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();
}
