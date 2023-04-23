//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // creating a min heap
	    priority_queue<int, vector<int>, greater<int> >pq;
	    
	    // pushing k elements in the maxHeap
	    for( int i=0; i<k; i++ ){
	        pq.push( arr[i] );
	    }
	    
	    //step2: pushing rest elements int he maxHeap
	    for( int i=k; i<n; i++ ){
	        if( arr[i] > pq.top() ){
	            pq.pop();
	            pq.push( arr[i] );
	        }
	    }
	    
	    //step3: returning the ans by storingit in a vector in reverse order
	    vector<int>res;
	    while( !pq.empty() ){
	        res.push_back( pq.top() );
	        pq.pop();
	    }
	    reverse( res.begin(), res.end() );
	    return res;
	}

};
