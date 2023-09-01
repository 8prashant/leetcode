class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=n;i++){
            bitset<32> b(i);
            int sum=0;
            for (int i = 0; i < 32; i++) {
                if (b[i] == 1) {
                    sum += 1;  
                }
            }
            v.push_back(sum);
        }
        return v;
    }
};