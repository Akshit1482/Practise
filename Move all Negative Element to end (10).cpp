class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        //copying original array to a temp. array
        int temp[n];
        for(int i=0; i<n; i++){
            temp[i]=arr[i];
        }
        //copying all positive element from temp array to original array
        int j=0;
        for(int i=0; i<n; i++){
            if(temp[i]>=0){
                arr[j++]=temp[i];
            }
        }
        //if temp array is negative or after copying positive elements j ha sreached the end of the array
        if(j==0 || j==n){
            return;
        }
        //copying all negative element from temp array to original array
        for(int i=0; i<n; i++){
            if(temp[i]<0){
                arr[j++]=temp[i];
            }
        }
        
    }
};
