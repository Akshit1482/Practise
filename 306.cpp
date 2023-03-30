lass Solution{
    private:
    // code for fibonacci
   	    int fib( int x ){
   	        if(x!= 1 && x!=0){
   	        int a = 0;
   	        int b = 1;
   	        for( int i=2; i<x; i++){
   	            int num =a;
   	            a = a+b;
   	            b = num;
   	        }
   	        return a;
   	        }
   	        else{
   	            return x;
   	        }
   	    }
	public:
   	int evaluate_exp(int n){
   
   	    int ans = (fib(n-1)*fib(n+1))-(fib(n)*fib(n));
   	    return ans;
   	}    
};
