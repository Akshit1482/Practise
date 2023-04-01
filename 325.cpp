class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int balance = 0;
       int deficit = 0;
       int start = 0;
       
       for( int i=0; i<n; i++){
           balance += p[i].petrol - p[i].distance; // checking if there is enough petrol to cover give n distace at that instance
           
           if( balance<0 ){  // if at any instant balance is less than zero
               deficit += balance;  // jab bhi balanc enegative aayega usko deficit mein add karte jao
               balance = 0;  // after adding balance to deficit, put balance again to zero
               start = i+1;  // we are arting from i+1, because as with balance we can't reach to ith element, so ther eis no chance of reaching ith elemnet if we start fom position ahead and behind of i, because as we move away from start balance costant reduces everytime
           }
       }
       
       if( deficit + balance >= 0){ // if remaining balance after traversing whole array cover deficit, then with help of that balance we can traverse the deficit part
           return start;
       }
       else{
           return -1;
       }
    }
};
