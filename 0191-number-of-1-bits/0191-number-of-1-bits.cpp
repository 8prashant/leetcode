class Solution {
public:
    int hammingWeight(uint32_t n) {
      //return n.count(1);  
      int count=0;
      while(n!=0){
        if((n>>1)<<1!=n){
          count++;
        }
        n>>=1;
      }
      return count;
    }
};