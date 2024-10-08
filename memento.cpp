#include <iostream>
#include <string>

class Memento {
private:
    std::string state;
public:
    Memento(const std::string& s) : state(s) {}
    
    std::string getState() const {
        return state;
    }
};

class Originator {
private:
    std::string state;
public:
    void setState(const std::string& s) {
        state = s;
        std::cout << "State set to: " << state << std::endl;
    }

    Memento* save() const {
        return new Memento(state);
    }

    void restore(Memento* memento) {
        state = memento->getState();
        std::cout << "State restored to: " << state << std::endl;
    }
};

class Caretaker {
private:
    Memento* memento;
public:
    void saveState(Originator* originator) {
        memento = originator->save();
    }

    void restoreState(Originator* originator) {
        originator->restore(memento);
    }

    ~Caretaker() {
        delete memento;
    }
};

int main() {
    Originator* originator = new Originator();
    Caretaker* caretaker = new Caretaker();

    originator->setState("State 1");
    caretaker->saveState(originator);
    
    originator->setState("State 2");
    caretaker->restoreState(originator);

    delete originator;
    delete caretaker;
    
    return 0;
}
