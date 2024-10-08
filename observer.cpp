#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notify(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    std::string name;
public:
    ConcreteObserver(const std::string& n) : name(n) {}

    void update(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }
};

int main() {
    Subject* subject = new Subject();

    Observer* observer1 = new ConcreteObserver("Observer 1");
    Observer* observer2 = new ConcreteObserver("Observer 2");
    
    subject->attach(observer1);
    subject->attach(observer2);
    
    subject->notify("Event 1");
    subject->notify("Event 2");

    delete observer1;
    delete observer2;
    delete subject;
    
    return 0;
}
