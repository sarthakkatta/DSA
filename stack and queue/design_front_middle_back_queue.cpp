/*
Problem: LeetCode 1670 – Design Front Middle Back Queue

Approach:
1. Use a vector to simulate the queue.
2. pushFront(val):
   - Insert value at the beginning.
3. pushMiddle(val):
   - Insert value at index size()/2.
4. pushBack(val):
   - Append value at the end.
5. popFront():
   - Remove and return first element.
   - Return -1 if queue is empty.
6. popMiddle():
   - Middle index = (size - 1) / 2.
   - Remove and return middle element.
   - Return -1 if queue is empty.
7. popBack():
   - Remove and return last element.
   - Return -1 if queue is empty.

Key Idea:
- Vector allows direct access to front, middle,
  and back positions.
- Middle operations use the problem-defined
  middle index: (size - 1) / 2.

Time Complexity:
- pushFront()  : O(N)
- pushMiddle() : O(N)
- pushBack()   : O(1)
- popFront()   : O(N)
- popMiddle()  : O(N)
- popBack()    : O(1)

Space Complexity: O(N)
*/

class FrontMiddleBackQueue {
public:
    vector<int> q;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q.insert(q.begin(), val);
    }
    
    void pushMiddle(int val) {
        int mid = q.size() / 2;
        q.insert(q.begin() + mid, val);
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.size() == 0) return -1;

        int a = q[0];
        q.erase(q.begin());

        return a;
    }
    
    int popMiddle() {
        if(q.size() == 0) return -1;

        int mid = (q.size() - 1) / 2;
        int a = q[mid];

        q.erase(q.begin() + mid);

        return a;
    }
    
    int popBack() {
        if(q.size() == 0) return -1;

        int a = q.back();
        q.pop_back();

        return a;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
