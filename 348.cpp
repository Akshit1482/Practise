class Solution
{
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if( maxHeap.size() == 0 || x < maxHeap.top() ){ // as x is smaller than maxHeap top, so it will be added in maxHeap
            maxHeap.push( x );
        }
        else{ // x > minHeap.top()
            minHeap.push( x );
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if( maxHeap.size() > minHeap.size() ){
            minHeap.push( maxHeap.top() );
            maxHeap.pop();
        }
        else if( minHeap.size() > maxHeap.size()  ){
            maxHeap.push( minHeap.top() );
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double res = 0;
        if( minHeap.size() == maxHeap.size() ){
            res = ( minHeap.top() + maxHeap.top() )/ 2.0 ;
        }
        else if( maxHeap.size() > minHeap.size() ){
            return maxHeap.top();
        }
        else{
            return minHeap.top();
        }
    }
    private:
        priority_queue< double, vector<double>, greater<int> > minHeap;
        priority_queue< double > maxHeap;
};
