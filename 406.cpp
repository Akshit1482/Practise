class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        // creating a map to store the anagrams frequency
        map<string, vector<string>>m;
        // loop to travel the input string
        for( int i=0; i<string_list.size(); i++ ){
            string s = string_list[i];
            sort( s.begin(), s.end() );
            m[s].push_back( string_list[i] );
        }
        
        // creating a matrix for returning
        vector<vector<string>>ans;  // as this atrix will be the size of the map
        
        // we'll start traversing the map
        for( auto i : m ){
            ans.push_back( i.second );   // we are keeping one loop as we have to enter the values in matrix, and not a lnear vector
        }
        return ans;
    }
};
