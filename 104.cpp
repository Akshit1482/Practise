class Solution {
  public:
    int countSquares(int N) {
        int i = 1;
        while( i*i < N ){
            i++;
        }
        return i-1;
    }
};
