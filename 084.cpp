class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>mp;
        for( int i=0; i<n; i++ ){
            mp[arr[i]]++;
        }
        
        if( mp.size() == 1 ){ // as there will be no second gratest element;
            return "";
        }
        
        priority_queue<pair<int,string>>pq;
        for( auto i:mp ){
            pq.push( {i.second, i.first} );
        }
        
        // now we need second top element
        pq.pop(); // pop greatest eleemnt
        return pq.top().second;
    }
};
