#include <stack>

using namespace std;

// ����һ������������ΪO(n)
/*class CQueue {
public:
    CQueue() {}

    void appendTail(int value) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(value);
    }

    int deleteHead() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (stack2.empty()) return -1;
        int value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1, stack2;
};*/

// ��������appendTail()ΪO(1)��deleteHead()ΪO(n)
class CQueue {
public:
    CQueue() {}

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if(stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) return -1;
        int value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1, stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */