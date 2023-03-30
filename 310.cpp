void sortedInsert( stack<int>&s, int num ){
    //base case
    if( s.empty() || (!s.empty()  && num >s.top() )){
        s.push( num );
        return;
    }
    
    //onee by one element ko pop karo
    int x = s.top();
    s.pop();
    
    //recursive call
    sortedInsert( s, num );
    
    //insert popped element while returning
    s.push( x);
}

void sortStack( stack<int>&s ){
    //base case
    if( s.empty() ){
        return;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    sortStack( s );
    
    //insert popped elemnet while returning
    sortedInsert( s, num );
}

void SortedStack :: sort()
{
   //Your code here
   sortStack( s );
}
