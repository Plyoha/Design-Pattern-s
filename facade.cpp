#include <iostream>

class SubsystemA {
public:
    void operationA() const {
        std::cout << "Subsystem A operation" << std::endl;
    }
};

class SubsystemB {
public:
    void operationB() const {
        std::cout << "Subsystem B operation" << std::endl;
    }
};

class Facade {
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;
public:
    Facade() {
        subsystemA = new SubsystemA();
        subsystemB = new SubsystemB();
    }

    void operation() const {
        subsystemA->operationA();
        subsystemB->operationB();
    }

    ~Facade() {
        delete subsystemA;
        delete subsystemB;
    }
};

int main() {
    Facade* facade = new Facade();
    facade->operation();
    
    delete facade;
    return 0;
}
