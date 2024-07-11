class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int i=k-1,j=c.size()-1;
        int sum=0;
        for(int l=0;l<=i;l++){
            sum+=c[l];
        }
        if(k==c.size()){
            return sum;
        }
        int ans=sum;
        while(i>=0){
            sum+=(-c[i])+c[j];
            i--;
            j--;
            ans=max(ans,sum);
            // cout<<ans<<" "<<i<<" "<<j<<" "<<sum<<endl;
        }
        return ans;
    }
};