class Solution {
public:
    int dfs(int i, int j, vector<int>& nums){
        if(i==j){
            return nums[i];
        }
        else if(i>j){
            return 0;
        }
        int a=nums[i]+min(dfs(i+2,j,nums),dfs(i+1,j-1,nums));
        int b=nums[j]+min(dfs(i+1,j-1,nums),dfs(i,j-2,nums));
        return max(a,b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int p1=dfs(0,n-1,nums);
        cout<<"p1="<<p1<<endl;
        return (total-p1)<=p1;
    }
};