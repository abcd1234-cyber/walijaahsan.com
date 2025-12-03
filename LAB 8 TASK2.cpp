// LAB 8 TASK2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

class MyQueue {
private:
    Node* front;
    Node* rear;

public:
    MyQueue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* n = new Node(value);

        if (rear == NULL) {
            front = rear = n;
        }
        else {
            rear->next = n;
            rear = n;
        }
        cout << value << " added to queue." << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << front->data << " removed from queue." << endl;
        front = front->next;

        if (front == NULL) rear = NULL;
    }

    void showFront() {
        if (front == NULL)
            cout << "Queue is EMPTY!" << endl;
        else
            cout << "Front = " << front->data << endl;
    }

    void isEmpty() {
        if (front == NULL)
            cout << "Queue is EMPTY." << endl;
        else
            cout << "Queue is NOT empty." << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is EMPTY." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;
    int choice, value;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Show Front\n4. Check Empty\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.showFront();
            break;
        case 4:
            q.isEmpty();
            break;
        case 5:
            q.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
