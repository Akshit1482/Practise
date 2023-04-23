// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int large=i;
        int left=2*i+1;
        int right=2*i+2;
      
        // checking for left and right nodes
        if(left<n && arr[large]<arr[left]){
          large=left;
        }
        if(right <n && arr[large]<arr[right]){
          large=right;
        }
        
        // checking if large has been changed or not for swapping
        if(large!=i){
          swap(arr[large],arr[i]);
          heapify(arr,n,large);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2;i>=0;i--){
         heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {  
        buildHeap(arr,n);
        
            for(int i=n-1;i>=0;i--){
            //swap
            swap(arr[0],arr[i]); // swapping last element of the array with first and decreasing the size of the array
            heapify(arr,i,0); // after  swapping the last and deccreasing the size, we will do heapify on 0th element,  to make all elements go at right positons
        }
    }
};
