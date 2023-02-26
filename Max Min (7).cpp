class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        for(int i=0; i<N; i++){
            maximum=max( A[i], maximum);
            minimum=min( A[i], minimum);
        }
        int sum=0;
        sum = maximum+minimum;
        return sum;
    }

};
