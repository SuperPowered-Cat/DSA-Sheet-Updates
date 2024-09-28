// leetcode 641

// **Q: Design Circular Deque**

// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false 
// otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false 
// otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false 
// otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false 
// otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.
 
// Example 1:
// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", 
// "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]
// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False, the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4
 
// Constraints:
// 1 <= k <= 1000
// 0 <= value <= 1000
// At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty,
// isFull.



// CODE ->

class MyCircularDeque {
public:

    // IMPLEMENTATION THROUGH VECTOR ARRAY
    // MISLEADING NAME THIS IS SIMPLY CIRCULAR LINKED LIST/ARRAY
    vector <int> vec;
    int l, r, size, full;

    MyCircularDeque(int k) {
        vec = vector <int> (k, -1);
        l = 0;
        r = 0;
        size = 0;
        full = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        if (l == 0) l = full-1;
        else l--;
        vec[l]= value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        vec[r] = value;
        if (r == full-1) r = 0;
        else r++;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        vec[l] = -1;
        if (l == full - 1) l = 0;
        else l++;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (r == 0) r = full-1;
        else r--;
        vec[r] = -1;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return vec[l];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        if (r == 0) return vec[full-1];
        else return vec[r-1];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == full);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
