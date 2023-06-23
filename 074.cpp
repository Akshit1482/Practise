class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>result;
            int n = txt.size() - pat.size();
            
            for( int i=0; i<=n; i++ ){
                string temp = txt.substr( i, pat.size() );
                if( temp == pat ){
                    result.push_back( i + 1 );
                }
            }
            if( result.size() == 0 ){
                result.push_back( -1 );
            }
            return result;
        }
     
};
