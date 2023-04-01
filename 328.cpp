vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
        
        deque<long long>q;
        vector<long long>ans;
        
        // for first k elements
        for( long long i =0; i<K; i++){
            if( A[i] < 0 ){
                q.push_back( i );
            }
        }
        // push ans q.front to ans
        if( !q.empty()){
            ans.push_back( A[q.front()]);
        }
        else{
            ans.push_back( 0 );
        }
        
        // for next k elements
        for( long long i=K; i<N; i++){
            
            //removal
            if( !q.empty() && i-q.front() >= K){
                q.pop_front();
            }
            
            // addition
            if( A[i] < 0){
                q.push_back( i );
            }
            
            if( !q.empty()){
                ans.push_back( A[q.front()]);
            }
            else{
                ans.push_back( 0 );
            }
        }
        return ans;
 }
