#include <iostream>

class Target {
public:
    virtual void request() const {
        std::cout << "Target: Default behavior" << std::endl;
    }
    virtual ~Target() = default;
};

class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee: Specific behavior" << std::endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);
    
    adapter->request();
    
    delete adaptee;
    delete adapter;
    return 0;
}
