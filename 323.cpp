queue<int> modifyQueue(queue<int> q, int k) {
    
    //stack declaration
    stack<int>s;
    
    for( int i=0; i<k; i++){
        int num = q.front();
        q.pop();
        s.push( num );
    }  // 4,5   stack[3,2,1]
    
    // push stack elemnet back to queue
    while( !s.empty() ){
        int num = s.top();
        s.pop();
        q.push( num );
    }   // 4,5,3,2,1
    
    // pop n-k elemnet from queue and push to back of queue
    for( int i= 0; i<q.size()-k; i++){
        int num = q.front();
        q.pop();
        q.push( num );
    }
    
    return q;
}
