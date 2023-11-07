class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i=0;i<dist.size();i++){
            time.push_back((double)dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        int ans=0;
        for(int i=0;i<time.size();i++){
            if(time[i]>i){
                ans+=1;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
