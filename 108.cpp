class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // create a map
        map<int,int>mp;
        for( int i=0; i<size; i++ ){
            mp[a[i]]++;
        }
        
        for(auto i:mp ){
            if( i.second > (size/2)){
                return i.first;
            }
        }
        return -1;
    }
};
