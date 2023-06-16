class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>ans;
            int i=0;
            int j=0;
            int k=0;
            int lastAdded = INT_MIN; // this to prevent entering of duplicate items in the array
            
            while( i<n1 && j<n2 && k<n3 ){
                if( (A[i] == B[j]) && (B[j] == C[k]) ){
                    if( lastAdded != A[i] ){
                        ans.push_back( A[i] );
                        lastAdded = A[i];  // updating the last added
                    }
                    i++;
                    j++;
                    k++;
                }
                else{  // elemnts are not equal
                    int smallest = min( A[i], min( B[j],C[k] ) );  // finding the samllest element to increment the position in array
                    if( smallest == A[i] ){
                        i++;
                    }
                    else if( smallest == B[j] ){
                        j++;
                    }
                    else{
                        k++;
                    }
                }
            }
            return ans;
        }

};
