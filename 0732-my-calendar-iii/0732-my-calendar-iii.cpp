class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int ans=0;
        int count=0;
        m[startTime]++;
        m[endTime]--;
        for(auto x:m){
            count+=x.second;
            ans=max(ans,count);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */