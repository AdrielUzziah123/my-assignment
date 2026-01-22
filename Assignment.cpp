#include <iostream>
#include <stack>
using namespace std;

class CircularQueueUsingStacks {
private:
    int size;
    int count;
    stack<int> inbox;   // stack for enqueue
    stack<int> outbox;  // stack for dequeue

public:
    CircularQueueUsingStacks(int s) {
        size = s;
        count = 0;
    }

    void enqueue(int x) {
        if (count == size) {
            cout << "Queue is full" << endl;
            return;
        }
        inbox.push(x);
        count++;
        cout << "Enqueued: " << x << endl;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        int val = outbox.top();
        outbox.pop();
        count--;
        cout << "Dequeued: " << val << endl;
        return val;
    }

    int front() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top();
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    CircularQueueUsingStacks cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Front element: " << cq.front() << endl;

    cq.dequeue();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); // should show "Queue is full"

    while (!cq.isEmpty()) {
        cq.dequeue();
    }

    return 0;
}

