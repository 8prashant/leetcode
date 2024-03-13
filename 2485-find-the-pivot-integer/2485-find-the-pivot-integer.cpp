class Solution {
public:
    int pivotInteger(int n) {
        int ans=-1;
        for(int i=1;i<=n;i++){
            int left=((i)*(i+1))/2;
            int right=((n*(n+1))/2)-(((i-1)*(i))/2);
            if(left==right){
                ans=i;
            }
        }
        return ans;
    }
};