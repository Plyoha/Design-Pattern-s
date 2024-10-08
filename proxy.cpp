#include <iostream>

class Subject {
public:
    virtual void request() const = 0;
    virtual ~Subject() = default;
};

class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request" << std::endl;
    }
};

class Proxy : public Subject {
private:
    RealSubject* realSubject;
public:
    Proxy() {
        realSubject = new RealSubject();
    }

    void request() const override {
        std::cout << "Proxy: Delegating request to RealSubject" << std::endl;
        realSubject->request();
    }

    ~Proxy() {
        delete realSubject;
    }
};

int main() {
    Subject* proxy = new Proxy();
    proxy->request();
    
    delete proxy;
    return 0;
}
