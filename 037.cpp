class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // as we just want to reorder our array with terms of our range
        int start = 0;
        int end = array.size() - 1;
        
        for( int i=0; i <= end;){  // we only traverse till end, as if the umber is swapped with end, we don't want to interupt that number again
        
            if( array[i] < a ){
                swap( array[i++], array[start++] );  // moving all elements smaller from a to left
            }
            else if( array[i] > b ){
                swap( array[i], array[end--] );  // moving all elements greater than b to right
            }
            else{
                i++;  // leaving the elements between a and b at their og place
            }
        }
    }
};
