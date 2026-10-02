#include <iostream>
using namespace std;

int top = -1, maxSize = 5;
int *stackArray;

void push() {
    int x;
    if (top == maxSize - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    cout << "Enter the value: ";
    cin >> x;
    stackArray[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "\nPopped: " << stackArray[top--] << "\n";
}

void display() {
    if (top == -1) {
        cout << "\nStack is empty\n";
        return;
    }
    cout << "\nStack: ";
    for (int i = top; i >= 0; i--) {
        cout << stackArray[i] << "  ";
    }
    cout << "\n";
}

int main() {
    stackArray = new int[maxSize];
    int option;

    while (true) {
        cout << "\nPlease choose an option from below\n";
        cout << "1 - Push\n2 - Pop\n3 - Display\n0 - Exit\n";
        cin >> option;

        switch (option) {
        case 1: push(); display(); break;
        case 2: pop(); display(); break;
        case 3: display(); break;
        case 0: return 0;
        default: cout << "Invalid option.\n";
        }
    }
}
