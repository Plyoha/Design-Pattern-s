#include <iostream>

class Handler {
protected:
    Handler* next;
public:
    Handler() : next(nullptr) {}

    void setNext(Handler* nextHandler) {
        next = nextHandler;
    }

    virtual void handleRequest(int request) {
        if (next) {
            next->handleRequest(request);
        }
    }

    virtual ~Handler() = default;
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request < 10) {
            std::cout << "ConcreteHandler1 handled request " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled request " << request << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

int main() {
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    handler1->setNext(handler2);
    
    handler1->handleRequest(5);
    handler1->handleRequest(15);
    
    delete handler1;
    delete handler2;
    
    return 0;
}
