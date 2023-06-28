class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort( arr, arr+n );
	    long long count = 0;
	    for( int i=0; i<n; i++ ){
	        int low=i+1;
	        int high=n-1;
	        while( low < high ){
	            if( arr[i] + arr[low] + arr[high] < sum ){
	                count += high-low; // as array is sorted, if arr[high] is smaller than sum, then all elements sum below high will be smaller thann sum
	               low++;
	            } 
	            else{
	               high--;
	            }
	        }
	    }
	    return count;
	}
		 

};
