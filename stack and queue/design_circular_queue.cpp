/*
Problem: LeetCode 622 – Design Circular Queue

Approach:
1. Use an array (vector) of fixed size k.
2. Maintain:
   - front → index of first element
   - rear  → index where next element will be inserted
   - size  → current number of elements
   - capacity → maximum queue size
3. enQueue(value):
   - Check if queue is full.
   - Insert value at rear.
   - Move rear circularly.
   - Increase size.
4. deQueue():
   - Check if queue is empty.
   - Move front circularly.
   - Decrease size.
5. Front():
   - Return front element.
6. Rear():
   - Return last inserted element.
7. isEmpty():
   - Queue contains no elements.
8. isFull():
   - Queue reached maximum capacity.

Key Idea:
- Use modulo (%) to wrap indices and simulate
  a circular structure inside a fixed-size array.

Time Complexity:
- enQueue() : O(1)
- deQueue() : O(1)
- Front()   : O(1)
- Rear()    : O(1)
- isEmpty() : O(1)
- isFull()  : O(1)

Space Complexity: O(K)
*/

class MyCircularQueue {
public:
    vector<int> q;

    int front;
    int rear;

    int size;
    int capacity;

    MyCircularQueue(int k) {
        q.resize(k);

        front = 0;
        rear = 0;

        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {

        if(isFull())
            return false;

        q[rear] = value;

        rear = (rear + 1) % capacity;

        size++;

        return true;
    }

    bool deQueue() {

        if(isEmpty())
            return false;

        front = (front + 1) % capacity;

        size--;

        return true;
    }

    int Front() {

        if(isEmpty())
            return -1;

        return q[front];
    }

    int Rear() {

        if(isEmpty())
            return -1;

        return q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
