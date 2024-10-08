#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    Singleton() = default;

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void operation() {
        std::cout << "Singleton operation" << std::endl;
    }
};

// Ініціалізація статичного члена
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->operation();
    
    return 0;
}
