void MyQueue :: push(int x)
{
        if( rear == 100005 ){ // checking overflow condition
            return;
        }
        else{
            arr[ rear ]= x; // entering the data
            rear++;         // incrementing the rear   
        }
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        if( front == rear ){  //checking the underflow condition, i.e., front and rear are both at starting position
            return -1;
        } 
        else{
            int ans = arr[ front ];
            arr[ front ] = -1;
            front++;
            
            if( front == rear ){  // to save memory, as array has gotten empty, so we start both front and rear from starting position
                front = 0;
                rear = 0;
            }
            return ans;
        }
}
