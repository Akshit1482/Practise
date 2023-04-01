

//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    stack<int>s;
    
    while( !q.empty()){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    while( !s.empty() ){
        int val = s.top();
        s.pop();
        q.push(val);
    }
     return q;
}
