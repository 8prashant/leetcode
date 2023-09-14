class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int sum=0;
        while(target!=1 && maxDoubles!=0){
          if((target&1)==1){
            target>>=1;
            sum+=2;
          }else{
            target>>=1;
            sum++;
          }
          maxDoubles--;
        }
        sum+=target-1;
        return sum;
    }
};