#include <bits/stdc++.h> 
class NQueue{
public:
    int n;
    int s;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;
    
    // Initialize your data structure.
    NQueue(int n, int s){
        this -> n = n;
        this -> s = s;
        arr = new int[n];
        front = new int[s];
        rear = new int[s];
        next = new int[n];
        freespot = 0;

        //initaialzing array front and prev
        for( int i=0; i<s; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // initializing next array
        for( int i=0; i<n; i++){
            next[i] = i+1;
        }
        // initializing the last element of next array
        next[n-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // check for overloading
        if( freespot == -1){
            return false;
        }

        int index = freespot;

        //updating the freespot
        freespot = next[ index ];

        // check if array is either empty or full
        if( front[m-1] == -1 ){
            front[ m-1 ] = index;
        }
        else{
            next[ rear[m-1] ] = index; // connecting the next freespot of mth queue to its last added element
        }

        // updating the next index
        next[ index ] = -1;

        // updating the rear array
        rear[ m-1 ] = index;

        // pushing the element
        arr[index] = x; 

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // check for underflow
        if( front[ m-1 ] == -1){
            return -1;
        }
        
        int index = front[ m-1 ];
        
        //update front
        front[ m-1 ] = next[ index ];

        //update next array
        next[ index ] = freespot; // next of that currently pop eleemt will point to next freespot available for pushing after something gets pushed into that index, 
                                  //because after opping the arr[ index ] will get empty

        // updating freespot
        freespot = index;

        return arr[index];
    }
};
