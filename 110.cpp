bool findPair(int arr[], int size, int n){
    //code
    sort( arr, arr+size );
    int i=0;
    int j=1;
    
    while( i<size && j<size ){
        int diff = arr[j] - arr[i];
        
        if( diff == n ){
            return true;
        }
        else if( diff < n ){
            j++; // move right pointerr t increase the diff
        }
        else{
            i++; // move left pointer to decrease the diff
        }
        
        // to check if the ponter should not point to dame element
        if( i == j ){
            j++;
        }
    }
    return false;
    
}
