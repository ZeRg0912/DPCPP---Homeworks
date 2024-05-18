#include "thread"
#include "iostream"

class SimpleSingleton {
public:
    // Метод для получения экземпляра
    static SimpleSingleton* GetInstance(int value)  {
        if (instance_) {
            return instance_;
        } else {
            instance_ = new SimpleSingleton(value);
        }
        return instance_;
    }

    void DoJob() const {
        std::cout << value_ << std::endl;
    }

    // Удаленные конструктор копирования и копирующий оператор присваивания
    SimpleSingleton(const SimpleSingleton& s) = delete;
    void operator=(const SimpleSingleton& s) = delete;

private:
    // Приватный конструктор
    explicit SimpleSingleton(int value) : value_(value) {}
    int value_;
    // Статический указатель на единственный экземпляр
    static SimpleSingleton* instance_;
};

SimpleSingleton* SimpleSingleton::instance_ = nullptr;

void worker1() {
    SimpleSingleton* s = SimpleSingleton::GetInstance(42);
    s->DoJob();
}
void worker2() {
    SimpleSingleton* s = SimpleSingleton::GetInstance(43);
    s->DoJob();
}

int main () {
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();
}
