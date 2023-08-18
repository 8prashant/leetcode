class Solution {
public:

    bool check(vector<int>& dist,int mid, double hour){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            double x=dist[i]*1.0/mid;
            if(i!=dist.size()-1){
                ans+=ceil(x);
            }
            else{
                ans+=x;
            }
            if(ans>hour){
                return false;
            }
        }
        if(ans<=hour){
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i=1;
        int j=1e7;
        int ma=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(check(dist,mid,hour)){
                j=mid-1;
                ma=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ma;
        
    }
};