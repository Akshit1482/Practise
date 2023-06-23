int minFlips (string S)
{
    int count_1 = 0;
    int count_2 = 0;
    int n = S.size();
    
    // we are now gonna make two binary strings one start from 1 and other from 0
    bool flag = true;
    string s1,s2;
    
    for( int i=0; i<n; i++ ){
        if( flag == true ){
            s1.push_back( '1' );
            s2.push_back( '0' );
            flag = false;
        }
        else{ // now we're going to add alternate bit
            s1.push_back( '0' );
            s2.push_back( '1' );
            flag = true;
        }
    }
    for( int i=0; i<n; i++ ){
        if( S[i] != s1[i] )
            count_1++;
        if( S[i] != s2[i] )
            count_2++;
    }
    
    return min( count_1,count_2 );
}
