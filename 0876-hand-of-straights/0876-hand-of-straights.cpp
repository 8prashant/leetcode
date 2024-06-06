class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>m;
        for(auto x:hand){
            m[x]++;
        }
        while(!m.empty()){
            int a=m.begin()->first;
            m.begin()->second--;
            if(m.begin()->second==0){
                m.erase(m.begin()->first);
            }
            for(int i=0;i<groupSize-1;i++){
                int b=a+1;
                if(m.find(b)==m.end()){
                    return false;
                }
                else{
                    m[b]--;
                    if(m[b]==0){
                        m.erase(b);
                    }
                    a=b;
                }
            }
        }
        return true;
    }
};