// LAB8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class MyQueue {
private:
    int arr[5];
    int front, rear;

public:
    MyQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == 4) {
            cout << "Queue is FULL!" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " added to queue." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
    }

    void showFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY!" << endl;
        }
        else {
            cout << "Front element = " << arr[front] << endl;
        }
    }

    void isEmpty() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY." << endl;
        }
        else {
            cout << "Queue is NOT empty." << endl;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
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
