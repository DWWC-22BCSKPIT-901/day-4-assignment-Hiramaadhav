#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;  
    stack<int> outputStack;
    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }
public:
    void push(int x) {
        inputStack.push(x);
    }
    int pop() {
        if (outputStack.empty()) {
            transfer(); 
        }
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }
    int peek() {
        if (outputStack.empty()) {
            transfer(); // Transfer elements if outputStack is empty
        }
        return outputStack.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    cout << "Peek: " << queue.peek() << endl; // Output: 1
    cout << "Pop: " << queue.pop() << endl;   // Output: 1
    cout << "Empty: " << (queue.empty() ? "true" : "false") << endl; // Output: false

    queue.push(3);
    cout << "Peek: " << queue.peek() << endl; // Output: 2
    cout << "Pop: " << queue.pop() << endl;   // Output: 2
    cout << "Pop: " << queue.pop() << endl;   // Output: 3
    cout << "Empty: " << (queue.empty() ? "true" : "false") << endl; // Output: true

    return 0;
}
