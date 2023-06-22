class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // we are firstly going to find the break point in array, which is going to be the element fisrt element smaller than the first largest elemnet
        // from the right side
        int index = -1;
        for( int i=N-1; i>=0; i-- ){
            if( arr[i] > arr[i-1] ){  // we're finding the first largest elemnt from right
                index = i-1;
                break;
            }
        }
        
        // IF break doon't exist
        if( index == -1 ){  // this means the input is the last permutation, i.e sorted in decreasing order
            reverse( arr.begin(),arr.end() );
            return arr;
        }
        // IF the break exist
        // we know index is the first largest element from right, and index-1 is the point where we founded index
        // so we need to swap index-1 with first greater element from  index-1 from the right
        for( int i=N-1; i>index; i-- ){
            if( arr[i] > arr[index] ){
                swap( arr[i],arr[index] );
                break;
            }
        }
        // now we have got our swapped element for next permutaion
        // for next permutation, sort every elemnet right from swapped to n-1
        reverse( arr.begin() + (index+1) , arr.end() );
        return arr;
    }
};
