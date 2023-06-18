class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        
        unordered_map<int,int>m;
        
        for( int i=0; i<n; i++ ){
            m[arr[i]]++;
        }
        int count = 0;
        for( auto i:m ){
            if( i.second > n/k ){
                count++;
            }
        }
        return count;
    }
};
