class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int size= m+n;
        int arr[size];
        int k=0;
        int count=1;
        //combining both arrays into one arrays
        for(int i=0; i<n; i++){
            arr[k++]=a[i];
        }
        for(int i=0; i<m; i++){
            arr[k++]=b[i];
        }
        //sorting the combined array
        sort(arr,arr+size);
        //counting the unique element
        for(int i=1; i<size; i++){
            if(arr[i]!=arr[i-1])
                count++;
        }
        return count;
    }
};
