class MyCircularQueue {
public:

    int *arr;
    int size;
    int szcounter;
    int front;
    int rear;

    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        szcounter = 0;
        front = -1;
        rear = -1;    
    }
    
    bool enQueue(int value) {
        if(front == -1 and rear == -1) {
            front = 0;
            rear = 0;
            arr[rear] = value;
            szcounter++;
            return true;
        }

        if((rear+1)%size == front) {
            return false;
        }

        rear = (rear+1)%size;
        arr[rear] = value;
        szcounter++;
        return true;
    }
    
    bool deQueue() {
        if(front == -1) {
            return false;
        }

        if(front == rear) {
            front = -1;
            rear = -1;
            szcounter--;
            return true;
        }

        front = (front+1)%size;
        return true;
    }

    int Front() {
        if(front == -1) {
            return -1;
        }

        return arr[front];
    }
    
    int Rear() {
        if(rear == -1) {
            return -1;
        }

        return arr[rear];
    }
    
    bool isEmpty() {
        return (front == -1);
    }
    
    bool isFull() {
        return ((rear+1)%size == front);
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