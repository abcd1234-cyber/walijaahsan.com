// bsee24071lab7 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Node of Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;  // top of stack

public:
    Stack() {
        top = NULL;
    }

    // push value on top
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack.\n";
    }

    // pop value from top
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    // view top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        }
        else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // check if empty
    bool isEmpty() {
        return top == NULL;
    }
};

// main menu-driven program
int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. View top element\n";
        cout << "4. Check if empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is NOT empty.\n";
            break;

        case 5:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
