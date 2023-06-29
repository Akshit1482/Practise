class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
        int j=0;
        int count = 0;
        vector<int>ans;
        while( i<n && j<m ){
            if( arr1[i] < arr2[j] ){
                ans.push_back( arr1[i] );
                i++;
                count++;
            }
            else{
                ans.push_back( arr2[j] );
                j++;
                count++;
            }
            
            if( count == k ){
                return ans[k-1];
            }
        }
        
        // if pne of the array remains
        while( i<n ){
            ans.push_back( arr1[i] );
            i++;
            count++;
            if( count == k ){
                return ans[k-1];
            }
        }
        while( j<m ){
            ans.push_back( arr2[j] );
            j++;
            count++;
            if( count == k ){
                return ans[k-1];
            }
        }
    }
};
