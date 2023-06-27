int firstOcc(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;
    int ans=-1;
    while(start <= end){
        
        if(arr[mid] == key){  // we have found the key, and have to find the lowest index
            ans=mid;
            end = mid - 1;
        }
        
        else if(arr[mid] > key){
            end = mid-1;
        }
        
        else{
            start = mid+1;
        }
        mid = (start + end)/2;
    } 
    return ans;
}

int LastOcc(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;
    int ans;
    while(start <= end){
        
        if(arr[mid] == key){  // we have found the key, and have to find the greater index
            ans=mid;
            start = mid + 1;
        }
        
        else if(arr[mid] > key){
            end = mid-1;
        }
        
        else{
            start = mid+1;
        }
        mid = (start + end)/2;
    } 
    return ans;
}
vector<int> find(int arr[], int n , int key )
{
    // code here
    vector <int> answer;
    
    int left = firstOcc(arr, n ,key);
    int right = LastOcc(arr, n ,key);
    
    return {left, right};
}
