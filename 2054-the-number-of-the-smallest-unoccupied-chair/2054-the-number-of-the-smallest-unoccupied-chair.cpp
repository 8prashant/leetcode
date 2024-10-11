class Solution {
public:
    using info=array<int, 3>;
    using int2=array<int, 2>;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int n=times.size();
        vector<info> A(n);
        for(int i=0; i<n; i++)
            A[i]={times[i][0], times[i][1], i};
        sort(A.begin(), A.end());

        vector<int> freeCh(n);
        iota(freeCh.begin(), freeCh.end(), 0);
        make_heap(freeCh.begin(), freeCh.end(), greater<int>{});
        priority_queue<int2, vector<int2>, greater<int2>> used;

        for (auto& t : A) {
            int arrival=t[0], leaving=t[1], index=t[2];
            int chair; 
            while (!used.empty() && used.top()[0]<=arrival) {
                chair = used.top()[1];
                freeCh.push_back(chair);  
                push_heap(freeCh.begin(), freeCh.end(), greater<int>{});

                used.pop();
            }
            
            pop_heap(freeCh.begin(), freeCh.end(), greater<int>{});
            chair = freeCh.back();
            freeCh.pop_back();
            
            if (index == targetFriend) 
                return chair;
            
            used.push({leaving, chair});
        }
        
        return -1; 
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();