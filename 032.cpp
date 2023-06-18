string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int,int>mp;
    // creating the map from first array
    for( int i=0; i<n; i++ ){
        mp[a1[i]]++;
    }
    
    // now traversing the map to check if the second array is subset
    for( int i=0; i<m; i++ ){
        if( mp.find(a2[i]) == mp.end() ){
            return "No";
        }
        mp[a2[i]]--; // decreasing the frequency, so that all dupicates should be considered differently al the time
        
        // if the frequency in 1st array gets decreased and has reached to zero, we know its not valid, but find function will still operate on this
        if( mp[a2[i]] == 0 ){
            mp.erase(a2[i]);
        }
    }
    return "Yes";
}
