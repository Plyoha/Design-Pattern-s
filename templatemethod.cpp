#include <iostream>

class AbstractClass {
public:
    void templateMethod() const {
        baseOperation1();
        requiredOperation1();
        baseOperation2();
        requiredOperation2();
        baseOperation3();
    }

    virtual ~AbstractClass() = default;

protected:
    void baseOperation1() const {
        std::cout << "AbstractClass: Base operation 1" << std::endl;
    }

    void baseOperation2() const {
        std::cout << "AbstractClass: Base operation 2" << std::endl;
    }

    void baseOperation3() const {
        std::cout << "AbstractClass: Base operation 3" << std::endl;
    }

    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;
};

class ConcreteClass : public AbstractClass {
protected:
    void requiredOperation1() const override {
        std::cout << "ConcreteClass: Implementing operation 1" << std::endl;
    }

    void requiredOperation2() const override {
        std::cout << "ConcreteClass: Implementing operation 2" << std::endl;
    }
};

int main() {
    AbstractClass* obj = new ConcreteClass();
    obj->templateMethod();

    delete obj;

    return 0;
}
