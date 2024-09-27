class MyCalendarTwo {
public:
    map<int,int> calendar;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        calendar[start]++;
        calendar[end]--;
        int ongoing = 0;
        
        for (auto &entry : calendar) {
            ongoing += entry.second;
           
            if (ongoing > 2) {
                calendar[start]--;
                calendar[end]++;
                return false;
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