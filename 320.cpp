#include <bits/stdc++.h> 
class CircularQueue{
    public:
        int* arr;
        int front;
        int rear;
        int size;
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //check the overflow condition
        if( (front == 0 && rear == size-1) || rear == (front-1)%(size-1) ){
            return false;
        }
        else if( front == -1){ // queue is empty
            front = rear = 0;
        }
        else if( rear == size-1 && front != 0 ){ // rear is at the end but the front is not at starting point
            rear = 0;    // cyclic nature
        }
        else{  // normal push
            rear++;
        }
        //push value inside array
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // cheCking the underflow condition
        if( front == -1){  // stack is empty
            return -1;
        }
        // taking out the popping element
        int ans = arr[ front ];
        arr[front] = -1;

        if( front == rear){  // only one element present in queue
            front = rear = -1;  // moving starting and ending position to the start
        }
        else if( front == size-1 ){
            front = 0; //cyclic nature
        }
        else{  // normal pop
            front++;
        }
        return ans;
        
    }
};
