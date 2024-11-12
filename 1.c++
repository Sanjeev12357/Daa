#include <iostream>
#define MAX 100

class Stack {
    int top;
    int arr[MAX]; // Stack array

public:
    Stack() { top = -1; } // Constructor initializes top to -1 (empty stack)

    // Function to push an element onto the stack
    bool push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = value;
            std::cout << value << " pushed into stack\n";
            return true;
        }
    }

    // Function to remove an element from the stack
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        } else {
            int value = arr[top--];
            return value;
        }
    }

    // Function to view the top element of the stack
    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is " << stack.peek() << "\n";

    std::cout << stack.pop() << " popped from stack\n";
    std::cout << "Top element is " << stack.peek() << "\n";

    return 0;
}
