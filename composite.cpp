#include <iostream>
#include <vector>

class Component {
public:
    virtual void operation() const = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual Component* getChild(int index) { return nullptr; }
    virtual ~Component() = default;
};

class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

class Composite : public Component {
private:
    std::vector<Component*> children;
public:
    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        for (auto child : children) {
            child->operation();
        }
    }

    void add(Component* component) override {
        children.push_back(component);
    }

    void remove(Component* component) override {
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }
};

int main() {
    Composite* root = new Composite();
    Leaf* leaf1 = new Leaf();
    Leaf* leaf2 = new Leaf();
    
    root->add(leaf1);
    root->add(leaf2);
    
    root->operation();
    
    delete leaf1;
    delete leaf2;
    delete root;
    return 0;
}
