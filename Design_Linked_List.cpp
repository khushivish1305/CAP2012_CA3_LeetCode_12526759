class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x, Node* nextNode = nullptr) : val(x), next(nextNode) {}
    };

    Node* dummyHead;
    int size;

public:
    MyLinkedList() {
        dummyHead = new Node(0);
        size = 0;
    }

    ~MyLinkedList() {
        Node* curr = dummyHead;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* curr = dummyHead->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        Node* pred = dummyHead;
        for (int i = 0; i < index; ++i) {
            pred = pred->next;
        }
        pred->next = new Node(val, pred->next);
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* pred = dummyHead;
        for (int i = 0; i < index; ++i) {
            pred = pred->next;
        }
        Node* toDelete = pred->next;
        pred->next = toDelete->next;
        delete toDelete;
        --size;
    }
};
