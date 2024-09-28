class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        int count=0;
        m[start]++;
        m[end]--;
        for(auto x:m){
            count+=x.second;
            if(count>=3){
                m[start]--;
                m[end]++;
                if(m[start]==0){
                    m.erase(start);
                }
                if(m[end]==0){
                    m.erase(end);
                }
                return false;
            }
            if(x.first>end){
                break;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */