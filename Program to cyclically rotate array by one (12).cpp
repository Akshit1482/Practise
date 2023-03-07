void rotate(int arr[], int n)
{
    //storing the last term
    int temp=arr[n-1];
    //using while loop shifting all elements to right by one
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    //storing the last no. at the first position of the array
    arr[0]=temp;
}
