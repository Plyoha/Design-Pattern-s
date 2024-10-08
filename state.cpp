#include <iostream>

class Context;

class State {
public:
    virtual void handle(Context* context) = 0;
    virtual ~State() = default;
};

class Context {
private:
    State* state;
public:
    Context(State* initialState) : state(initialState) {}

    void setState(State* newState) {
        state = newState;
    }

    void request() {
        state->handle(this);
    }
};

class ConcreteStateA : public State {
public:
    void handle(Context* context) override {
        std::cout << "State A handling request. Changing to State B." << std::endl;
        context->setState(new ConcreteStateB());
    }
};

class ConcreteStateB : public State {
public:
    void handle(Context* context) override {
        std::cout << "State B handling request. Changing to State A." << std::endl;
        context->setState(new ConcreteStateA());
    }
};

int main() {
    Context* context = new Context(new ConcreteStateA());

    context->request();
    context->request();

    delete context;

    return 0;
}
