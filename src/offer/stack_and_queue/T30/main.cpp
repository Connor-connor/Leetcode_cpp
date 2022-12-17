#include <stack>
#include <climits>

using namespace std;

/*class MinStack {
private:
    stack<int> x_stack, min_stack;
public:
    *//** initialize your data structure here. *//*
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(),x));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int min() {
        return min_stack.top();
    }
};*/

class MinStack {
private:
    stack<int> x_stack, min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        x_stack.push(x);
        if(min_stack.empty() || min_stack.top() >= x)
            min_stack.push(x);
    }

    void pop() {
        int value = x_stack.top();
        x_stack.pop();
        if(value == min_stack.top())
            min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int min() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */