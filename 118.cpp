

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>copy(nums);
	    unordered_map<int,int>mp;
	    for( int i=0; i<nums.size(); i++ ){
	        mp[nums[i]] = i;
	    }
	    
	    int count = 0;
	    
	    sort( copy.begin(), copy.end() );
	    
	    // check if the element is placed in right position or not
	    for( int i=0; i<nums.size(); i++ ){
	        if( nums[i] != copy[i] ){
	            count++;
	            int index = mp[copy[i]]; // index after getting sorted
	            mp[nums[i]] = index; // alloting the nums[i] element its right position;
	            mp[nums[index]] = i; // alloting the swapped element its, new temporary position44
	            
	            swap( nums[i], nums[index] );
	        }
	    }
	    return count;
	}
};

// next approach

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>ans(nums);
	    sort( ans.begin(), ans.end() );
	    unordered_map<int,int>m;
	    for( int i=0; i<ans.size(); i++ ){
	        m[ans[i]] = i;
	    }
	    
	    int count = 0;
	    for( int i=0; i<nums.size(); i++ ){
	        while( m[nums[i]] != i ){
	            count++;
	            swap( nums[i], nums[m[nums[i]]] );
	        }
	    }
	    return count;
	}
};
