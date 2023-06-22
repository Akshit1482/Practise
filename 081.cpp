class Solution {
  public:
    int romanToDecimal(string &str) {
        // first we store value of each roman numeral in map
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] =100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int sum = 0;
        int prev = 0;
        // now we get greater numeral than  prev, the we add to the sum, but if get smaller than prev, then we substract that numeral from sum
        // we'll start from end
        // as XI is 11 as I is smaller and ocuurs first from end
        // but IX is 9 as I is smaller tha its previous numeral
        for( int i=str.length()-1; i>=0; i-- ){
            int ch = m[str[i]];
            if(prev <= ch ){
                sum += ch;
            }
            else{ // previous elemnet was greater than current, so the current will get minus from sum, as the rule of roman numeral
                sum -= ch;
            }   
                prev = ch; // updating prev, as we have got a new smaller element
            
        }
        return sum;
        
    }
};
