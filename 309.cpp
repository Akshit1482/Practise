class Solution{
private:
void insertAtBottom( stack<int>&St, int num){
        
        //base case
        if( St.empty() ){
            St.push( num );
            return;
        }
        
        int x = St.top();
        St.pop();
        
        //recursive call
        insertAtBottom( St, num);
        
        // return karte waqt num ko vaps add karna hai
        St.push( x );
}
public:
    void Reverse(stack<int> &St){
        // base case
        if( St.empty()){
            return;
        }
        
        int num = St.top();
        St.pop();
        
        //recursive call
        Reverse( St ); // it will five the reverse array, except num
        
        // insert num at the bottom of reverse stack
        insertAtBottom( St, num);
    }
};
