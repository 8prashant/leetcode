class Solution {
public:
    int countSeniors(vector<string>& d) {
        int sum=0;
        for(int i=0;i<d.size();i++){
            int a=(d[i][11]-'0')*10+(d[i][12]-'0');
            if(a>60){
                sum++;
            }
        }
        return sum;
        
    }
};