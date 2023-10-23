class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n%4!=0 && n>1 || n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(isPowerOfFour(n/4)){
            return true;
        }
        else{
            return false;
        }
        
    }
};