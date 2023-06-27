class Solution{
    public:
    int getPivot( int A[], int l, int h ){
        int s = l;
        int e = h;
        int mid = s+(e-s)/2;
        
        while( s < e ){
            if( A[mid] >= A[0] ){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
    
    int binarySearch( int A[], int l, int h, int key ){
        int s = l;
        int e = h;
        int mid = s+(e-s)/2;
        
        while( s<=e ){
            if( A[mid] == key ){
                return mid;
            }
            // go right
            if( A[mid] < key ){
                s = mid+1;
            }
            else{ // go left
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        int pivot = getPivot( A, l, h);
        
        if( key>=A[pivot] && key<=A[h] ){
            return binarySearch( A, pivot, h, key );
        }
        else{
            return binarySearch( A, l, pivot-1, key );
        }
    }
};
