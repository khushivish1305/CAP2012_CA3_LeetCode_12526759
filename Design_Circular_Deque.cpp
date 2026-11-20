class MyCircularDeque {
private:
    vector<int> q;
    int front, rear, size, cap;

public:
    MyCircularDeque(int k) : q(k), front(0), rear(k - 1), size(0), cap(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        q[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % cap;
        q[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + cap) % cap;
        size--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : q[front];
    }

    int getRear() {
        return isEmpty() ? -1 : q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};
