class MyCircularQueue {
public:
    vector<int> arr;
    int size;
    int capacity;
    int front;
    int rear;
    MyCircularQueue(int k) {
        arr.resize(k);
        capacity =k;
        size = 0;
        front = 0;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        rear = (rear+1)%capacity;
        arr[rear] = value;
        size++;


        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        front = (front+1)%capacity;
        size--;


        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */