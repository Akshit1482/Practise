class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        
        // 4 0 2 1 3 -> input
        // 3 4 2 0 1 -> output
        // y gives the desired result but alters the element at that position, so to recover from that we use formula ((y%n)*n)+x, 
        // from which we can acces both old input element and the desired output element
        
        // as we only move forward so x can't be changed, so it represent the current elemnt we are standing
        //and y represents the elemnt which we have traverssed through, and we altered with our formula,
        // to access old input we modulus the new numbr by n
        // to access desired output we divide  the array numbr by n
        
        
        long long maxx = n;
        // as we want the array to have element as arr[arr[i]];
        for( int i=0; i<n; i++ ){
            int x = arr[i];
            int y = arr[x];  // i.e, arr[arr[i]];
            
            arr[i] = (( y % maxx ) * maxx ) + x; // y is the new number at old places or og input numbers, so to get og input numbers from that we modulus it by n
                                                 // and x is the current elemnt
        }
        
        for( int i=0; i<n; i++ ){
            arr[i] = arr[i]/n;
        }
        
    }
};
