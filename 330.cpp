#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	
	deque<int>maxi(k);
	deque<int>mini(k);

	// for first k elements
	for( int i=0; i<k; i++){
		// maximum array
		while( !maxi.empty() && nums[maxi.back()] <= nums[i] ){ // we have got larger elemnet than maxi.back, so thats the temp mximum
			maxi.pop_back();
		}
		while( !mini.empty() && nums[mini.back()] >= nums[i] ){// we have got smaller elemnet than mini.back, so thats the temp minimum
			mini.pop_back();
		}
		maxi.push_back( i );
		mini.push_back( i );
	}
	long long ans = 0;
	ans = nums[ maxi.front() ] + nums[ mini.front() ];

	// for next n-k elements
	for( int i=k; i<n; i++){
		// reoval of element, for next k subarray
		while( !maxi.empty() && i-maxi.front() >= k){
			maxi.pop_front();
		}
		while( !mini.empty() && i-mini.front() >= k){
			mini.pop_front();
		}

		// addition of next element for next k subarray
		while( !maxi.empty() && nums[maxi.back()] <= nums[i] ){
			maxi.pop_back();
		}
		while( !mini.empty() && nums[mini.back()] >= nums[i] ){
			mini.pop_back();
		}

		maxi.push_back( i );
		mini.push_back( i );

		ans += nums[ maxi.front()] + nums[ mini.front()];
	}
	return ans;
}
