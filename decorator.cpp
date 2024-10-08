#include <iostream>

class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

class Decorator : public Component {
protected:
    Component* component;
public:
    Decorator(Component* comp) : component(comp) {}
    
    void operation() const override {
        component->operation();
    }
};

class ConcreteDecorator : public Decorator {
public:
    ConcreteDecorator(Component* comp) : Decorator(comp) {}
    
    void operation() const override {
        Decorator::operation();
        std::cout << "ConcreteDecorator added behavior" << std::endl;
    }
};

int main() {
    Component* component = new ConcreteComponent();
    Component* decorator = new ConcreteDecorator(component);
    
    decorator->operation();
    
    delete decorator;
    delete component;
    return 0;
}
