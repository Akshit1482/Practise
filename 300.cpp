#include <bits/stdc++.h> 
class NStack
{
    int* arr;
    int* top;
    int* next;
    
    int n,s;
    
    int freespot;
public:
    // Initialize your data structure.
    
    NStack(int N, int S)
    {
        n=N;
        s=S;
        arr = new int[ s ];
        top = new int[ n ];
        next = new int[ s ];

        //iniitalize top array
        for( int i=0; i<n; i++ ){
            top[i] = -1;
        }

        //initialize next array
        for( int i=0; i<s; i++){
            next[i] = i+1; // every element represents next free space
        }
        //initialize nth element
        arr[s-1] = -1; // as last element don't have any freespace

        // initialize freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // overflow condition
        if( freespot == -1 ){
            return false;
        }

        int index = freespot;

        arr[ index ] = x;

        //update freespot
        freespot = next[ index ];

        //update next
        next[ index ] = top[ m-1 ]; // this store will help in tracking during pop() which will tell where to go after popping the elemet

        //update top
        top[ m-1 ] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow codition
        if( top[m-1] == -1 ){
            return -1;
        }
        
        // write all push code in return
        int index = top[ m-1 ];

        top[ m-1 ] = next[ index ]; // as discussed in push

        next[ index ] = freespot; //gives the index of next free space of specific stack when an element gets popped

        freespot = index;

        return arr[ index ];
    }
};
